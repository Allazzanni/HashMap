#include "HashTable.cpp"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

void test1 ();
void test2 ();
void test3 ();
void test4 ();
void test5 ();
int main (){
  // test1 ();
  // test2 ();
  // test3 ();
  // test4();
  test5 ();
  return 0;
}
void test1 (){
  HashTable<int>* hash = new HashTable<int> ();
  int collisions = 0;
  hash->insert (123904321, 12, collisions);
  hash->insert (12390321, 12, collisions);
  hash->insert (1239321, 12, collisions);
  hash->insert (123321, 12, collisions);
  hash->insert (12321, 12, collisions);
  hash->insert (1321, 12, collisions);
  hash->insert (321, 12, collisions);
  cout << collisions << endl;
}
void test2 (){
  HashTable<int>* hash = new HashTable<int> ();
  int collisions = 0;
  hash->insert (123904321, 12, collisions);
  hash->insert (12390321, 12, collisions);
  hash->insert (1239321, 12, collisions);
  hash->insert (123321, 12, collisions);
  hash->insert (12321, 12, collisions);
  hash->insert (1321, 12, collisions);
  hash->insert (321, 12, collisions);
  hash->remove (1321);
  hash->insert (321, 12, collisions);
  cout << collisions << endl;
}
void test3 (){
  HashTable<int>* hash = new HashTable<int> ();
  int collisions = 0;
  hash->insert (123904321, 12, collisions);
  hash->insert (12390321, 12, collisions);
  hash->insert (1239321, 109, collisions);
  hash->insert (123321, 12, collisions);
  hash->insert (12321, 12, collisions);
  hash->insert (1321, 18, collisions);
  hash->insert (321, 12, collisions);
  hash->remove (123904321);
  hash->remove (12390321);
  int found = 0;
  hash->find (1239321, found);
  cout << found << endl;
  cout << collisions << endl;
}
void test4 (){
  HashTable<int>* hash = new HashTable<int> ();
  int collisions = 0;
  hash->insert (1, 1, collisions);
  if (hash->insert(1, 2, collisions)){
    cout << "fail" << endl;
  }
  int target = 0;
  if (hash->find(1, target)){
    cout << target << endl;
  } else {
    cout << "fail2" << endl;
  }
  if (hash->find (12, collisions)){
    cout << "fail3" << endl;
  }
}
void test5 (){
  HashTable<int>* hash = new HashTable<int> ();
  int collisions = 0;
  for (int x = 0; x < 100; x++){
    hash->insert (8822319*x, x, collisions);
  }
  cout << *hash << endl;
}
