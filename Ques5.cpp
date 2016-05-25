/**
 UCS-406 (Data Structure)
 Lab Assignment-3
 101403037_Ques5.cpp
 
 Question: Write a program using functions for implementation of circular Queue.
 
 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2
 
*/

#include<iostream>
using namespace std;

void printline();

class Circular_Queue{
    
    int cq_array[100];
    int front,rear,max;
    
public:
    Circular_Queue(int len){
        front=rear=-1;
        max=len;
    }
    
    void enqueue(int item){
        
        if ((front == 0 && rear == max-1) || (front == rear+1)) {
            cout<<"Queue Overflow"<<endl;
            return ;
        }
        
        if (front == -1) {
            front = rear = 0;
        }
        
        else{
            if (rear == max-1) {
                rear = 0;
            }
            else{
                rear = rear + 1;
            }
        }
        
        cq_array[rear]=item;
    }
    
    void dequeue(){
       
        if (front == -1 && rear == -1) {
            cout<<"Queue Underflow"<<endl;
            return ;
        }
        
        cout<<"Element Deleted From the Queue : "<<cq_array[front]<<endl;
        
        if (front == rear) {
            front =rear=-1;
        }
        
        else{
            if (front == max-1 ) {
                front =0;
            }
            else{
                front =front +1;
            }
        }
        
    }
    
    void display(){
        
        int front_pos=front,rear_pos=rear;
        
        if (front == -1) {
            cout<<"Queue Underflow"<<endl;
            return ;
        }
        
        cout<<"Queue Elements : "<<endl;
        if (front_pos <= rear_pos ) {
            while (front_pos<=rear_pos) {
                cout<<cq_array[front_pos++]<<"\t";
            }
            cout<<endl;
        }
        else{
            while (front_pos<=max-1) {
                cout<<cq_array[front_pos++]<<"\t";
            }
            cout<<endl;
            
            front_pos=0;
            while (front_pos<=rear_pos) {
                cout<<cq_array[front_pos++]<<"\t";
            }
            cout<<endl;
        }
    }
};
int main(){
    
    int choice,element,size;
    cout<<"Enter the Length of the Queue"<<endl;
    cin>>size;
    Circular_Queue cq(size);
    
    for (int i=5; i>1; i++) {
        
        do {
            printline();
            cout<<"Choose One Option"<<endl;
            printline();
            cout<<"1. Insert the Element in the Queue (Enqueue)"<<endl;
            cout<<"2. Delete the Element in the Queue (Dequeue)"<<endl;
            cout<<"3. Display the Queue"<<endl;
            cout<<"4. Exit"<<endl;
            printline();
            cout<<"Enter the Choice"<<endl;
            cin>>choice;
            
        } while (choice<0 || choice>5);
        
        switch (choice) {
            case 1:
                cout<<"Enter the Element to be inserted"<<endl;
                cin>>element;
                cq.enqueue(element);
                break;
                
            case 2:
                cq.dequeue();
                break;
                
            case 3:
                cq.display();
                break;
                
            case 4:
                return 0;
        }
        
    }

}

void printline(){
    
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}