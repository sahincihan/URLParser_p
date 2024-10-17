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


TEST(UrlTest, ExtractMethodeSucces) {
    struct url_struct testurl = {0};
    url_parse("GET /led?action=on HTTP/1.1",&testurl);
    EXPECT_EQ(URL_RET_OK, url_parse("GET /led?action=on HTTP/1.1",&testurl));
    EXPECT_STREQ("GET ", testurl.methode);
    
}

TEST(UrlTest, ExtractMethodeFail) {
    struct url_struct testurl = {0};
    //Test fürs falsch parsen zb ein anderes Symbol dazwischen nicht erkannt
    url_parse("GET /led?action=on HTTP/1.1",&testurl);
    EXPECT_EQ(URL_RET_OK, url_parse("GET /led?action=on HTTP/1.1",&testurl));
    EXPECT_STRNE("GET /", testurl.methode);
   
}


TEST(UrlTest, ExtractRessourceSuccess) {
    struct url_struct testurl = {0};
    url_parse("GET /led?action=on HTTP/1.1",&testurl);
    EXPECT_EQ(URL_RET_OK, url_parse("GET /led?action=on HTTP/1.1",&testurl));
    EXPECT_STREQ("/led", testurl.ressource);

}


TEST(UrlTest, ExtractRessourceFail) {
    struct url_struct testurl = {0};
    //Test fürs falsch parsen zb ein Leerzeichen dazwischen nicht erkannt
    url_parse("GET /led?action=on HTTP/1.1",&testurl);
    EXPECT_EQ(URL_RET_OK, url_parse("GET /led?action=on HTTP/1.1",&testurl));
    EXPECT_STRNE(" /led", testurl.ressource);

}

TEST(UrlTest, ExtractActionSuccess) {
    struct url_struct testurl = {0};
    url_parse("GET /led?action=on HTTP/1.1",&testurl);
    EXPECT_EQ(URL_RET_OK, url_parse("GET /led?action=on HTTP/1.1",&testurl));
    EXPECT_STREQ("action=on", testurl.action);

}

TEST(UrlTest, ExtractActionFail) {
    struct url_struct testurl = {0};
    //Test fürs falsch parsen zb ein Leerzeichen dazwischen nicht erkannt
    url_parse("GET /led?action=on HTTP/1.1",&testurl);
    EXPECT_EQ(URL_RET_OK, url_parse("GET /led?action=on HTTP/1.1",&testurl));
    EXPECT_STRNE("action=on ", testurl.action);

}