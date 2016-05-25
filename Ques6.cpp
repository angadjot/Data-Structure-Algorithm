/**
 UCS-406 (Data Structure)
 Lab Assignment-3
 101403037_Ques6.cpp

 Question: Write a program to perform following operations on Link List
 a) Insertion
    at the beginning
    at the end
    at the given location
    in the sorted list
 b) Deletion
    of first node
    of last node
    of given item of node
    of given item from sorted list
 c) Given a list, split it into two sublists — one for the front half, and one for the back half. If the number of elements is odd, the extra element should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}.
 d) Given two one-way-link lists A and B. Sort them independently and then Merge as list C.
 e) Two way link list insertion and Deletion
 f) Header link list insertion and deletion

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

 */

#include<iostream>
using namespace std;

void printline(); //Function to print a line

//Single Link List Node
struct node{
    int val;
    node *next;
    node *prev;
};

//Single Link List Class
class Linked_List{

private:

    node *header; //Header Node

public:
    node *start;  //Start node Pointer for Single Link List
    //Function to Create a New Node
    node* Create_Node(int value){

        struct node *temp=new node;

        if (temp == NULL) {
            cout<<"Memory Not Allocated"<<endl;
            return 0;
        }
        else{
            temp->val=value;
            temp->next=NULL;
            return temp;
        }
    }

    //Function to Insert a Node in the Beginning
    void insert_begin(){

        int value;
        cout<<"Enter the value to be inserted: "<<endl;
        cin>>value;
        node *temp,*p;
        temp = Create_Node(value);

        if (start == NULL) {
			start       = temp;
			start->next = NULL;
        }
        else{
			p           =start;
			start       =temp;
			start->next =p;
        }
        cout<<"Element Inserted at Beginning"<<endl;
    }

    //Function to Insert a Node in the End
    void insert_end(){

        int value;
        cout<<"Enter the value to be inserted: "<<endl;
        cin>>value;
        node *temp,*s;
        temp=Create_Node(value);
        if (start==NULL) {
            start       = temp;
            start->next = NULL;
        }
        else{
            s = start;
            while (s->next != NULL) {
                s = s->next;
            }
            temp->next=NULL;
            s->next=temp;
        }
    }

    //Function to insert a Node at a particular Position
    void insert_pos(){
        int value,pos,counter=0;
        cout<<"Enter the Position to insert the New Node"<<endl;
        cin>>pos;
        cout<<"Enter the value to be inserted: "<<endl;
        cin>>value;
        node *temp,*s,*ptr=new node;

        temp=Create_Node(value);

        s=start;
        while (s!=NULL) {
            s=s->next;
            counter++;
        }
        if (pos==1) {
            if (start == NULL) {
                start = temp;
                start->next=NULL;
            }
            else{
                ptr=start;
                start=temp;
                start->next = ptr;
            }
        }

        else if(pos>1 && pos<=counter){
            s=start;

            for (int i=1; i<pos; i++) {
                ptr = s;
                s=s->next;
            }
            ptr->next = temp;
            temp->next =s;
        }

        else
            cout<<"Position Out of Range"<<endl;
    }

    //Function to Sort the List
    void sort_list(){

        node *ptr,*s;
        int temp;

        if (start == NULL) {
            cout<<"List is Empty"<<endl;
            return ;
        }

        ptr = start;

        while (ptr != NULL) {
            for (s=ptr->next; s!= NULL; s=s->next) {
                if (ptr->val > s->val) {
                    temp=ptr->val;
                    ptr->val=s->val;
                    s->val=temp;
                }
            }
            ptr=ptr->next;
        }

    }

    //Function to Delete a Node in the Beginning
    void delete_begin(){

        node *s;
        s=start;
        if (start==NULL) {
            cout<<"List is Empty"<<endl;
        }

        else{
            start=s->next;
            cout<<"Element Deleted"<<endl;
        }
    }

    //Function to Delete a Node in the End
    void delete_end(){
        node *s,*ptr = nullptr;

        s=start;
        while (s->next!= NULL) {
            ptr=s;
            s=s->next;
        }
        ptr->next= NULL;
        cout<<"Element Deleted"<<endl;
    }

    //Function to Delete a Node at a particular Position
    void delete_pos(){
        int pos,counter=0;

        if (start==NULL) {
            cout<<"List is Empty"<<endl;
            return ;
        }

        node *s,*ptr = nullptr;

        cout<<"Enter the position to be deleted"<<endl;
        cin>>pos;
        s=start;

        if (pos==1) {
            start=s->next;
        }

        else{
            while (s!=NULL) {
                s=s->next;
                counter++;
            }

            if (pos>0 && pos<=counter) {
                s=start;

                for (int i=0; i<pos-1; i++) {
                    ptr=s;
                    s=s->next;
                }
                ptr->next=s->next;
            }
            else{
                cout<<"Position out of range"<<endl;
            }
        }

        cout<<"Element Deleted"<<endl;
    }

    //Split a list in Half
    void FrontBackSplit(){

        node *s,*start1,*start2;
        int counter=0,mid;

        if (start == NULL) {
            cout<<"List is Empty"<<endl;
            return ;
        }

        s=start;

        while (s!=NULL) {
            s=s->next;
            counter++;
        }

        if (counter%2 == 0) {
            mid = counter/2;
        }
        else{
            mid = (counter/2) +1;
        }

        s=start;
        start1=start;
        for (int pos=0; pos<mid-1; pos++) {
            s=s->next;
        }

        start2=s->next;
        s->next=NULL;

        printline();
        cout<<"Splitted List :"<<endl;
        printline();
        cout<<"First Half List : ";

        s=start1;
        while (s != NULL) {
            cout<<s->val<<"\t";
            s=s->next;
        }
        cout<<"NULL"<<endl;
        s=start2;
        printline();
        cout<<"Second Half List : ";
        while (s != NULL) {
            cout<<s->val<<"\t";
            s=s->next;
        }
        cout<<"NULL"<<endl;

    }
    //Merge 2 list
    void Merge_List(){

        char choice;
        int count=0,j=0;
        node *start1,*start2,*temp;
        printline();
        cout<<"Create Two Lists to merge"<<endl;
        printline();
        cout<<"Enter the Elements of List 1"<<endl;

        do {
            insert_end();
            cout<<"Do you want to Continue Adding Elements to List 1 (y/n)"<<endl;
            cin>>choice;
            count++;
        } while (choice == 'y' || choice == 'Y');
        sort_list();

        temp=start1=start;

        printline();
        cout<<"Enter the Elements of List 2"<<endl;

        do {
            insert_end();
            cout<<"Do you want to Continue Adding Elements to List 2 (y/n)"<<endl;
            cin>>choice;
            count++;
        } while (choice == 'y' || choice == 'Y');
        sort_list();
        start2=start;

        while (start1->next!=NULL) {
            start1=start1->next;
        }
        start1->next=start2;

        cout<<"Merged List :"<<endl;
        while (temp != NULL && j!=count) {
            cout<<temp->val<<"\t";
            temp=temp->next;
            j++;
        }
        cout<<"NULL"<<endl;
    }

    //Display the List
    void display(){
        node *temp;
        if (start == NULL) {
            cout<<"The List is Empty"<<endl;
        }
        temp=start;
        cout<<"Element of List are: "<<endl;
        while (temp != NULL) {
            cout<<temp->val<<"\t";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void header_insert_end(){

        int value;
        cout<<"Enter the value to be inserted: "<<endl;
        cin>>value;
        node *temp,*s;

        temp = Create_Node(value);

        node *t1=new node;

        t1->val=0;
        t1->next=temp;
        s = header;
        if(header == NULL){
            header = t1;
        }
        else{
            while(s->next!=NULL){
                s=s->next;
            }
            s->next=temp;
            temp->next=NULL;
        }
    }

    void header_delete_end(){
        node *s,*ptr = nullptr;

        s=header;
        while (s->next!= NULL) {
            ptr=s;
            s=s->next;
        }
        ptr->next= NULL;
        cout<<"Element Deleted"<<endl;
    }

    void header_display(){

        node *temp;
        if (header == NULL) {
            cout<<"The List is Empty"<<endl;
        }
        temp=header;
        cout<<"Element of List are: "<<endl;
        while (temp != NULL) {
            cout<<temp->val<<"\t";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void reverse_itr(node *start){

        if(start == NULL){
            cout<<"Linked List Empty"<<endl;
            return;
        }
        node *prev=NULL;
        node *current=start;
        node * next=NULL;
        while(current != NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }

        start=prev;
    }

    void reverse_rec(node *p){

        if(p==NULL){
            cout<<"Linked List Empty"<<endl;
            return;
        }

        if(p->next ==  NULL){
            start = p;
            return;
        }
        reverse_rec(p->next);
        node *q=p->next;
        q->next=p;
        p->next=NULL;

    }

};

//Class of Two Way Link list
class Double_Linked_List {

private:

    node *start;

public:

    //Two Way Link List Function to create a Node
    node* Create_Node(int value){

        struct node *temp=new node;

        if (temp == NULL) {
            cout<<"Memory Not Allocated"<<endl;
            return 0;
        }
        else{
            temp->val=value;
            temp->next=NULL;
            temp->prev=NULL;
            return temp;
        }
    }

    //Two Way Link List Function to Insert a node in the beginning
    void insert_end(){

        int value;
        cout<<"Enter the value to be inserted: "<<endl;
        cin>>value;
        node *temp,*p;
        temp = Create_Node(value);

        if (start == NULL) {
            start = temp;
            start->next = NULL;
            start->prev = NULL;
        }
        else{
            p=start;
            start=temp;
            start->prev=NULL;
            p->prev=start;
            start->next=p;
        }
        cout<<"Element Inserted at Beginning"<<endl;

    }

    //Two Way link list Function to delete an element
    void delete_pos(){
        int value;
        cout<<"Enter the Element to be Deleted"<<endl;
        cin>>value;

        node *temp, *ptr;

        if (start->val == value){
            temp = start;
            start = start->next;
            start->prev = NULL;
            cout<<"Element Deleted"<<endl;\
            return;
        }

        ptr = start;
        while (ptr->next->next != NULL){

            if (ptr->next->val == value){

                temp = ptr->next;
                ptr->next = temp->next;
                temp->next->prev = ptr;
                cout<<"Element Deleted"<<endl;
                return;
            }
            ptr = ptr->next;
        }

        if (ptr->next->val == value){
            temp = ptr->next;
            ptr->next = NULL;
            cout<<"Element Deleted"<<endl;
            return;
        }
        cout<<"Element "<<value<<" not found"<<endl;
    }

    //Two Way link list to display the list
    void display(){

        node *temp;

        if (start == NULL) {
            cout<<"List is Empty"<<endl;
            return ;
        }

        temp=start;
        cout<<"The Doubly Link List is :"<<endl;
        while (temp != NULL) {
            cout<<temp->val<<"\t";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

int main(){
    int choice;
    Linked_List ob; //Object of Single Link List
    Double_Linked_List list; //Object of Two Way link List
start:
    for (int i=0; i<1; ) {

        do {
            printline();
            cout<<"Select One Option"<<endl;
            printline();
            cout<<"1. Insert Node at Beginning"<<endl;
            cout<<"2. Insert Node at End"<<endl;
            cout<<"3. Insert Node at a given position"<<endl;
            cout<<"4. Sort Link List"<<endl;
            cout<<"5. Delete First Node"<<endl;
            cout<<"6. Delete Last Node"<<endl;
            cout<<"7. Delete Node at a given position"<<endl;
            cout<<"8. Display Linked List"<<endl;
            cout<<"9. Split List in Half"<<endl;
            cout<<"10. Sort and Merge Two Link lists into One"<<endl;
            cout<<"11. Two Way Link List"<<endl;
            cout<<"12. Header Link List"<<endl;
            cout<<"13. Reverse Linked List (iterative)"<<endl;
            cout<<"14. Reverse Linked List (Recursive)"<<endl;
            cout<<"15. Exit"<<endl;
            printline();
            cout<<"Enter the Choice"<<endl;
            cin>>choice;
        } while (choice <0 || choice >16);

        switch (choice) {
            case 1:
                ob.insert_begin();
                break;

            case 2:
                ob.insert_end();
                break;

            case 3:
                ob.insert_pos();
                break;

            case 4:
                ob.sort_list();
                break;

            case 5:
                ob.delete_begin();
                break;

            case 6:
                ob.delete_end();
                break;

            case 7:
                ob.delete_pos();
                break;

            case 8:
                ob.display();
                break;

            case 9:
                ob.FrontBackSplit();
                break;

            case 10:
                ob.Merge_List();
                break;

            case 11:
                for (int i=5; i>0; ) {

                    do {
                        printline();
                        cout<<"Select One Option"<<endl;
                        printline();
                        cout<<"1. Insert Node"<<endl;
                        cout<<"2. Delete Node"<<endl;
                        cout<<"3. Display Linked List"<<endl;
                        cout<<"4. Exit"<<endl;
                        printline();
                        cout<<"Enter the Choice"<<endl;
                        cin>>choice;
                    } while (choice <0 || choice >4 );

                    switch (choice) {
                        case 1:
                            list.insert_end();
                            break;

                        case 2:
                            list.delete_pos();
                            break;

                        case 3:
                            list.display();
                            break;

                        case 4:
                            goto start;
                    }
                }

                break;

            case 12:
                for (int i=5; i>0; ) {

                    do {
                        printline();
                        cout<<"Select One Option"<<endl;
                        printline();
                        cout<<"1. Insert Node"<<endl;
                        cout<<"2. Delete Node"<<endl;
                        cout<<"3. Display Linked List"<<endl;
                        cout<<"4. Exit"<<endl;
                        printline();
                        cout<<"Enter the Choice"<<endl;
                        cin>>choice;
                    } while (choice <0 || choice >4 );

                    switch (choice) {
                        case 1:
                            ob.header_insert_end();
                            break;

                        case 2:
                            ob.header_delete_end();
                            break;

                        case 3:
                            ob.header_display();
                            break;

                        case 4:
                            goto start;
                    }
                }
                break;

            case 13:
                ob.reverse_itr(ob.start);
                break;

            case 14:
                ob.reverse_rec(ob.start);
            case 15:
                return 0;
        }
    }

}

//Function to print a line
void printline(){
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}
