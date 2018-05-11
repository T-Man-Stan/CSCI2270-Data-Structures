#ifndef MinHeap_H
#define MinHeap_H

#include<vector>
#include<iostream>
using namespace std;

struct vertex
{
  string name;
  int pri;
  int TT;
  vertex(string n, int p, int t): name(n), pri(p), TT(t) {};
  bool operator<(const vertex & v)const
  {
    if(this->pri < v.pri) return true;
    else if(this->pri > v.pri) return false;
    else if(this->TT < v.TT) return true;
    else return false;
  }
  bool operator>(const vertex & v)const
  {
    if(this->pri > v.pri) return true;
    else if(this->pri < v.pri) return false;
    else if(this->TT > v.TT) return true;
    else return false;
  }
};


class MinHeap
{
    public:
        MinHeap();
        ~MinHeap();
        //MinHeap(int capacity);   //same as heapsort??.. I don't need this...
        void push(string name, int prior, int tre);
        void swap(int a, int b);
        void print(int y);
        int printSort();
        //pop();
        //printHeap();
        void setup(string, int);   //void?
        //void buildHeap()          //string type?
        //vector<vertex> unsorted;  //use a vector to store read in info, then sort later? or use array first?
        //can I make an array of type vertex
    private:
        //vector<vertex > vertices;
        //vertex * findVertex(string name);   //use a bst search function or tree min?
        vertex* heap[880];                              //supposed to be an array?
        int capacity = 880;
        int currentSize = 0;
        //void minHeapify(int);
        //void minHeapify(int);
};
#endif


//n^2 will always be larger than c*n when n is very large; O(n^2) > O(n)
//is log2(n); worst case is going through to bttom of tree
//depth is given by log2(n) when balanced

//insertion time complexity nlog(n)
//O(1) for switching elements for dequeueing, then is log(n); deleting all elements is nlog(n)
//heap sort is O(nlog(n)) ; bubble sort is O(n^2)

//O(n) for printing
