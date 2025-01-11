#include "treeMT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define Left 0
#define Right 1




Tree* makeEmptyTree()
{
  /*
    TODO: Create a new Tree, setting the root to NULL. Initialize any necessary mutexes. 

    Return Tree*.
   */
  Tree* t = malloc(sizeof(Tree));
  t->root = NULL;
  pthread_mutex_init(&t->lock, NULL);
  return t;
}
void NodeInserter(TNode* branch, int ori, TNode* newnode){
    TNode** child;
    if(ori == Left)
        child = &branch->left;
    else
        child = &branch->right;
    // Case 0: Child is NULL
    if(*child == NULL){
        *child = newnode;
        pthread_mutex_unlock(&branch->lock);
    } else {
        TNode* curnode = *child;
        pthread_mutex_lock(&curnode->lock);
        pthread_mutex_unlock(&branch->lock);
        int nextori;
        if(newnode->val < curnode->val)
            nextori = Left;
        else if(newnode->val > curnode->val)
            nextori = Right;
        else {
            pthread_mutex_unlock(&curnode->lock);
            return;
        }
        NodeInserter(curnode, nextori, newnode);
    }
}
void insertIntoTree(Tree* t, int val)
{
  /*
    TODO: This function should construct a new Node, traverse the BST to find the correct insertion location, and insert it. If there is already a node with that value, nothing needs to be inserted.

    Use mutexes to prevent threads from interfering with one another.  
   */
  // Initialize the empty node with our value
  TNode* node = malloc(sizeof(TNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  // init & lock the new nodes mutex
  pthread_mutex_init(&node->lock, NULL);
  pthread_mutex_lock(&t->lock);
  if(t->root == NULL){
      // case 0: the root is null, add new node to the leaf
      t->root = node;
      pthread_mutex_unlock(&t->lock);
  } else {
      // t exists, so traverse left and right
      TNode* root = t->root;
      pthread_mutex_lock(&root->lock);
      pthread_mutex_unlock(&t->lock);
      // case 1: Val is less, go left
      if(val < root->val) NodeInserter(root, Left, node);
      // case 2: Val is more, go right
      else if(val > root->val) NodeInserter(root, Right, node);
      // case 3: Val is already here, free node and unlock
      else {
          free(node);
          pthread_mutex_unlock(&root->lock);
      }
  }
}

void printTreeAux(TNode* root)
{
   if (root == NULL)
      return;
   else {
      printf("(");
      printTreeAux(root->left);
      printf(" %d ",root->val);
      printTreeAux(root->right);
      printf(")");      
   }
}

void printTree(Tree* t)
{
  printTreeAux(t->root);
}

void destroyTreeAux(TNode* root)
{
  if(root != NULL){
    destroyTreeAux(root->left);
    destroyTreeAux(root->right);
    pthread_mutex_destroy(&root->lock);
    free(root);
  }
}

void destroyTree(Tree* t)
{
  destroyTreeAux(t->root);
  pthread_mutex_destroy(&t->lock);
  free(t);
}


