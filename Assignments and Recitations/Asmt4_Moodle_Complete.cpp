#include "CommunicationNetwork.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


void CommunicationNetwork::addCity(string newCityName, string previousCityName)
{
   //previous is found with the search function and passed in

    City *head2=this->head;
    City *newCity = new City (newCityName, NULL, NULL,""); //do I need a double null here?

	 if(this->head == NULL)//for null head node
	 {
		this->head = newCity;
	    this->tail=this->head;
	 }
	 else
	 {
            if(previousCityName == "First")
            {
                newCity->next = this->head;
                this->head->previous = newCity;
                this->head=newCity;
            }
            else if(previousCityName == "")
            {
                newCity->next = NULL;
                this->tail->next = newCity;
                newCity->previous = this->tail;
                this->tail = newCity;
            }
            else
            {
        	   while(head2!=NULL)
        		{
        				if(head2->cityName==previousCityName)
        				{
        				    break;
        				}
        				else
        				{
        					head2 = head2->next;
        				}
        		}
            	 head2->next->previous = newCity;
            	 newCity->previous = head2;
            	 newCity->next = head2->next;
            	 head2->next = newCity;
        	 }
    }
}

void CommunicationNetwork::transmitMsg(char* filename)
{
    string lines;
    string file(filename);
    ifstream myFile;
    myFile.open(file);
    if (!myFile){
        terminate();
    }
    City *h = head;
    City *temp;
    City *n;
    City *t;
    n = h;
    t = tail;
        string word;
        while(myFile >>word)
        {
            //at this point i have a word to transmit through all the cities
            //step through the linked list starting with n, which is currently equal to head
            for(;n;n = n-> next){
                n -> message = word;
                cout << n ->cityName << " received " << word << endl;
            }
            t = t ->previous;
            for(;t; t = t -> previous){
                t -> message = word;
                cout << t -> cityName << " received " << word << endl;
            }
            //cout << "1st" << endl;
            //reset n to head so that the next message sends through the whole linked list
            n = h;
            t = tail;
        }
}

void CommunicationNetwork::printNetwork()
{
    //declare pointers that are objects of city to use to make the linked list
    City *n;
    City *temp;
    City *head1;

    n = new City;
    n -> cityName = "Los Angeles";
    n -> previous = NULL;
    temp = n;
    head1= n;
    head = n;

    //now i have the head set and can make the list

    n = new City; //make a new city and have n point to it
    n ->cityName = "Phoenix"; //set n's name
    n ->previous = temp;
    temp -> next = n; //look at the node temp was pointing to, and have its next point to the new node n
    temp = temp -> next; // tell temp to move to what next is pointing to
    //repeat for all the cities
    n = new City;
    n -> cityName = "Denver";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Dallas";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "St. Louis";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Chicago";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Atlanta";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Washington, D.C.";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "New York";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Boston";
    n -> previous = temp;
    temp -> next = n;
    tail = n;
    //n -> next = NULL; //tell it this is the last one

    City *r = head;
    //print the network
    cout << "===CURRENT PATH===" << endl;
    cout << "NULL <- ";
    while(r -> cityName != tail -> cityName){
        cout << r -> cityName << " <-> ";
        r = r -> next;
    }
    cout << tail -> cityName <<" -> NULL" << endl;
    cout  << "==================" << endl;
}

void CommunicationNetwork::buildNetwork()
{
    //declare pointers that are objects of city to use to make the linked list
    City *n;
    City *temp;
    City *head1;

    n = new City;
    n -> cityName = "Los Angeles";
    n -> previous = NULL;
    temp = n;
    head1= n;
    head = n;

    //now i have the head set and can make the list

    n = new City; //make a new city and have n point to it
    n ->cityName = "Phoenix"; //set n's name
    n ->previous = temp;
    temp -> next = n; //look at the node temp was pointing to, and have its next point to the new node n
    temp = temp -> next; // tell temp to move to what next is pointing to
    //repeat for all the cities
    n = new City;
    n -> cityName = "Denver";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Dallas";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "St. Louis";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Chicago";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Atlanta";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Washington, D.C.";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "New York";
    n -> previous = temp;
    temp -> next = n;
    temp = temp -> next;

    n = new City;
    n -> cityName = "Boston";
    n -> previous = temp;
    temp -> next = n;
    tail = n;
    //n -> next = NULL; //tell it this is the last one
}

void CommunicationNetwork::deleteCity(string removeCity)
{
    City *n = head;
    //declare a pointer that is one step ahead of n
    City *tempNext = head -> next;
    //check if head is the one to delete
    bool F = false;
    while (n!=NULL)
    {

        if(n -> cityName == removeCity)
        {
            if(n->next == NULL && n->previous == NULL)
            {
                delete n;
                tail = NULL;
                head = NULL;
                break;
            }
            else if(n->next == NULL)
            {
                n->previous->next = NULL;
                tail = n->previous;
                delete n;
                F = true;
                break;
            }
            else if(n->previous == NULL)
            {
                n->next->previous = NULL;
                head = n->next;
                delete n;
                F= true;
                break;
            }
            else
            {
                n->previous->next = n->next;
                n->next->previous = n->previous;
                F = true;
                delete n;
                break;
            }
        }
        n = n->next;
    }
    if (F == false)
    {
        cout<<removeCity<<" not found"<<endl;
        return;
    }
}

void CommunicationNetwork::deleteNetwork()
{
    City *n = head;
    City *temp;
    //step through the list until you hit next = NULL
    while(n != NULL){
        //print what city is being deleted
        cout << "deleting " << n -> cityName << endl;
        //temp is equal to the next node
        temp = n -> next;
        //delete current and then set n equal to the new current node
        delete n;
        n = temp;
    }
    head = NULL;
}

CommunicationNetwork::CommunicationNetwork(){
    head = NULL;
    tail = NULL;
}

CommunicationNetwork::~CommunicationNetwork(){
    deleteNetwork();
    head = NULL;
    tail = NULL;
}

int main()
{
    int choice = 9;
    string name1;
    string prev1;
    CommunicationNetwork comNet;
    do
    {
        cout << "======Main Menu======" << endl;
        cout<< "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Delete City" << endl;
        cout << "6. Clear Network" << endl;
        cout << "7. Quit" << endl;
        cin >> choice;

        if(choice == 1)
        {
            //Call the build network method
            comNet.buildNetwork();
            comNet.printNetwork();
        }
        else if(choice == 2)
        {
            //call the print net path method
            comNet.printNetwork();
        }
        else if(choice == 3)
        {
            //call the transmit c2c method
            //string file;
            //cin >> file;
            comNet.transmitMsg("messageIn.txt");
        }
        else if(choice == 4)
        {
            //call the add city method
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter a city name: " << endl;
            getline(cin, name1);
            cout << "Enter a previous city name: " << endl;
            getline(cin, prev1);
            comNet.addCity(name1, prev1);
        }
        else if(choice == 5)
        {
            cout << "Enter a city name: " << endl;
            string cityDel;
            cin >> cityDel;
            comNet.deleteCity(cityDel);
        }
        else if(choice == 6)
        {
            comNet.deleteNetwork();
        }
        else if(choice == 7)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Please enter a valid option" << endl;
        }

    }while(choice != 7);

    return 0;
}
