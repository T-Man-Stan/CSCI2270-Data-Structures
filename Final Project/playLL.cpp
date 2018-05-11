#include <iostream>
#include <sstream>
#include <vector>
#include "LL.hpp"
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

LL::LL()
{

}
LL::~LL()
{
}
void LL::setup(string fname, int size)
{
  ifstream file; // declare file stream:
  file.open(fname);
  int y = 0;
  if(!file.is_open()){  cout << "File open error" << endl;  }

  if(size ==9)
  {
    string name, prior, treat, line;
    getline(file, line,'\r');              //get rid of first line of file
    while(getline(file, line,'\r') )
    {
        stringstream line2(line);
        getline (line2, name, ','); // read a string until next comma:
        getline(line2, prior, ',');
        getline(line2, treat);

        addNode(name, stoi(prior),stoi(treat));
        cout<<"Added "<<name<<endl;
      }
  }
  else
  {
    string name, prior, treat, line;
    getline(file, line,'\r');              //get rid of first line of file
    while(getline(file, line,'\r') && y < size*100 )
    {
        stringstream line2(line);
        getline (line2, name, ','); // read a string until next comma:
        getline(line2, prior, ',');
        getline(line2, treat);

        addNode(name, stoi(prior),stoi(treat));
        cout<<"Added "<<name<<endl;
        y++;
      }
    }
}

void insertInSecondary(Vertex* node, string name, int treatment){
  vert2* nextNode = node->head2;
  vert2* prevNode= nullptr;
  while(nextNode != nullptr)
  {

    if(treatment < nextNode->Tr)
    {
      vert2* v2 = new vert2;
      v2->Tr = treatment;
      v2->name = name;
      v2->next = nextNode;
      if(prevNode!=nullptr){
        prevNode->next=v2;
      }else{
        node->head2=v2;
      }
      return;
    }
    prevNode=nextNode;
    nextNode=nextNode->next;
  }
  vert2* v2 = new vert2;
  v2->Tr = treatment;
  v2->name = name;
  prevNode->next=v2;
  v2->next=nullptr;
}
void LL::addNode(string name, int priority, int treatment)
{
  if(mainHead == NULL)
  {
    mainHead = new Vertex;
    mainHead->pri = priority;
    mainHead->head2 = new vert2;
    mainHead->head2->Tr = treatment;
    mainHead->head2->name = name;
  }
  else{
    Vertex* nextNode = mainHead;
    Vertex* prevNode= nullptr;

    while(nextNode != NULL)
    {
      if (priority==nextNode->pri){
        insertInSecondary(nextNode,name,treatment);
        return;
      }
      else if(priority < nextNode->pri)
      {
        Vertex* n2 = new Vertex;
        n2->pri = priority;
        vert2* v2 = new vert2;
        n2->head2=v2;
        v2->Tr = treatment;
        v2->name = name;
        n2->next = nextNode;
        if(prevNode!=nullptr){
          prevNode->next=n2;
        }else{
          mainHead=n2;
        }
        return;
      }
      prevNode=nextNode;
      nextNode=nextNode->next;
    }
    Vertex* n2 = new Vertex;
    n2->pri = priority;
    vert2* v2 = new vert2;
    n2->head2=v2;
    v2->Tr = treatment;
    v2->name = name;
    n2->next = nullptr;
    prevNode->next=n2;
  }
}

void LL::deleteN(int x)
{
  x = x*10;
  //x is the number of things I want to delete
  while(x>0)
  {
    if(mainHead->head2->next != nullptr)
    {
      cout<<"deleted "<<mainHead->head2->name<<", "<<mainHead->pri<<", "<<mainHead->head2->Tr<<endl;
      mainHead->head2 = mainHead->head2->next;
    }
    else if(mainHead->head2->next == nullptr)
    {
      cout<<"deleted "<<mainHead->head2->name<<", "<<mainHead->pri<<", "<<mainHead->head2->Tr<<endl;
      delete mainHead->head2;
      mainHead = mainHead->next;
    }
    x--;
  }
}

//call vertices.sort alphabetically? may need more detailed bubble sort

   //put in an array that you then sort before constructing tree, or easier to just put into a tree and then sort using the binary heap sort method?
