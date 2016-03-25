#git_repository(
#    name = "io_bazel_rules_jsonnet",
#    remote = "https://github.com/bazelbuild/rules_jsonnet.git",
#    tag = "0.0.1",
#)
local_repository(
    name = "io_bazel_rules_jsonnet",
    path = "/Users/dzc/Projects/bazelbuild/rules_jsonnet",
)
load("@io_bazel_rules_jsonnet//jsonnet:jsonnet.bzl", "jsonnet_repositories")

jsonnet_repositories()

new_http_archive(
    name = "gmock_archive",
    url = "https://googlemock.googlecode.com/files/gmock-1.7.0.zip",
    sha256 = "26fcbb5925b74ad5fc8c26b0495dfc96353f4d553492eb97e85a8a6d2f43095b",
    build_file = "gmock.BUILD",
)

bind(
    name = "gtest",
    actual = "@gmock_archive//:gtest",
)

bind(
    name = "gtest_main",
    actual = "@gmock_archive//:gtest_main",
)
