/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 12: Searching
 *  Nama File: latsol.c 
 *  Tugas: Mengimplementasikan Linear Searching dan 
 *         Binary Searching pada salah satu struktur data
 *         yang sudah pernah dipelajari.
 */ 

/* Preprocessor */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Struct Definitions for Linked List and Its Nodes */
typedef struct nodes Node;

typedef struct nodes {
  int info;
  Node* next;
} Node;

typedef struct linkedList {
  Node* head;
} LinkedList;

/* Function Declarations */
Node* createNode(int info);
void printLL(LinkedList* list);
void insertAtEnd(LinkedList** list, int info);
void checkAllocationMemoryList(LinkedList* list);
void checkAllocationMemoryNode(Node* head);
void bubbleSort(LinkedList* list);
void swap(Node* a, Node* b);
int randomInt();

/* Main Entry Point */
int main()
{
  printf("\n");
  LinkedList* list = (LinkedList*)calloc(1, sizeof(LinkedList));
  checkAllocationMemoryList(list);

  srand(time(0));
  for (int i = 10; i >= 0; i--)
    insertAtEnd(&list, randomInt());

  printf("Before:\n");
  printLL(list);
  printf("\nAfter:\n");
  bubbleSort(list);
  printLL(list);

  free(list);
  return 0;
}

/* Function Definitions */
Node* createNode(int info)
{
  Node* newNode = (Node*)calloc(1, sizeof(Node));
  checkAllocationMemoryNode(newNode);
  newNode->info = info;
  newNode->next = NULL;
  return newNode;
}

void printLL(LinkedList* list)
{
  if (list->head == NULL)
  {
    perror("List is Empty!\n");
    return;
  }

  // Traverse throughout the list.
  Node* temp = list->head;
  while (temp != NULL)
  {
    printf("%d%s", temp->info, temp->next != NULL ? " -> " : "");
    temp = temp->next;
  }
}

void insertAtEnd(LinkedList** list, int info)
{
  Node* newNode = createNode(info);
  if ((*list)->head == NULL)
  {
    (*list)->head = newNode;
    return;
  }

  // Traverse throughout the list.
  Node* temp = (*list)->head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newNode;
}

void checkAllocationMemoryList(LinkedList* list)
{
  if (list == NULL)
  {
    perror("Memory Allocation for Linked List Failed!\n");
    exit(1);
  }
}

void checkAllocationMemoryNode(Node* head)
{
  if (head == NULL)
  {
    perror("Memory Allocation for Node Failed!\n");
    exit(1);
  }
}

void bubbleSort(LinkedList* list)
{
  int swapped;
  Node* ptr1;
  Node* lptr = NULL;
  if (list->head == NULL)
    return;
  do 
  {
    swapped = 0;
    ptr1 = list->head;
    while (ptr1->next != lptr) 
    {
      if (ptr1->info > ptr1->next->info) 
      {
        swap(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

void swap(Node* a, Node* b)
{
  int temp = a->info;
  a->info = b->info;
  b->info = temp;
}

int randomInt() { return rand() % 10; }