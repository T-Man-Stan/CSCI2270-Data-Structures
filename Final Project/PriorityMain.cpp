#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
#include <new>
#include "playLL.cpp"
#include "MinHeapImp2.cpp"
//#include "STL.cpp"
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

//struct for STL
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

int main(int argc, const char* argv[]) {
    //Graph g;  have your initializings
    int choice = int(argv[1]);  //menu number

    do
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Build LL PQueue" << endl;
        cout << "2. Build Heap PQueue" << endl;
        cout << "3. Dequeue LL PQueue" << endl;
        cout << "4. Dequeue Heap PQueue" << endl;
        cout << "5. Dequeue All LL PQueue" << endl;
        cout << "6. Dequeue All Heap PQueue" << endl;
        cout << "7. STL build" << endl;
        cout << "8. STL dequeue" << endl;
        cout << "9. Quit" << endl;
        cin >> choice;

        LL link;
        MinHeap MH = MinHeap();

      if(choice == 1)
      {
        double Array[6];
        double total = 0;
        double avg;
        int size = 1;
        while(size<7)
        {
          int D = 500;
          while(D >= 0)
          {
            using namespace std::chrono;


            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            link.setup(argv[2], size);
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
       int x = 0;
       cout<<"_________________"<<endl;
       while(x<6)
       {
         cout<<"size "<<Array[x]<<endl;
         x++;
       }

       cout<<"adding to file"<<endl;
       ofstream myfile;
       myfile.open ("AllData.csv");

       // Creating array that has Employee names

       myfile << "calculation done, 100, 200, 300, 400, 500, 600, \n";
       string name[6] = {"LL Average", " LL StDev", "STL Average", "STL StDev", "Heap Average", "Heap StDev"};

         // Writing to the csv file
         for(int r = 0; r<6; r++)
         {
           myfile << name[r]+",";
         }
           myfile << to_string(Array[0])+",";
           myfile << to_string(Array[1])+",";
           myfile << to_string(Array[2])+",";
           myfile << to_string(Array[2])+",";
           myfile << to_string(Array[4])+",";
           myfile << to_string(Array[5])+",";
           myfile << "\n";
       // CLosing the CSV File
       myfile.close();
      }


      else if(choice == 2)
      {
        double Array[6];
        double total = 0;
        double avg;
        int size = 1;
        while(size<7)
        {
          int D = 500;
          while(D >= 0)
          {
            using namespace std::chrono;
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            //cout<<"++++++++++"<<size<<"++++++++++"<<endl;
            MH.setup(argv[2], size);
            //cout<<"fuck"<<endl;
            //MH.print(size);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();

              duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

              //std::cout << "It took me " << time_span.count()*1000 << " miliseconds.";
              MH.print(size); //deconstructs
              total = total + time_span.count()*1000;
              D--;
          }
           cout<<total/500<<endl;
           Array[size-1] = total/500;
           cout<<"size "<<Array[size-1]<<endl;
           size++;
       }
       int x = 0;
       cout<<"_________________"<<endl;
       while(x<6)
       {
         cout<<"size "<<Array[x]<<endl;
         x++;
       }
       cout<<"adding to file"<<endl;
         ofstream myfile;
       	myfile.open ("AllData.csv");

       	// Creating array that has Employee names
       	//myfile << "calculation done, 100, 200, 300, 400, 500, 600, \n";
       	//string name[6] = {"LL Average", " LL StDev", "STL Average", "STL StDev", "Heap Average", "Heap StDev"};

     		// Writing to the csv file

           //myfile << name[1]+",";
           myfile << to_string(Array[0])+",";
           myfile << to_string(Array[1])+",";
           myfile << to_string(Array[2])+",";
           myfile << to_string(Array[2])+",";
           myfile << to_string(Array[4])+",";
           myfile << to_string(Array[5])+",";
           myfile << "\n";
     	// CLosing the CSV File
     	myfile.close();
      }

    if(choice == 3)
    {
      double Array[6];
      double total = 0;
      double avg;
      int size = 1;
      while(size<7)
      {
        int D = 500;
        while(D >= 0)
        {
          using namespace std::chrono;
          link.setup(argv[2], size);
          high_resolution_clock::time_point t1 = high_resolution_clock::now();
          link.deleteN(size);
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
     int x = 0;
     cout<<"_________________"<<endl;
     while(x<6)
     {
       cout<<"size "<<Array[x]<<endl;
       x++;
     }
     cout<<"adding to file"<<endl;
     ofstream myfile;
     myfile.open ("AllData.csv");

     // Creating array that has Employee names

     //myfile << "calculation done, 100, 200, 300, 400, 500, 600, \n";
     //string name[6] = {"LL Average", " LL StDev", "STL Average", "STL StDev", "Heap Average", "Heap StDev"};

       // Writing to the csv file
       //for(int i = 0; i<6; i++)
       //{
         //myfile << name[i]+",";
         myfile << to_string(Array[0])+",";
         myfile << to_string(Array[1])+",";
         myfile << to_string(Array[2])+",";
         myfile << to_string(Array[2])+",";
         myfile << to_string(Array[4])+",";
         myfile << to_string(Array[5])+",";
         myfile << "\n";
       //}
     // CLosing the CSV File
     myfile.close();
    }
    if(choice == 4)
    {
      double Array[6];
      double total = 0;
      double avg;
      int size = 1;
      while(size<7)
      {
        int D = 500;
        while(D >= 0)
        {
          using namespace std::chrono;
          MH.setup(argv[2], size);
          high_resolution_clock::time_point t1 = high_resolution_clock::now();
        MH.print(size); //will need to change this to just run once!!
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
   int x = 0;
   cout<<"_________________"<<endl;
   while(x<6)
   {
     cout<<"size "<<Array[x]<<endl;
     x++;
   }
   cout<<"adding to file"<<endl;
   ofstream myfile;
   myfile.open ("AllData.csv");

   // Creating array that has Employee names

   //myfile << "calculation done, 100, 200, 300, 400, 500, 600, \n";
   //string name[6] = {"LL Average", " LL StDev", "STL Average", "STL StDev", "Heap Average", "Heap StDev"};

     // Writing to the csv file
     //for(int i = 0; i<6; i++)
     //{
       //myfile << name[i]+",";
       myfile << to_string(Array[0])+",";
       myfile << to_string(Array[1])+",";
       myfile << to_string(Array[2])+",";
       myfile << to_string(Array[2])+",";
       myfile << to_string(Array[4])+",";
       myfile << to_string(Array[5])+",";
       myfile << "\n";
     //}
   // CLosing the CSV File
   myfile.close();
    }


    if(choice == 5)
    {
      double Array[6];
      double total = 0;
      double avg;
      int size = 1;
      while(size<7)
      {
        int D = 500;
        while(D >= 0)
        {
          using namespace std::chrono;
          link.setup(argv[2], 9);
          high_resolution_clock::time_point t1 = high_resolution_clock::now();
          link.deleteN(88);
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
     int x = 0;
     cout<<"_________________"<<endl;
     while(x<6)
     {
       cout<<"size "<<Array[x]<<endl;
       x++;
     }
     cout<<"adding to file"<<endl;
     ofstream myfile;
     myfile.open ("AllData.csv");

     // Creating array that has Employee names

     //myfile << "calculation done, 100, 200, 300, 400, 500, 600, \n";
     //string name[6] = {"LL Average", " LL StDev", "STL Average", "STL StDev", "Heap Average", "Heap StDev"};

       // Writing to the csv file
       //for(int i = 0; i<6; i++)
       //{
         //myfile << name[i]+",";
         myfile << to_string(Array[0])+",";
         myfile << to_string(Array[1])+",";
         myfile << to_string(Array[2])+",";
         myfile << to_string(Array[2])+",";
         myfile << to_string(Array[4])+",";
         myfile << to_string(Array[5])+",";
         myfile << "\n";
      // }
     // CLosing the CSV File
     myfile.close();
    }



    if(choice == 6)
    {
      double Array[6];
      double total = 0;
      double avg;
      int size = 1;
      while(size<7)
      {
        int D = 500;
        while(D >= 0)
        {
          using namespace std::chrono;
          MH.setup(argv[2], size);
          high_resolution_clock::time_point t1 = high_resolution_clock::now();
          //cout<<"++++++++++"<<size<<"++++++++++"<<endl;
          MH.print(1);
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
     int x = 0;
     cout<<"_________________"<<endl;
     while(x<6)
     {
       cout<<"size "<<Array[x]<<endl;
       x++;
     }
     cout<<"adding to file"<<endl;
     ofstream myfile;
     myfile.open ("AllData.csv");

     // Creating array that has Employee names

     //myfile << "calculation done, 100, 200, 300, 400, 500, 600, \n";
     //string name[6] = {"LL Average", " LL StDev", "STL Average", "STL StDev", "Heap Average", "Heap StDev"};

       // Writing to the csv file
       //for(int i = 0; i<6; i++)
       //{
         //myfile << name[i]+",";
         myfile << to_string(Array[0])+",";
         myfile << to_string(Array[1])+",";
         myfile << to_string(Array[2])+",";
         myfile << to_string(Array[2])+",";
         myfile << to_string(Array[4])+",";
         myfile << to_string(Array[5])+",";
         myfile << "\n";
       //}
     // CLosing the CSV File
     myfile.close();
    }


    if(choice == 7)
    {
      double Array[6];
      double total = 0;
      double avg;
      int size = 1;
      while(size<7)
      {
        int D = 500;
        while(D >= 0)
          {
          using namespace std::chrono;

          priority_queue<patient, vector<patient>, compare> pq;
          high_resolution_clock::time_point t1 = high_resolution_clock::now();


          ifstream file;
          file.open(argv[2]);   //csv infile

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
              // while(!pq.empty())
              //  {
              // //    patient pat = pq.top();
              // //    cout<<z<<": "<<pat.name<<" "<<pat.pri<<" "<<pat.TT<<endl;
              //     pq.pop();
              // //    z++;
              //   }
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
    }
    if(choice == 8)
    {
      double Array[6];
      double total = 0;
      double avg;
      int size = 1;
      while(size<7)
      {
        int D = 500;
        while(D >= 0)
          {
          using namespace std::chrono;

          priority_queue<patient, vector<patient>, compare> pq;
          ifstream file;
          file.open(argv[2]);   //csv infile

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
          }
          high_resolution_clock::time_point t1 = high_resolution_clock::now();
          while(z < size*100)
           {
          //    patient pat = pq.top();
          //    cout<<z<<": "<<pat.name<<" "<<pat.pri<<" "<<pat.TT<<endl;
              pq.pop();
              z++;
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
    }
    if(choice == 9)
    {
        cout<<"quit";
    }

  }while(choice != 9);
    return 0;
}
