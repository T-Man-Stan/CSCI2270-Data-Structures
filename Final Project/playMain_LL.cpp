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
  //priority_queue< patient, vector<patient>, compare<patient> pq;  //should be compare or operator??
  //setup here for STL only
  double Array[6];
  double total = 0;
  double avg;
  int size = 9;
  LL link;
  // while(size<7)
  // {
  //   int D = 500;
  //   while(D >= 0)
  //   {
      using namespace std::chrono;


      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      //cout<<"++++"<<size<<"++++"<<endl;
      link.setup("patientData2270.csv",size);
      link.deleteN(size);

         high_resolution_clock::time_point t2 = high_resolution_clock::now();

           duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

           //std::cout << "It took me " << time_span.count()*1000 << " miliseconds.";

           total = total + time_span.count()*1000;
//            D--;
//      }
//       cout<<total/500<<endl;
//       Array[size-1] = total/500;
//       cout<<"size "<<Array[size-1]<<endl;
//       size++;
//   }
//   int x = 0;
//   cout<<"_________________"<<endl;
//   while(x<6)
//   {
//     cout<<"size "<<Array[x]<<endl;
//     x++;
//   }
//
// cout<<"adding to file"<<endl;
//   ofstream myfile;
// 	myfile.open ("LLData1.csv");
//
// 	// Creating array that has Employee names
//
// 	myfile << "calculation done, 100, 200, 300, 400, 500, 600, \n";
// 	string name[6] = {"LL Average", " LL StDev", "STL Average", "STL StDev", "Heap Average", "Heap StDev"};
//
// 		// Writing to the csv file
//     for(int i = 0; i<6; i++)
//     {
//       myfile << name[i]+",";
//       myfile << to_string(Array[0])+",";
//       myfile << to_string(Array[1])+",";
//       myfile << to_string(Array[2])+",";
//       myfile << to_string(Array[2])+",";
//       myfile << to_string(Array[4])+",";
//       myfile << to_string(Array[5])+",";
//       myfile << "\n";
//     }
//
// 	// CLosing the CSV File
//
// 	myfile.close();
	//return 0;

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
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    //link.deleteN(880);
    cout<<"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"<<endl;
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
