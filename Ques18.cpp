/*
 UCS-406 (Data Structure)
 Lab Assignment

 Question:  Write a program to find shortest path between all the source destination pairs (All pairs shortest path Floyd’s algorithm).

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

*/
#include <iostream>
using namespace std;

#define INFINITY 999

class Floyd{

    private:
        int adjMatrix[15][15];                //Adjancecy Matrix
        int dist[15][15];                    //shortest distances between every pair of vertices
        int numOfVertices;                  //Total Number of Vertex in Graph

    public:

        //Constructor to Initialise Values
        Floyd(int V){
            numOfVertices = V;
        }

        //Read the Adjancecy Matrix
        void read(){

            cout<<"Enter the Adjacency Matrix for the Graph"<<endl;
            cout<<"To Enter INFINITY enter "<<INFINITY<<endl;

            for(int i=0; i<numOfVertices; i++){
                cout<<"Enter the Weights for the row "<<i<<" :"<<endl;
                for (int j=0; j<numOfVertices ; j++){
                    cin>>adjMatrix[i][j];
                }
            }
        }

        //Solves the all-pairs shortest path problem using Floyd Warshall algorithm
        void floydWarshell(){

            for (int i = 0; i < numOfVertices; i++)
                for (int j = 0; j < numOfVertices; j++)
                    dist[i][j] = adjMatrix[i][j];

            for(int k = 0; k < numOfVertices; k++ ){
                for(int i = 0; i < numOfVertices; i++ ){
                    for(int j = 0; j < numOfVertices; j++){
                        if(dist[i][j] > dist[i][k] + dist[k][j] ){
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        //Print the Shortest Distance
        void printSolution(){

            cout<<"Following matrix shows the shortest distances between every pair of vertices "<<endl;

            for (int i = 0; i < numOfVertices; i++){
                for (int j = 0; j < numOfVertices; j++){
                    if (dist[i][j] == INFINITY)
                        cout<<"INF\t";
                    else
                        cout<<dist[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

int main(){

    int totNodes,source;
    cout<<"Enter the Number of Verteces of the Graph"<<endl;
    cin>>totNodes;

    Floyd F(totNodes);
    F.read();
    F.floydWarshell();
    F.printSolution();

    return 0;
}

