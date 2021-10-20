#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "car.h"

void fn(void *elementp) {
    car_t *carp = (car_t*)elementp;
    carp->price = 420;
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

int main(int argc, char *argv[]) {

    car_t *car4 = make_car("4pi3142", 900000, 2017);

    queue_t *qp = qopen();

    printf("[Test] Put null in\n");
    printf("%d\n", qput(qp, NULL));
    printf("%d\n", qput(NULL, NULL));
    printf("\n");
    printf("[Test] Get from null instead of a queue\n");
    qget(NULL);
    printf("[Test] Get from an empty queue\n");
    qget(qp);
    printf("\n");
    printf("[Test] Apply fn to null instead of a queue\n");
    qapply(NULL, fn);
    printf("\n");

    printf("[Test] Search for null instead of a car\n");

    qsearch(qp, searchfn, NULL);
    printf("[Test] Search car in null instead of a queue\n");
    qsearch(NULL, searchfn, (void *)car4);

    printf("\n");

    
    printf("[Test] Remove a car from null instead of queue\n");
    
    qremove(NULL, searchfn, (void *)car4);

    printf("[Test] Remove null from a queue instead of a car\n");
    qremove(qp, searchfn, NULL);

    printf("\n");

    queue_t *qp2 = qopen();
    queue_t *qp3 = qopen();
    queue_t *qp4 = qopen();
    queue_t *qp5 = qopen();
    qput(qp5,(void*)car4);
    queue_t *qp6 = qopen();
    qput(qp6,(void*)car4);
    printf("[Test] Concat null to null\n");
    qconcat(NULL, NULL);
    qconcat(qp,NULL);
    qconcat(NULL,qp2);
    queue_t *qp7 = qopen();
    queue_t *qp8 = qopen();
    qconcat(qp3,qp4); //empty to empty
    qconcat(qp5,qp7); //non empty to empty
    qconcat(qp8,qp6); //empty to non empty



    qclose(qp);
    qclose(qp2);

    free(car4);  


    exit(EXIT_SUCCESS);
}