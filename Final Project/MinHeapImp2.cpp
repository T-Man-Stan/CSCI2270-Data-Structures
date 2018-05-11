//Trevor Stanley
//Project, Hoenigman
//open file
//this can be the .cpp for the two types

#include <iostream>
#include <sstream>
#include <vector>
#include "MinHeap2.hpp"
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

MinHeap::MinHeap()
{
}
MinHeap::~MinHeap()
{
}
void MinHeap::print(int i) {
  i = i*100;               //number to be printed and "deleted" is given
    while(currentSize != 1)
    {
        cout << heap[1]->name << " " << heap[1]->pri << " " << heap[1]->TT << endl;
        //bellow, equivalent to "pop" as the first element is replaced w/ last
        heap[1] = heap[currentSize-1];        //end of array
        currentSize--;                        //decrements end size
        printSort();                           //resorts the new first element down; essentially the reverse of push
    }
}

void MinHeap::setup(string fname, int size)
{
  int y = 0;
  ifstream file; // declare file stream:
  file.open(fname);
  if(!file.is_open()){  cout << "File open error" << endl;  }
  if(size == 9)
  {
    string name, prior, treat, line;
    getline(file, line,'\r');              //get rid of first line of file
    while(getline(file, line,'\r'))
    {
        stringstream line2(line);
        getline (line2, name, ','); // read a string until next comma:
        getline(line2, prior, ',');
        getline(line2, treat);

        push(name, stoi(prior), stoi(treat));
    }
  }
  else
  {
    string name, prior, treat, line;
    getline(file, line,'\r');              //get rid of first line of file
    while(getline(file, line,'\r') && y < 1+size*100)
    {
        stringstream line2(line);
        getline (line2, name, ','); // read a string until next comma:
        getline(line2, prior, ',');
        getline(line2, treat);

        push(name, stoi(prior), stoi(treat));
        y++;
    }
  }
}

void MinHeap::swap(int a, int b)
{
  vertex * temp = heap[a];
  heap[a] = heap[b];
  heap[b] = temp;
}
void MinHeap::push(string n, int P, int T)
{
  vertex* V = new vertex(n, P, T);         //create new vertex
  if(currentSize==capacity)                 //check if full
  {
    cout<<"full"<<endl;
  }
  else
  {
    currentSize++;              //increments current size each time, is a global/public variable
    int i = currentSize;        //sets index equal to this
    if(currentSize == 1)        //case when heap array is empty, adds to 1th element
    {
      heap[i] = V;
      return;
    }
    else if(currentSize > 1)            //adds to the next available spot, then checks if parent is larger
    {                                   //if so, then will iterate through entire array and swap until
      heap[i] = V;                      //the array is "heapified", or in the i*2 and i*2+1 order
      while(i != 1)
      {
        if(*heap[i/2] > *heap[i])
        {
          swap(i/2, i);
          i = i/2;
        }
        else
        {
          return;
        }
      }
    }
  }
  //return;
}

int MinHeap::printSort()                       //starts at top; while the index of the child is smaller than size of array
{                                              //willfirst check if child is smaller and if "LC" is smaller than "RC"
    int i = 1;                                 //if so, then will swap and the newly pushed down node will continue to be
    while(2*i < currentSize-1)                 //compared to and swapped with children until array is again heapified
    {
      if(*heap[2*i] < *heap[i] && *heap[2*i] < *heap[2*i+1])
      {
        swap(2*i, i);
        i = 2*i;
      }
      else if(*heap[2*i+1] < *heap[i])
      {
        swap(2*i+1, i);
        i = 2*i+1;
      }
      else
      {
        return i;         //once heapified will break while loop/
      }
    }
}
//pg 140, chp 4
