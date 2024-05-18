/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Nama Program: priority_queue.c
 */

// Preprocessor
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

// Variables's Declaration and Definitions
typedef struct item {
    int data;
    int priority;
} Item;

Item queue[MAX_SIZE];
int front = -1, rear = -1;

// Functions Declarations
bool isFull();
bool isEmpty();
void enqueue(int data, int priority);
Item dequeue();
void printQueue();

// Main code
int main(int argc, char** argv)
{
    enqueue(5, 2);
    enqueue(20, 4);
    enqueue(10, 1);
    enqueue(11, 4);
    enqueue(12, 3);
    enqueue(15, 5);

    Item dequeueItem = dequeue();
    printf("Dequeued Element: (%d, %d)\n", dequeueItem.data, dequeueItem.priority);

    printQueue();

    return 0;
}

// Functions Definitions
bool isFull() { return rear == MAX_SIZE - 1; }

bool isEmpty() { return front == -1; }

void enqueue(int data, int priority)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }

    Item newItem = {data, priority};

    if (isEmpty())
    {
        front = rear = 0;
        queue[rear] = newItem;
        return;
    }

    int i;
    for (i = rear; i >= front && queue[i].priority < priority; i--);

    if (i != rear)
    {
        int j;
        for (j = rear + 1; j > i + 1; j--)
            queue[j] = queue[j - 1];
        queue[j] = newItem;
        rear++;
    }
    else
    {
        rear++;
        queue[rear] = newItem;
    }
}

Item dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return (Item) {-1, -1};
    }

    Item item = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;
    
    return item;
}

void printQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue Elements: ");
    for (int i = front; i <= rear; i++)
        printf("(%d, %d); ", queue[i].data, queue[i].priority);
    printf("\n");
}