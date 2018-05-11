#include <iostream>
#include <fstream>
#include <sstream>
#include <new>
using namespace std;

struct city
{
	string cityName;
	string message="";
	city *next;
	city(){}; // default constructor
    city(string initName, city *initNext, string initMessage)
    {
        cityName = initName;
        next = initNext;
        message = initMessage;
    }
};

city *buildNetwork()
{
    city *head=NULL;
    city *tail=NULL;

    string cityarr[10]={"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.","New York","Boston"};

    for(int i = 0; i<10;i++)
    {
        if(head==NULL)
        {
            head = new city;
            head->cityName=cityarr[i];
						//head->message="";//do this here vs when declaring struct?
            tail=head;
        }
      else
        {
          city* newNode = new city;
          newNode->cityName=cityarr[i];
          newNode->next = NULL;
          tail->next = newNode;
          tail=tail->next;

        }
    }
    return head;
}


city *addCity(city *head, city *previous, string cityName)
{
    city *h = head;
    city *newCity = new city(cityName, NULL,"");

    //if replacing head
    if(previous == NULL)
    {
        head = newCity;
        newCity->next = h;
        h = head;
    }
    else
    {
        newCity->next = previous->next;
        previous->next = newCity;
    }
    //if previous is null, and head == LA, then insert the cityName for new head
    return head;
}


void transmitMsg(city *head)
{
    string lines;
    string myfile("messageIn.txt");
    ifstream myFile;
    myFile.open(myfile);
    if (!myFile)
    {
        terminate();
    }
    city *h = head;
    city *n;
    n = h;
        string word;
        while(myFile >> word)
        {
            //at this point i have a word to transmit through all the cities
            //step through the linked list starting with n, which is currently equal to head
            for(;n;n = n-> next)
            {
                n -> message = word;
                cout << n ->cityName << " received " << word << endl;
            }
            //cout << "1st" << endl;
            //reset n to head so that the next message sends through the whole linked list
            n = h;
        }
}

void printPath(city *head)
{
    cout << "===CURRENT PATH===" << endl;
    //step through the linked list starting with the head and going until it's done
    city * temp=head;
    while(temp!=nullptr) {
        cout << temp ->cityName << " -> ";
        temp=temp->next;
    }
    cout << " NULL" << endl;
    cout  << "==================" << endl;
}

city *search(city *head, string cityName)
{
	city *head2 = head;
	while(head2!=NULL)
	{
        if(head2->cityName==cityName)
    		{
          	return head2;
            }
    		else
    		{
    			head2 = head2->next;
    		}
    }
}


int main()
{
	//start here :D
	//display menu
	/*
	cout<<"======Main Menu======"<<endl;
	cout<<"1. Build Network"<<endl;
	cout<<"2. Print Network Path"<<endl;
	cout<<"3. Transmit Message Coast-To-Coast"<<endl;
	cout<<"4. Add City"<<endl;
	cout<<"5. Quit"<<endl;
    */
	int userInput = -10;
	city *head1;
	string temp;

	while(userInput!=5)
	{
	    cout<<"======Main Menu======"<<endl;
    	cout<<"1. Build Network"<<endl;
    	cout<<"2. Print Network Path"<<endl;
    	cout<<"3. Transmit Message Coast-To-Coast"<<endl;
    	cout<<"4. Add City"<<endl;
    	cout<<"5. Quit"<<endl;

        cin>>temp;
    	userInput = stoi(temp);
    	if (userInput == 1)
    	{
    		head1 = buildNetwork();
    	}
    	else if(userInput == 2)
    	{
    		printPath(head1);
    	}
    	else if(userInput == 3)
    	{
    		transmitMsg(head1);
    	}
    	else if(userInput == 4)
    	{
    		cout<<"Enter a City name: "<<endl;
    		string cityNew;

    		cin>>cityNew;
    		cout<<"Enter a previous City name: "<<endl;
    		string cityPrevious;
    		cin>>cityPrevious;
            city*prev;

            if(cityPrevious == "First")
            {
                prev = NULL;
            }
            else
            {
                prev = search(head1, cityPrevious);
                //cout<<prev->cityName;
        		//searching for previous node
        		head1=addCity(head1, prev, cityNew);
            }
    	}
    	else if(userInput == 5)
    	{
    		cout<<"Goodbye!";
    	}
	}
}
