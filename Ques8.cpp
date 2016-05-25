/**
 UCS-406 (Data Structure)
 Lab Assignment
 
 Question:  Implement following functions for Binary Search Trees
 a)	Search a given item (Recursive & Non-Recursive)
 b)	Insertion of a new node
 c)	Maximum element of the BST
 d)	Minimum element of the BST
 e)	Successor of the BST
 f)	Delete a given node from the BST
 
 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2
 
 */
#include<iostream>
using namespace std;

void printline();

struct node {
    int value;
    node *left,*right,*parent;
};

node *root;

class BST {
    
    
public:
    BST(){
        root=NULL;
    }
    
    void insert(node *tree,node *newnode){
        
        if (root == NULL) {
            root = new node;
            root->value=newnode->value;
            root->left=root->right=root->parent=NULL;
            cout<<"Root Node is Added"<<endl;
            return ;
        }
        
        if (tree->value == newnode->value) {
            cout<<"Element already in the tree"<<endl;
            return ;
        }
        
        if (newnode->value < tree->value) {
            if (tree->left!=NULL) {
                insert(tree->left,newnode);
            }
            else{
                tree->left=newnode;
                (tree->left)->left=(tree->left)->right=NULL;
                (tree->left)->parent=tree;
                cout<<"Node Added to Left"<<endl;
                return ;
            }
        }
        
        else{
            if (newnode->value > tree->value) {
                if (tree->right != NULL) {
                    insert(tree->right,newnode);
                }
                else{
                    tree->right=newnode;
                    (tree->right)->left=(tree->right)->right=NULL;
                    (tree->right)->parent=tree;
                    cout<<"Node Added to Right"<<endl;
                    return ;
                }
            }
        }
    
    }
    
    node* search_recursive(node *ptr,int search){
        
        if (ptr == NULL || search == ptr->value) {
            return ptr;
        }
        else if(search < ptr->value){
            return search_recursive(ptr->left,search);
        }
        else{
            return search_recursive(ptr->right,search);
        }
    }
    
    node* search(node *ptr,int search){
        
        while (ptr != NULL && search != ptr->value) {
            if (search < ptr->value) {
                ptr=ptr->left;
            }
            else{
                ptr=ptr->right;
            }
        }
        
        return ptr;
        
    }
    
    node* Maximum(node *ptr){
        
        if (root == NULL) {
            cout<<"Tree is Empty"<<endl;
            return 0;
        }
        
        while (ptr->right != NULL) {
            ptr=ptr->right;
        }
        
        return ptr;
    }
    
    node* Minimum(node *ptr){
        if (root == NULL) {
            cout<<"Tree is Empty"<<endl;
            return 0;
        }
        
        while (ptr->left != NULL) {
            ptr=ptr->left;
        }
        
        return ptr;
    }
    
    node* Successor(){
        
        int num;
        cout<<"Enter the Element to find its Successor"<<endl;
        cin>>num;
        
        node *ptr;
        node *temp=search(root,num);
        
        if (temp->right != NULL) {
            return Minimum(temp->right);
        }
        
        ptr = temp->parent;
        
        while (ptr !=NULL && temp == ptr->right) {
            temp = ptr;
            ptr=ptr->parent;
        }
        return ptr;
        
        
    }
    
    
    void tree_delete(node* tree){
        
        if (tree==NULL) {
            cout<<"Tree is Empty"<<endl;
            return ;
        }
        
        node *z,*y;
        int num;
        cout<<"Enter the Element to Deleted from the Tree"<<endl;
        cin>>num;
        z=search(root,num);
        
        if (z->left == NULL) {
            transplant(tree,z,z->right);
        }
        
        else if(z->right == NULL){
            transplant(tree,z,z->left);
        }
        else{
            y=Minimum(z->right);
            
            if (y->parent !=z) {
                transplant(tree,y,y->right);
                y->right=z->right;
                y->right->parent=y;
            }
            transplant(tree,z,y);
            y->left=z->left;
            y->left->parent=y;
        }
    }
    
    void transplant(node *tree,node *u,node *v){
        
        if (u->parent == NULL) {
            root = v;
        }
        else if(u == u->parent->left){
            u->parent->left=v;
        }
        else{
            u->parent->right = v;
        }
        
        if (v!=NULL) {
            v->parent=u->parent;
        }
    }
    
    void display(node *ptr,int level){
        
        if (root == NULL) {
            cout<<"Tree is Empty"<<endl;
            return ;
        }
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
    
    BST bst;
    node *temp;
    int choice,Option,search;
    
    for (int i=1; i>0; ) {
        
        do {
            printline();
            cout<<"Select One Option"<<endl;
            printline();
            cout<<"1. Insert an Element in the Tree"<<endl;
            cout<<"2. Search an Element (Recursive)"<<endl;
            cout<<"3. Search an Element (Non - Recursive)"<<endl;
            cout<<"4. Maximum element of the BST"<<endl;
            cout<<"5. Minimum element of the BST"<<endl;
            cout<<"6. Successor  of the BST"<<endl;
            cout<<"7. Delete a given node from the BST"<<endl;
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
                        temp = new node;
                        cout<<"Enter the number to be inserted : "<<endl;;
                        cin>>temp->value;
                        bst.insert(root,temp);
                        cin>>Option;
                    }
                    
                    else if(Option == 0){
                        break;
                    }
                }
                break;
                
            case 2:
                cout<<"Enter the Element to search in the tree"<<endl;
                cin>>search;
                temp = bst.search_recursive(root,search);
                if (temp == NULL) {
                    cout<<search<<" is not present in the tree"<<endl;
                    break;
                    
                }
                if (temp->value == search) {
                    cout<<search<<" is present in the tree"<<endl;
                }
                break;
                
            case 3:
                cout<<"Enter the Element to search in the tree"<<endl;
                cin>>search;
                temp = bst.search(root,search);
                if (temp == NULL) {
                    cout<<search<<" is not present in the tree"<<endl;
                    break;

                }
                if (temp->value == search) {
                    cout<<search<<" is present in the tree"<<endl;
                }
                break;
                
            case 4:
                temp = bst.Maximum(root);
                cout<<"Maximum: "<<temp->value<<endl;
                break;
                
            case 5:
                temp = bst.Minimum(root);
                cout<<"Minimum: "<<temp->value<<endl;
                break;
                 
            case 6:
                temp = bst.Successor();
                cout<<"Successor: "<<temp->value<<endl;
                cout<<endl;
                break;
                 
            case 7:
                bst.tree_delete(root);
                cout<<endl;
                break;
                
            case 8:
                cout<<"Display BST:"<<endl;
                bst.display(root,1);
                cout<<endl;
                break;
                
            case 9:
                return 0;
        }
    }

	return(0);
}

void printline(){
    
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}