/*
 UCS-406 (Data Structure)
 Lab Assignment

 Question:  Write a program to traverse various nodes of a given graph using stack as an intermediate data structure (DFS).

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

*/
#include <iostream>
#include <stack>
using namespace std;

#define SIZE 10

struct node{
    int vertex;
    node *next;
};

node *array[SIZE];

class Graph{

private:
    int totNodes;   //No. of Nodes in Graph.
    struct node *adj[50];      //For storing Adjacency list of nodes.

public:

    //Graph Constructor
    Graph(int nodes){
        totNodes = nodes;           //Total Number of Nodes in Graph
        for(int i=0;i<totNodes;i++){
            array[i]=newNode(i);
        }
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

                newl=array[neighbour_value];

                if(adj[i]==NULL)
                    adj[i]=last=newl;
                else{
                    last->next = newl;
                    last = newl;
                }
            }
        }
    }

    //DFS Traversal of Graph
    void DFS_traversal(){

        bool visited[totNodes];

        //Initialize all nodes to false visited state.
        for(int i=0;i<totNodes;i++)
            visited[i]=false;

        for(int i=0;i<totNodes;i++){
            if(visited[i]==false)
                DFS_Visit(i,visited);
        }
    }

    //DFS Visit
    void DFS_Visit(int v,bool *visited){

        node *temp;
        int i;
        visited[v] = true;
        cout<<v<<"\t";

        temp = adj[v];
        while(temp!=NULL){
            i=temp->vertex;
            if(visited[i]==false){
                DFS_Visit(i,visited);
            }
            temp=temp->next;
        }

    }
};

int main(){

    int nodes,start_node;
    cout<<"Enter total nodes in graph : ";
    cin>>nodes;
    Graph g(nodes);
    cout<<"*****Depth First Search Traversal*****"<<endl;
    g.createGraph();
    cout<<endl<<"===DFS traversal is as under==="<<endl;
    g.DFS_traversal();
    cout<<endl;
    return 0;
}