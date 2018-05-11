# include "Queue.h"
# include <iostream>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

//constructor
Queue::Queue(int size) {
    queueSize = size;
    arrayQueue = new string [size];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}



bool Queue::queueIsFull() {
    //the queue is full when count is equal to its size
    if(queueCount == queueSize){
        return true;
    }
    else{
        //queue aint full
        return false;
    }
}

//destructor
Queue::~Queue() {
  delete [] arrayQueue;
}

void Queue::enqueue(string word) {
    //cout << "queue count " <<  queueCount << endl;
    //cout << "tail " << queueTail << endl;
    //if the queue is not full then add the word
    if(!queueIsFull()){
        arrayQueue[queueTail] = word;
        //increment count
        queueCount++;
        //if the tail is at the end, it needs to wrap around!
        if(queueTail == queueSize-1){
            queueTail = 0;
        }
        else{
            //if its not at the end just increment
            queueTail++;
        }
    }else{
        cout << "Queue is full" << endl;
        return;
    }
    /*
    if(queueTail == 0 && queueHead == 0){
        arrayQueue[queueTail] = word;
        queueTail++;
        queueCount++;
        cout << "E: " << word << endl;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
        return;
    }
    else if(queueTail == queueSize - 1){
       //the tail needs to wrap around
        queueTail = 0;
    }
    else{
        arrayQueue[queueTail] = word;
        queueTail++;
        queueCount++;

    }
     */

    //arrayQueue[queueTail] = word;
    //queueSize++;

    //print the pertinent information
    cout << "E: " << word << endl;
    cout << "H: " << queueHead << endl;
    cout << "T: " << queueTail << endl;
    //cout << "size: " << queueSize << endl;
    return;
}

bool Queue::queueIsEmpty() {
    //queue is only empty when the count is zero
    if(queueCount == 0){ //queueTail == 0 && queueHead == 0
        return true;
    }
    else{
        return false;
    }
}

void Queue::dequeue() {
    if(queueIsEmpty()==true)
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        //store the word
        string word = arrayQueue[queueHead];
        //decrement the count
        queueCount--;
        //if the head is at the end, we want to wrap it around to the front
        if(queueHead == queueSize -1){
            queueHead = 0;
        }else{
            //otherwise just increment
            queueHead++;
        }
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
        cout << "word: " << word << endl;
        }
}

void Queue::printQueue() {
    if (queueIsEmpty()){
        cout << "Empty" << endl;
        return;
    }else if (queueTail == 0 && queueHead == 0){
        //if the tail and head are zero and count is greater than zero, the array is full
        //we just need to print from start to finish
        for(int i = queueHead; i <= queueSize-1; i++){
            cout << i << ": " << arrayQueue[i] << endl;
        }
    }else if(queueTail == queueHead){
        //if the tail is equal to the head, it is full but head is not at the start of the array
        //need to step through 10 places but the cout for i needs to be modulo(arraysize)
        //if we do 2mod10 the remainder is just 2 since no division performed
        //since the for loop needs to wrap around, the i term needs to travel an extra queuehead-1 past 10
        //10mod10 = 0, 11mod10 = 1
        for(int i = queueHead; i <= (10+queueHead-5); i++){
            cout << (i%(queueSize)) << ": " << arrayQueue[i%queueSize] << endl;
        }
    }

    else{
        //in all other cases the head and the tail are different and we can step through with modulus to wrap around
        for(int i = queueHead; i != queueTail; i = (i+1)%queueSize){ //the modulus in the increment lets me go from position 9 to pos 0
            cout << (i%(queueSize)) << ": " << arrayQueue[i%queueSize] << endl;
        }
    }
}


void Queue::enqueueSentence(string os)
{
    stringstream ss(os);
    while(getline(ss, os, ' '))
    {
        enqueue(os);
    }
}

int main() {
    string choice;

    Queue comQue(10);

do {
    cout << "======Main Menu=====" << endl;
    cout << "1. Enqueue word" << endl;
    cout << "2. Dequeue word" << endl;
    cout << "3. Print queue" << endl;
    cout << "4. Enqueue sentence" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;
    //check that the user enters an int, and check for that error
    //I got the code for cin.ignore on stack overflow

    if (choice == "1") {
        string word;
        cout << "word: ";
        cin >> word;
        if (!comQue.queueIsFull()) {
            //string word;
            //cout << "word: ";
            //cin >> word;
            comQue.enqueue(word);
        } else {
            cout << "Queue is full" << endl;
        }

    } else if (choice == "2") {
        if(!comQue.queueIsEmpty()){
            //string deq;
            //deq =
            comQue.dequeue();

        }else{
            cout << "Queue is empty." << endl;
        }
    } else if (choice == "3") {
        comQue.printQueue();
    } else if (choice == "4") {
        string senWord;
        string sen;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "sentence: ";
        getline(cin, sen);
        //cout << endl;
        stringstream s(sen);
        //need to split up the sentence and read in until full or out of words

        while(getline(s, senWord, ' ')){
            comQue.enqueue(senWord);
            /*
            if(!comQue.queueIsFull()){
                comQue.enqueue(senWord);
            }
            else{
                cout << "Queue is full" << endl;
            }*/

        }

    } else if (choice == "5") {
        cout << "Goodbye!" << endl;
        comQue.~Queue();
    }
    else{
        comQue.enqueueSentence(choice);
    }
}while(choice != "5");
   return 0;
}
