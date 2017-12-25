#include "HashTable.h"
#include "Record.h"
#include <string>

/*Generic constructor*/
template <class T> HashTable<T>::HashTable()
{
    hashMap = new Record<T>[MAXHASH];
    currentSize = 0;
    probe = 0;
}

/*Finds an element with a certain key and stores it in the value passed*/
template <class T> bool HashTable<T>::find(int key, T& value) {
    int local = hashFunction (key);
    int count = 0;
    while (count != MAXHASH && !hashMap[local].isEmpty()) {
        if (hashMap[local].isNormal() && hashMap[local].getKey() == key) {
            value = hashMap[local].getValue();
            probe = 0;
            return true;
        }
        else {
          probe = probe + 1;
          local = probeFunction(local);
        }
        count++;
    }
    probe = 0;
    return false;

}

/*Inserts the key/value into the hashtable and stores the amount of collisions in the passed collisions*/
template <class T> bool HashTable<T>::insert(int key, T value, int& collisions) {
    int local = hashFunction (key);
    int count = 0;
    int col = 0;
    //if (hashMap[local].isEmpty()){
      while (count != MAXHASH) {
        if (hashMap[local].isEmpty() || hashMap[local].isTombstone()) {
            if (!hashMap[local].isTombstone()){
              if (hashMap[local].getKey() == key){
              probe = 0;
              return false;
              } else {
              currentSize = currentSize + 1;
              hashMap[local] = new Record<T> (key, value);
              collisions = collisions + col;
              probe = 0;
              return true;
              }
            } else {
              hashMap[local] = new Record<T> (key, value);
              collisions = collisions + col;
              probe = 0;
              return true;
            }
          }
          else {
            if (hashMap[local].getKey() == key){
              probe = 0;
              return false;
            } else {
              probe = probe + 1;
              local = probeFunction(local);
              col = col + 1;
            }
          }
          count++;
        }
      probe = 0;
      return false;
}

/*Returns the load factor for the hash*/
template <class T> float HashTable<T>::alpha() {
    return currentSize / 1000.00;
}

/*Kills a table key*/
template <class T> bool HashTable<T>::remove(int key)
{
    int local = hashFunction(key);
    int count = 0;

    while (count != MAXHASH) {
        if (hashMap[local].isNormal() && hashMap[local].getKey() == key) {
            hashMap[local].kill();
            probe = 0;
            return true;
        }
        else {
            probe = probe + 1;
            local = probeFunction(local);
        }
        count++;
    }
    probe = 0;
    return false;
}

/*Hash function for finding the home position*/
template <class T> int HashTable<T>::hashFunction(int key) {
    int hash = key%MAXHASH;
    return hash;
}

/*The result of probing is returned with the new slot's position*/
template <class T> int HashTable<T>::probeFunction(int key) {
  int target = key + 4*probe + 3*(probe^2);
  target = target%MAXHASH;
  return target;
    // int probe = 27;
    // if (MAXHASH - key <= probe){
    //   probe = probe + key - MAXHASH;
    // } else {
    //   probe = key + probe;
    // }
    // return probe;
}

/*Deallocater*/
template <class T> HashTable<T>::~HashTable()
{
    delete[] hashMap;
}


//Sets what types T can be
template class HashTable<int>;
template class HashTable<float>;
template class HashTable<string>;
