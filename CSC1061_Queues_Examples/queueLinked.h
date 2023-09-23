//Queue derived from the class linkedListType
//Header file: queueLinked.h
 
#ifndef H_QueueType
#define H_QueueType
 
#include <iostream> 
#include "unorderedLinkedList.h"
 
using namespace std;

template<class Type>
class linkedQueueType: public unorderedLinkedList<Type>
{
public:
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    void addQueue(const Type& newElement);
    Type front() const;
    Type back() const;
    void deleteQueue();
};

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
    unorderedLinkedList<Type>::initializeList();
}

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return unorderedLinkedList<Type>::isEmptyList();
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    unorderedLinkedList<Type>::insertLast(newElement);
}

template<class Type>
Type linkedQueueType<Type>::front() const
{
    return unorderedLinkedList<Type>::front();      
}

template<class Type>
Type linkedQueueType<Type>::back() const
{
    return unorderedLinkedList<Type>::back();       
}

template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;

    if (!isEmptyQueue())
    {
        temp = this->first;   //make temp point to the first node
        this->first = this->first->link;  //advance first to the next node
        delete temp;    //delete the first node

        if (this->first == nullptr)  //if after deletion the queue 
                            //is empty,
            this->last = nullptr;    //set last to nullptr
    }
    else
        cout << "Cannot remove from an empty queue." << endl;
}

#endif