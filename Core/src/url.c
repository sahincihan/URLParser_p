#include "url.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>






enum URL_RET url_parse(const char* url, struct url_struct* url_p)
{
char *methode_start = {0};
char *methode_end = {0};

    if ( NULL == url || NULL == url_p){
        return URL_RET_ENULL;
    }

methode_start = strstr(url, "GET");
     if (NULL == methode_start){
          return URL_RET_ERROR;
         }

// //ip_start += 2;                  //Skipped "//"

methode_end = strchr(url, '/' );
    if (NULL == methode_end){
      return URL_RET_ERROR;
    }

   strncpy(url_p->methode,methode_start, methode_end-methode_start);

      if (NULL == url_p->methode){
          return URL_RET_ERROR;
        }


// url_p->ip[ip_end-ip_start] = '\0';


// char *path_start = ip_end + 1;
// if (NULL == path_start){
//       return URL_RET_ERROR;
//     }

// char *path_end = strchr(url, '?');
//  if (NULL == path_end){
//       return URL_RET_ERROR;
//     }

// strncpy(url_p->path,path_start, path_end - path_start );
// url_p->path[path_end-path_start] = '\0';

// char *query_start = path_end + 1;
//     if (NULL==query_start){
//         return URL_RET_ERROR;
//     }

// char *query_end = strchr(url, '\0' );
// if (NULL==query_end){
//         return URL_RET_ERROR;
//     }
// strncpy(url_p->query,query_start, query_end - query_start );
// url_p->query[query_end-query_start] = '\0';


return URL_RET_OK;

};