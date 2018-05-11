//Trevor Stanley
//3.22.18
//assignment 8

#include <iostream>
#include <sstream>
#include <vector>
#include "Graph.hpp"
#include <fstream>
#include <map>
//#include "zombieCities.txt"

using namespace std;

void Graph::addVertex(std::string n)
{
    bool found = false;
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].name == n) {
			found = true;
			cout << vertices[i].name << " already in the graph." << endl;
		}
	}
	if (found == false) {
		vertex v;
		v.name = n;
		vertices.push_back(v);
	}
}


void Graph::addEdge(std::string v1, std::string v2, int distance)
{
    	// find first vertex
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].name == v1) {

			// check if vertex already exists
			bool exists = false;
			for (int k = 0; k < vertices[i].adj.size(); ++k) {
				if (vertices[i].adj[k].v->name == v2) {
					exists = true;
					break;
				}
			}
			if (exists) {
				break;
			}

			// find second vertex
			for (int j = 0; j < vertices.size(); j++) {
				if (vertices[j].name == v2 && i != j) {
					// add element to first vertex adjacent
					adjVertex av;
					av.v = &vertices[j];
					av.weight = distance;
					vertices[i].adj.push_back(av);

					// another vertex for edge in other direction
					adjVertex av2;
					av2.v = &vertices[i];
					av2.weight = distance;
					vertices[j].adj.push_back(av2);
				}
			}
		}
	}
}

int Graph::isAdjacent(string s, string d)
{
     // Base case
    if (s == d)
        return true;

    else
    {
        for(int a = 0; a<vertices.size(); a++)
        {

            if(s == vertices[a].name)
            {
              for(int c = 0; c<vertices[a].adj.size(); c++)
              {
                  if(d==vertices[a].adj[c].v->name)
                  {
                      return true;
                  }
              }
            }
        }
        return false;
    }
}

void Graph::assignDistricts()
{
    int district = 1;

  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].districtID == -1) {
      DFSLabel(vertices[i].name, district);
      district++;
    }
  }
}

void Graph::DFSLabel(string startingCity, int distID)
{
    stack<vertex *> t;

  for (int i = 0; i < vertices.size(); i++)
  {
    vertices[i].visited = false;
  }

  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].name == startingCity) {
      vertices[i].visited = true;
      t.push(&vertices[i]);
      vertices[i].districtID = distID;
      break;
    }
  }

  while (t.empty() != true) {
    vertex *top = t.top();
    t.pop();
    for (int i = 0; i < top->adj.size(); i++) {
      if (top->adj[i].v->visited == false) {
        top->adj[i].v->visited = true;
        top->adj[i].v->districtID = distID;
        t.push(top->adj[i].v);
      }
    }
  }
}

void Graph::shortestPath(string startingCity, string endingCity)
{
    vertex *start = findVertex(startingCity);
    vertex *end = findVertex(endingCity);

  if (start == NULL or end == NULL)
  {
    cout << "One or more cities doesn't exist"
         << "\n";
    return;
  }

  if (end->districtID != start->districtID) {
    cout << "No safe path between cities"
         << "\n";
    return;
  }

  if (end->districtID == -1 || start->districtID == -1) {
    cout << "Please identify the districts before checking distances"
         << "\n";
    return;
  }

  for (int i = 0; i < vertices.size(); i++) {
    vertices[i].visited = false;
    vertices[i].unweightedDistance = numeric_limits<int>::max();
  }

  if (end->districtID == start->districtID)
  {

        int count = 0;
        vertex *x = start;
        x->unweightedDistance = 0;
        //vertex * VE = end;
        unsigned T = 0;
        unsigned Y = 0;

		queue<vertex*> Q;

		x->visited = true;
		x->parent = NULL;
	    Q.push(x);
		while(!Q.empty())
			{
				vertex *V = Q.front();
				Q.pop();
				//cout<<V->name<<" ";
				if(V->name != endingCity)
				{
					for(unsigned t = 0; t < V->adj.size(); t++)
					{
					    //cout << t << endl;
						if(V->adj[t].v->visited==false)
						{
							V->adj[t].v->visited = true;
							Q.push(V->adj[t].v);
							V->adj[t].v->parent = V;
							V->adj[t].v->unweightedDistance = V->unweightedDistance +1;
						}
					}
				}
				else
				{
					break;
				}
			}
    }
    cout<<end->unweightedDistance;
    while(end->parent!=NULL)
    {
        cout<<", "<<end->name;
        end = end->parent;
    }
    cout<<", "<<end->name<<endl;
}

void Graph::shortestWeightedPath(string startingCity, string endingCity)
{
    vertex *start = findVertex(startingCity);
    vertex *end = findVertex(endingCity);

  if (start == NULL or end == NULL)
  {
    cout << "One or more cities doesn't exist"
         << "\n";
    return;
  }

  if (end->districtID != start->districtID) {
    cout << "No safe path between cities"
         << "\n";
    return;
  }

  if (end->districtID == -1 || start->districtID == -1) {
    cout << "Please identify the districts before checking distances"
         << "\n";
    return;
  }

  for (int i = 0; i < vertices.size(); i++)
  {
    vertices[i].visited = false;
    vertices[i].weightedDistance = numeric_limits<int>::max();
    vertices[i].parent = NULL;
  }

  if (end->districtID == start->districtID)
  {
      start->visited = true;
      start->weightedDistance = 0;
      vector<vertex*> s;  //"solved"
      vertex * parent;
      vertex* VE;
      vertex* SV;
      int minDistance;
      int dist;
      s.push_back(start);

    while (!end->visited)
    {
        minDistance = INT_MAX;
        SV = NULL;
        for (int i = 0; i < s.size(); ++i)
        {
            VE = s[i];
            for (int j = 0; j < VE->adj.size(); ++j)
            {
                if (!VE->adj[j].v->visited)
                {
                    dist = VE->weightedDistance + VE->adj[j].weight;
                    VE->visited = true;
					if (dist < minDistance)
					{
					    SV = VE->adj[j].v;
					    minDistance = dist;
					    parent = VE;
					}
                }
            }
        }
        SV->weightedDistance = minDistance;
        SV->parent = parent;
        SV->visited = true;
        s.push_back(SV);
    }
    start->parent = NULL;
    cout<<end->weightedDistance<<", ";
    vector<string> V2;
    while(end!=NULL)
    {
        V2.push_back(end->name);
        end = end->parent;
    }
    for(int t = V2.size()-1; t>=0;t--)
    {
        cout<<V2[t];
        if(t!=0)
        {
            cout<<", ";
        }
    }
    cout<<endl;
    }
}





int main(int argc, const char* argv[]) {
    Graph g;
    int choice = 9;
    string data;
    string dataProcessed;
    map<int, string> columnIndex;
    bool onLabelRow = true;
    ifstream inFile(argv[1]);

     while (getline(inFile, data)) {
            stringstream ss(data);
            int positionWithinRow = 0;
            string currentCity;
            while (getline(ss, dataProcessed, ',')) {
            // first row
                if (onLabelRow) {
                    if (positionWithinRow != 0) {
                        columnIndex[positionWithinRow] = dataProcessed;
                        g.addVertex(dataProcessed);
                        //cout<<"added"<<dataProcessed<<endl;
                    }
                }
                else { // every other row
                    if (positionWithinRow == 0) {
                        currentCity = dataProcessed;
                    } else {
                        if (stoi(dataProcessed) > 0) {
                            g.addEdge(currentCity, columnIndex[positionWithinRow], stoi(dataProcessed));
                        }
                    }
                }
                positionWithinRow++;
            }
        positionWithinRow = 0;
        onLabelRow = false;
      }
    //g.displayEdges();
    do
    {

        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Find shortest weighted path" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;


      if(choice == 1)
      {
          g.displayEdges();
      }
      else if(choice == 2)
      {
          string c1, c2;
          cout<<"Enter first city:"<<endl;
          cin>>c1;
          cout<<"Enter second city:"<<endl;
          cin>>c2;

          if(g.isAdjacent(c1,c2) == true)
          {
              cout<<"True"<<endl;
          }
          else
          {
              cout<<"False"<<endl;
          }
      }
    if(choice == 3)
    {
        cout<<"Goodbye!"<<endl;
        break;
    }

    }while(choice != 3);
    return 0;
}
