/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 7: Double Linked List
 *  Nama File: latihan_double_linked_list.c 
 */

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 4096

// Struct
typedef struct node 
{
    char data[LEN];
    struct node* prev;
    struct node* next; 
} Node;

Node* pHead = NULL;

// Functions Declaration
Node* alokasi_node_baru(char* kata);
Node* tambah_awal(char* kata);
void cetak();
Node* tambah_tengah(char* sisip, char* kata);
Node* tambah_akhir(char* kata);
Node* hapus_awal();
Node* hapus_tengah(char* hapus);
Node* hapus_akhir();
void isPalindrome();

// Main Entry Point
int main(int argc, char** argv)
{
    int pilih;
    char* kata = (char*) malloc(sizeof(char) * LEN);
    char* sisip = (char*) malloc(sizeof(char) * LEN);

    do
    {
        system("cls");
        printf("--------> MENU <--------");
        printf("\n1. Tambah Awal");
        printf("\n2. Tambah Tengah");
        printf("\n3. Tambah Akhir");
        printf("\n4. Hapus Awal");
        printf("\n5. Hapus Tengah");
        printf("\n6. Hapus Akhir");
        printf("\n7. Cetak");
        printf("\n8. Cek Apakah Palindrome");
        printf("\n9. Exit");
        printf("\nPilihan: ");
        scanf("%d", &pilih);
        fflush(stdin);

        switch(pilih)
        {
            case 1:
                printf("Masukkan Kata: ");
                fgets(kata, LEN, stdin);
                *(kata + strlen(kata) - 1) = '\0';
                fflush(stdin);
                pHead = tambah_awal(kata);
                break;
            case 2:
                printf("Masukkan Kata yang Ingin Ditambahkan: ");
                printf("Data Disisipkan Setelah Kata: ");
                fgets(kata, LEN, stdin);
                *(kata + strlen(kata) - 1) = '\0';
                fflush(stdin);
                pHead = tambah_tengah(sisip, kata);
                break;
            case 3:
                printf("Masukkan Kata yang Ingin Ditambahkan: ");
                fgets(kata, LEN, stdin);
                *(kata + strlen(kata) - 1) = '\0';
                fflush(stdin);
                pHead = tambah_akhir(kata);
                break;
            case 4:
                pHead = hapus_awal();
                break;
            case 5:
                printf("Masukkan Kata yang Ingin Dihapus: ");
                fgets(kata, LEN, stdin);
                *(kata + strlen(kata) - 1) = '\0';
                fflush(stdin);
                pHead = hapus_tengah(kata);
                break;
            case 6:
                pHead = hapus_akhir();
                break;
            case 7:
                cetak();
                getch();
                break;
            case 8:
                isPalindrome();
                getch();
                break;
            case 9:
                break;
            default:
                printf("Pilihan Tidak Valid!\n");
        }
    } while (pilih != 9);

    free(kata);
    free(sisip);
    
    return 0;
}

// Functions Definition
Node* alokasi_node_baru(char* kata)
{
    Node* pNew = (Node*) malloc(sizeof(Node));
    strcpy(pNew -> data, kata);
    return pNew;
}

Node* tambah_awal(char* kata)
{
    Node* pNew = alokasi_node_baru(kata);

    if (pHead == NULL)
    {
        pNew -> prev = NULL;
        pNew -> next = NULL;
        pHead = pNew;
    }
    else
    {
        pNew -> prev = NULL;
        pNew -> next = pHead;
        pHead = pNew;
    }

    return pHead;
}

void cetak()
{
    Node* pWalker = pHead;
    int i = 1;
    while (pWalker != NULL)
    {
        printf("Node Ke-%d = %s\n", i, pWalker -> data);
        i++;
        pWalker = pWalker -> next;
    }
}

Node* tambah_tengah(char* sisip, char* kata)
{
    Node* pNew = alokasi_node_baru(kata);
    Node* pWalker = pHead;

    while (pWalker != NULL && pWalker -> data != sisip)
    {
        pWalker = pWalker -> next;
    }

    if (pWalker == NULL)
    {
        printf("\nData tidak ditemukan!");
        getch();
    }
    else
    {
        pNew -> next = pWalker -> next;
        pNew -> prev = pWalker;
        if (pWalker -> next != NULL)
        {
            pWalker -> next -> prev = pNew;
        }
        pWalker -> next = pNew;
    }

    return pHead;
}

Node* tambah_akhir(char* kata)
{
    Node* pNew = alokasi_node_baru(kata);
    Node* pEnd = pHead;

    if (pHead == NULL)
    {
        pNew -> prev = NULL;
        pNew -> next = NULL;
        pHead = pNew;
    }
    else
    {
        while (pEnd -> next != NULL)
        {
            pEnd = pEnd -> next;
        }
        pEnd -> next = pNew;
        pNew -> prev = pEnd;
        pNew -> next = NULL;
    }

    return pHead;
}

Node* hapus_awal()
{
    if (pHead != NULL)
    {
        Node* pHapus = pHead;
        pHead = pHead -> next;
        if (pHead != NULL)
        {
            pHead -> prev = NULL;
        }
        free(pHapus);
    }

    return pHead;
}

Node* hapus_tengah(char* hapus)
{
    if (pHead != NULL)
    {
        Node* pCari = pHead;

        while (pCari != NULL && pCari -> data != hapus)
        {
            pCari = pCari -> next;
        }

        if (pCari == NULL)
        {
            printf("\nData tidak ditemukan!");
            getch();
        }
        else
        {
            if (pCari -> prev != NULL)
            {
                pCari -> prev -> next = pCari -> next;
            }

            if (pCari -> next != NULL)
            {
                pCari -> next -> prev = pCari -> prev;
            } 
            free(pCari);
        }
    }
    else
    {
        printf("\nData tidak ditemukan!");
        getch();
    }

    return pHead;
}

Node* hapus_akhir()
{
    if (pHead != NULL)
    {
        Node* pEnd = pHead;
        while(pEnd -> next != NULL)
        {
            pEnd = pEnd -> next;
        }

        if (pEnd -> prev != NULL)
        {
            pEnd -> prev -> next = NULL;
        }
        else
        {
            pHead = NULL;
        }
        free(pEnd);
    }

    return pHead;
}

void isPalindrome()
{
    char* target = (char*) malloc(sizeof(char) * LEN);

    printf("Mau Pilih String yang Mana: ");
    fgets(target, LEN, stdin);
    *(target + strlen(target) - 1) = '\0';
    fflush(stdin);

    Node* pCari = pHead;

    while (pCari != NULL && strcmp(pCari -> data, target) != 0)
    {
        pCari = pCari -> next;
    }

    if (pCari == NULL)
    {
        printf("String Tidak Ditemukan!\n");
        return;
    }

    bool flag = true;

    char* awal = pCari -> data;
    char* akhir = pCari -> data + strlen(pCari -> data) - 1;
    
    while (awal < akhir)
    {
        if (tolower(*awal) != tolower(*akhir))
        {
            flag = false;
            break;
        }
        awal++;
        akhir--;
    }

    if (flag)
    {
        printf("\"%s\" adalah Palindrome!\n", target);
    }
    else
    {
        printf("\"%s\" bukan merupakan Palindrome!\n", target);
    }

    free(target);
}