#include "url.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>






enum URL_RET url_parse(const char* url, struct url_struct* url_p)
{
char *methode_start = {0};
char *methode_end = {0};
char *ressource_start = {0};
char *ressource_end = {0};
char *action_start = {0};
char *action_end = {0};

/*-----------------------------------------------------------*/

//Test ob überhauupt etwas ankommt

    if ( NULL == url || NULL == url_p){
        return URL_RET_ENULL;
    }


/*------------------------------------------------------------*/

// Parsen der Methode

methode_start = strstr(url, "GET");
     if (NULL == methode_start){
          return URL_RET_ERROR;
         }

methode_end = strchr(url, '/' );
    if (NULL == methode_end){
      return URL_RET_ERROR;
    }

  
   strncpy(url_p->methode,methode_start, methode_end-methode_start);

      if (NULL == url_p->methode){
          return URL_RET_ERROR;
        }
/*---------------------------------------------------------------*/

//Parsen der Ressource

 ressource_start = methode_end;
  if (NULL == ressource_start){
       return URL_RET_ERROR;
      }

 ressource_end = strchr(url, '?');
  if (NULL == ressource_end){
       return URL_RET_ERROR;
     }

 strncpy(url_p->ressource,ressource_start, ressource_end - ressource_start );

/*------------------------------------------------------------------*/

//Parsen der Action

action_start = ressource_end+1;
 if (NULL == action_start){
       return URL_RET_ERROR;
     }

 action_end = strstr(url, " HTTP");
  if (NULL == action_end){
       return URL_RET_ERROR;
     }

 strncpy(url_p->action,action_start, action_end - action_start );

/*---------------------------------------------------------------------*/


return URL_RET_OK;

};