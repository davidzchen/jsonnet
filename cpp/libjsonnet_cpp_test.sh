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

readonly TEST_SNIPPET="std.assertEqual(({ x: 1, y: self.x } { x: 2 }).y, 2)"
readonly LIBJSONNET_CPP_TEST_SNIPPET="libjsonnet_cpp_test_snippet"
readonly LIBJSONNET_CPP_TEST_FILE="libjsonnet_cpp_test_file"
readonly OBJECT_JSONNET="test_suite/object.jsonnet"

function test_libjsonnet_cpp_snippet {
  $LIBJSONNET_CPP_TEST_SNIPPET $TEST_SNIPPET
}

function test_libjsonnet_cpp_file {
  $LIBJSONNET_CPP_TEST_FILE $OBJECT_JSONNET
}

function main {
  test_libjsonnet_cpp_snippet
  test_libjsonnet_cpp_file
}

main
