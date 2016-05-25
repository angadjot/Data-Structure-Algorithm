/*
 UCS-406 (Data Structure)
 Lab Assignment

 Question:  Write a program to arrange all the nodes of a given graph (Topological sort).

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

*/
#include <iostream>
#include <stack>
using namespace std;

struct node{
    int vertex;
    node *next;
};

class Graph{

private:
    int totNodes;               //No. of Nodes in Graph.
    struct node *adj[50];      //For storing Adjacency list of nodes.

public:

    //Graph Constructor
    Graph(int nodes){
        totNodes = nodes;           //Total Number of Nodes in Graph
    }

    //Create new Node for Graph
    node* newNode(int value){

        node* newNode = new node;
        newNode->vertex = value;
        newNode->next = NULL;

        return newNode;
    }

    //Create Graph
    void createGraph(){

        node *newl,*last;
        int neighbours,neighbour_value;

        for(int i=0;i<totNodes;i++){

            last=NULL;
            cout<<endl<<"Enter no. of nodes in the adjacency list of node "<<i<<endl;
            cout<<"--> That is Total Neighbours of "<<i<<" : ";
            cin>>neighbours;

            for(int j=0;j<neighbours;j++){

                cout<<"Enter neighbour #"<<j<<" : ";
                cin>>neighbour_value;

                newl=newNode(neighbour_value);

                if(adj[i]==NULL)
                    adj[i]=last=newl;
                else{
                    last->next = newl;
                    last = newl;
                }
            }
        }
    }

    //Topological Sort of Graph
    void Topological_Sort(){

        bool visited[totNodes];
        stack<int> s;
        //Initialize all nodes to false visited state.
        for(int i=0;i<totNodes;i++)
            visited[i]=false;

        for(int i=0;i<totNodes;i++){
            if(visited[i]==false)
                Topological_Visit(i,visited,s);
        }

        while(!s.empty()){
            cout<<s.top()<<"\t";
            s.pop();
        }
    }

    //Topological Visit
    void Topological_Visit(int v,bool *visited,stack<int> &s){

        node *temp;
        int i;
        visited[v] = true;

        temp = adj[v];
        while(temp!=NULL){
            i=temp->vertex;
            if(visited[i]==false){
                Topological_Visit(i,visited,s);
            }
            temp=temp->next;
        }
        s.push(v);

    }
};

int main(){

    int nodes,start_node;
    cout<<"Enter total nodes in graph : ";
    cin>>nodes;
    Graph g(nodes);
    cout<<"Create New Graph"<<endl;
    g.createGraph();
    cout<<endl<<"Topological Sort :"<<endl;
    g.Topological_Sort();
    cout<<endl;
    return 0;
}