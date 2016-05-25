/**
 UCS-406 (Data Structure)
 Lab Assignment

 Question: Implement Strassen's Matrix Multiplication problem using Divide & Conquer approach.

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

 */
#include<iostream>
using namespace std;

int main(){
    int a[2][2],b[2][2],c[2][2],i,j;
    int m1,m2,m3,m4,m5,m6,m7;

    cout<<"Enter the 4 elements of first matrix: "<<endl;
    for(i=0;i<2;i++)
      for(j=0;j<2;j++)
           cin>>a[i][j];

    cout<<"Enter the 4 elements of Second matrix: "<<endl;
    for(i=0;i<2;i++)
      for(j=0;j<2;j++)
           cin>>b[i][j];

    cout<<"First Matrix :"<<endl;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
           cout<<a[i][j]<<"\t";
        cout<<endl;
    }

    cout<<"Second Matrix :"<<endl;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
           cout<<b[i][j]<<"\t";
        cout<<endl;
    }

    m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
    m2= (a[1][0]+a[1][1])*b[0][0];
    m3= a[0][0]*(b[0][1]-b[1][1]);
    m4= a[1][1]*(b[1][0]-b[0][0]);
    m5= (a[0][0]+a[0][1])*b[1][1];
    m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

    c[0][0]=m1+m4-m5+m7;
    c[0][1]=m3+m5;
    c[1][0]=m2+m4;
    c[1][1]=m1-m2+m3+m6;

    cout<<"After Matrix Multiplication:"<<endl;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
           cout<<c[i][j]<<"\t";
        cout<<endl;
    }

    return 0;

}