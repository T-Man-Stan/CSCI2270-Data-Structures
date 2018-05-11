#ifndef LL_H
#define LL_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

struct vert2
{
  int Tr;
  string name;
  vert2 *next = nullptr;
};
struct Vertex
{
  int pri;
  Vertex* next = nullptr;
  vert2* head2 = nullptr;
};

class LL
{
  public:
  Vertex* mainHead=nullptr;

    void addNode(string name, int priority, int treatment);
    void setup(string, int);    //very similar to setup in minheap; added int to setup
    void deleteN(int);
    LL();
    ~LL();
};
#endif
