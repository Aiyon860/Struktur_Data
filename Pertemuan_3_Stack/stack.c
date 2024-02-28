/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Nama Program: stack.c
 */

// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

// init variable needed
int stack[N], top = -1;

/* init functions needed */
// Menampilkan isi Stack
void display(int* stack)
{
    if (top >= 0)
    {
        printf("Isi stack : \n");
        for (int i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
        }
    }
    else
    {
        printf("Stack Kosong");
    }
    printf("\n\n");
}

// Memasukkan item/data ke Stack
void push(int* stack, int item)
{
    if (top == N-1)
    {
        printf("\nTidak dapat menambah item, stack sudah penuh");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

// Cek apakah bisa memasukkan item/data yang ganjil ke Stack
bool pushGanjil(int item)
{
    return item % 2 == 1;
}

// Cek apakah bisa memasukkan item/data yang ganjil ke Stack
bool pushGenap(int item)
{
    return item % 2 == 0;
}

// Menghapus item dari stack (a.k.a mindahin posisi top)
void pop(int* stack)
{
    if (top == -1)
    {
        printf("Stack sudah kosong!\n");
    }
    else
    {
        int hapusItem = stack[top];
        top--;
        printf("Elemen %d telah dihapus\n\n", hapusItem);
    }
}

// main entry point
int main(int argc, char** argv)
{
    top = -1;
    int pilihan;
    int oddOrEven;
    
    do
    {
        printf("Masukkan Pilihan : \n");
        printf("1. Display\n");
        printf("2. Tambah Item (Push)\n");
        printf("3. Hapus Item (Pop)\n");
        printf("4. Exit\n");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan)
        {
        case 1:
            display(stack);
            break;
        case 2:
            printf("Mau memasukkan angka ganjil (1) / genap (2) : ");
            scanf("%d", &oddOrEven);

            if (oddOrEven == 1)
            {
                printf("Tambahkan item : ");
                int item;
                scanf("%d", &item);
                fflush(stdin);
                
                if (pushGanjil(item))
                {
                    push(stack, item);
                    printf("Berhasil memasukkan angka ganjil!\n");
                } 
                else 
                {
                    printf("Angka yang dimasukkan bukan angka ganjil!\n");
                }
            }
            else if (oddOrEven == 2)
            {
                printf("Tambahkan item : ");
                int item;
                scanf("%d", &item);
                fflush(stdin);

                if (pushGenap(item))
                {
                    push(stack, item);
                    printf("Berhasil memasukkan angka genap!\n");
                } 
                else 
                {
                    printf("Angka yang dimasukkan bukan angka genap!\n");
                }
            }
            else
            {
                printf("Bukan opsi ganjil atau genap!\n");
            }

            break;
        case 3:
            pop(stack);
            break;
        case 4:
            printf("\nKeluar...");
            break;
        default:
            printf("\nPilihan tidak valid!\n\n");
            break;
        }
    } while (pilihan != 4);
    
    return 0;
}