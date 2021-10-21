/* queue.c ---
 * 
 * 
 * Author: Chayisara Sakunkoo, Kevin Chakornsiri, Nuttaset Pattanadee
 * Created: Sat Oct  9 16:57:46 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "queue.h"

#define MAXREG 10

typedef struct node {
 	struct node *next;
 	void *element;
} node_t;

typedef struct queue {
 	struct node *front;
    struct node *back;
} queue_s;

queue_t* qopen(void){
    queue_s *qs = malloc(sizeof(queue_s));
    qs->front = NULL;
    qs->back = NULL;
    return ((queue_t*)qs);
}

void qclose(queue_t *qp) {
    node_t *p = ((queue_s *)qp)->front;

    while (p != NULL) {        
        node_t *temp = p;
        p = p->next;
        
        free(temp);
    }

    free(p);
    free(qp);
}

int32_t qput(queue_t *qp, void *elementp){
    if(qp == NULL || elementp == NULL){
        printf("At least of the input is NULL\n");
        return 1;
    }
    else{
        if(((queue_s *)qp)->back == NULL){
            node_t *newNode = malloc(sizeof(node_t));
            newNode->next = NULL;
            newNode->element = elementp;
            ((queue_s *)qp)->back = newNode;
            ((queue_s *)qp)->front = newNode;
            return 0;
        }
        else{
            node_t *newNode = malloc(sizeof(node_t));
            newNode->next = NULL;
            newNode->element = elementp;
            (((queue_s *)qp)->back)->next = newNode;
            ((queue_s *)qp)->back = newNode;
            return 0;
        }
    }
}

void* qget(queue_t *qp){
    if( qp == NULL){
        printf("The input is null\n");
        return (void*)NULL;
    }
    if(((queue_s *)qp)->back == NULL || ((queue_s *)qp)->front == NULL){
        printf("The queue is empty\n");
        return (void*)NULL;
    }
    node_t *getNode = ((queue_s *)qp)->front;
    ((queue_s *)qp)->front = getNode->next;
    void* element = getNode->element;
    free(getNode);
    
    return element;
}

void qapply(queue_t *qp, void (*fn)(void* elementp)){
    if(qp == NULL){
        printf("qp is NULL\n");
        return;
    }
    node_t *newNode;
    for (newNode = (node_t*)(((queue_s *)qp)->front); newNode != NULL; newNode = newNode->next) {
        fn(newNode->element);
    }
}

void* qsearch(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp){
    if(qp == NULL || skeyp == NULL){
        printf("qp or skeyp is NULL\n");
        return (void *)NULL;
    }
    node_t *newNode;
    for (newNode = (node_t*)(((queue_s *)qp)->front); newNode != NULL; newNode = newNode->next) {
        if(searchfn(newNode->element, skeyp) == true){
            return newNode->element;
        }
    }
    printf("not found\n");
    return (void *)NULL;
}

void* qremove(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp){
    if(qp == NULL || skeyp == NULL){
        printf("qp or skeyp is NULL\n");
        return (void*)NULL;
    }
    node_t *newNode;
    node_t *preNode = ((queue_s *)qp)->front;
    for (newNode = (node_t*)(((queue_s *)qp)->front); newNode != NULL; newNode = newNode->next) {
        if(searchfn(newNode->element, skeyp) == true){
            if(newNode == (((queue_s *)qp)->front)){
                node_t *temp = (((queue_s *)qp)->front)->next;
                (((queue_s *)qp)->front)->next = NULL;
                ((queue_s *)qp)->front = temp;
            }
            else if(newNode == (((queue_s *)qp)->back)){
                ((queue_s *)qp)->back = preNode;
                preNode->next = NULL;
            }
            else{
                preNode->next = newNode->next;
            }
            void* element = newNode->element;
            free(newNode);
    
            return element;
        }
        preNode = newNode;
    }
    printf("not found\n");
    return NULL;
}

void qconcat(queue_t *q1p, queue_t *q2p){
    if(q1p == NULL || q2p == NULL){
        printf("q1p or q2p is NULL\n");
        return;
    }
    if(((queue_s *)q1p)->back == NULL || ((queue_s *)q1p)->front == NULL){
        printf("First queue is empty\n");
        return;
    }
    if(((queue_s *)q2p)->back == NULL || ((queue_s *)q2p)->front == NULL){
        printf("Second queue is empty\n");
        return;
    }
    (((queue_s *)q1p)->back)->next = ((queue_s *)q2p)->front;
    ((queue_s *)q1p)->back = ((queue_s *)q2p)->back;
    ((queue_s *)q2p)->front = NULL;
    ((queue_s *)q2p)->back = NULL;
}