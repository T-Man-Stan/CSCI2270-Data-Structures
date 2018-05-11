#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
#include <new>
//#include "LL.cpp"
#include "MinHeapImp2.cpp"
//#include "STL.cpp"
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int main()
{
  MinHeap MH = MinHeap();
  //MinHeap MH;
  //string n = argv["PTest.txt"];
  MH.setup("patientData2270.csv", 9);
  MH.print(880);

}
