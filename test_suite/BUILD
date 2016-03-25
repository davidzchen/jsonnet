package(default_visibility = ["//visibility:public"])

load(
    "@io_bazel_rules_jsonnet//jsonnet:jsonnet.bzl",
    "jsonnet_to_json_test",
)

TESTS = [
    "arith_bool",
    "arith_string",
    "assert",
    "condition",
    "format",
    "import",
    "invariant",
    "local",
    "merge",
    "null",
    "oop",
    "oop_extra",
    "parsing_error",
    "precedence",
    "recursive_function",
    "recursive_import_ok",
    "recursive_object",
    "unicode",
    "unix_line_endings",
]

[jsonnet_to_json_test(
    name = "%s_test" % test,
    src = "%s.jsonnet" % test,
    jsonnet = "//cmd:jsonnet",
) for test in TESTS]

jsonnet_to_json_test(
    name = "stdlib_test",
    src = "stdlib.jsonnet",
    deps = ["//test_suite/lib"],
    data = ["//test_suite/lib:data"],
    imports = ["test_suite"],
    test_dir = "test_suite",
    jsonnet = "//cmd:jsonnet",
)

GOLDEN_TESTS = [
    "formatter",
    "invariant_manifest",
    "sanity",
    "sanity2",
    "unparse",
]

[jsonnet_to_json_test(
    name = "%s_test" % test,
    src = "%s.jsonnet" % test,
    golden = "%s.jsonnet.golden" % test,
    jsonnet = "//cmd:jsonnet",
) for test in GOLDEN_TESTS]

ERROR_TESTS = [
    "01",
    "02",
    "03",
    "04",
    "05",
    "06",
    "07",
    "array_recursive_manifest",
    "assert.fail1",
    "assert.fail2",
    "comprehension_spec_object",
    "comprehension_spec_object2",
    "computed_field_scope",
    "divide_zero",
    "equality_function",
    "field_not_exist",
    "function_duplicate_param",
    "import_empty",
    "import_folder",
    "import_folder_slash",
    "inside_equals_array",
    "inside_tostring_array",
    "inside_tostring_object",
    "invariant.avoid_output_change",
    "invariant.equality",
    "invariant.option",
    "invariant.simple",
    "invariant.simple2",
    "invariant.simple3",
    "obj_recursive",
    "obj_recursive_manifest",
    "overflow",
    "overflow2",
    "overflow3",
    "parse.array_comma",
    "parse.import_not_literal",
    "parse.method_plus",
    "parse.object_comprehension_local_clash",
    "parse.object_local_clash",
    "parse.self_in_computed_field",
    "parse.static_error_bad_number",
    "parse.string.invalid_escape",
    "parse.string.invalid_escape_unicode_non_hex",
    "parse.string.invalid_escape_unicode_short",
    "parse.string.invalid_escape_unicode_short2",
    "parse.string.invalid_escape_unicode_short3",
    "parse.string.unfinished",
    "parse.string.unfinished2",
    "parse.text_block_bad_whitespace",
    "parse.text_block_eof",
    "parse.text_block_not_terminated",
    "recursive_function_nonterm",
    "recursive_import",
    "recursive_object_non_term",
    "sanity",
    "static_error_self",
    "static_error_super",
    "static_error_var_not_exist",
    "std_makeArray_negative",
]

[jsonnet_to_json_test(
    name = "error_%s_test" % test,
    src = "error.%s.jsonnet" % test,
    golden = "error.%s.jsonnet.golden" % test,
    error = 1,
    jsonnet = "//cmd:jsonnet",
) for test in ERROR_TESTS]
