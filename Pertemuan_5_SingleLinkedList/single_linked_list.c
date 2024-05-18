/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Nama File: single_linked_list.c 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node {
    int data;
    struct node* next;
} Node; 

typedef struct linkedlist {
    Node* head;
} LinkedList;

// Function Declarations
Node* create_node(int value);
void append_node(Node** head, Node* newNode);  // adding node at the end of list
void insert_at_head(Node** head, Node* newNode);  // adding node at whatever position we want
void insert_after_node();
Node* find_node(Node* head, int value);
Node* delete_node(Node* head, Node* nodeToBeDeleted);
void display_list();

// Main code
int main(int argc, char** argv)
{
    system("cls");

    LinkedList* list1 = (LinkedList*) malloc(sizeof(LinkedList));
    list1 -> head = NULL;
    LinkedList* list2 = (LinkedList*) malloc(sizeof(LinkedList));
    list2 -> head = NULL;

    Node* temp;

    // all nodes are inserted through head
    printf("Latest Inserted Node is The Head: \n");
    for (int i = 0; i <= 25; i++)
    {
        temp = create_node(i);
        insert_at_head(&list1 -> head, temp);
    }
    display_list(list1 -> head);

    printf("\n\n");

    printf("Insertion and Deletion Operations: \n");
    printf("Insert 100 after 20\n");
    temp = find_node(list1 -> head, 20);
    insert_after_node(temp, create_node(100));
    display_list(list1 -> head);
    printf("Deleted Node: %d\n", delete_node(list1 -> head, temp) -> data);

    display_list(list1 -> head);

    printf("\n\n");

    // all nodes are inserted after head
    printf("Oldest Inserted Node is The Head: \n");
    for (int i = 0; i <= 25; i++)
    {
        temp = create_node(i);
        append_node(&list2 -> head, temp);
    }
    display_list(list2 -> head);

    printf("\n\n");
    
    return 0;
}

// Functions Definitions
Node* create_node(int value)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;

    return newNode;
}

void append_node(Node** head, Node* newNode)
{
    Node* current = *head;

    if (current == NULL) { *head = newNode; }
    else 
    {
        while(current -> next != NULL)
        {
            current = current -> next;
        }
        current -> next = newNode;
    }
}

void insert_at_head(Node** head, Node* newNode)
{
    Node* current = *head;

    if (current == NULL) { *head = newNode; }
    else
    {
        newNode -> next = *head;
        *head = newNode;
    }
}

void insert_after_node(Node* nodeToInsertAfter, Node* newNode)
{
    newNode -> next = nodeToInsertAfter -> next;
    nodeToInsertAfter -> next = newNode;
}

Node* find_node(Node* head, int value)
{
    Node* current = head;

    while (current != NULL)
    {
        if (current -> data == value) 
        { 
            return current; 
        }
        current = current -> next;
    }

    return NULL;
}

Node* delete_node(Node* head, Node* nodeToBeDeleted)
{
    Node* current = head;

    while (current != nodeToBeDeleted)
    {
        if (current -> next == nodeToBeDeleted)
        {
            break;
        }
        current = current -> next;
    }

    current -> next = nodeToBeDeleted -> next;
    return nodeToBeDeleted;
}

void display_list(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        if (current -> next == NULL)
        {
            printf("%d", current -> data);
            break;
        }

        printf("%d - ", current -> data);
        current = current -> next;
    }
    
    printf("\n");
}