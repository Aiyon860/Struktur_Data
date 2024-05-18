/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 10: Tree
 *  Nama File: tree.c 
 */ 

// Preprocessor
#include <stdlib.h>
#include <stdio.h>
#define info(p) (p) -> info
#define left(p) (p) -> left
#define right(p) (p) -> right

// Node Declaration and Tree Structure
typedef struct treenode* data;
typedef struct treenode {
  int info;
  data right;
  data left;
} node;
data root;

// Functions Declaration
void insert(data* tree, int elem);
void preorder(data* tree);
void inorder(data* tree);
void postorder(data* tree);

// Main Entry Point
int main(int argc, char const *argv[])
{
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 1);
  insert(&root, 4);

  printf("Inorder: ");
  inorder(&root);

  printf("\n\n");

  printf("Preorder: ");
  preorder(&root);
  
  printf("\n\n");

  printf("Postorder: ");
  postorder(&root);

  return EXIT_SUCCESS;
}

// Functions Definition
void insert(data* tree, int elem)
{
  // Dictionary
  data item;

  // Algorithm
  item = (data)calloc(1, sizeof(node));
  left(item) = right(item) = NULL;
  info(item) = elem; 

  if (!(*tree))
  {
    *tree = item;
    return;
  }

  if (info(item) < info(*tree))
  {
    insert(&left(*tree), elem);
  }
  else if (info(item) > info(*tree))
  {
    insert(&right(*tree), elem);
  }
}

void preorder(data* tree)
{
  if (*tree != NULL)
  {
    printf(" %d ", info(*tree));
    preorder(&left(*tree));
    preorder(&right(*tree));
  }
}

void inorder(data* tree)
{
  if (*tree != NULL)
  {
    inorder(&left(*tree));
    printf(" %d ", info(*tree));
    inorder(&right(*tree));
  }
}

void postorder(data* tree)
{
  if (*tree != NULL)
  {
    postorder(&left(*tree));
    postorder(&right(*tree));
    printf(" %d ", info(*tree));
  }
}
