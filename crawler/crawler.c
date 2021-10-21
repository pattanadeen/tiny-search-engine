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
#include <unistd.h>
#include <math.h>

#include "webpage.h"
#include "hash.h"
#include "queue.h"

void print_webpage(void * element) {
    printf("URL: %s %d\n", webpage_getURL((webpage_t *)element), webpage_getDepth((webpage_t *)element));
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

int32_t pagesave(webpage_t *pagep, int id, char *dirname){
    // int result;
    char filename[strlen(dirname) + 5];
    sprintf(filename, "%s%d", dirname, id);

    // result = access(filename, F_OK);

    // if (result == 0) {
    //     printf("File existed in the directory\n");
    //     return -1;
    // }

    FILE * fp;
    fp = fopen(filename, "w");

    fprintf(fp, "%s\n", webpage_getURL(pagep));
    fprintf(fp, "%d\n", webpage_getDepth(pagep));
    fprintf(fp, "%d\n", webpage_getHTMLlen(pagep));
    fprintf(fp, "%s", webpage_getHTML(pagep));
    
    fclose(fp);

    return 0;
}

void delete_page(void * page) {
    webpage_delete(page);
    page = NULL;
}

int main(int argc, char *argv[]){

    /*
     *  Start of Step 2
     */
    // webpage_t *pagep = webpage_new("https://thayer.github.io/engs50/", 0, NULL);
    

    // if(webpage_fetch(pagep)){
    //     printf("Fetch Successful!!\n");
    //     printf("Seed URL: %s\n", webpage_getURL(pagep));
    // }
    // else{
    //     exit(EXIT_FAILURE);
    // }

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
     *  End of Step 2
     */

    /*
     *  Start of Step 3
     */
    // webpage_t *pagep = webpage_new("https://thayer.github.io/engs50/", 0, NULL);
    

    // if(webpage_fetch(pagep)){
    //     printf("Fetch Successful!!\n");
    //     printf("Seed URL: %s\n", webpage_getURL(pagep));
    // }
    // else{
    //     exit(EXIT_FAILURE);
    // }
    
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
     *  End of Step 3
     */


    /*
     *  Start of Step 4
     */
    // webpage_t *pagep = webpage_new("https://thayer.github.io/engs50/", 0, NULL);
    

    // if(webpage_fetch(pagep)){
    //     printf("Fetch Successful!!\n");
    //     printf("Seed URL: %s\n", webpage_getURL(pagep));
    // }
    // else{
    //     exit(EXIT_FAILURE);
    // }

    // int pos = 0;
    // char *result;
    // queue_t *qp = qopen();
    // hashtable_t *htp = hopen(10);    

    // while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
    //     if(IsInternalURL(result)) {
    //         if(hsearch(htp, searchfn, result, strlen(result)) == (void *)NULL) {
    //             printf("New Internal URL: %s\n", result);

    //             webpage_t *newpagep = webpage_new(result, 0, NULL);
    //             // webpage_fetch(newpagep);

    //             qput(qp, newpagep);
    //             hput(htp, newpagep, result, strlen(result));
    //         }
    //         else{
    //             printf("already visit\n");
    //         }
    //     }
    //     else {
    //         printf("External URL: %s\n", result);
    //     }

    //     free(result);     
    // }

    // printf("-----Print Queue-----\n");
    // qapply(qp, print_webpage);
    // printf("-----End of Queue-----\n");

    // qapply(qp, webpage_delete);
    // qclose(qp);
    // hclose(htp);
    // webpage_delete((void *)pagep);
    /*
     *  End of Step 4
     */

    /*
     *  Start of Step 5
     */ 
    // webpage_t *pagep = webpage_new("https://thayer.github.io/engs50/", 0, NULL);
    

    // if(webpage_fetch(pagep)){
    //     printf("Fetch Successful!!\n");
    //     printf("Seed URL: %s\n", webpage_getURL(pagep));
    // }
    // else{
    //     exit(EXIT_FAILURE);
    // }

    // int pos = 0;
    // char *result;
    // queue_t *qp = qopen();
    // hashtable_t *htp = hopen(10);    

    // while ((pos = webpage_getNextURL(pagep, pos, &result)) > 0) {
    //     if(IsInternalURL(result)) {
    //         if(hsearch(htp, searchfn, result, strlen(result)) == (void *)NULL) {
    //             printf("New Internal URL: %s\n", result);

    //             webpage_t *newpagep = webpage_new(result, 0, NULL);
    //             webpage_fetch(newpagep);

    //             qput(qp, newpagep);
    //             hput(htp, newpagep, result, strlen(result));
    //         }
    //         else{
    //             printf("already visit\n");
    //         }
    //     }
    //     else {
    //         printf("External URL: %s\n", result);
    //     }

    //     free(result);     
    // }

    // printf("-----Print Queue-----\n");
    // qapply(qp, print_webpage);
    // printf("-----End of Queue-----\n");

    // pagesave(pagep, 1, "../pages/");

    // qapply(qp, webpage_delete);
    // qclose(qp);
    // hclose(htp);
    // webpage_delete((void *)pagep);
    /*
     *  End of Step 5
     */

    /*
     *  Start of Step 6
     */  
    // if(argc != 4) {
	// 	printf("usage: crawler <seedurl> <pagedir> <maxdepth>\n");
	// 	exit(EXIT_FAILURE);
	// }

    // char *seedurl = argv[1];
    // char *pagedir = argv[2];
    // int maxdepth = atoi(argv[3]);

    // webpage_t *pagep = webpage_new(seedurl, 0, NULL);
    
    // if(webpage_fetch(pagep)){
    //     printf("Fetch Successful!!\n");
    //     printf("Seed URL: %s\n", webpage_getURL(pagep));
    // }
    // else{
    //     exit(EXIT_FAILURE);
    // }

    // int pos, id = 1, i;
    // char *result;
    // queue_t *qp = qopen();
    // hashtable_t *htp = hopen(10);

    // qput(qp, pagep);
    // hput(htp, pagep, seedurl, strlen(seedurl));
    // pagesave(pagep, id, pagedir);

    // for (i = 0; i < maxdepth; i++) {
    //     pos = 0;
    //     printf("%d", i);
    //     webpage_t *looppage = (webpage_t *)qget(qp);

    //     while ((pos = webpage_getNextURL(looppage, pos, &result)) > 0) {
    //         if(IsInternalURL(result)) {
    //             if(hsearch(htp, searchfn, result, strlen(result)) == (void *)NULL) {
    //                 printf("New Internal URL: %s\n", result);

    //                 webpage_t *newpagep = webpage_new(result, i, NULL);
    //                 // webpage_fetch(newpagep);

    //                 qput(qp, newpagep);
    //                 hput(htp, newpagep, result, strlen(result));

    //                 pagesave(pagep, id, pagedir);
    //                 id++;
    //             }
    //             else{
    //                 printf("already visit\n");
    //             }
    //         }
    //         else {
    //             printf("External URL: %s\n", result);
    //         }

    //         free(result);  
    //     }

    // }
    // happly(htp, webpage_delete);
    // hclose(htp);
    // qclose(qp);
    /*
     *  End of Step 6
     */

    exit(EXIT_SUCCESS);
}