# Copyright 2015 Google Inc. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""Build rule for running Jsonnet test suite tests."""

JSONNET_FILETYPE = FileType([".jsonnet"])
GOLDEN_FILETYPE = FileType([".golden"])

def _jsonnet_suite_test_impl(ctx):
  test_files = [ctx.file.src]
  if ctx.file.golden:
    test_files += [ctx.file.golden]

  runfiles = ctx.runfiles(files = test_files)
  return struct(runfiles = runfiles)

jsonnet_suite_test = rule(
    _jsonnet_suite_test_impl,
    attrs = {
        "src": attr.label(allow_files = JSONNET_FILETYPE,
                          mandatory = True,
                          single_file = True),
        "golden": attr.label(allow_files = GOLDEN_FILETYPE,
                             single_file = True),
        "error": attr.bool(),
        "_jsonnet": attr.label(default = Label("//:jsonnet"),
                               executable = True,
                               single_file = True),
        "_std": attr.label(default = Label("//:std"),
                           single_file = True),
    },
    executable = True,
    test = True,
)
