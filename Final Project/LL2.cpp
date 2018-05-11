#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
#include <new>
#include "playLL.cpp"
//#include "MinHeapImp2.cpp"
//#include "STL.cpp"
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;


//int main(int argc, const char* argv[])
int main()
{
  //size = stoi(argv[1]);
  //
  int size = 9;
  LL link;
  link.setup("patientData2270.csv",size);
  //link.setup(argv[2],size);
  link.deleteN(size);
  Vertex * tmp=link.mainHead;
  while(tmp!=nullptr){
    vert2 * tmpinnerhead=tmp->head2;
    while(tmpinnerhead!=nullptr){
      cout<<tmpinnerhead->name<<" "<<tmp->pri<<" "<<tmpinnerhead->Tr<<endl;
      tmpinnerhead=tmpinnerhead->next;
    }
    tmp=tmp->next;
  }
}
