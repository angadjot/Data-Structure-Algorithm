/**
 UCS-406 (Data Structure)
 Lab Assignment-1
 101403037_Ques2.cpp
 Purpose: Student Database
 
 Create a structure/class for a group of 50 students holding data for their Regn no., Name, Branch, CGPA
 a) Call linear search function to display data of student with a particular Regn no..
 b) Call bubble sort function to arrange data of students according to Regn no.
 c) Apply binary search on the above output (part b) to display data of a student with a particular Regn no. d) Use and modify Insertion sort logic to arrange data of students in descending order of CGPA.
 
 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2
 
 */
#include<iostream>
using namespace std;

void printline();

class Student{
	
	private:
		int regno;
		float CGPA;
		string Name,Branch;
		
	public:
		void get_data(){
			cout<<"Enter the Reg. No. of the Student"<<endl;
			cin>>regno;
			cout<<"Enter the Name of the Student"<<endl;
			cin>>Name;
			cout<<"Enter the Branch of the Student"<<endl;
			cin>>Branch;
			cout<<"Enter the CGPA of the Student"<<endl;
			cin>>CGPA;			
		}
		
		void display(){
			cout<<"Student's Detail: "<<endl;
            cout<<"Reg No :"<<regno<<endl;
            cout<<"Name : "<<Name<<endl;
            cout<<"Branch : "<<Branch<<endl;
            cout<<"CGPA : "<<CGPA<<endl;
        }
    
    friend void linear_search(Student stud[],int size);
    friend void bubble_sort(Student stud[],int size);
    friend void binary_search(Student stud[],int size);
    friend void insertion_sort(Student stud[],int size);

};

int main(){

    int num,choice;
    Student std[100];
    cout<<"Enter the Number of Students"<<endl;
    cin>>num;
    
    
    for (int i=0; i<num; i++) {
        cout<<"For Student "<<i+1<<" :"<<endl;
        std[i].get_data();
    }
    
    cout<<"All Students Details : "<<endl;
    for (int i=0; i<num; i++) {
        std[i].display();
    }
    
    do{
        printline();
        cout<<"Select One Option"<<endl;
        printline();
        cout<<"1. Linear Serch Student Detail Using Reg No."<<endl;
        cout<<"2. Arrange Student Detail According to Reg No."<<endl;
        cout<<"3. Binary Serch Student Detail Using Reg No."<<endl;
        cout<<"4. Insertion Sort to sort Student Detail Using CGPA"<<endl;
        printline();
        cout<<"Enter the Choice"<<endl;
        printline();
        cin>>choice;
    }while(choice<1||choice>4);
    
    switch (choice) {
            
        case 1:
            linear_search(std,num);
            break;
            
        case 2:
            bubble_sort(std,num);
            cout<<"All Students Details : "<<endl;
            for (int i=0; i<num; i++) {
                std[i].display();
            }
            break;
            
        case 3:
            binary_search(std,num);
            break;
            
        case 4:
            insertion_sort(std,num);
            cout<<"All Students Details : "<<endl;
            for (int i=0; i<num; i++) {
                std[i].display();
            }
            break;
    }
    return(0);
}

void linear_search(Student stud[],int size){
    
    int search,index=0;
    
    cout<<"Enter the Reg No. to Search"<<endl;
    cin>>search;
    
    for(int i=0;i<size;i++){
        if(stud[i].regno==search){
            index=i;
            break;
        }
    }
    stud[index].display();
}

void bubble_sort(Student stud[],int size){
    int num=size,flag;
    Student temp;
    for (int i=0; i<size-1; i++) {
        flag=0;
        for (int j=i; j<--num; j++) {
            if(stud[j+1].regno<stud[j].regno){
                temp=stud[j+1];
                stud[j+1]=stud[j];
                stud[j]=temp;
                flag=1;
            }
        }
        if(flag!=0){
            break;
        }
    }
}

void binary_search(Student stud[],int size){
    int search,index=0,first=0,last=size-1,mid;
    mid=(first+last)/2;
    cout<<"Enter the Red No. to Search"<<endl;
    cin>>search;
    
    while (first<=last) {
        if (stud[mid].regno==search) {
            index=mid;
            break;
        }
        else if(stud[mid].regno<mid){
            last=mid-1;
        }
        else
            first=mid+1;
    }
    
    if(first>last){
        cout<<"Reg No. "<<search<<" not present in the Database"<<endl;
    }
    stud[index].display();
    
}

void insertion_sort(Student stud[],int size){
    
    Student temp,temp1;
    
    for(int i=1;i<size;i++){
        temp.CGPA=stud[i].CGPA;
        temp1=stud[i];
        int j;
        for(j=i-1;temp.CGPA>stud[j].CGPA && j>=0;j--){
            stud[j+1]=stud[j];
        }
        stud[j+1]=temp1;
    }
}

void printline(){
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}
