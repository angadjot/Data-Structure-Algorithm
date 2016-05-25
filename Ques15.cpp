/*
 UCS-406 (Data Structure)
 Lab Assignment

 Question:  Write a program to find approachable nodes from a given source of a give graph using queue as an intermediate data structure (BFS).

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

*/
#include <iostream>
#include <queue>
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

                newl=new node;
                newl->vertex=neighbour_value;
                newl->next=NULL;

                if(adj[i]==NULL)
                    adj[i]=last=newl;
                else{
                    last->next = newl;
                    last = newl;
                }
            }
        }
    }

    //BFS Traversal of Graph
    void BFS_traversal(int start_node){

        node *temp;
        int N,v,status[totNodes];               //status arr for maintaing status.
        const int ready=1,wait=2,processed=3;   //status of node.
        queue<int > q;


        //Initialize all nodes to ready state.
        for(int i=0;i<totNodes;i++)
            status[i]=ready;

        q.push(start_node);
        status[start_node]=wait;

        while(!q.empty()){

            N = q.front();
            status[N]=processed;
            cout<<N<<"\t";

            temp = adj[N];
            while(temp!=NULL){
                v = temp->vertex;
                if(status[v]==ready){
                    q.push(v);
                    status[v]=wait;
                }
                temp=temp->next;
            }
            q.pop();
        }
    }
};

int main(){

    int nodes,start_node;
    cout<<"Enter total nodes in graph : ";
    cin>>nodes;
    Graph g(nodes);
    cout<<"*****Breadth First Search Traversal*****"<<endl;
    g.createGraph();
    cout<<endl<<"===BFS traversal is as under==="<<endl;
    cout<<"Enter starting node : ";
    cin>>start_node;
    g.BFS_traversal(start_node);
    return 0;
}