/**
    UCS-406 (Data Structure)
    Lab Assignment-1
    101403037_Ques1.cpp
    Purpose: Sorting Algorithms

 Implement the following programs in C/C++/Python/Java using functions:
 a) Insertion Sort
 b) Bubble Sort
 c) Selection Sort
 d) Linear Search
 e) Binary Search
 f) Shell sort.
 Display the total number of comparisons and swaps made by each searching/sorting function for the given input N.

    Name : Angadjot Singh Bhasin
    Roll No. : 101403037
    Group : COE2

*/
#include<iostream>
using namespace std;

void get_array(int *array1,int n);
void display(int *arr,int n);
void insertion_sort(int *arr,int n);
void bubble_sort(int *arr,int n);
void selection_sort(int *arr,int n);
void shell_sort(int *arr,int n);
void linear_search(int *arr,int n);
void binary_search(int *arr,int n);
void printline();

int main(){

	int array[100],choice,size;

	do{
		printline();
		cout<<"Select One Option from the List"<<endl;
		printline();
		cout<<"1. Insertion Sort"<<endl;
		cout<<"2. Bubble Sort"<<endl;
		cout<<"3. Selection Sort"<<endl;
		cout<<"4. Shell Sort"<<endl;
		cout<<"5. Linear Search"<<endl;
		cout<<"6. Binary Search"<<endl;
		printline();
		cout<<"Enter your choice"<<endl;
		printline();
		cin>>choice;
	}while(choice<1||choice>6);

	switch(choice){

		case 1:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size;
			get_array(array,size);
			insertion_sort(array,size);
			display(array,size);
			break;

		case 2:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size;
			get_array(array,size);
			bubble_sort(array,size);
			display(array,size);
			break;

		case 3:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size;
			get_array(array,size);
			selection_sort(array,size);
			display(array,size);
			break;

        case 4:
            printline();
            cout<<"Enter the size of array"<<endl;
            cin>>size;
            get_array(array,size);
            shell_sort(array,size);
            display(array,size);
            break;

		case 5:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size;
			get_array(array,size);
			linear_search(array,size);
			display(array,size);
			break;

		case 6:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size;
			get_array(array,size);
			bubble_sort(array,size);
			display(array,size);
			binary_search(array,size);
			display(array,size);
			break;
	}

	return(0);

}

void get_array(int *array1,int n){

	printline();
	cout<<"Enter "<<n<<" elemets in the array"<<endl;
	printline();
	for(int i=0;i<n;i++){
		cin>>array1[i];
	}
}

void display(int *arr,int n){

	printline();
	cout<<"Elements of Array :"<<endl;
	printline();

	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}

	cout<<endl;
	printline();
}

void insertion_sort(int *arr,int n){

	int temp,j=0,swaps=0;
	for(int i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(temp<arr[j] && j>=0){
				arr[j+1]=arr[j];
                swaps++;
				--j;
		}
		arr[j+1]=temp;
	}
    cout<<"Total Number of Swaps: "<<swaps<<endl;

}

void bubble_sort(int *arr,int n){

	int temp,flag,swaps=0;

	for(int i=0;i<n-1;i++){
		flag=0;

		for(int j=0;j<n-i-1;j++){
			if(arr[j+1]<arr[j]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
				flag=1;
                swaps++;
			}
		}
		if(flag==0)
			break;
	}
    cout<<"Total Number of Swaps: "<<swaps<<endl;
}

void selection_sort(int *arr,int n){

	int temp,min,swaps=0;

	for(int i=0;i<n-1;i++){
		min=i;

		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min = j;
			}
		}

		if(min!=i){
			temp = arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
            swaps++;
		}

	}
    cout<<"Total Number of Swaps: "<<swaps<<endl;
}

void shell_sort(int *arr,int num){
    int temp,swaps=0;

    for(int i=num/2;i>0;i=i/2){
        for(int j=i;j<num;j++){
            for(int k=j-i;k>=0;k=k-i){
                if(arr[k+i]<=arr[k]){
                    temp=arr[k+i];
                    arr[k+i]=arr[k];
                    arr[k]=temp;
                    swaps++;
                }
            }
        }
    }
    cout<<"Total Number of Swaps: "<<swaps<<endl;
}

void linear_search(int *arr,int n){

	int element;

	cout<<"Enter the element to Search"<<endl;
	cin>>element;

	for(int i=0;i<n;i++){
		if(arr[i]==element){
			cout<<"Element "<<element<<" is present in the array"<<endl;
			break;
		}
	}

}

void binary_search(int *arr,int n){

	int search,first=0,last=n-1,mid;
	cout<<"Enter the element to Search"<<endl;
	cin>>search;
	while(first<=last){
        mid=(first+last)/2;
		if(arr[mid]==search){
			cout<<"Element "<<search<<" is present in the array"<<endl;
			break;
		}

		else if(arr[mid]<search){
			last = mid -1;
		}
		else if(arr[mid]>search){
			first = mid+1;
		}
	}
    if(first>last){
        cout<<"Element "<<search<<" is not present in the array"<<endl;
    }

}

void printline(){
	for(int i=0;i<50;i++){
		cout<<"-";
	}
	cout<<endl;
}
