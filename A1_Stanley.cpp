//Trevor Stanley
//CSCI2270 Prashil 9:30 am Tuesdays; Hoenigman Lectures
//1.26.18  Assignment 1

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

//This declares a struct, gsitems, that has the members item, price, and Exchange Type
struct gsitems
{
  string item;
  int price;
  string ExT;
};

//initializing struct array elements to empty strings and null values (did this primarily for testing)
void initialize(gsitems ItemArray[])
{
  for(int i = 0;i<100;i++)
  {
      ItemArray[i].price = 0;
      ItemArray[i].item = " ";
      ItemArray[i].ExT = "";
  }
}

//In this fill function, the struct array and the file argument are passed from main. I then check that the file opens properly; if it does, then a while loop is
//employed to implement getline until the end of the file. Each line from the file is parsed on the comma and the element is stored in values that will are used
//to fill the struct array. The for loop is employed such that if the newly parsed/gotten element matches what is in the struct array at a given index, then
//it progresses to the next check that the stored exchange type, either for sale or wanted, is not a match and thus can POSSIBLY be exchanged. If these conditions are
//met, then two if conditions are utilized; they will cout the given item and price for both wanted and for sale that have been exhanged. See bellow inline notes.
int fill(gsitems ItemArray[], string FN)
{
  int F = 0;
  //could this be the issue?
  ifstream GS;

  GS.open(FN);  //have a .c_str()??

  cout<<"Items Sold: "<<endl;

  if(!GS.is_open())
  {
      cout << "File open error" << endl;
  }
  else
  {
    string line, item, ExT, price;
    while (getline(GS, line))
    {
        stringstream ss(line);
        getline(ss, item, ',');
        getline(ss, ExT, ',');
        getline(ss, price);
        bool match=false;
        for(int z = 0; z<F;z++)
        {
          if (ItemArray[z].item == item)
            {
              if (ItemArray[z].ExT != ExT)
              {
                int x = stoi(price);
                if(ItemArray[z].price >= x && ExT == " for sale")
                  {
                    cout<< item << " "<< price << endl;
                    for(int k = z; k<F;k++)
                      {
                        ItemArray[k] = ItemArray[k+1];
                      }
                      F--;
                      match=true;
                      break;
                  }
                else if(ItemArray[z].price <= x && ExT == " wanted")
                  {
                    cout<<item << " "<< ItemArray[z].price <<endl;
                    for(int k = z; k<F;k++)
                      {
                        ItemArray[k] = ItemArray[k+1];
                      }
                      F--;
                      match=true;
                      break;
                  }
                }
              }
          }
//If there is not match, then the struct array is filled with the respective elements
          if (match==false)
            {
              ItemArray[F].item = item;
              ItemArray[F].ExT = ExT;
              ItemArray[F].price = stoi(price);
              F++;
            }
          }
    }
    //F is returned so that when called in main, the struct array length is known and passed to the printArray function.
  return F;
}


//this function takes the struct array and the array length. If the exchange tupe matches either wanted or for sale, it prints the given index
//in the array until the end of the array length.
void printArray(gsitems ItemArray[], int num1)
{
  cout<<"#"<<endl;
  cout<<"Items remaining: "<<endl;
    for(int i = 0; i < num1; i++)
    {
      if (ItemArray[i].ExT == " wanted")
      {
        cout<< ItemArray[i].item << ", wanted" <<", " << ItemArray[i].price << endl;
      }
      if (ItemArray[i].ExT == " for sale")
      {
        cout<< ItemArray[i].item << ", for sale" <<", " << ItemArray[i].price << endl;
      }
    }
    cout<<"#"<<endl;

}


/* Algo
need to have some sort of array that is filled from the filled
after getting the line from the file and potentially parsing it, we must check
whether or not the product type is already in the array. If it is, then we must check
if this product is for sale or wanted. If it is wanted, we must check if the same product is
already for sale in the array. If it is, then we remove both? If it isn't, then we add to array

Algo from 3.2.4
for x = index to numElements - 2
  A[x] = A[x+1]
numElements = numElements -1
*/

//Here, the main calls the above functions and passes the given arguments and values.
//int main(int argc, char *argv[])
int main(int argc, char *argv[])
{
  int FR;
  gsitems ItemArray[stoi(argv[1])];
  initialize(ItemArray);
  FR = fill(ItemArray, argv[2]);
  printArray(ItemArray, FR);
  return 0;
}
