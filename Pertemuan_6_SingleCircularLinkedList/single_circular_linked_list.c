/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 6: Single Circular Linked List
 *  Nama File: single_circular_linked_list.c 
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node; 

// Functions Declaration
Node* create_node(int data);
void print_list(Node* last);
void insert_at_end(Node** last_ref, int data);
void delete_node(Node** last_ref, int key);
void insert_after_node(Node** last_ref, int data, int key);

// Main Function
int main(int argc, char** argv)
{
    system("cls");

    Node* last = NULL;  // Initialize the empty list

    // Create some nodes with sample data
    insert_at_end(&last, 10);
    insert_at_end(&last, 20);
    insert_at_end(&last, 30);

    printf("Created Linked List: \n");
    // print_list(last);

    // printf("Inserting 5 at the end: \n");
    insert_at_end(&last, 5);
    // print_list(last);

    // printf("Deleting node with value 20: \n");
    delete_node(&last, 20);
    print_list(last);

    printf("Adding node with value 50 After 10: \n");
    insert_after_node(&last, 50, 10);
    print_list(last);

    printf("Adding node with value 70 After 30: \n");
    insert_after_node(&last, 70, 30);
    print_list(last);

    printf("Adding node with value 100 After Last Node: \n");
    insert_after_node(&last, 100, 5);
    print_list(last);

    Node* last2 = NULL;
    insert_at_end(&last2, 50);
    printf("New List =>\n");
    print_list(last2);
    printf("Adding Node with value 30 After First Node!\n");
    insert_after_node(&last2, 30, 10);
    print_list(last2);

    return 0;
}

// Functions Definition

// Function to create a new node
Node* create_node(int data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("Memory Allocation Failed!\n");
        exit(1);
    }

    new_node -> data = data;
    new_node -> next = NULL;

    return new_node;
}

// Function to print all elements of the linked list
void print_list(Node* last)
{
    Node* temp = last -> next; // start from the next of 'last'
    if (temp == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    printf("List Elements: \n");
    Node* start = temp;
    do
    {
        if (temp -> next == start)
        {
            printf("%d ", temp -> data);
            break;
        }

        printf("%d - ", temp -> data);
        temp = temp -> next;
    } while (temp != start);

    printf("\n\n");
}

// Function to insert a node at the end of the linked list
void insert_at_end(Node** last_ref, int data)
{
    Node* new_node = create_node(data);

    // Handle empty list case
    if (*last_ref == NULL)
    {
        *last_ref = new_node;
        (*last_ref) -> next = *last_ref;
    }

    // Insert the new node at the end
    new_node -> next = (*last_ref) -> next;  // Point new node to the first node
    (*last_ref) -> next = new_node; // Point last node to the new node
    *last_ref = new_node; // Update 'last' to the new node
}

void delete_node(Node** last_ref, int key)
{
    // Handle empty list case
    if (*last_ref == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    Node* temp = (*last_ref) -> next; // point to the first node
    Node* prev = NULL;

    // if the list hast only one node
    if (temp -> data == key && temp -> next == temp)
    {
        free(temp);
        *last_ref = NULL;
        return;
    }

    // Find the node to be deleted and its previous node
    while (temp -> data != key)
    {
        if (temp -> next == (*last_ref) -> next)
        {
            printf("Key Not Found!\n");
            return;
        }

        prev = temp;
        temp = temp -> next;
    }

    // If the node to be deleted is the first node
    if (temp == (*last_ref) -> next)
    {
        (*last_ref) -> next = temp -> next;
        free(temp);
    }

    // If the node to be deleted is the last node
    else if (temp == *last_ref)
    {
        prev -> next = (*last_ref) -> next;
        *last_ref = prev;
        free(temp);
    }

    // if the node to be deleted is any other node
    else
    {
        prev -> next = temp -> next;
        free(temp);
    }
}

void insert_after_node(Node** last_ref, int data, int key)
{
    // Check if the list is empty
    if (*last_ref == NULL)
    {
        printf("Must Insert At Least One Node!\n");
        return;
    }
    
    Node* temp = (*last_ref) -> next; // point to the first node

    // if the list hast only one node
    if (temp -> data == key && temp -> next == temp)
    {
        insert_at_end(last_ref, data);
        return;
    }

    // Find the position of the new node to be placed after specific node
    while (temp -> data != key)
    {
        if (temp -> next == (*last_ref) -> next)
        {
            printf("Key Not Found!\n");
            return;
        }

        temp = temp -> next;
    }

    // If the position of the new node is on the last
    if (temp == *last_ref)
    {
        insert_at_end(last_ref, data);
        return;
    }

    // if the position of the new node is not on the beginning AND not on the last
    Node* new_node = create_node(data);
    Node* xs = temp -> next; // store the 'next' of the first node
    temp -> next = new_node;
    temp -> next -> next = xs;
}