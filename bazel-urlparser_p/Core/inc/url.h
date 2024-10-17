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
/*   Beispiel URL wie sie in Wireshark ankommt:

     "GET /led?action=on HTTP/1.1"               */


    char methode[80];       //Angekommene HTTP Methode
    char ressource[80];     //Ressource die benutzt werden soll 
    char action[80];      //was mit der Ressource gemacht werden soll 

};

enum URL_RET url_parse(const char* url, struct url_struct* url_p);





#ifdef __cplusplus
}
#endif
#endif /*__ url_H */