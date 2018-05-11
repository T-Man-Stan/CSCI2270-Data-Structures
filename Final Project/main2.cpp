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


struct patient
{
  string name;
  int pri;
  int TT;
  patient(string n, int p, int t): name(n), pri(p), TT(t) {};
};

struct compare
{
  bool operator()(const patient &a, const patient &b)
  {
        if(a.pri > b. pri) return true;
        if(a.pri == b.pri && a.TT > b.TT) return true;
        else return false;
  }
};

//int main(int argc, const char* argv[])
int main()
{
  //priority_queue<patient, vector<patient>, compare> pq;

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


  //MinHeap MH = MinHeap();
  //MH.setup("patientData2270.csv", 9);
  //MH.setup(argv[2],argv[1]);
  //MH.print(880);

  ifstream file;
  file.open(argv[2]));   //csv infile

  int y = 0;
  int z = 0;

  //  if(!file.is_open()){  cout << "File open error" << endl;  }
  //
  //  else
  //  {
  //    string name, prior, treat, line;
  //    getline(file, line,'\r');              //get rid of first line of file
  //    while(getline(file, line,'\r'))
  //    {
  //        stringstream line2(line);
  //        getline (line2, name, ','); // read a string until next comma:
  //        getline(line2, prior, ',');
  //        getline(line2, treat);
  //
  //        patient* node = new patient(name, stoi(prior), stoi(treat));
  //        //cout<<node->name<<" "<<node->pri<<endl;
  //        pq.push(*node);   //will build a queue using stl
  //        y++;
  //     }
  //     while(!pq.empty())
  //      {
  //         patient pat = pq.top();
  //         cout<<z<<": "<<pat.name<<" "<<pat.pri<<" "<<pat.TT<<endl;
  //         pq.pop();
  //         z++;
  //       }
  // }
}
