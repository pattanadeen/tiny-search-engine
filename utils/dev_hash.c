#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "car.h"
#include "hash.h"

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

    hashtable_t *htp = hopen(3);

    // decalre cars
    car_t *car1 = make_car("1gt7117", 2100000, 2018);
    car_t *car2 = make_car("5ab2131", 2700000, 2019);
    car_t *car3 = make_car("6ff3145", 1100000, 2015);
    car_t *car4 = make_car("4pi3142", 900000, 2017);

    hput(htp, car1, car1->plate, strlen(car1->plate));
    hput(htp, car2, car2->plate, strlen(car2->plate));
    hput(htp, car3, car3->plate, strlen(car3->plate));
    hput(htp, car4, car4->plate, strlen(car4->plate));
    
    printf("Before:\n");
    print_car_hash(htp);

    // happly(htp, fn);

    // printf("After:\n");
    // print_car_hash(htp);

    // print_car((car_t *)hsearch(htp,searchfn, car3->plate, strlen(car3->plate));

    // printf("Before:\n");
    // print_car_hash(htp);

    hremove(htp, searchfn, car1->plate, strlen(car1->plate));

    printf("After:\n");
    print_car_hash(htp);

    hclose(htp);
    free(car1);
    free(car2);
    free(car3);
    free(car4);

    exit(EXIT_SUCCESS);
} 