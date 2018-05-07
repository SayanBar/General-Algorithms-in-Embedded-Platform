//Insert, Delete and Search BST
//Preorder Inorder and PostOrder Traversal

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define INT_BITS 16
#define ASCII_SIZE 256
 
typedef struct Node{
    int8_t data;
    struct Node* left;
    struct Node* right;
}NodeBST;

NodeBST * getNode(int8_t data);
NodeBST * insertNode(NodeBST *root, int8_t data);
NodeBST * deleteNode(NodeBST *root,int8_t data);
uint8_t SearchNode(NodeBST *root,int8_t data);
void Preorder(NodeBST *root);
void Postorder(NodeBST *root);
void Inorder(NodeBST *root);
NodeBST *FindMin(NodeBST *root);


int main()
{
    NodeBST * root=NULL;
    
    root=insertNode(root,4);
    root=insertNode(root,7);
    root=insertNode(root,1);
    root=insertNode(root,34);
    root=insertNode(root,73);
    root=insertNode(root,23);
    root=insertNode(root,28);
    printf("Preorder\n");
    Preorder(root);
    root=deleteNode(root,23);
    if(SearchNode(root,34)==SUCCESS)
        printf("\nElement found\n");
    else
        printf("Element not found\n");
    
    printf("\nInorder\n");
    Inorder(root);
    printf("\nPostorder\n");
    Postorder(root);
    return 0;
}

NodeBST * getNode(int8_t data)
{
    NodeBST * newNode=(NodeBST *)malloc(sizeof(NodeBST));
    if(!newNode)
        return NULL;
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
    
    
}


NodeBST * insertNode(NodeBST *root, int8_t data)
{
    NodeBST *newNode=getNode(data);
    if(!newNode)
        return NULL;
    if(!root)
        root=newNode;
    else if(root->data<=data)
        root->right=insertNode(root->right,data);
    else
        root->left=insertNode(root->left,data);
    return root;
    
}


NodeBST * deleteNode(NodeBST *root,int8_t data)
{
    if(!root)
        return NULL;
    else if(root->data>data)
        root->left=deleteNode(root->left,data);
    else if(root->data<data)
        root->right=deleteNode(root->right,data);
    else{
        if(!(root->left) && !(root->right)){
            free(root);
            //root=NULL;
        }
        else if(!(root->left)){
            NodeBST *temp=root;
            root=root->right;
            free(temp);//temp=NULL;
        }
        else if(!root->right){
            NodeBST *temp=root;
            root=root->left;
            free(temp);//temp=NULL;
        }
        else{
            NodeBST *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}

uint8_t SearchNode(NodeBST *root,int8_t data)
{
    if(!root)
        return FAIL;
    if(root->data==data)
        return SUCCESS;
    else if(root->data<data)
        return SearchNode(root->right,data);
    else
        return SearchNode(root->left,data);
}

void Preorder(NodeBST *root)
{
    if(!root)
        return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}



void Postorder(NodeBST *root){
    if(!root)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}


void Inorder(NodeBST *root){
    if(!root)
        return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

NodeBST *FindMin(NodeBST *root)
{
    if(!root)
        return NULL;
    while(root->left)
        root=root->left;
    return root;
    
}
