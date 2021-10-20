/* 
// Chayisara Sakunkoo, Kevin Chakornsiri, Nuttaset Pattanadee
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hash.h"
#include "queue.h"
/* 
 * SuperFastHash() -- produces a number between 0 and the tablesize-1.
 * 
 * The following (rather complicated) code, has been taken from Paul
 * Hsieh's website under the terms of the BSD license. It's a hash
 * function used all over the place nowadays, including Google Sparse
 * Hash.
 */
#define get16bits(d) (*((const uint16_t *) (d)))

static uint32_t SuperFastHash (const char *data,int len,uint32_t tablesize) {
  uint32_t hash = len, tmp;
  int rem;
  
  if (len <= 0 || data == NULL)
		return 0;
  rem = len & 3;
  len >>= 2;
  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }
  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }
  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;
  return hash % tablesize;
}

typedef struct hashtable {
  uint32_t hsize;
  queue_t **htable;
} hashtable_s;

hashtable_t *hopen(uint32_t hsize) {
 
  hashtable_s *htp = malloc(sizeof(hashtable_s));
  queue_t **htable = malloc(sizeof(queue_t *) * hsize);
  int i;

  for (i = 0; i < hsize; i++) {
    htable[i] = qopen();
  }

  htp->hsize = hsize;
  htp->htable = htable;

  return htp;
}

void hclose(hashtable_t *htp){
  int i;
  int hsize = ((hashtable_s *)htp)->hsize;
  queue_t **htable = ((hashtable_s *)htp)->htable;

  for (i = 0; i < hsize; i++) {
    qclose(htable[i]);
  }

  free(htable);
  free(htp);
  return;
}

int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen){
  int hsize = ((hashtable_s *)htp)->hsize;
  int32_t loc = SuperFastHash(key, keylen, hsize);

  queue_t **htable = ((hashtable_s *)htp)->htable;

  if ( ep == NULL || key == NULL || keylen <= 0){
    printf("element is null or key is null\n");
    return 1;
  }

  qput(htable[loc], ep);

  return 0;
}

void happly(hashtable_t *htp, void (*fn)(void* ep)){
  int i;
  int hsize = ((hashtable_s *)htp)->hsize;

  for(i = 0; i < hsize; i++){
    queue_t **htable = ((hashtable_s *)htp)->htable;
    qapply(htable[i],fn);
  }

  return;
}

void *hsearch(hashtable_t *htp, bool (*searchfn)(void* elementp, const void* searchkeyp), const char *key, int32_t keylen){
  int hsize = ((hashtable_s *)htp)->hsize;
  int32_t loc = SuperFastHash(key, keylen, hsize);

  queue_t **htable = ((hashtable_s *)htp)->htable;
  if ( key == NULL || keylen <= 0){
    printf("key is null\n");
    return (void*)NULL;
  }
  
  return qsearch(htable[loc], searchfn, key);
}

void *hremove(hashtable_t *htp, bool (*searchfn)(void* elementp, const void* searchkeyp), const char *key, int32_t keylen){
  int hsize = ((hashtable_s *)htp)->hsize;
  int32_t loc = SuperFastHash(key, keylen, hsize);

  queue_t **htable = ((hashtable_s *)htp)->htable;

  if ( key == NULL || keylen <= 0){
    printf("key is null\n");
    return (void*)NULL;
  }
  
  return qremove(htable[loc],searchfn,key);
}
