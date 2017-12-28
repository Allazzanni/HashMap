#pragma once
#include "Record.h"
#define MAXHASH 1000
template <class T> class HashTable
{
private:
    Record<T> *hashMap;
    int currentSize;
    int probe;
	  //friend function for << operator.
	  friend ostream& operator<<(ostream& os, const HashTable& me);

public:
    /**
     Constructs a new
     */
	HashTable();
    /**
     If a value is found, it will be placed in the `value` pointer and the function will return true. Otherwise returns false, and the value pointer is unchanged.
     - parameters:
        - key: The key to search for
        - value: A storage pointer for the found value
     - ret urns: whether or not the value was found.
     */
	bool find(int key, T& value);
	bool insert(int key, T value, int& collisions);
	float alpha();
	bool remove(int key);
	int hashFunction(int key);
	int probeFunction(int key);
	~HashTable();
};
