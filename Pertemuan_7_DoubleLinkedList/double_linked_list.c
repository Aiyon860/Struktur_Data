/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 7: Double Linked List
 *  Nama File: double_linked_list.c 
 */

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

// Struct
typedef struct node 
{
    int data;
    struct node* prev;
    struct node* next; 
} Node;

Node* pHead = NULL;

// Functions Declaration
Node* alokasi_node_baru(int bil);
Node* tambah_awal(int bil);
void cetak();
Node* tambah_tengah(int sisip, int bil);
Node* tambah_akhir(int bil);
Node* hapus_awal();
Node* hapus_tengah(int hapus);
Node* hapus_akhir();
void isPalindrome();

// Main Entry Point
int main(int argc, char** argv)
{
    int pilih, bil, sisip;

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
                printf("Masukkan Bilangan: ");
                scanf("%d", &bil);
                pHead = tambah_awal(bil);
                break;
            case 2:
                printf("Masukkan Nilai yang Ingin Ditambahkan: ");
                scanf("%d", &bil);
                printf("Data Disisipkan Setelah Nilai: ");
                scanf("%d", &sisip);
                pHead = tambah_tengah(sisip, bil);
                break;
            case 3:
                printf("Masukkan Nilai yang Ingin Ditambahkan: ");
                scanf("%d", &bil);
                pHead = tambah_akhir(bil);
                break;
            case 4:
                pHead = hapus_awal();
                break;
            case 5:
                printf("Masukkan Bilangan yang Ingin Dihapus: ");
                scanf("%d", &bil);
                pHead = hapus_tengah(bil);
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
    
    return 0;
}

// Functions Definition
Node* alokasi_node_baru(int bil)
{
    Node* pNew = (Node*) malloc(sizeof(Node));
    pNew -> data = bil;
    return pNew;
}

Node* tambah_awal(int bil)
{
    Node* pNew = alokasi_node_baru(bil);

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
        printf("Node Ke-%d = %d\n", i, pWalker -> data);
        i++;
        pWalker = pWalker -> next;
    }
}

Node* tambah_tengah(int sisip, int bil)
{
    Node* pNew = alokasi_node_baru(bil);
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

Node* tambah_akhir(int bil)
{
    Node* pNew = alokasi_node_baru(bil);
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

Node* hapus_tengah(int hapus)
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
    bool flag = true;

    if (pHead != NULL && pHead -> next != NULL)
    {
        Node* awal = pHead;
        Node* akhir = pHead;
        
        while (akhir -> next != NULL) 
        {
            akhir = akhir -> next;
        }

        while ((awal != akhir) && (awal -> prev != akhir))
        {
            if (awal -> data != akhir -> data)
            {
                flag = false;
            }
            awal = awal -> next;
            akhir = akhir -> prev;
        }
    }

    if (flag)
    {
        printf("List ini termasuk Palindrome!\n");
    }
    else
    {
        printf("List ini bukan termasuk Palindrome!\n");
    }
}