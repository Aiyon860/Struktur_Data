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
bool linearSearch(LinkedList* list, int target);
Node* getMiddle(Node* start, Node* end);
int countNodes(Node* head);
bool binarySearch(LinkedList* list, int target);
void bubbleSort(LinkedList* list);
void swap(Node* a, Node* b);

/* Main Entry Point */
int main()
{
  printf("\n");
  LinkedList* list = (LinkedList*)calloc(1, sizeof(LinkedList));
  checkAllocationMemoryList(list);

  for (int i = 10; i >= 0; i--)
    insertAtEnd(&list, i);
  printLL(list);

  // Main Objectives
  // printf("\nLinear Searching Test: \n");
  // printf("Angka %d %s\n", 3, linearSearch(list, 3) ? "Ditemukan" : "Tidak Ditemukan");
  // printf("Angka %d %s\n", 9, linearSearch(list, 9) ? "Ditemukan" : "Tidak Ditemukan");
  // printf("Angka %d %s\n", 12, linearSearch(list, 12) ? "Ditemukan" : "Tidak Ditemukan");

  // printf("\n");

  bubbleSort(list);
  printLL(list);
  printf("\nBinary Searching Test: \n");
  printf("Angka %d %s\n", 10, binarySearch(list, 10) ? "Ditemukan" : "Tidak Ditemukan");
  printf("Angka %d %s\n", 0, binarySearch(list, 0) ? "Ditemukan" : "Tidak Ditemukan");
  printf("Angka %d %s\n", -80, binarySearch(list, -80) ? "Ditemukan" : "Tidak Ditemukan");

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

bool linearSearch(LinkedList* list, int target)
{
  Node* temp = list->head;
  while (temp != NULL)
  {
    if (temp->info == target) 
      return true;
    temp = temp->next;
  }
  return false;
}

Node* getMiddle(Node* start, Node* end)
{
  if (start == NULL)
    return NULL;
  Node* slow = start;
  Node* fast = start->next;
  while (fast != end) 
  {
    fast = fast->next;
    if (fast != end) 
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  return slow;
}

bool binarySearch(LinkedList* list, int target)
{
  Node* start = list->head;
  Node* end = NULL;
  while (start != end) 
  {
    Node* mid = getMiddle(start, end);

    if (mid == NULL)
      return true;

    if (mid->info == target)
      return true;
    else if (mid->info < target)
      start = mid->next;
    else
      end = mid;
  }
  return false;
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