/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Nama Program: doublestack.c
 */

// Preprocessor
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARRAY 6
#define MAX_STRING 50

// Init global variables
char stack[MAX_ARRAY][MAX_STRING];
int top1 = 0; 
int top2 = 0;
int* ptop1 = &top1;
int* ptop2 = &top2;

// Declare functions
void init();
void push(char* item, int nomorStack);
char* pop(int nomorStack);
void clear(int nomorStack);
bool isFull();
bool isEmpty(int nomorStack);
void display();

// Main entry point
int main(int argc, char** argv)
{
    char item[MAX_STRING];
    int pilihan, nomorStack;

    init();

    do
    {
        printf("-----> Contoh Program Double Stack <-----");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Clear");
        printf("\n4. Tampilkan Stack");
        printf("\n5. Selesai");
        printf("\nPilihan anda : ");
        scanf("%i", &pilihan);
        fflush(stdin);

        switch (pilihan)
        {
        case 1:
            printf("Push\n");
            printf("Masukkan datanya : ");
            fgets(item, MAX_STRING, stdin);
            item[strcspn(item, "\n")] = '\0';
            fflush(stdin);
            printf("Mau dimasukkan ke stack berapa? (1 atau 2) ? : ");
            scanf("%i", &nomorStack);
            fflush(stdin);
            printf("\n");
            push(item, nomorStack);
            break;
        case 2:
            printf("Pop\n");
            printf("Masukkan nomor stack : ");
            scanf("%i", &nomorStack);
            fflush(stdin);
            strcpy(item, pop(nomorStack));

            if (*item != '0') 
            {
                printf("\nData yang dikeluarkan adalah %s\n\n", item);
            }
            else
            {
                printf("\n");
            }

            break;
        case 3:
            printf("Clear\n");
            printf("Nomor Stack yang akan dikosongkan : ");
            scanf("%i", &nomorStack);
            fflush(stdin);
            clear(nomorStack);
            printf("\n");
            break;
        case 4:
            printf("Tampilkan Stack\n");
            display();
            break;
        case 5:
            printf("Exit...");
            break;
        default:
            printf("Pilihan yang anda masukkan tidak ada!\n");
            break;
        }
    } while (pilihan != 5);
    
    return 0;
}

/* Function Definition */
// Inisialisasi stack/membuat stack
void init()
{
    top1 = -1;
    top2 = MAX_ARRAY;
}

// Memasukkan item/data ke dalam stack di posisi yang paling atas
void push(char* item, int nomorStack)
{
    if (!isFull())
    {
        switch(nomorStack)
        {
        case 1:
            top1++;
            
            // meng-copy value string dari item ke dalam index pada stack 1
            strcpy(stack[top1], item);
            break;
        case 2:
            top2--;

            // meng-copy value string dari item ke dalam index pada stack 2
            strcpy(stack[top2], item);
            break;
        default:
            printf("\nNomor stack yang anda masukkan salah!\n");
            break;
        }
    }
    else
    {
        printf("Stack sudah penuh!\n\n");
    }
}

// Menghapus item/data dari stack (a.k.a mindahin posisi top1 dan top2)
char* pop(int nomorStack)
{
    char* item;

    if (!isEmpty(nomorStack))
    {
        switch (nomorStack)
        {
        case 1:
            item = stack[top1];
            top1--;
            stack[top1][0] = '\0';
            return item;
            break;
        case 2:
            item = stack[top2];
            stack[top2][0] = '\0';
            top2--;
            return item;
            break;
        default:
            printf("\nNomor stack salah!\n");
            item = "0";
            return item;
            break;
        }
    }
    else
    {
        printf("\nStack masih kosong!\n");
        item = "0";
        return item;
    }
}

// Cek jika stack sudah penuh atau belum
bool isFull()
{
    return top1+1 >= top2;
}

// Cek apakah stack kosong
bool isEmpty(int nomorStack)
{
    switch (nomorStack)
    {
    case 1:
        return top1 == -1; 
        break;
    case 2:
        return top2 == MAX_ARRAY;
        break;
    default:
        printf("Nomor stack yang anda masukan salah!\n");
        return 0;
        break;
    }
}

// Membersihkan isi stack
void clear(int nomorStack)
{
    switch (nomorStack)
    {
    case 1:
        // Membersihkan array stack
        for (int i = 0; i <= top1; i++) 
        {
            // Set tiap karakter pertama 
            // pada setiap index array of strings ke null-terminator
            stack[i][0] = '\0'; 
        } 

        top1 = -1;
        break;
    case 2:
        // Membersihkan array stack
        for (int i = MAX_ARRAY-1; i >= top2; i--) 
        {
            // Set tiap karakter pertama 
            // pada setiap index array of strings ke null-terminator
            stack[i][0] = '\0'; 
        } 

        top2 = MAX_ARRAY;
        break;
    default:
        printf("Nomor stack yang anda masukan salah!\n");
        break;
    }
}

// Menampilkan isi stack
void display()
{
    printf("Baca isi stack pertama: \n");

    for (int i = 0; i <= top1; i++)
    {
        printf("\t%s\n", stack[i]);
    }

    printf("Baca isi stack kedua: \n");

    for (int i = MAX_ARRAY-1; i >= top2; i--)
    {
        printf("\t%s\n", stack[i]);
    }

    printf("\n");
} 