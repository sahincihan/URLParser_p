#include <gtest/gtest.h>
#include "url.h"

// Demonstrate some basic assertions.
TEST(UrlTest, BasicAssertions) {
    struct url_struct testurl = {0};

    // Expect equality.
    EXPECT_EQ(URL_RET_ENULL, url_parse(NULL, NULL));
    EXPECT_EQ(URL_RET_ENULL, url_parse(NULL, &testurl));
    EXPECT_EQ(URL_RET_ENULL, url_parse("", NULL));
    EXPECT_EQ(URL_RET_ERROR, url_parse("", &testurl));

}


TEST(UrlTest, ExtractMethode) {
    struct url_struct testurl = {0};
    url_parse("GET/led?action=on HTTP/1.1",&testurl);

    // Expect equality.
    //EXPECT_EQ(URL_RET_ERROR, url_parse("GET /led?action=on HTTP/1.1",&testurl));

    EXPECT_STREQ("GET", testurl.methode);

}