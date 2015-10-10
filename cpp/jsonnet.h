// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CPP_JSONNET_H_
#define CPP_JSONNET_H_

#include <functional>
#include <cstring>
#include <map>

#include "core/vm.h"

namespace jsonnet {

template <typename C>
using ImportCallbackFunc =
    std::function<bool(
        const std::string& base_dir,
        const std::string& path,
        C* context,
        std::string* found_here,
        std::string* output)>;


template <typename ContextType>
struct ImportCallbackWrapper {
  ImportCallbackWrapper(ImportCallbackFunc<ContextType> callback,
                        ContextType* context)
      : callback(callback),
        context(context),
        vm(nullptr) {}

  ImportCallbackFunc<ContextType> callback;
  ContextType* context;
  ::Vm* vm;
};

namespace internal {
template <typename ContextType>
char* DelegateImportCallback(void* ctx, const char* base, const char* file,
                             char** found_here_cptr, int* success) {
  auto* context = static_cast<ImportCallbackWrapper<ContextType>>(ctx);
  std::string found_here;
  std::string result;
  *success = context->callback(base, file, context->context, &found_here,
                               &result);

  // Allocate a char* with jsonnet_realloc and copy the relative path string.
  *found_here_cptr = ::jsonnet_realloc(context->vm, nullptr,
                                       found_here.length() + 1);
  std::strcpy(*found_here_cptr, found_here.c_str());

  // Allocate a char* with jsonnet_realloc and copy the result string.
  char* result_buffer = ::jsonnet_realloc(context->vm, nullptr,
                                          result.length() + 1);
  std::strcpy(result_buffer, result.c_str());
  return result_buffer;
}
}  // namespace internal

class JsonnetVm {
 public:
  JsonnetVm();
  ~JsonnetVm();

  template <typename ContextType>
  void SetImportCallback(ImportCallbackWrapper<ContextType>* callback_wrapper) {
    callback_wrapper->vm = &vm_;
    ::jsonnet_import_callback(internal::DelegateImportCallback,
                              callback_wrapper);
  }

  /// Sets the maximum stack depth.
  void SetMaxStack(uint32_t depth);

  /// Sets the number of objects required before a carbage collection cycle is
  /// allowed.
  void SetGcMinObjects(uint32_t objects);

  /// Run the garbage collector after this amount of growth in the number of
  /// objects.
  void SetGcGrowthTrigger(double growth);

  /// Set whether to expect a string as output and don't JSON encode it.
  void SetStringOutput(bool string_output);

  /// Set whether to emit the Jsonnet input after parsing/desugaring.
  void SetDebugAst(bool debug_ast);

  /// Set the number of lines of stack trace to display (0 to display all).
  void SetMaxTrace(uint32_t lines);

  /// Bind a Jsonnet external variable to the given value.
  ///
  /// Argument values are copied so memory should be managed by caller.
  void BindExtVar(const std::string& key, const std::string& value);

  /// Bind a Jsonnet external code variable to the given value.
  ///
  /// Argument values are copied so memory should be managed by caller.
  void BindExtCodeVar(const std::string& key, const std::string& value);

  /// Evaluate a file containing Jsonnet code to return a JSON string.
  ///
  /// @param filename Path to a file containing Jsonnet code.
  /// @param output Pointer to string to contain the output.
  bool EvaluateFile(const std::string& filename, std::string* output);

  /// Evaluate a string containing Jsonnet code to return a JSON string.
  ///
  /// @param filename Path to a file (used in error message).
  /// @param snippet Jsonnet code to execute.
  /// @param output Pointer to string to contain the output.
  bool EvaluateSnippet(const std::string& filename,
                       const std::string& snippet,
                       std::string* output);

  /// Evaluate a file containing Jsonnet code, return a number of JSON files.
  ///
  /// @param filename Path to a file containing Jsonnet code.
  /// @param outputs Pointer to map which will store the output map of filename
  ///        to JSON string.
  bool EvaluateFileMulti(const std::string& filename,
                         std::map<std::string, std::string>* outputs);

  /// Evaluate a string containing Jsonnet code, return a number of JSON files.
  ///
  /// @param filename Path to a file containing Jsonnet code.
  /// @param snippet Jsonnet code to execute.
  /// @param outputs Pointer to map which will store the output map of filename
  ///        to JSON string.
  bool EvaluateSnippetMulti(const std::string& filename,
                            const std::string& snippet,
                            std::map<std::string, std::string>* outputs);

 private:
  char* EvaluateFileAux(const char* filename, int* error, bool multi);
  char* EvaluateSnippetAux(const char* filename, const char* snippet,
                           int* error, bool multi);

  ::Vm vm_;
};

}  // namespace jsonnet

#endif  // CPP_JSONNET_H_
