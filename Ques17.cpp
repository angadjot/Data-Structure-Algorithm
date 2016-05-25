/*
 UCS-406 (Data Structure)
 Lab Assignment

 Question:  Write a program to find shortest path from a given source to all the approachable nodes (Single source shortest path Dijkstra’s algorithm).

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

*/
#include <iostream>
using namespace std;

#define INFINITY 999

class Dijkstra{

    private:
        int adjMatrix[15][15];              //Adjancecy Matrix
        int predecessor[15],distance[15];
        bool visited[15];                   //Keep track of visited node
        int source;                         //Source Vertex
        int numOfVertices;                  //Total Number of Vertex in Graph

    public:

        //Constructor to Initialise Values
        Dijkstra(int V,int src){

            numOfVertices = V;
            source = src;

            for(int i=0 ;i<numOfVertices ;i++){
                visited[i]=false;
                predecessor[i]=-1;
                distance[i]=INFINITY;
            }

            distance[source]=0;

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

        //Get the Closesest Not Visited Node
        int getClosestUnmarkedNode(){

            int minDistance = INFINITY;
            int closestUnmarkedNode;
            for(int i=0;i<numOfVertices;i++){
                if((visited[i]==false) && (minDistance >= distance[i])){
                    minDistance = distance[i];
                    closestUnmarkedNode = i;
                }
            }

            return closestUnmarkedNode;
        }

        //Calculate the Distance to the Closest not visited Node
        void calculateDistance(){

            int closestUnmarkedNode;
            int count = 0;

            while(count < numOfVertices){
                closestUnmarkedNode = getClosestUnmarkedNode();
                visited[closestUnmarkedNode] = true;

                for (int i = 0; i < numOfVertices; i++){
                    if( (visited[i]==false) && (adjMatrix[closestUnmarkedNode][i]>0)){
                        if(distance[i] > distance[closestUnmarkedNode] + adjMatrix[closestUnmarkedNode][i]){
                            distance[i] = distance[closestUnmarkedNode] + adjMatrix[closestUnmarkedNode][i];
                            predecessor[i] = closestUnmarkedNode;
                        }
                    }
                }
                count++;
            }
        }

        //Print the Path and Distance
        void printPath(int node){

            if(node == source)
                cout<<(char)(node + 97);
            else if(predecessor[node] == -1)
                cout<<"No Path from "<<source<<" to "<<(char)(node + 97)<<endl;
            else{
                printPath(predecessor[node]);
                cout<<" -> "<<(char)(node + 97);
            }
        }

        void output(){

            for(int i=0; i<numOfVertices; i++){
                if(i == source)
                    cout<<(char)(source + 97)<<" -> "<<source;
                else
                    printPath(i);
                cout<<" Distance: "<<distance[i]<<endl;
            }
        }


};

int main(){

    int totNodes,source;
    cout<<"Enter the Number of Verteces of the Graph"<<endl;
    cin>>totNodes;

    cout<<"Enter the source vertex\n";
    cin>>source;
    Dijkstra G(totNodes,source);
    G.read();
    G.calculateDistance();
    G.output();

    return 0;
}
