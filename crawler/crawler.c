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
        printf("\n");
        i = i+1;
        printf("| %s, %d |", webp->url, webp->depth);
    }
    printf(" <-- back\n");

    return;
}

bool searchfn(void* elementp, const void* keyp){
    if(keyp == NULL || elementp == NULL){
        printf("NULL value");
        return false;
    }
    // webpage_s *webp = (webpage_s *)elementp;
    printf("=[dfgwregear %s and %s\n", webpage_getURL(elementp), (char *)keyp);
    if(strcmp(webpage_getURL(elementp), (char *)keyp) == 0) {
        return true;
    }
    else{
        return false;
    }
}
int32_t pagesave(webpage_t *pagep, int id, char *dirname){
    int result;
    const char *filename = "/tmp/pages/%d";
    result = access (filename, F_OK);
}
int main(int argc, char *argv[]){
    
    // 2.1. create webpage
    webpage_t *pagep = webpage_new("https://thayer.github.io/engs50/", 0, NULL);
    

    // 2.3. check fetching
    if(webpage_fetch(pagep)){
        printf("Fetch Successful!!\n");
        printf("Seed URL: %s\n", webpage_getURL(pagep));
    }
    else{
        exit(EXIT_FAILURE);
    }

    // 5. save one page
    int id = 1;
    

    // 2.4. print URL
    int pos = 0;
    char *result;
    queue_t *qp = qopen();
    
    while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
        
        if(IsInternalURL(result)){
            int i, count = 0;
            for (i=0; result[i + 1]; i++) {
                if (result[i] == '/') {
                    count++;
                }
            }
            count = count - 3;

            printf("Found Internal URL: ");

            webpage_t *newpagep = webpage_new(result, count, NULL);
            webpage_fetch(newpagep);
            qput(qp, (void *)newpagep);
        }
        else{
            printf("Found External URL: ");
        }

        printf("%s\n", result);

        free(result);
    }

    print_web_queue(qp);

    qapply(qp, webpage_delete);
    qclose(qp);   
    
    pos = 0;
    hashtable_t *htp = hopen(10);
    queue_t *qp2 = qopen();
    while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
        webpage_t *newpagep = webpage_new(result, 0, NULL);
        webpage_fetch(newpagep);
        if(IsInternalURL(result)) {
            if(hsearch(htp, searchfn, result, strlen(result)) == (void *)NULL) {
                printf("New Internal URL: %s\n", result);
                qput(qp2, newpagep);
                hput(htp, newpagep, result, strlen(result));
            }
            else{
                printf("already visit\n");
            }
        }
        else {
            printf("External URL: %s\n", result);
        }

        free(result);     
    }
    // qapply(qp, webpage_delete);
    print_web_queue(qp2);
    qclose(qp2);
    webpage_delete((void *)pagep);

    exit(EXIT_SUCCESS);
}