/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 9: Multiple Linked List
 *  Nama File: multiple_linked_list.c 
 */

// Preprocessor
#include <stdio.h>
#include <stdlib.h>

// Representation of Node
typedef struct node 
{
    int data;
    struct node* next;
    struct node* child; 
} Node;

// Functions Declaration
Node* create_list(int* arr, int n);
void print_multi_level_list(Node* head);
void insert_elements_per_level(Node* head, int level);
void print_per_level(Node* head);

// Main entry point
int main(int argc, char const** argv)
{
    // Initializing the data in arrays (row wise)
    int arr1[3] = { 1, 2, 3 };
    int arr2[2] = { 5, 6 };
    int arr3[1] = { 4 };
    int arr4[3] = { 7, 8, 9 };

    // Creating Four Linked Lists
    // Passing array and size of array as parameters
    Node* head1 = create_list(arr1, 3);
    Node* head2 = create_list(arr2, 2);
    Node* head3 = create_list(arr3, 1);
    Node* head4 = create_list(arr4, 3);
    
    // Initializing children and next pointers as shown in given diagram
    head1 -> child = head2;
    head1 -> next -> next -> child = head3;
    head2 -> next -> child = head4;

    // Creating a null pointer
    Node* head = NULL;
    head = head1;

    printf("\n");

    // Function Call to print
    print_multi_level_list(head);

    printf("\n\n");

    // task
    print_per_level(head);

    return 0;
}

// Functions Definition
// A function to create a linked list with n(size) nodes returns head pointer
Node* create_list(int* arr, int n)
{
    Node* head = NULL;
    Node* tmp;

    // Traversing the passed array
    for (int i = 0; i < n; i++)
    {
        // Creating a node if the list is empty
        if (head == NULL)
        {
            tmp = head = (Node*) calloc(1, sizeof(Node));
        }
        else
        {
            tmp -> next = (Node*) calloc(1, sizeof(Node));
            tmp = tmp -> next;
        }
        // Created a node with data and setting child and next pointer as NULL.
        tmp -> data = arr[i];
        tmp -> next = tmp -> child = NULL;
    }
    
    return head;
}

// To print the linked list
void print_multi_level_list(Node* head)
{
    // While head is not null
    while (head)
    {
        printf("%d ", head -> data);
        if (head -> child)
        {
            print_multi_level_list(head -> child);
        }
        head = head -> next;
    }
}

// task: print every linked list on each level
int arr[10][10] = {0};

void insert_elements_per_level(Node* head, int level)
{
    if (head == NULL) return;

    int col = 0;
    
    // Traverse the main linked list at the current level
    while (head != NULL)
    {
        for (size_t x = 0; x < 10; x++)
        {
            if (arr[level - 1][col]) col++;
            else break;
        }
        arr[level - 1][col++] = head -> data;
        
        // If the current node has a child, recursively print the child's elements at the next level
        if (head -> child != NULL)
        {
            insert_elements_per_level(head -> child, level + 1);
        }
        head = head -> next;
    }
}

void print_per_level(Node* head)
{
    int level = 1;
    insert_elements_per_level(head, 1);

    for (size_t i = 0; i < 10; i++, level++)
    {   
        printf("Level %d: ", level);
        for (size_t j = 0; j < 10; j++)
        {
            if (arr[i][j]) printf("%d ", arr[i][j]);
        }
        printf("\n");

        if (!arr[i + 1][0]) break;
    }
}