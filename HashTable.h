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
	friend ostream& operator<<(ostream& os, const HashTable& me) {
    int i = 0;
    while (i < MAXHASH){
      if (!me.hashMap[i].isEmpty()){
        cout << "Index: " << i << " " << me.hashMap[i] << endl;
      }
      i++;
    }
    return os;
	}

public:
	HashTable();
	bool find(int key, T& value);
	bool insert(int key, T value, int& collisions);
	float alpha();
	bool remove(int key);
	int hashFunction(int key);
	int probeFunction(int key);
	~HashTable();
};
