#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
#include <new>
//#include "LL.cpp"
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
  //priority_queue< patient, vector<patient>, compare<patient> pq;  //should be compare or operator??
  //setup here for STL only
  double Array[6];
  double total = 0;
  double avg;
  int size = 1;
  int D = 500;
  while(size<7)
  {
    while(D >= 0)
      {
      using namespace std::chrono;

      priority_queue<patient, vector<patient>, compare> pq;
      high_resolution_clock::time_point t1 = high_resolution_clock::now();


      ifstream file;
      file.open("patientData2270.csv");   //csv infile

      int y = 0;
      int z = 0;

       if(!file.is_open()){  cout << "File open error" << endl;  }

       else
       {
         string name, prior, treat, line;
         getline(file, line,'\r');              //get rid of first line of file
         while(getline(file, line,'\r') && y < size*100)
         {
             stringstream line2(line);
             getline (line2, name, ','); // read a string until next comma:
             getline(line2, prior, ',');
             getline(line2, treat);

             patient* node = new patient(name, stoi(prior), stoi(treat));
             //cout<<node->name<<" "<<node->pri<<endl;
             pq.push(*node);   //will build a queue using stl
             y++;
          }
          while(!pq.empty())
           {
              patient pat = pq.top();
              cout<<z<<": "<<pat.name<<" "<<pat.pri<<" "<<pat.TT<<endl;
              pq.pop();
          //    z++;
            }
      }

         high_resolution_clock::time_point t2 = high_resolution_clock::now();

           duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

           //std::cout << "It took me " << time_span.count()*1000 << " miliseconds.";

           total = total + time_span.count()*1000;
           D--;
     }
      cout<<total/500<<endl;
      Array[size-1] = total/500;
      cout<<"size "<<Array[size-1]<<endl;
      size++;

  }

//   LL link;
//   //string n = argv[1];
//   link.setup("patientData2270.csv");
//
//   Vertex * tmp=link.mainHead;
//   while(tmp!=nullptr){
//     vert2 * tmpinnerhead=tmp->head2;
//     while(tmpinnerhead!=nullptr){
//       cout<<tmpinnerhead->name<<" "<<tmp->pri<<" "<<tmpinnerhead->Tr<<endl;
//       tmpinnerhead=tmpinnerhead->next;
//     }
//     tmp=tmp->next;
//   }
//   cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
//   link.deleteN(880);
// }



//MinHeap MH = MinHeap();
//MinHeap MH;
//string n = argv["PTest.txt"];
//MH.setup("patientData2270.csv");
//MH.print(1);

//STL priority;
//priority.queue< vertex, vector<vertex>, compare<patient>> pq;
//vertex();
//pq.push()
// LL link;
// //string n = argv[1];
// link.setup("patientData2270.csv");
// Vertex * tmp=link.mainHead;
// while(tm5p!=nullptr){
//   vert2 * tmpinnerhead=tmp->head2;
//   while(tmpinnerhead!=nullptr){
//     cout<<tmpinnerhead->name<<" "<<tmp->pri<<" "<<tmpinnerhead->Tr<<endl;
//     tmpinnerhead=tmpinnerhead->next;
//   }
//   tmp=tmp->next;
}


//need to start clock (begin) and end time clock, subtract to get actual runtime
//need std deviation function and another
