#include "hashMap.h"
#include "dllist.h"
#include <string.h>

unsigned long long hash(char* key)
{
  const int p = 31;
  const int m = 1e9 + 9;
  unsigned long long hash_value = 0;
  long long p_pow = 1;
  for (int i = 0; i < strlen(key); i++) {
    char c = key[i];
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}
void initHashMap(HashMap* hm, unsigned int nb)
{
  /*
    TODO: Set the numBuckets and numItems fields of hm.
    allocate memory for nb buckets, allocate memory for a DLList for each bucket, initialize the list, and initialize the bucket's lock.
    Initialize the tableLock.
   */
  Bucket* bucketspace = (Bucket*)malloc(sizeof(Bucket) * nb);
  hm->numBuckets = nb;
  hm->numItems = 0;
  pthread_mutex_init(&hm->tableLock, NULL);
  for(int i=0; i<nb; i++){
      DLList* DLL = malloc(sizeof(DLList));
      initList(DLL);
      bucketspace[i].list = DLL;
      pthread_mutex_init(&bucketspace[i].lock, NULL);
  }
    hm->buckets = bucketspace;
}
void clearHashMap(HashMap* hm)
{
  /*
    TODO: free up the hash map and buckets, destroy the mutexes. Set the numBuckets and numItems fields to zero. 
   */
  //free the buckets lock and list
  for(int i; i<hm->numBuckets; i++){
      pthread_mutex_destroy(&hm->buckets[i].lock);
      destroyList(hm->buckets[i].list);
      free(hm->buckets[i].list);
  }
  // Set the num Buckets and Num Items to 0
  hm->numBuckets = 0;
  hm->numItems = 0;
  pthread_mutex_destroy(&hm->tableLock);
  //free(&hm->buckets);
}
void destroyHashMap(HashMap* hm)
{
  clearHashMap(hm);
}

void insertHashMap(HashMap* hm, char* key, char* value)
{
  
  unsigned int h = hash(key) % hm->numBuckets;
  /*
    TODO: Go to bucket h, and insert the (key, value) pair, unless the key is already in the hash map. If you inserted the pair, increment the hash map's numItems field (under mutex protection, of course!)
   */
  //lock Table and bucket
  // Lock the bucket, insert the key/val pair, unlock
  pthread_mutex_lock(&hm->buckets[h].lock);
  int val =insertSortedList(hm->buckets[h].list, key, value);
  pthread_mutex_unlock(&hm->buckets[h].lock);
  // test the value
  if(val == 1){
      //if successfully added, lock the table, increment num items, unlock table
      pthread_mutex_lock(&hm->tableLock);
      hm->numItems++;
      pthread_mutex_unlock(&hm->tableLock);
  }
}
char* retrieveValue(HashMap* hm, char* key)
{
  unsigned int h = hash(key) % hm->numBuckets;
  /*
    TODO: Find the key in bucket h, under mutex protection. Since the bucket's key-value pairs are stored in a DLList, look at the DLList.h file for an appropriate function to get the value corresponding to the key.
   */
    pthread_mutex_lock(&hm->buckets[h].lock);
    char* value = getValue(hm->buckets[h].list, key);
    pthread_mutex_unlock(&hm->buckets[h].lock);
    // test the value
    if(value){
       return value;
    }
}
void deleteEntry(HashMap* hm, char* key)
{
  unsigned int h = hash(key) % hm->numBuckets;
  /*
    TODO: Delete the key from bucket h, under mutex protection. If they key isn't in the bucket, don't do anything. If the key was successfully removed from the bucket, decrement the hashmap's numItems field. 
   */
    pthread_mutex_lock(&hm->buckets[h].lock);
    int status = removeFromList(hm->buckets[h].list, key);
    pthread_mutex_unlock(&hm->buckets[h].lock);
    // test the value
    if(status){
        //if successfully added, lock the table, increment num items, unlock table
        pthread_mutex_lock(&hm->tableLock);
        hm->numItems--;
        pthread_mutex_unlock(&hm->tableLock);
    }
}

