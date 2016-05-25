/*
 UCS-406 (Data Structure)
 Lab Assignment
 
 Question:  Write a program to implement concept of hashing. Design a menu based interface to call different functions for collision handling techniques. 
 
 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2
 
 */
#include <iostream>
using namespace std;

#define SIZE 40

void printline();

class Hash_Table{

private:
    int hash_pos;
    int array[SIZE];

public:

    Hash_Table(){
        for(int i=0 ;i<=SIZE;i++)
            array[i] = '*' ;
    }

    int Hash(int key){
        return key%100;
    }

    int linearProbing(int key,int i){
        return (key+i)%100;
    }

    int quadraticProbing(int key,int i){
        return (key+(i*i))%100;
    }

    void reHash(int data){

        int Choice,count=0;

    label:
        printline();
        cout<<"Collision Occured"<<endl;
        printline();
        cout<<"Choice One of The Option for Collision Handling"<<endl;
        printline();
        cout<<"1. Linear Probing"<<endl;
        cout<<"2. Quadratic Probing"<<endl;
        printline();
        cout<<"Enter the Choice : ";
        cin>>Choice;

        switch(Choice){
            case 1:
                printline();
                cout<<"Linear Probing"<<endl;
                printline();
                while(array[hash_pos] != '*'){
                    hash_pos=linearProbing(data,count);
                    count++;

                    if(count>=SIZE){
                        cout<<"Memory Full!!No space is avaible for storage"<<endl;
                        break;
                    }
                }

                if(array[hash_pos] == '*'){
                    array[hash_pos] = data;
                }
                cout<<"Data is stored at index "<<hash_pos<<endl;
                break;

            case 2:
                printline();
                cout<<"Quadratic Probing"<<endl;
                printline();
                while(array[hash_pos] != '*'){
                    hash_pos=quadraticProbing(data,count);
                    count++;

                    if(count>=SIZE){
                        cout<<"Memory Full!!No space is avaible for storage"<<endl;
                        break;
                    }
                }

                if(array[hash_pos] == '*'){
                    array[hash_pos] = data;
                }
                cout<<"Data is stored at index "<<hash_pos<<endl;
                break;

            default:
                cout<<"Wrong Option Entered"<<endl;
                goto label;
        }
    }

    void insert(){

        int data;

        cout<<"Enter the data to insert: ";
        cin>>data;

        hash_pos = Hash(data);

        if(hash_pos >= SIZE){
            hash_pos = 0;
        }

        if(array[hash_pos] == '*'){
            array[hash_pos] = data;
            cout<<"Data is stored at index "<<hash_pos<<endl;
            return ;
        }
        else{
            reHash(data);
        }
    }

    void search(){

        int key,i;
        bool isFound = false;

        cout<<"Enter the key to search: ";
        cin>>key;

        for(i=0;i<=SIZE;i++){

            if(array[i] == key){
                isFound = true;
                break;
            }
        }

        if(isFound)
            cout<<"The key is found at index "<< i <<endl;
        else
            cout<<"No record found!!"<<endl;
    }

    void Delete(){

        int key,i;
        bool isFound = false;

        cout<<"Enter the key to search: ";
        cin>>key;

        for(i=0;i<=SIZE;i++){

            if(array[i] == key){
                isFound = true;
                break;
            }
        }

        if(isFound){
            array[i] = '*';
            cout<<"The key is deleted"<<endl;
        }
        else{
            cout<<"No Key is Found!!"<<endl;
        }

    }

    void display(){
        for(int i=0;i<SIZE;i++){
            cout<<array[i]<<"\t";
        }
        cout<<endl;
    }
};

int main(){

    Hash_Table h;
    int Choice;
    bool go_on = true;
    while(go_on){

        do{
            printline();
            cout<<"Select One Option"<<endl;
            printline();
            cout<<"1. Insert"<<endl;
            cout<<"2. Search"<<endl;
            cout<<"3. Delete"<<endl;
            cout<<"4. Display"<<endl;
            cout<<"5. Exit"<<endl;
            printline();
            cout<<"Enter the Choice : ";
            cin>>Choice;
        }while(Choice < 0 || Choice > 5);

        switch(Choice){
           case 1:
                h.insert();
                break;

            case 2:
                h.search();
                break;

            case 3:
                h.Delete();
                break;

            case 4:
                h.display();
                break;

            case 5:
                exit(0);

        }
    }
    return 0;
}

void printline(){

    for(int i=0; i<50; i++){
        cout<<"-";
    }
    cout<<endl;
}
