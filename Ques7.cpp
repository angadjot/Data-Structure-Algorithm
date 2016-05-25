/**
 UCS-406 (Data Structure)
 Lab Assignment
 
 Question: Write program using functions for binary tree traversals Pre-order, In-order and Post-order using both Recursive and Non-recursive approach.
 
 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2
 
 */

#include<iostream>
#include<stack>
using namespace std;

void printline();

struct node{
	int value;
	node *left,*right;
};

node *root;

class BST{
    
public:
    
    BST(){
        root=NULL;
    }
    

    void tree_insert(node *tree,node *z){
        
        if (root == NULL) {
            root = new node;
            root->value = z->value;
            root->left = NULL;
            root->right = NULL;
            cout<<"Root Node is Added"<<endl;
            return ;
        }
        
        if (tree->value == z->value) {
            cout<<"Element already in the tree"<<endl;
            return ;
        }
        
        if (tree->value>z->value) {
            if (tree->left !=NULL) {
                tree_insert(tree->left,z);
            }
            else{
                tree->left=z;
                (tree->left)->left=(tree->left)->right=NULL;
                cout<<"Node Added to Left"<<endl;
                return ;
            }
        }
        
        else{
            if (tree->right != NULL) {
                tree_insert(tree->right,z);
            }
            else{
                tree->right=z;
                (tree->right)->left=(tree->right)->right=NULL;
                cout<<"Node Added to Right"<<endl;
                return ;
            }
        }
    }
    
    void preorder_recursive(node *ptr){
        
        if (root == NULL)
        {
            cout<<"Tree is empty"<<endl;
            return;
        }

        if (ptr !=NULL) {
            cout<<ptr->value<<"  ";
            preorder_recursive(ptr->left);
            preorder_recursive(ptr->right);
        }
    }
    
    void inorder_recursive(node *ptr){
        
        if (root == NULL)
        {
            cout<<"Tree is empty"<<endl;
            return;
        }

        if (ptr!=NULL) {
            inorder_recursive(ptr->left);
            cout<<ptr->value<<"  ";
            inorder_recursive(ptr->right);
        }
    }
    
    void postorder_recursive(node *ptr){
        
        
        if (root == NULL)
        {
            cout<<"Tree is empty"<<endl;
            return;
        }

        
        if (ptr!=NULL) {
            postorder_recursive(ptr->left);
            postorder_recursive(ptr->right);
            cout<<ptr->value<<"  ";
        }
    }
    
    void preorder(node *ptr){
        
        if (root == NULL) {
            cout<<"Tree is Empty"<<endl;
            return ;
        }
        
        stack<node *> s;
        s.push(ptr);
        
        while (s.empty() == false) {
            node *temp=s.top();
            cout<<temp->value<<"  ";
            s.pop();
            
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        
    }
    
    void inorder(node *ptr){
        
        if (root == NULL) {
            cout<<"Tree is Empty"<<endl;
            return ;
        }
        
        stack<node *> s;
        node *temp=ptr;
        
        while (s.empty() == false || temp != NULL) {
            if (temp != NULL) {
                s.push(temp);
                temp=temp->left;
            }
            else{
                temp=s.top();
                s.pop();
                cout<<temp->value<<"  ";
                temp=temp->right;
            }
        }

    }
    
    void postorder(node *ptr){
        
        if (root == NULL) {
            cout<<"Tree is Empty"<<endl;
            return ;
        }
        
        stack<node *> s1;
        stack<node *> s2;
        
        s1.push(ptr);
        node *temp;
        
        while (s1.empty() == false) {
            temp=s1.top();
            s1.pop();
            s2.push(temp);
            
            if (temp->left) {
                s1.push(temp->left);
            }
            
            if(temp->right){
                s1.push(temp->right);
            }
        }
        
        while (s2.empty() == false) {
            temp=s2.top();
            s2.pop();
            cout<<temp->value<<"  ";
        }
    }
    
    void display(node *ptr,int level){
        
        int i;
        if (ptr != NULL) {
            
            display(ptr->right,level+1);
            cout<<endl;
            
            if (ptr == root) {
                cout<<"Root ->\t";
            }
            
            else{
                for (i=0; i<level; i++) {
                    cout<<"\t";
                }
            }
            
            cout<<ptr->value;
            display(ptr->left,level+1);
        }
        
    }
    
};

int main(){
    
    BST ob;
    int choice,Option;
    node *temp;
    
    for (int i=1; i>0; ) {
        
        do {
            printline();
            cout<<"Select One Option"<<endl;
            printline();
            cout<<"1. Insert an Element in the Tree"<<endl;
            cout<<"2. Pre-order Traversal (Recursive)"<<endl;
            cout<<"3. In-order Traversal (Recursive)"<<endl;
            cout<<"4. Post-order Traversal (Recursive)"<<endl;
            cout<<"5. Pre-order Traversal (Non - Recursive)"<<endl;
            cout<<"6. In-order Traversal (Non - Recursive)"<<endl;
            cout<<"7. Post-order Traversal (Non - Recursive)"<<endl;
            cout<<"8. Display the Tree"<<endl;
            cout<<"9. Exit"<<endl;
            printline();
            cout<<"Enter the Choice"<<endl;
            cin>>choice;
        } while (choice <0 || choice >10);
        
        switch (choice) {
            
            case 1:
                Option=1;
                printline();
                cout<<"Enter 1 to Continue Inserting"<<endl<<"Enter 0 to Stop Inserting values"<<endl;
                printline();
                cout<<endl;
                while (Option == 1) {
                    if (Option == 1) {
                        temp=new node;
                        cout<<"Enter the number to be inserted : "<<endl;;
                        cin>>temp->value;
                        ob.tree_insert(root,temp);
                        cin>>Option;
                    }
                    
                    else if(Option == 0){
                        break;
                    }
                }
                break;
                
            case 2:
                ob.preorder_recursive(root);
                cout<<endl;
                break;
                
            case 3:
                ob.inorder_recursive(root);
                cout<<endl;
                break;
                
            case 4:
                ob.postorder_recursive(root);
                cout<<endl;
                break;
                
            case 5:
                ob.preorder(root);
                cout<<endl;
                break;
                
            case 6:
                ob.inorder(root);
                cout<<endl;
                break;
                
            case 7:
                ob.postorder(root);
                cout<<endl;
                break;
              
            case 8:
                cout<<"Display BST:"<<endl;
                ob.display(root,1);
                cout<<endl;
                break;
             
            case 9:
                return 0;
        }
    }
	return 0;
}

void printline(){
    
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}