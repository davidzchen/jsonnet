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

#include "cpp/jsonnet.h"

namespace jsonnet {

JsonnetVm::JsonnetVm() {}
JsonnetVm::~JsonnetVm() {}

void JsonnetVm::SetMaxStack(uint32_t depth) {
  vm_.maxStack = static_cast<unsigned>(depth);
}

void JsonnetVm::SetGcMinObjects(uint32_t objects) {
  vm_.gcMinObjects = static_cast<unsigned>(objects);
}

void JsonnetVm::SetGcGrowthTrigger(double growth) {
  vm_.gcGrowthTrigger = growth;
}

void JsonnetVm::SetStringOutput(bool string_output) {
  vm_.stringOutput = string_output;
}

void JsonnetVm::SetDebugAst(bool debug_ast) {
  vm_.debugAst = static_cast<int>(debug_ast);
}

void JsonnetVm::SetMaxTrace(uint32_t lines) {
  vm_.maxTrace = static_cast<unsigned>(lines);
}

void JsonnetVm::BindExtVar(const std::string& key, const std::string& value) {
  vm_.ext.insert(std::make_pair(key, ::VmExt(value, false)));
}

void JsonnetVm::BindExtCodeVar(const std::string& key,
                               const std::string& value) {
  vm_.ext.insert(std::make_pair(key, ::VmExt(value, true)));
}

char* JsonnetVm::EvaluateFileAux(const char* filename, int* error, bool multi) {
  try {
    return vm_.evaluate_file_aux(filename, error, multi);
  } catch (const std::bad_alloc&) {
    fputs("FATAL_ERROR: A memory allocation error occurred.\n", stderr);
    abort();
  } catch (const std::exception& e) {
    std::cerr << "Something went wrong when evaluating file " << filename
              << ", please report this: " << e.what() << std::endl;
    abort();
  }
  return nullptr;  // Never happens.
}

char* JsonnetVm::EvaluateSnippetAux(const char* filename, const char* snippet,
                                    int* error, bool multi) {
  try {
    return vm_.evaluate_snippet_aux(filename, snippet, error, multi);
  } catch (const std::bad_alloc&) {
    fputs("FATAL_ERROR: A memory allocation error occurred.\n", stderr);
    abort();
  } catch (const std::exception& e) {
    std::cerr << "Something went wrong when evaluating file " << filename
              << ", please report this: " << e.what() << std::endl;
    abort();
  }
  return nullptr;  // Never happens.
}

bool JsonnetVm::EvaluateFile(const std::string& filename, std::string* output) {
  if (output == nullptr) {
    return false;
  }
  int error = 0;
  const char* jsonnet_output = EvaluateFileAux(filename.c_str(), &error, false);
  output->assign(jsonnet_output);
  return error == 0;
}

bool JsonnetVm::EvaluateSnippet(const std::string& filename,
                                const std::string& snippet,
                                std::string* output) {
  if (output == nullptr) {
    return false;
  }
  int error = 0;
  const char* jsonnet_output =
      EvaluateSnippetAux(filename.c_str(), snippet.c_str(), &error, false);
  output->assign(jsonnet_output);
  return error == 0;
}

namespace {
void ParseMultiOutput(const char* jsonnet_output,
                      std::map<std::string, std::string>* outputs) {
  for (const char* c = jsonnet_output; *c != '\0'; ) {
    const char *filename = c;
    const char *c2 = c;
    while (*c2 != '\0') ++c2;
    ++c2;
    const char *json = c2;
    while (*c2 != '\0') ++c2;
    ++c2;
    c = c2;
    outputs->insert(std::make_pair(filename, json));
  }
}
}  // namespace

bool JsonnetVm::EvaluateFileMulti(
    const std::string& filename,
    std::map<std::string, std::string>* outputs) {
  if (outputs == nullptr) {
    return false;
  }
  int error = 0;
  const char* jsonnet_output = EvaluateFileAux(filename.c_str(), &error, true);
  ParseMultiOutput(jsonnet_output, outputs);
  return error == 0;
}

bool JsonnetVm::EvaluateSnippetMulti(
    const std::string& filename,
    const std::string& snippet,
    std::map<std::string, std::string>* outputs) {
  if (outputs == nullptr) {
    return false;
  }
  int error = 0;
  const char* jsonnet_output =
      EvaluateSnippetAux(filename.c_str(), snippet.c_str(), &error, true);
  ParseMultiOutput(jsonnet_output, outputs);
  return error == 0;
}

}  // namespace jsonnet
