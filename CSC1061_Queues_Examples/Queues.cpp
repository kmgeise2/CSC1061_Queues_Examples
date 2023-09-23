/*
File: CSC1061_Queues_Examples.cpp
Author: Ram Longman
Revised: 9/22/23 by Kathy Geise 
Description: Includes two examples
(1) Create a queue of integers and print them. 
       Queue is an Array (not Linked List)
(2) Search a queue for a target and return the 
    minimum distance from the starting location
    to the target (forward or backward)
*/

#include <iostream>
#include "queueAsArray.h"
#include <vector>
#include <unordered_set>

using namespace std;

void first(); //Load a queue with integers
void print(vector<int> v, int size); //print array
int search(vector<int> v, int location, int target);

int main()
{
    cout << "Create a queue and load it with integers" << endl;
    first();

    cout << endl;

    cout << "Search a queue for target values" << endl;
    // Create an array of values and print the array
    vector<int> v = { 3, 7, 2, 33, 52, 1, 14, 8, 6, 2 };
    int size = 10;
    cout << "Print the unordered queue array" << endl;
    print(v, size);

    // Search the queue for the value 2 starting at location 4
    cout << "\nThe starting index location is 4 and target is 2" << endl;
    cout << "The minimum distance from the starting location to the target is: ";
    cout << search(v, 4, 2) << endl;

}

void first() {
    queueType<int> q; //queuesAsArray header

    for (int i = 1; i <= 20; i++) {
        q.addQueue(i);
    }

    cout << "Print the queue" << endl;

    while (!q.isEmptyQueue()) {
        cout << q.front() << " ";
        q.deleteQueue();
    }
    cout << endl;
}

int search(vector<int> v, int location, int target) {

    unordered_set<int> visitedIndices; //visited indices

    //create queue and put starting element in it
    queueType<int> q;
    q.addQueue(location); //Add to the back of the queue
    visitedIndices.insert(location);

    while (!q.isEmptyQueue()) {
        //remove element from front of q
        int e = q.front();
        q.deleteQueue();

        //if element is the target, return its distance from starting position
        if (v[e] == target)
            return abs(location - e);

        //if there's an element to the left and it wasn't visited
        if (e > 0 && !visitedIndices.count(e - 1)) {
            q.addQueue(e - 1); //add element on left
            visitedIndices.insert(e - 1);
        }
        //if there's an element to the right and it wasn't visited
        if (e < v.size() - 1 && !visitedIndices.count(e + 1)) {
            q.addQueue(e + 1); //add element on right
            visitedIndices.insert(e + 1);
        }
    }
    return -1;
}
void print(vector<int> input, int size) {
    // loop through the array elements
    for (size_t i = 0; i < size; i++) {
        cout << input[i] << ' ';
    }
}