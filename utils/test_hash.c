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

    hashtable_t *ht = hopen(4);
    
    hput(ht, NULL, NULL, 0);

    car_t *car1 = make_car("1gt7117", 2100000, 2018);

    hput(ht, NULL, car1->plate, strlen(car1->plate));
    hput(ht, car1, NULL, strlen(car1->plate));
    hput(ht, car1, car1->plate, 0);

    car_t *car2 = make_car("5ab2131", 2700000, 2019);
    car_t *car3 = make_car("6ff3145", 1100000, 2015);
    car_t *car4 = make_car("4pi3142", 900000, 2017);
    car_t *car5 = make_car("1gt7115", 2100000, 2018);
    car_t *car6 = make_car("5ab2133", 2700000, 2019);
    car_t *car7 = make_car("6ff3142", 1100000, 2015);
    car_t *car8 = make_car("4pi3146", 900000, 2017);
    car_t *car9 = make_car("1gt7113", 2100000, 2018);
    car_t *car10 = make_car("5ab2111", 2700000, 2019);
    car_t *car11 = make_car("6ff3145", 1100000, 2015);
    car_t *car12 = make_car("4pi3172", 900000, 2017);
    car_t *car13 = make_car("1gt37119", 2100000, 2018);
    car_t *car14 = make_car("5ae23131", 2700000, 2019);
    car_t *car15 = make_car("6sf53143", 1100000, 2015);
    car_t *car16 = make_car("4yi33145", 900000, 2017);
    car_t *car17 = make_car("4Qi33145", 900000, 2017);

    hput(ht, car1, car1->plate, strlen(car1->plate));
    hput(ht, car2, car2->plate, strlen(car2->plate));
    hput(ht, car3, car3->plate, strlen(car3->plate));
    hput(ht, car4, car4->plate, strlen(car4->plate));
    hput(ht, car5, car5->plate, strlen(car5->plate));
    hput(ht, car6, car6->plate, strlen(car6->plate));
    hput(ht, car7, car7->plate, strlen(car7->plate));
    hput(ht, car8, car8->plate, strlen(car8->plate));
    hput(ht, car9, car9->plate, strlen(car9->plate));
    hput(ht, car10, car10->plate, strlen(car10->plate));
    hput(ht, car11, car11->plate, strlen(car11->plate));
    hput(ht, car12, car12->plate, strlen(car12->plate));
    hput(ht, car13, car13->plate, strlen(car13->plate));
    hput(ht, car14, car14->plate, strlen(car14->plate));
    hput(ht, car15, car15->plate, strlen(car15->plate));
    hput(ht, car16, car16->plate, strlen(car16->plate));


    printf("\nBefore:\n");
    
    print_car_hash(ht);

    printf("\n");

    print_car((car_t *)hsearch(ht, searchfn, car9->plate, strlen(car9->plate)));
    hsearch(ht, searchfn, car17->plate, strlen(car17->plate));
    hsearch(ht, searchfn, NULL, strlen(car17->plate));
    hsearch(ht, searchfn, car17->plate, 0);

    printf("\n");
    hremove(ht, searchfn, car9->plate, strlen(car9->plate));
    hremove(ht, searchfn, car17->plate, strlen(car17->plate));
    hremove(ht, searchfn, NULL, strlen(car9->plate));
    hremove(ht, searchfn, car17->plate, 0);

    printf("\n");

    printf("After:\n");

    print_car_hash(ht); 

    hclose(ht);
    free(car1);
    free(car2);
    free(car3);
    free(car4);
    free(car5);
    free(car6);
    free(car7);
    free(car8);
    free(car9);
    free(car10);
    free(car11);
    free(car12);
    free(car13);
    free(car14);
    free(car15);
    free(car16);
    free(car17);

    exit(EXIT_SUCCESS);




    // hashtable_t *htp = hopen(3);

    // decalre cars
    // car_t *car1 = make_car("1gt7117", 2100000, 2018);
    // car_t *car2 = make_car("5ab2131", 2700000, 2019);
    // car_t *car3 = make_car("6ff3145", 1100000, 2015);
    // car_t *car4 = make_car("4pi3142", 900000, 2017);

    // hput(htp, car1, car1->plate, strlen(car1->plate));
    // hput(htp, car2, car2->plate, strlen(car2->plate));
    // hput(htp, car3, car3->plate, strlen(car3->plate));
    // hput(htp, car4, car4->plate, strlen(car4->plate));
    
    // printf("Before:\n");
    // print_car_hash(htp);

    // happly(htp, fn);

    // printf("After:\n");
    // print_car_hash(htp);

    // print_car((car_t *)hsearch(htp,searchfn, car3->plate, strlen(car3->plate));

    // printf("Before:\n");
    // print_car_hash(htp);

    // hremove(htp, searchfn, car1->plate, strlen(car1->plate));

    // printf("After:\n");
    // print_car_hash(htp);

    // hclose(htp);
    // free(car1);
    // free(car2);
    // free(car3);
    // free(car4);

    // exit(EXIT_SUCCESS);
} 