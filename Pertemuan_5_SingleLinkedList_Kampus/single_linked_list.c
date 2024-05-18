/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Nama File: single_linked_list.c 
 */

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Functions Declarations
Node* create_node(int data);
void print_list(Node* head);
void insert_at_end(Node** head, int data);
void delete_node(Node** head, int key);

// Main Entry Point
int main(int argc, char** argv)
{
    system("cls");

    Node* head = NULL; // Initially, the list is empty

    // Create some nodes with sample data
    head = create_node(10);
    head -> next = create_node(20);
    head -> next -> next = create_node(30);

    printf("Created Linked List: \n");
    print_list(head);

    printf("Inserting 5 at the end: \n");
    insert_at_end(&head, 5);
    print_list(head);

    printf("Deleting Node with Value 20: \n");
    delete_node(&head, 20);
    print_list(head);

    // latihan soal
    printf("Latihan Soal: \n");
    Node* head2 = NULL;

    for (int i = 20; i <= 99; i++)
    {
        insert_at_end(&head2, i);
    }
    print_list(head2);

    return 0;
}

// Function Definitions
// Function to create a new node
Node* create_node(int data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) 
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    new_node -> data = data;
    new_node -> next = NULL;
    
    return new_node;
}

// Function to print all elements of the linked list
void print_list(Node* head)
{
    Node* current = head;   // create a temporary-like pointer to traverse

    if (current == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    while (current != NULL)
    {
        if (current -> next == NULL)
        {
            printf("%d\n", current -> data);
            break;
        }

        printf("%d - ", current -> data);
        current = current -> next;
    }
    printf("\n");
}

// Function to insert Node at the end of the linked list
void insert_at_end(Node** head, int data)
{
    Node* new_node = create_node(data);
    
    // Handle empty list case
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    // Traverse to the last node
    Node* current = *head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }

    // insert the new node at the end of the linked list
    current -> next = new_node;
}

// Function to delete a node with a given value
void delete_node(Node** head, int key)
{
    // Handle empty list case
    if (*head == NULL)
    {
        return;
    }

    // Store head node for traverse operation
    Node* current = *head;

    // Handle deletion of the head node if the data matches
    if (current != NULL && current -> data == key)
    {
        *head = current -> next;
        free(current);
        return;
    }

    // Find the previous node of the node to be deleted
    while (current != NULL && current -> next != NULL)
    {
        if (current -> next -> data == key)
        {
            break;
        }
        current = current -> next;
    }

    // If the key was not present in linked list
    if (current == NULL || current -> next == NULL)
    {
        printf("Key not found!\n");
        return;
    }

    // Store the node to be deleted
    Node* del = current -> next;
    current -> next = current -> next -> next;

    // Free memory of the deleted node
    free(del);
}