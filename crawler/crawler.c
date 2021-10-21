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
    if(elementp == keyp){
        return true;
    }
    else{
        return false;
    }
}

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
        webpage_t *newpagep = webpage_new(result, 0, NULL);
        if(IsInternalURL(result)){
            printf("Internal URL: ");
            hput(htp, newpagep, result, strlen(result));
            printf("put already");
        }
        else{
            printf("External URL: ");
        }
        printf("Found url: %s\n", result);
        free(result);
        webpage_delete((void*)newpagep);
    }

    // queue
    // pos = 0;
    // char *result2;
    
    // 2.4. print URL
    // int pos = 0;
    // char *result;
    // while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
    //     // webpage_t *newpagep = webpage_new(result, 0, html);

    //     if(IsInternalURL(result)){
    //         printf("Found Internal URL: ");
    //         // qput(qp, newpagep);
    //     }
    //     else{
    //         printf("Found External URL: ");
    //     }

    //     printf("%s\n", result);

    //     webpage_delete((void *)pagep);
    //     free(result);
    // }
    
    exit(EXIT_SUCCESS);
}