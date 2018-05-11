//#include "Assignment6Movies.txt"
#include<fstream>
#include<sstream>
#include "MovieTree.hpp"
#include <iostream>
using namespace std;

MovieTree::MovieTree() {
    root = NULL;
}

MovieTree::~MovieTree() {
    DeleteAll(root);
    root = NULL;
}

void MovieTree::printMovieInventory() {
    printMovieInventory(root);
}

int MovieTree::countMovieNodes()
{
    int c = 0;
    countMovieNodes(root,&c);
    return c;
}

void MovieTree::DeleteAll(MovieNodeBST *node) {
//cout<<"called again"<<endl;
    if(node == NULL)
        return;

        DeleteAll(node -> leftChild);
        DeleteAll(node -> rightChild);

        MovieNodeLL*LL = node->head;
        MovieNodeLL*temp = node->head;
        while(LL!=NULL)
        {
            cout<<"Deleting: "<<LL->title<<endl;
            temp = LL->next;
            deleteMovieNode(LL->title);
            LL = temp;
        }

}

MovieNodeLL*MovieTree::searchLL(MovieNodeLL* head, string title)
{
    MovieNodeLL* h = head;
    while(h!=NULL)
    {
        if(h->title == title)
        {
            return h;
        }
        else{
            h = h->next;
        }
    }
}

void MovieTree::printMovieInventory(MovieNodeBST* p)
{
    if(p != NULL)
    {
            printMovieInventory(p->leftChild);
            MovieNodeLL* LL = p->head;
            while(LL!=NULL)
            {
                cout<<"Movie: "<<LL->title<<" "<<LL->quantity<<endl;
                LL=LL->next;
            }

            printMovieInventory(p->rightChild);
   }
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity)
{
    MovieNodeBST * movie = new MovieNodeBST(title[0]);
    MovieNodeLL* newnode = new MovieNodeLL(ranking, title, releaseYear, quantity);

    //check if the root is empty, if it is this node is the root
    //MovieNodeBST * parent = NULL;
    MovieNodeBST * temp;
    if(root == NULL){
        root = movie;
        root->head = newnode;
        return;
    }
    MovieNodeBST* r = root;
    while(r != NULL)
        {
            if (r->letter == title[0])
                break;
            temp = r;
            if (title[0] > r->letter)
                r = r->rightChild;
            else if (title[0] < r->letter)
                r = r->leftChild;
        }
    //below: tells us if at the current node we go left or right or stay there
    if(r==NULL)
    {
        if(temp->letter<title[0])
        {
            MovieNodeBST* newChar = new MovieNodeBST(title[0]);
            temp->rightChild = newChar;
            newChar->parent = temp;
            r = newChar;
        }
        else if(temp->letter>title[0])
        {
            MovieNodeBST* newChar = new MovieNodeBST(title[0]);
            temp->leftChild = newChar;
            newChar->parent = temp;
            r = newChar;
        }
    }
    //below: temp is placeholder for parent. if less or greater than then insert BST node left or right
    //cout<<temp->parent<<endl;

    //cout<<temp->rightChild->letter<<endl;
    //Below: if r is not null, then start serching and adding to LL
    if(r!=NULL)
    {
        if(r->head == NULL)
            {
                r->head = newnode;
                return;
            }
            MovieNodeLL * h = r->head;
            MovieNodeLL * temp2 = r->head;
        while(h!=NULL)
            {
                if(h->title>=title)
                {
                    if(h==temp2)
                    {
                        newnode->next = h;
                        r->head = newnode;
                        return;
                    }
                    break;
                }

                temp2 = h;
                h = h->next;
            }
            newnode->next = temp2->next;
            temp2->next = newnode;
        }
}
MovieNodeBST*MovieTree::treeMinimum(MovieNodeBST * r)
{
  if(r)
  {
    while(r->leftChild != NULL)
        {
            r = r->leftChild;
        }
    }
    return r;
}
MovieNodeBST* delNode(MovieNodeBST*delNode,MovieNodeBST* root,MovieNodeBST* min){
  if(delNode->leftChild == NULL && delNode->rightChild == NULL){ //no chiuldren
      if(delNode==root){
        root=NULL;
        delete delNode;
        return root;
      }
      if(delNode->parent->leftChild==delNode){
        delNode->parent->leftChild=NULL;
        delete delNode;
        return root;
      }else{
      delNode->parent->rightChild=NULL;
      delete delNode;
      return root;
      }
  }else if(delNode->leftChild == NULL && delNode->rightChild != NULL){
    if(delNode==root){

      root=delNode->rightChild;
      delete delNode;
      return root;
    }
    if(delNode->parent->leftChild==delNode){
      delNode->parent->leftChild=delNode->rightChild;
      delete delNode;
      return root;
    }else{
      delNode->parent->rightChild=delNode->rightChild;
      delete delNode;
      return root;
    }
  }else if(delNode->leftChild != NULL && delNode->rightChild == NULL){
    if(delNode==root){

      root=delNode->leftChild;
      delete delNode;
      return root;
    }
    if(delNode->parent->leftChild==delNode){
      delNode->parent->leftChild=delNode->leftChild;
      delete delNode;
      return root;
    }else{
      delNode->parent->rightChild=delNode->leftChild;
      delete delNode;
      return root;
    }
  }else{
    MovieNodeBST* minright=min->rightChild;
    MovieNodeBST* minparent=min->parent;
    MovieNodeBST* nodeparent=delNode->parent;

    MovieNodeBST*nodeleft=delNode->leftChild;
    MovieNodeBST* noderight=delNode->rightChild;
    if(nodeparent==NULL){
      if(minparent==delNode){
        min->parent=nodeparent;
        min->leftChild=nodeleft;
        nodeleft->parent=min;
      }else{

        minparent->leftChild=minright;
        if (minright!=NULL)
          minright->parent=minparent;

        min->parent=nodeparent;
        min->leftChild=nodeleft;
        min->rightChild=noderight;
        nodeleft->parent=min;
        noderight->parent=min;
      }
      root=min;
      delete delNode;
      return root;
    }
    if(minparent==delNode){
      min->parent=nodeparent;
      min->leftChild=nodeleft;
      nodeleft->parent=min;
      if(nodeparent->leftChild==delNode){
        nodeparent->leftChild=min;
      }else{
        nodeparent->rightChild=min;
      }

    }else{

      minparent->leftChild=minright;
      if (minright!=NULL)
        minright->parent=minparent;

      min->parent=nodeparent;
      min->leftChild=nodeleft;
      min->rightChild=noderight;
      nodeleft->parent=min;
      noderight->parent=min;
      if(nodeparent->leftChild==delNode){
        nodeparent->leftChild=min;
      }else{
        nodeparent->rightChild=min;
      }
    }
    delete delNode;
    return root;

  }
}

void MovieTree::deleteMovieNode(string title)
{
MovieNodeBST* currNode = searchBST(root, title);
if(currNode == NULL)
{
    cout << "Movie not found." << endl;
}
else
{
    MovieNodeLL * current;
    current = searchLL(currNode->head, title);
    if(current==NULL){
        cout << "Movie not found." << endl;
        return;
    }
    if(currNode->head==current){
      currNode->head=current->next;
      delete current;
    }else{
    MovieNodeLL* parent=currNode->head;
      while(parent->next!=current){
      parent=parent->next;
      }
      parent->next=current->next;
      delete current;
    }
    if (currNode->head==NULL){
      root=delNode(currNode,root,treeMinimum(currNode->rightChild));
    }
}
}





MovieNodeBST *MovieTree::searchBST(MovieNodeBST *r, string title) {
    //MovieNodeBST * current = root;
    //search the tree for title with post order search
    MovieNodeLL * LL;
    r = root;
    while(r != NULL)
        {
            if (r->letter == title[0])
                break;
            else if (title[0] > r->letter)
                r = r->rightChild;
            else if (title[0] < r->letter)
                r = r->leftChild;
        }
    return r;
}

void MovieTree::findMovie(string title)
{
    MovieNodeBST* currNode = searchBST(root, title);
    if(currNode == NULL)
    {
        cout << "Movie not found." << endl;
        return;
    }
    MovieNodeLL * current;
    current = searchLL(currNode->head, title);
    if(current != NULL)
    {
        cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << current->ranking << endl;
            cout << "Title:" << current->title << endl;
            cout << "Year:" << current->year << endl;
            cout << "Quantity:" << current->quantity << endl;
    }
    else
    {
        cout << "Movie not found." << endl;
        return;
    }
    return;
}


void MovieTree::rentMovie(string title)
{
    MovieNodeBST* currNode = searchBST(root, title);
    if(currNode == NULL)
    {
        cout << "Movie not found." << endl;
        return;
    }
    MovieNodeLL* current = searchLL(currNode->head,title);
    if(current != NULL)
    {
        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << current ->ranking << endl;
        cout << "Title:" << current ->title << endl;
        cout << "Year:" << current ->year << endl;
        current->quantity = current->quantity-1;
        cout << "Quantity:" << current ->quantity << endl;

        if(current->quantity==0)
        {
            deleteMovieNode(current->title);
        }
    }
    else
    {
        cout << "Movie not found." << endl;
        return;
    }
}

void MovieTree::countMovieNodes(MovieNodeBST*node, int*c)
{
    MovieNodeLL* LLnode;
    if (node == NULL){
        return;
    }
    else{
        LLnode = node->head;
         while(LLnode != NULL)
            {
                *c = *c+1;
                LLnode = LLnode->next;
            }
        countMovieNodes(node->leftChild,c);
        countMovieNodes(node->rightChild,c);
    }
}

int main()
{

    MovieTree myTree;

    ifstream myFile;
    myFile.open("Assignment6Movies.txt");

    string lines;
    //while loop to grab each line of the file
    while(getline(myFile, lines)){
        stringstream line(lines);
        string imbdStr;
        string title1;
        string releaseStr;
        string quantStr;
        //use getline to parse the line of stuff
        getline(line, imbdStr , ',');
        getline(line, title1, ',');
        getline(line, releaseStr, ',');
        getline(line, quantStr, ',');
        //convert strings to int with stoi
        int imbd = stoi(imbdStr);
        int release = stoi(releaseStr);
        int quant = stoi(quantStr);
        //call the add movie function to add this line of info into a node
        myTree.addMovieNode(imbd, title1, release, quant);
    }
    int choice = 0;
    do{
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Delete a movie" << endl;
        cout << "5. Count the movies" << endl;
        cout << "6. Quit" << endl;
        cin >> choice;
        if(choice ==1){
            //call the find movie
            cin.clear();
            cin.ignore(100, '\n');
            string titleSearch;
            cout << "Enter title:" << endl;
            getline(cin, titleSearch);
            myTree.findMovie(titleSearch);
        }else if(choice == 2){
            cin.clear();
            cin.ignore(100, '\n');
            string titleRent;
            cout << "Enter title:" << endl;
            getline(cin, titleRent);
            myTree.rentMovie(titleRent);
        }else if(choice == 3){
            myTree.printMovieInventory();
        }else if(choice == 4){
            string deleteTitle;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter title:" << endl;
            getline(cin, deleteTitle);
            myTree.deleteMovieNode(deleteTitle);
        }else if(choice == 5){
            cout<<"Tree contains: "<<myTree.countMovieNodes()<<" movies." << endl;

        }else if(choice == 6){
            cout << "Goodbye!" << endl;
            //myTree.~MovieTree();
        }else{
            cout << "enter valid input" << endl;
        }
    }while(choice != 6);
    return 0;
}
