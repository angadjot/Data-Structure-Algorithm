/**
 UCS-406 (Data Structure)
 Lab Assignment-2
 101403037_Ques3.cpp
 Purpose: Student Database
 
 Write a program to perform following operations on stack.
 a) Create functions for push and pop operations of stack.
 b) Write a function to convert an infix expression to postfix expression. Pass a one dimensional character array P to the function as input (infix exp) and return character array Q (postfix exp). Test your program for following input
 P : (A+(B/C)*D+E)*F%G
 c) Write a function for the evaluation of a given postfix expression. For testing pass the postfix expression Q of part b and supply following set of values. A = 90, B = 50, C = 2, D = 3, E = 1, F = 2, G = 5
 
 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2
 
 */
#include<iostream>
#include<string.h>
using namespace std;

bool IsOperator(char C);
bool IsOperand(char C);
void printline();
int precedence(char operand);

class IntStack{
    
    private:
        float array[100];
        int top;
        int maxlen;
        
    public:
        IntStack(){
            top=0;
            maxlen=50;
        }
        void push(float num){
            if (top==maxlen) {
                cout<<"Stack Overflow"<<endl;
            }
            else
                array[top++]=num;
        }
        
        float pop(){
            if (top == 0) {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else
                return array[--top];
        }
        
        void display(){
            if (top<0) {
                cout<<"Stack Underflow"<<endl;
            }
            else{
                cout<<"Stack : ";
                for (int i=top-1; i>=0; i--) {
                    cout<<array[i]<<"\t";
                }
            }
        }
        
};


class Stack{
    
private:
    char stack_array[50];
    int top;
    
public:
    
    
    Stack(){
        top=0;
    }
    
    void push(char val){
        if (top==49) {
            cout<<"Stack Full"<<endl;
        }
        else{
            stack_array[top++]=val;
        }
    }
    
    char pop(){
        if (top==0) {
            cout<<"Stack Underflow"<<endl;
            return('#');
        }
        else{
            return (stack_array[--top]);
        }
    }
    
    int empty(){
        if(top==-1)
            return(1);
        else
            return(0);
    }
    
    void display(){
        
        if (top==-1) {
            cout<<"Stack Underflow"<<endl;
        }
        else{
            cout<<"Stack : ";
            for (int i=0; i<top; i++) {
                cout<<stack_array[i]<<"\t";
            }
        }
        cout<<endl;
    }
};

class Expression{

private:
    char infix[100],Postfix[100];
    
public:
    
    void readExp(){
        cout<<"Enter the Mathematical Expression to be Evaluated"<<endl;
        cout<<"The Expression should contain variables not numbers"<<endl;
        cin>>infix;
    }
    
    void ConvertToPostfix(){
        
        Stack stack;
        long len;
        int p=0;
        char entry1,entry2;
        stack.push('(');
        len=strlen(infix);
        infix[len]=')';
        infix[++len]='\0';
        
        for (int i=0; i<len; i++) {
            
            entry1=infix[i];
            switch (entry1) {
                case '(':
                    stack.push(entry1);
                    break;
                    
                case ')':
                    while((entry2=stack.pop()) !='('){
                        Postfix[p++]=entry2;
                    }
                    break;
                    
                case '%':
                case '/':
                case '*':
                case '+':
                case '-':
                    
                    entry2=stack.pop();
                    if (entry2 == '%' || entry2 == '/' || entry2 == '*' || entry2 == '+' || entry2 == '-') {
                        if(precedence(entry1)>=precedence(entry2)){
                            stack.push(entry2);
                            stack.push(entry1);
                        }
                        
                        else if(precedence(entry1)<precedence(entry2)){
                            
                            while (precedence(entry1)<precedence(entry2)) {
                                Postfix[p++]=entry2;
                                entry2=stack.pop();
                                
                                if (entry2=='(') {
                                    stack.push(entry2);
                                    stack.push(entry1);
                                    break;
                                }
                                else if(precedence(entry1)>=precedence(entry2)){
                                    stack.push(entry2);
                                    stack.push(entry1);
                                    break;
                                }
                            }
                        }

                    }
                    else if (entry2=='(') {
                        stack.push(entry2);
                        stack.push(entry1);
                    }

                    
                    break;

                    
                default:
                    Postfix[p++]=entry1;
                    break;
            }
    
        }
        
        Postfix[p]='\0';
        cout<<"Postfix Expression : "<<Postfix<<endl;
        
    }
    
    void CalculatePostfix(){
        
        IntStack s;
        char temp;
        float val,prev,next,result = 0.0;
        
        for (int i=0; Postfix[i]!='\0'; i++) {
            temp=Postfix[i];
            
            if (IsOperand(temp)) {
                cout<<"Enter the Value of variable "<<temp<<" :"<<endl;
                cin>>val;
                
                s.push(val);
            }
            
            else if(IsOperator(temp)){
                prev=s.pop();
                next=s.pop();
                
                switch (temp) {
                    
                    case '/':
                        result = next / prev;
                        break;
                    case '*':
                        result = next * prev;
                        break;
                    case '+':
                        result = next + prev;
                        break;
                        
                    case '-':
                        result = next - prev;
                        break;
                        
                    default:
                        break;
                }
                s.push(result);
            }
        }
    
        cout<<"Result :"<<s.pop()<<endl;
        
    }

    
    int precedence(char operand){
        
        switch (operand) {
            case '%':
                return 10;
                break;
            case '/':
                return 8;
                break;
                
            case '*':
                return 6;
                break;
                
            case '+':
                return 4;
                break;
                
            case '-':
                return 2;
                break;
                
            default:
                return -1;
                break;
        }
    }
    
};

int main(){
    
    int choice;
    IntStack s;
    
    do {
        printline();
        cout<<"Select One Option"<<endl;
        printline();
        cout<<"1. Push and Pop operations of Stack"<<endl;
        cout<<"2. Convert an Infix Expression to Postfix Expression."<<endl;
        printline();
        cout<<"Enter a Choice"<<endl;
        cin>>choice;
    } while (choice <0 || choice >2);
    
    switch (choice) {
        
        case 1:
            int choice1,number;
            
            for (int i=1; i>0; i++) {
                cout<<endl;
                do{
                    printline();
                    cout<<"Select One Option:"<<endl;
                    printline();
                    cout<<"1. Push Element to Stack"<<endl;
                    cout<<"2. Pop Element From Stack"<<endl;
                    cout<<"3. Display the whole Stack"<<endl;
                    cout<<"4. Exit"<<endl;
                    printline();
                    cin>>choice1;
                }while (choice1<0 || choice1>5);
                
                switch (choice1) {
                    case 1:
                        cout<<"Enter the element to push in the stack"<<endl;
                        cin>>number;
                        s.push(number);
                        break;
                        
                    case 2:
                        cout<<"Poping the Element : ";
                        number=s.pop();
                        cout<<number;
                        break;
                        
                    case 3:
                        s.display();
                        break;
                        
                    case 4:
                        return 0;
                }
            }

            
        case 2:
            Expression expr;
            expr.readExp();
            expr.ConvertToPostfix();
            expr.CalculatePostfix();
            break;
    }
    
    
	return(0);
}

void printline(){
    
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
    
}

bool IsOperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    
    return false;
}
