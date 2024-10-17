cc_test(
    name = "hello_test",
    size = "small",
    srcs = ["test/url_test.cc"],
    deps = [
        "@googletest//:gtest",
        "@googletest//:gtest_main",
        ":core",
    ],
)


cc_library(
    name = "core",
    srcs = [
        "src/url.c",
    ],
    hdrs = [
        "inc/url.h",
    ],
    includes = [
        "inc/",
    ],

)