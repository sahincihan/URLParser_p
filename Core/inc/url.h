#ifndef __url_H
#define __url_H
#ifdef __cplusplus
 extern "C" {
#endif

enum URL_RET{

URL_RET_OK = 0,
URL_RET_ENULL,
URL_RET_ERROR

};


struct url_struct
{
    char* methode;
    char* ip;
    char* path;      //Pfad
    char* query;


};

enum URL_RET url_parse(const char* url, struct url_struct* url_p);





#ifdef __cplusplus
}
#endif
#endif /*__ url_H */