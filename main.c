#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
struct  Node * right;
int value;
struct Node * left;
}Node;

//function initialiser un binary tree

Node *createNode(int value){
  Node *node=(Node*)malloc(sizeof(Node));
  node->value=value;
  node->right=NULL;
  node->left=NULL;
  return node;
}
//function inserer un element dans un binary tree
void insert (Node *tree, int value ) {
  
  if (tree == NULL) {
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->value = value;
    tree = newElement;
    return;
  }

  if (value < tree->value) {
    if ( tree->left != NULL) {
      insert(tree->left, value);
    } else {
      Node* newElement = (Node*)malloc(sizeof(Node));
      newElement->value = value;
      tree->left = newElement;
    }
  } else {
    if (tree->right != NULL) {
      insert(tree->right, value);
    } else {
      Node* newElement = (Node*)malloc(sizeof(Node));
      newElement->value = value;
      tree->right = newElement;
    }
  }

}

void prefix( Node* tree) {
  if(tree == NULL) return;
  printf("%d, ", tree->value);
  prefix(tree->left);
  prefix(tree->right);
}

void postFix( Node* tree) {
  if(tree == NULL) return;
  postFix(tree->left);
  postFix(tree->right);
  printf("%d, ", tree->value);
}


void inFix( Node* tree) {
  if(tree == NULL) return;
  inFix(tree->left);
  printf("%d, ", tree->value);
  inFix(tree->right);
}
//function min

void minArbre(Node *tree){
  if(tree->left ==NULL){
    printf("\nLe min est: %d ",tree->value);
  } else
  minArbre(tree->left);
}

void maxArbre(Node *tree){
  if(tree->right == NULL){
    printf("\nLe max est: %d ",tree->value);

  } else 
  maxArbre(tree->right);
}

int main () {
  Node* racine = createNode(10);

  insert(racine, 4);
  insert(racine, 1);
  insert(racine, 5);
  insert(racine, 17);
  insert(racine, 16);
  insert(racine, 21);


  printf("Prefix: \n");
  prefix(racine);
  printf("\n");
  printf("Postfix: \n");
  postFix(racine);
  printf("\n");
  printf("Infix: \n");
  inFix(racine);
  printf("\n");
  minArbre(racine);
  maxArbre(racine);
  printf("\n");

}
