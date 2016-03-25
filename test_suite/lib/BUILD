load("@io_bazel_rules_jsonnet//jsonnet:jsonnet.bzl", "jsonnet_library")

package(default_visibility = ["//test_suite:__pkg__"])

jsonnet_library(
    name = "lib",
    srcs = glob(["*.jsonnet"]),
    jsonnet = "//cmd:jsonnet",
)

filegroup(
    name = "data",
    srcs = ["some_file.txt"],
)
