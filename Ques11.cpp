/*
 UCS-406 (Data Structure)
 Lab Assignment

 Question:  Implement following problems using Greedy Approach:
                a)  Partial knapsack
                b)  Huffman compression

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

*/
#include<iostream>
using namespace std;

void printline();
void knapsack(float value[],float weight[],float max,float n);

int main(){

    int choice;
    float value[50],weight[50],max,n;

    do{
        printline();
        cout<<"Select One Option"<<endl;
        printline();
        cout<<"1. Partial Knapsack"<<endl;
        cout<<"2. Huffman Compression"<<endl;
        printline();
        cout<<"Enter your Choice"<<endl;
        cin>>choice;
    }while(choice <0 || choice > 3);

    switch(choice){

        case 1:
            cout<<"Enter the Maximum Capacity of Knapsack"<<endl;
            cin>>max;

            cout<<"Enter the Number of Item "<<endl;
            cin>>n;

            cout<<"Enter the values of item,according to per unit value in descending order"<<endl;
            for(int i=0;i<n;i++){
                cin>>value[i];
            }

            cout<<"Enter the value of weight according to value of item"<<endl;
            for(int i=0;i<n;i++){
                cin>>weight[i];
            }

            cout<<"Elements :"<<endl;
            for(int i=0;i<n;i++){
                cout<<"Value "<<value[i];
                cout<<"\t Weight "<<weight[i]<<endl;
            }

            knapsack(value,weight,max,n);
            break;
        case 2:

            break;
    }
    return 0;

}

void printline(){

    for(int i=0;i<50;i++)
        cout<<"-";
    cout<<endl;
}

void knapsack(float value[],float weight[],float max,float n){
    float current=0,rem,currentval=0;
    int i=0;

    for(i=0;((current<=max)&& (weight[i]<=max-current));i++){
        current=current+weight[i];
        currentval=currentval+value[i];
    }
    rem=max-current;

    if(current<max){
        current =current+rem;
        currentval=currentval+((rem * value[i])/weight[i] );
    }

   cout<<"Maximum profit is: "<<currentval<<endl;
   cout<<"Current weight is: "<<current<<endl;

}