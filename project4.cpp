
#include "HashTable.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

void measure1 ();
void measure2 ();

int main()
{
	/* initialize random seed: */
	srand((unsigned int)time(0));
	measure1 ();
	measure2 ();
	return 0;
}
//measure2 collects the data that is used for the graph by finding the average collisions accross 10000 inserts
//at a certain alpha
void measure2 (){
	HashTable<int>* hash = new HashTable<int> ();
	int i = 0;
	int collisions = 0;
	int randNum;
	int c = 0;
	//this while increments the number of items in the hashmap by 50 untill it reaches 900 and tests 10000 times each step
	while (c < 18){
		i = 0;
	//adds 50 values to the hashmap
	while (i < 50){
		randNum = rand();
		if (hash->insert(randNum, 12, collisions)){
			i++;
		}
	}
	collisions = 0;
	i = 0;
	int count = 0;
	//checks the amount of collisions and inserts (verifies inserts in case of insert failure)
	while (i < 10000){
		randNum = rand();
		if (hash->insert (randNum, 12, collisions)){
			hash->remove(randNum);
			count = count + 1;
		}
		i++;
	}
	cout << count << " " << collisions << endl;
	c++;
}
}
//measure1 serves as an alarm that helps to detect unusually high collisions at a low level
void measure1 (){
	HashTable<int>* hash2 = new HashTable<int> ();
	int index = 0;
	int collision = 0;
	int avgCollisions = 0;
	int rNum;
	//fills the hashmap 1 by 1 and reports the collisions that are above a threshhold (15)
	while (index < 1000){
		collision = 0;
		rNum = rand();
		if (hash2->insert(rNum, 12, collision)){
			avgCollisions = avgCollisions + collision;
			if (collision > 15){
				cout << collision << " " << index << endl;
			}
			index++;
		}
	}
	//reports the total average number of collisions (for fun)
	cout << avgCollisions/index << endl;
}
