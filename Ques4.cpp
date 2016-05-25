/**
 UCS-406 (Data Structure)
 Lab Assignment-2
 101403037_Ques4.cpp
 Purpose: Student Database
 
 a) Write program using functions to implement Mergesort.
 b) Write two different (recursive and non-recursive) functions to implement quick sort.
 c) Write two different (recursive and non-recursive) functions to solve towers of Hanoi.
 
 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2
 
 */

#include<iostream>
using namespace std;

void swap(int i,int j, int *a);
void Merge_Sort(int *a,int first,int last);
void Merge(int *a,int first,int last,int mid);
void display(int *a,int num);
void Quick_Sort(int *arr, int left, int right);
void Hanoi(int n,char beg,char aux,char end);
void printline();

int main(){

    int array[100],size,choice,discs;
    
        do {
        printline();
        cout<<"Select One Option"<<endl;
        printline();
        cout<<"1. Merge Sort"<<endl;
        cout<<"2. Quick Sort"<<endl;
        cout<<"3. Towers of Hanoi"<<endl;
        printline();
        cout<<"Enter a Choice"<<endl;
        cin>>choice;
    } while (choice <0 || choice >3);

    switch (choice) {
        case 1:
            printline();
            cout<<"Enter the Size of the array"<<endl;
            cin>>size;
            printline();
            
            cout<<"Enter "<<size<<" elements in the array"<<endl;
            
            for (int i=0; i<size; i++) {
                cin>>array[i];
            }
            

            Merge_Sort(array,0,size-1);
            display(array,size);
            break;
            
        case 2:
            printline();
            cout<<"Enter the Size of the array"<<endl;
            cin>>size;
            printline();
            
            cout<<"Enter "<<size<<" elements in the array"<<endl;
            
            for (int i=0; i<size; i++) {
                cin>>array[i];
            }
            

            Quick_Sort(array,0,size-1);
            display(array,size);
            break;
            
        case 3:
            
            cout << "Enter the number of discs: " << endl;
            cin >> discs;
            cout<<"\n*****Tower of Hanoi*****\n";
            Hanoi(discs, 'A', 'B', 'C');
            break;
    }
    
    
    return 0;

}

void Merge_Sort(int *a,int first,int last){

    int mid;
    
    if (first<last) {
        mid=(first+last)/2;
        Merge_Sort(a,first,mid);
        Merge_Sort(a,mid+1,last);
        Merge(a,first,last,mid);
    }
}

void swap(int i,int j, int *a){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Merge(int *a,int first,int last,int mid){

    int i=first,j=mid+1,k=first,c[50];
    
    while (i<=mid && j<=last) {
        if (a[i]<a[j]) {
            c[k++]=a[i++];
        }
        else
            c[k++]=a[j++];
    }
    
    while (i<=mid) {
        c[k++]=a[i++];
    }
    
    while (j<=last) {
        c[k++]=a[j++];
    }
    
    for (int i=first; i<k; i++) {
        a[i]=c[i];
    }
}

void display(int *a,int num){
    printline();
    cout<<"Elements of Array:"<<endl;
    for (int i=0; i<num; i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

void printline(){

    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}

void Quick_Sort(int *arr, int left, int right){
    int min = (left+right)/2;
    
    int i = left;
    int j = right;
    int pivot = arr[min];
    
    while(i<j)
    {
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        
        if(i<=j){
            swap(i,j,arr);
            i++;
            j--;
        }
        else{
            if(left<j)
                Quick_Sort(arr, left, j);
            if(i<right)
                Quick_Sort(arr,i,right);
            return;
        }
    }
}

void Hanoi(int n,char beg,char aux,char end){
    
    if (n==1) {
        cout << "Move disc " << n << " from " << beg << " to " << end << endl;
    }
    
    else{
        Hanoi(n-1,beg,end,aux);
        cout << "Move disc " << n << " from " << beg << " to " << end << endl;
        Hanoi(n-1,aux,beg,end);
    }
}