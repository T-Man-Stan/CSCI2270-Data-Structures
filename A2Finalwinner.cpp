styr//Trevor Stanley
//CSCI2270 Prashil 9:30 am Tuesdays; Hoenigman Lectures
//2.4.18  Assignment 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <new>
using namespace std;


//Declares a struct w/ string and int elements

struct wordItem{
    string word = "";
    int count = 0;
};

void getStopWords(string IgF, string *ignoreWords);
int*readHGF(wordItem wordItemList[], string HGF, int cap, int numwords[], string ignoreWords[]);
bool isStopWord(string word, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem wordItemList[], int numberOfUniqueWords);
void arraySort(wordItem wordItemList[], int numberOfUniqueWords);
void printTopN(wordItem wordItemList[], int topN);arr


//resize function; takes in the pointers for the struct array and capacity
//Then doubles the size of cap, creates a new dynamic array of type struct and
//the elements from the passed array are put into the new array that is twice the size
//then the old array deleted, a new instance is created andset equal to the new one
void resizeA(wordItem*& wordItemList, int*cap)
{
  int newCap = *cap*2;
  wordItem*newarray = new wordItem[newCap];
  for(int i=0;i<*cap;i++)
  {
    newarray[i].word = wordItemList[i].word;
    newarray[i].count = wordItemList[i].count;
  }
  delete[] wordItemList;
  wordItemList = newarray;
  *cap = newCap;
}


//main function; it takes in command line arguments which are put into variables to be passed
//to various functions. This is also where the file is opened, parsed, and the dynamic struct
//array is filled. Counters for the number of unique words, common words, and doubling
//are imbedded in here and stored into an array of size 3 that is then used in
//later functions that sort and call word-number combos


int main(int argc,char*argv[])
{
  int cap = 100;
  int numwords[3];
  //wordItem*wordItemList = new wordItem[cap];
  string ignoreWords[50]; //problem making this 50? (based on how I wrote the getStopWords function)
  int topN = stoi(argv[1]);
  string FNam1 = argv[2];
  string FNam2 = argv[3];

  wordItem *wordItemList = new wordItem[cap];
  //initialize(wordItemList, &cap);
  getStopWords(FNam2, ignoreWords);
  //readHGF(wordItemList, FNam1, cap, numwords, ignoreWords);

  int numE1 = 0;
  int totalW = 0;
  int totUW = 0;
  int dblnum = 0;
  ifstream readFileStream;
  readFileStream.open(FNam1);  //have a .c_str()??

  if(!readFileStream.is_open())
  {
      cout << "File open error" << endl;
  }
  else
  {
    string line, word;
    while(readFileStream >> word)
    {
      bool match = false;
      for(int k = 0;k<cap;k++)
      {
        if(wordItemList[k].word == word)
          {
            wordItemList[k].count = wordItemList[k].count+1;
            totalW++;
            match = true;
          }
      }
      if (match != true)
      {
        if(numE1 < cap)
        {
                if(isStopWord(word, ignoreWords) == false)
                {
                  wordItemList[numE1].word = word;
                  wordItemList[numE1].count =1;
                  totUW++; //can I have this incrementing in two places
                  totalW++;
                  numE1++;
                }
        }
        else if(numE1 == cap)
        {
          resizeA(wordItemList, &cap); //may need to have a pointer from main unless cap created in this function
          dblnum++;
              if(isStopWord(word, ignoreWords) == false)
              {
                wordItemList[numE1].count = 1;
                wordItemList[numE1].word = word;
                totUW++;
                totalW++;
                numE1++;
              }
        }
      }
    }
    numwords[0] = totUW;
    numwords[1] = totalW;
    numwords[2] = dblnum;
  }


  int numberOfUniqueWords = numwords[0];
  getTotalNumberNonStopWords(wordItemList, numberOfUniqueWords);

  arraySort(wordItemList, numberOfUniqueWords);
  printTopN(wordItemList, topN);

  cout<<"#"<<endl;
  cout<<"Array doubled: "<<numwords[2]<<endl;
  cout<<"#"<<endl;
  cout<<"Unique non-common words: "<<numwords[0]<<endl;
  cout<<"#"<<endl;
  cout<<"Total non-common words: "<<numwords[1]<<endl;
}

//this function takes in the ignore words file and a dynamic array
//it then fills this array with the words from the file.

void getStopWords(string IgF, string *ignoreWords)
{
    string line, wrd;
    ifstream df;
    int tally = 0;
    df.open(IgF);
    if(df.is_open())
    {
        while(getline(df,line))
        {
            ignoreWords[tally]=line;
            tally++;
        }
    }
}

//this function takes in a word and the ignor words array; it then checks to see if
//the given word matches one of the ignore words. If it does, true is returned and the
//function ends

bool isStopWord(string word, string ignoreWords[])
{
    bool w1 = false;
    for(int z=0;z<50;z++)
    {
        if(word==ignoreWords[z])
        {
            w1 = true;
            break;
        }
    }
    return w1;
}

//Thius function takes in the dynamic array and the number of unique words (calculated in main)
//it then iterates through this number to add to tally the given number of unique words from every index

int getTotalNumberNonStopWords(wordItem wordItemList[], int numberOfUniqueWords)
{
    int tally = 0;
    for(int k = 0; k< numberOfUniqueWords; k++)
    {
        tally+=wordItemList[k].count;
    }
    return tally;
}

//this function takes in the struct array and number of unique words and sorts the
//array via bubble sort

void arraySort(wordItem wordItemList[], int numberOfUniqueWords)
{
    for(int y = 0; y<numberOfUniqueWords;y++)
    {
        for(int h =0; h<numberOfUniqueWords;h++)
        {
            if(wordItemList[h].count<wordItemList[h+1].count)
            {
                int var1 = wordItemList[h].count;
                wordItemList[h].count=wordItemList[h+1].count;
                wordItemList[h+1].count = var1;
                string var2 = wordItemList[h].word;
                wordItemList[h].word=wordItemList[h+1].word;
                wordItemList[h+1].word=var2;
            }
        }
    }
}

//this function takes in the struct arary and topN (a command line arg) and
//iterates through the sorted array for the given interval (topN), and couts
//the word and number at the given index.

void printTopN(wordItem wordItemList[], int topN)
{
    for (int p = 0; p<topN;p++)
    {
        cout<<wordItemList[p].count<<" - "<<wordItemList[p].word<<endl;
    }
}
