/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Nama Program: queue.c
 */

// Preprocessor
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

// Declarations and Definitions
int queue[MAX_SIZE];
int front = -1, rear = -1;

// Functions Declarations
bool isFull();
bool isEmpty();
void enqueue(int data);
void enqueuePrime(int data);
int dequeue();
void printQueue();

// Main code
int main(int argc, char** argv)
{
    // enqueue(5);
    // enqueue(10);
    // enqueue(15);
    enqueuePrime(13);
    enqueuePrime(20);
    enqueuePrime(1);

    printf("Rear Position: %d\n", rear);
    printQueue();
    // printf("Dequeued Element: %d\n\n", dequeue());
    // printQueue();
    // printf("Dequeued Element: %d\n\n", dequeue());
    // printQueue();
    // printf("Dequeued Element: %d\n\n", dequeue());
    // printQueue();
    // printf("Dequeued Element: %d\n\n", dequeue()); // queue is empty!
    // printQueue();

    return 0;
}

// Functions Definitions
bool isFull() { return rear == MAX_SIZE - 1; }

bool isEmpty() { return front == -1; }

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear++;
    
    queue[rear] = data;
}

bool isPrime(int data)
{
    // using trial division method (low memory usage but long runtime)
    if (data <= 1)
        return false;
    
    for (int i = 2; i <= data / 2; i++)
    {
        if (data % i == 0)
            return false;
    }

    return true;
}

void enqueuePrime(int data)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return; 
    }

    if (isEmpty()) 
    {
        if (isPrime(data))
        {
            front = rear = 0;   
            queue[rear] = data;
        }
        else
        {
            printf("%d is not prime number!\n", data);
            return;
        }
    }
    else
    {
        if (isPrime(data))
        {
            rear++;
            queue[rear] = data;
        }
        else
        {
            printf("%d is not prime number!\n", data);
            return;
        }
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    int data = queue[front];
    
    if (front == rear)
        front = rear = -1;
    else
        front++;

    return data;
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
        printf("%d ", queue[i]);
    printf("\n");
}
