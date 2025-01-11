#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int* value;
    struct node *left;
    struct node *right;
}node;


node* makeEmptyTree(){
    return NULL;
}

void destroyTree(node* root){
    if (root != NULL){
        destroyTree(root->left);
        destroyTree(root->right);
        // if it stores char* or other pointers, you're required to free the pointer
        // free(root->value);
        free(root);
    }
}
node* insertIntoTree(node* root, int val){
    if(root==NULL){
        node* new = (node*)malloc(sizeof(node));
        new->value = val;
        new->right = makeEmptyTree();
        new->left = makeEmptyTree();
        return new;
    } else {
        // int compare = strcmp(string, root->val)
        if (val < root->value){
            root->left = insertIntoTree(root->left,val);
        } if (val > root->value){
            root->right = insertIntoTree(root->right,val);
        } else {
            return root;
        }
    }
}
node* searchTree(node* root, int val){
    if(root){
        if (val == root->value){
            return root;
        } if (val > root->value){
            return searchTree(root->right, val);
        } if (val < root->value) {
            return searchTree(root->left, val);
        }
    } else {
        return NULL;
    }
}
node* deleteHelper(node* deleteThis){
    if (nodeToDelete == NULL){
        return root;
    } else {
        if (nodeToDelete->left == NULL && nodeToDelete->right == NULL){
            free(root);
            return NULL;
        } else if(nodeToDelete->left == NULL){
            node* temp = nodeToDelete->right;
            free(nodeToDelete);
            return temp;
        } else if(nodeToDelete->right == NULL){
            node* temp = nodeToDelete->;
            free(nodeToDelete);
            return temp;
        } else{

        }
    }
}
node* deleteValue(node* root, int val){
    node* nodeToDelete = searchTree(root, val);

}

void printTree(node* root){
    if(root==NULL){
        return;
    } else {
        printf("(");
        printTree(root->left);
        printf(" %d ", root->value);
        printTree(root->right);
        printf(")");
    }
}