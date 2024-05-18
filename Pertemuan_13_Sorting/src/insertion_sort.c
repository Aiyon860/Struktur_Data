/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 13: Sorting
 *  Nama File: insertion_sort.c 
 */ 

// Preprocessor
#include <stdio.h>
#include <time.h>

// Function Declarations
void insertion_sort(int* arr, int n);
void print_array(int* arr, int sz);

// Main Entry Point
int main()
{
  int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("\nArray sebelum diurutkan: ");
  print_array(arr, n);

  clock_t t = clock();

  insertion_sort(arr, n);

  t = clock() - t;
  double time_taken = (double)t / CLOCKS_PER_SEC;

  printf("\nWaktu yang dihabiskan: %lf detik", time_taken);

  printf("\nArray setelah diurutkan: ");
  print_array(arr, n);

  return 0;
}

// Function Definitions
void insertion_sort(int* arr, int n)
{
  int i, j, key;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void print_array(int* arr, int sz)
{
  printf("[ ");
  for (int i = 0; i < sz; i++)
  {
    printf("%d%s", arr[i], i + 1 != sz ? ", " : " ");
  }
  printf("]");
}