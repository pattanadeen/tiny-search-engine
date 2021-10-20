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
    printf("-----Test 'put' method-----\n");

    printf("[Test] Put 4 cars\n");

    // decalre cars
    car_t *car1 = make_car("1gt7117", 2100000, 2018);
    car_t *car2 = make_car("5ab2131", 2700000, 2019);
    car_t *car3 = make_car("6ff3145", 1100000, 2015);
    car_t *car4 = make_car("4pi3142", 900000, 2017);

    // open a queue
    queue_t *qp = qopen();

    // put cars into queue
    printf("Put car ");
    print_car(car1);
    qput(qp, car1);
    printf("Put car ");
    print_car(car2);
    qput(qp, car2);
    printf("Put car ");
    print_car(car3);
    qput(qp, car3);
    printf("Put car ");
    print_car(car4);
    qput(qp, car4);

    printf("[Result] ");
    print_car_queue(qp);

    printf("\n");

    printf("-----Test 'get' method-----\n");
    
    printf("[Test] Get 2 times\n");
    printf("Remove car ");
    print_car((car_t *)qget(qp));
    printf("Remove car ");
    print_car((car_t *)qget(qp));
    printf("[Result] ");
    print_car_queue(qp);

    printf("\n");

    printf("-----Test 'qapply' method-----\n");
    printf("[Test] Set all price to 420\n");
    qapply(qp, fn);
    print_car_queue(qp);

    printf("\n");

    printf("-----Test 'qsearch' method-----\n");
    printf("[Test] Search car4\n");
    printf("Found car ");
    print_car(qsearch(qp, searchfn, (void *)car4));

    printf("\n");

    printf("-----Test 'qremove' method-----\n");
    printf("[Test] Remove car4\n");
    printf("Remove car ");
    print_car(qremove(qp, searchfn, (void *)car4));
    printf("[Result] ");
    print_car_queue(qp);

    printf("\n");

    printf("-----Test 'qconcat' method-----\n");
    printf("[Test] Create another queue\n");
    queue_t *qp2 = qopen();
    car_t *car5 = make_car("3jf2342", 3200000, 2013);
    car_t *car6 = make_car("0gb6402", 1300000, 2021);
    qput(qp2, car5);
    qput(qp2, car6);
    printf("[Result] ");
    print_car_queue(qp2);

    printf("[Test] Concat to the old queue\n");
    qconcat(qp, qp2);
    printf("[Result] ");
    print_car_queue(qp);

    qclose(qp);
    qclose(qp2);

    free(car1);
    free(car2);
    free(car3);
    free(car4);  
    free(car5);
    free(car6); 

    exit(EXIT_SUCCESS);
}