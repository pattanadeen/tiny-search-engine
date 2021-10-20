#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "hash.h"
#include "queue.h"
#include "car.h"

typedef struct hashtables {
 	uint32_t hsize;
  queue_t **tablepp;
} hashtable_u;

typedef struct queuep {
 	struct node *front;
    struct node *back;
} queue_sp;

int main(int argc, char *argv[]){
  hashtable_t *htp = hopen(32);
  // queue_t table[32] = (queue_t *)((((hashtable_u *)htp)->table)[0]);
  // print_car_hash(htp);
  printf("%p", ((queue_t *)(*((hashtable_u *)htp)->tablepp))      );
  exit(EXIT_SUCCESS);
}