load("@rules_cc//cc:defs.bzl", "cc_library")
load("@envoy//bazel:envoy_build_system.bzl", "envoy_package")

licenses(["notice"])  # Apache 2

envoy_package()

cc_library(
    name = "jni_import_lib",
    srcs = [
        "jni_import.h",
    ],
    deps = select({
        "@envoy//bazel:linux": ["//bazel:jni"],
        "@envoy//bazel:apple": ["//bazel:jni"],
        "//conditions:default": [],
    }),
)
