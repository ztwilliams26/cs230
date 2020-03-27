#include <stdio.h>

// See the README.txt file for the challenge description.
struct BSTNode{
  char *value;
  struct BSTNode *left;
  struct BSTNode *right;

};

void print_tree(const struct BSTNode *root){
  if(root->left != NULL){
    print_tree(root->left);
  }
  printf("%s\n", root->value);
  if(root->right != NULL){
    print_tree(root->right);
  }
  return;
}


int main(void) {
  struct BSTNode root, n2, n3, n4, n5, n6;
  root.value="orange";
  n2.value="banana";
  n3.value="apple";
  n3.left = NULL;
  n3.right = NULL;
  n4.value="pear";
  n4.left = NULL;
  n4.right = NULL;
  n5.value="peach";
  n5.left = NULL;
  n5.right = NULL;
  n6.value="kiwi";
  n6.left = NULL;
  n6.right = NULL;

  root.left = &n2;
  root.right = &n3;
  n2.left =&n4;
  n2.right = &n5;
  n3.left =&n6;
  
  printf("Get to work!\n");
  print_tree(&root);
  return 0;
}