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

void print_webpage(void * element) {
    printf("URL: %s\n", webpage_getURL((webpage_t *)element));
}

bool searchfn(void* elementp, const void* keyp){
    if(keyp == NULL || elementp == NULL){
        printf("NULL value");
        return false;
    }
    
    if(strcmp(webpage_getURL(elementp), (char *)keyp) == 0) {
        return true;
    }
    else{
        return false;
    }
}

// int32_t pagesave(webpage_t *pagep, int id, char *dirname){
//     int result;
//     const char *filename = "/tmp/pages/%d";
//     result = access (filename, F_OK);
// }

int main(int argc, char *argv[]){
    
    webpage_t *pagep = webpage_new("https://thayer.github.io/engs50/", 0, NULL);
    

    if(webpage_fetch(pagep)){
        printf("Fetch Successful!!\n");
        printf("Seed URL: %s\n", webpage_getURL(pagep));
    }
    else{
        exit(EXIT_FAILURE);
    }

    /*
     * Start of Step 2
     */
    // int pos = 0;
    // char *result;

    // while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
            
    //     if(IsInternalURL(result)){
    //         printf("Found Internal URL: ");
    //     }
    //     else{
    //         printf("Found External URL: ");
    //     }

    //     printf("%s\n", result);

    //     free(result);
    // }

    // webpage_delete((void *)pagep);
    /*
     * End of Step 2
     */

    /*
     * Start of Step 3
     */
    // int pos = 0;
    // char *result;
    // queue_t *qp = qopen();
    
    // while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
    //     if(IsInternalURL(result)){
    //         printf("Found Internal URL: ");

    //         webpage_t *newpagep = webpage_new(result, 0, NULL);
    //         webpage_fetch(newpagep);
            
    //         qput(qp, (void *)newpagep);
    //     }
    //     else{
    //         printf("Found External URL: ");
    //     }

    //     printf("%s\n", result);

    //     free(result);
    // }

    // printf("-----Print Queue-----\n");
    // qapply(qp, print_webpage);
    // printf("-----End of Queue-----\n");

    // qapply(qp, webpage_delete);
    // qclose(qp);   
    // webpage_delete((void *)pagep);
    /*
     * End of Step 3
     */


    /*
     * Start of Step 4
     */  
    int pos = 0;
    char *result;
    queue_t *qp = qopen();
    hashtable_t *htp = hopen(10);    

    while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
        if(IsInternalURL(result)) {
            if(hsearch(htp, searchfn, result, strlen(result)) == (void *)NULL) {
                printf("New Internal URL: %s\n", result);

                webpage_t *newpagep = webpage_new(result, 0, NULL);
                // webpage_fetch(newpagep);

                qput(qp, newpagep);
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

    printf("-----Print Queue-----\n");
    qapply(qp, print_webpage);
    printf("-----End of Queue-----\n");

    qapply(qp, webpage_delete);
    qclose(qp);
    hclose(htp);
    webpage_delete((void *)pagep);
    /*
     * End of Step 4
     */


    exit(EXIT_SUCCESS);
}