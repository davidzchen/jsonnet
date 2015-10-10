/*
Copyright 2015 Google Inc. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <cstdlib>
#include <cstring>

#include <exception>
#include <iostream>
#include <sstream>

extern "C" {
#include "core/libjsonnet.h"
}

#include "core/desugaring.h"
#include "core/parser.h"
#include "core/static_analysis.h"
#include "core/vm.h"

struct JsonnetVm {
    Vm vm;
};

#define TRY try
#define CATCH(func) \
    catch (const std::bad_alloc &) {\
        fputs("FATAL ERROR: A memory allocation error occurred.\n", stderr);\
        abort();\
    } catch (const std::exception &e) {\
        std::cerr << "Something went wrong during " func ", please report this: " \
                  << e.what() << std::endl; \
        abort(); \
    }

const char *jsonnet_version(void)
{
    return LIB_JSONNET_VERSION;
}

JsonnetVm *jsonnet_make(void)
{
    TRY {
        return new JsonnetVm();
    } CATCH("jsonnet_make");
    return nullptr;
}

void jsonnet_destroy(JsonnetVm *vm)
{
    TRY {
        delete vm;
    } CATCH("jsonnet_destroy");
}

void jsonnet_max_stack(JsonnetVm *vm, unsigned v)
{
    vm->vm.maxStack = v;
}

void jsonnet_gc_min_objects(JsonnetVm *vm, unsigned v)
{
    vm->vm.gcMinObjects = v;
}

void jsonnet_gc_growth_trigger(JsonnetVm *vm, double v)
{
    vm->vm.gcGrowthTrigger = v;
}

void jsonnet_string_output(struct JsonnetVm *vm, int v)
{
    vm->vm.stringOutput = bool(v);
}

void jsonnet_import_callback(struct JsonnetVm *vm, JsonnetImportCallback *cb, void *ctx)
{
    vm->vm.importCallback = cb;
    vm->vm.importCallbackContext = ctx;
}

void jsonnet_ext_var(JsonnetVm *vm, const char *key, const char *val)
{
    vm->vm.ext[key] = VmExt(val, false);
}

void jsonnet_ext_code(JsonnetVm *vm, const char *key, const char *val)
{
    vm->vm.ext[key] = VmExt(val, true);
}

void jsonnet_debug_ast(JsonnetVm *vm, int v)
{
    vm->vm.debugAst = v;
}

void jsonnet_max_trace(JsonnetVm *vm, unsigned v)
{
    vm->vm.maxTrace = v;
}

char *jsonnet_evaluate_file(JsonnetVm *vm, const char *filename, int *error)
{
    TRY {
        return vm->vm.evaluate_file_aux(filename, error, false);
    } CATCH("jsonnet_evaluate_file");
    return nullptr;  // Never happens.
}

char *jsonnet_evaluate_file_multi(JsonnetVm *vm, const char *filename, int *error)
{
    TRY {
        return vm->vm.evaluate_file_aux(filename, error, true);
    } CATCH("jsonnet_evaluate_file_multi");
    return nullptr;  // Never happens.
}

char *jsonnet_evaluate_snippet(JsonnetVm *vm, const char *filename, const char *snippet, int *error)
{
    TRY {
        return vm->vm.evaluate_snippet_aux(filename, snippet, error, false);
    } CATCH("jsonnet_evaluate_snippet");
    return nullptr;  // Never happens.
}

char *jsonnet_evaluate_snippet_multi(JsonnetVm *vm, const char *filename,
                                     const char *snippet, int *error)
{
    TRY {
        return vm->vm.evaluate_snippet_aux(filename, snippet, error, true);
    } CATCH("jsonnet_evaluate_snippet_multi");
    return nullptr;  // Never happens.
}

char *jsonnet_realloc(JsonnetVm *vm, char *str, size_t sz)
{
    return vm->vm.realloc(str, sz);
}

