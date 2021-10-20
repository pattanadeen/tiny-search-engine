/* crawler.c --- 
 * 
 * 
 * Author: Chayisara Sakunkoo
 * Created: Tue Oct 19 11:47:21 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "webpage.h"
#include "hash.h"
#include "queue.h"
#include "car.h"

typedef struct webpage {
  char *url;                               // url of the page
  char *html;                              // html code of the page
  size_t html_len;                         // length of html code
  int depth;                               // depth of crawl
} webpage_s;

void print_web_queue(queue_s *qp) {
    node_t *p;
    int i=0;
    printf("front --> ");
    for (p = ((node_t *)qp->front); p != NULL; p = p->next) {
        webpage_s * webp = (webpage_s *)p->element;
        printf("%d\n", i);
        i = i+1;
        printf("| %s, %d |", webp->url, webp->depth);
    }
    printf("%d\n", i);
    printf(" <-- back\n");

    return;
}

bool searchfn(void* elementp,const void* keyp){
    if(keyp == NULL || elementp == NULL){
        printf("NULL value");
        return false;
    }
    if(elementp == keyp){
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char *argv[]){
    printf("Hello Worlddd\n");
    // 2.1. create webpage
    char *html = "html";
    webpage_t *pagep = webpage_new("https://thayer.github.io/engs50/", 0, html);

    // 2.3. check fetching
    if(webpage_fetch(pagep)){
        printf("fetch success\n");
    }
    else{
        exit(EXIT_FAILURE);
    }

    // 2.4. print URL
    int pos = 0;
    char *result;
    queue_t *qp = qopen();
    // hashtable_t *htp = hopen(10);

    // hash
    // while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
    //     webpage_t *newpagep = webpage_new(result, 0, html);
    //     if(IsInternalURL(result)){
    //         printf("Internal URL: ");
    //         hput(htp, newpagep, result, strlen(result));
    //         printf("put already");
    //     }
    //     else{
    //         printf("External URL: ");
    //     }
    //     printf("Found url: %s\n", result);
    //     free(result);
        // webpage_delete((void*)newpagep);
    // }

    // queue
    // pos = 0;
    // char *result2;
    
    while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
        webpage_t *newpagep = webpage_new(result, 0, html);
        if(IsInternalURL(result)){
            printf("Internal URL: ");
            qput(qp, newpagep);
            printf("put already");
        }
        else{
            printf("External URL: ");
        }
        printf("Found url: %s\n", result);
        // webpage_delete((void*)newpagep);
        // free(newpagep);
        free(result);
    }
    print_web_queue((queue_s *)qp);
    qclose(qp);
    // 2.5. dealocate webpage
    webpage_delete((void*)pagep);
    exit(EXIT_SUCCESS);
}