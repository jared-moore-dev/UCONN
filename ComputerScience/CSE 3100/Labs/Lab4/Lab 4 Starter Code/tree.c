#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct TNode{
  char* val;
  struct TNode* left;
  struct TNode* right;
} TNode;

TNode* makeEmptyTree()
{
   return NULL;
}

TNode* insertIntoTree(TNode* root,char* string)
{
  /*
    TODO: Insert the string into the tree. First, check if the root is NULL. If it is, then create a new TNode, copy the string into it, and return the pointer to the new TNode. 

    If root is not NULL, then compare root->val and string using strcmp. If root->val < string, then call insertIntoTree again on root->left. Keep in mind that root->left might be NULL. If root->val > string, then call insertIntoTreeAgain on root->right. Again, root->right might be NULL. If root->val is equal to string, then the string is already in the tree, and you don't need to do anything. In any case, return root.
   */
   if (root == NULL){
     /*make a new node with an empty left and right subtree and populate it with str*/
     TNode* newnode = (TNode*)malloc(sizeof(TNode));
     newnode->val = malloc(sizeof(char)*(strlen(string) + 1));
     strcpy(newnode->val, string);
     newnode->left = makeEmptyTree();
     newnode->right = makeEmptyTree();
     return newnode;
   } else {
     /*find which string has a higher bit value*/
     int strval = strcmp(string, root->val);
     if(strval < 0){
       /*place reccursive call to insert in left subtree*/
       root->left = insertIntoTree(root->left, string);
     } else if(strval > 0){
       /*place recursive call to insert in right subtree*/
       root->right = insertIntoTree(root->right, string);
     }
     return root;
   }
}

TNode* searchTree(TNode* root, char* string)
{
  if(root){
    /*
      TODO: Search the tree for the string. First, use strcmp to compare root->val to string. 

      If string == root->val, return the root. 

      If string < root->val, then call searchTree on the right child of root.

      If string > root->val, then call searchTree on the left child of root.
     */
     int strval = strcmp(string, root->val);
     if(strval == 0)
       return root;
     else if(strval<0)
       return searchTree(root->left, string);
     else
       return searchTree(root->right, string);
  }else
    return NULL;
}

void printTree(TNode* root)
{
   if (root == NULL)
      return;
   else {
      printf("(");
      printTree(root->left);
      printf(" %s ",root->val);
      printTree(root->right);
      printf(")");      
   }
}

void destroyTree(TNode* root)
{
  /*
    TODO: Free the nodes in the tree, and the strings stored in those nodes. This is easier to do recursively. 
   */
  if (root!=NULL){
    /* run destroyTree on children*/
    destroyTree(root->left);
    destroyTree(root->right);
    /*free the parent node so there are no memory leaks*/
    free(root->val);
    free(root);
  }
}




int main(int argc, char* argv[])
{
  if(argc != 2){
    printf("Usage: ./tree wordList\n");
    return 1;
  }
  TNode* tree = makeEmptyTree();
  /*
    TODO: The path to the file containing the words is stored in argv[1]. Call fopen to open it. 
   */
  FILE* file = fopen(argv[1], "r");
  char word[200];
  size_t length;
  /*
    TODO: Use fscanf to read a word at a time from the file, and call insertIntoTree to insert the word into the tree.
   */
  while(fscanf(file, "%s", word) == 1 && strlen(word) >=1){
    tree = insertIntoTree(tree,word);
  }
  /*
    TODO: fclose the file.
   */
  fclose(file);
  while(1){
    printf("word: ");
    int r = scanf("%s", word);
    if(r != 1)
      break;
    length = strlen(word);
    if(length < 1)
      break;
    TNode* node = searchTree(tree, word);
    if(node){
      printf("PRESENT\n");
    }else{
      printf("ABSENT\n");
    }    
  }
  destroyTree(tree);
  return 0;
}
