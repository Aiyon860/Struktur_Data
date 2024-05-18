/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 13: Sorting
 *  Nama File: selection_sort.c 
 */ 

// Preprocessor
#include <stdio.h>
#include <time.h>

// Function Declarations
void selection_sort(int* arr, int n);
void print_array(int* arr, int sz);

// Main Entry Point
int main()
{
  int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("\nArray sebelum diurutkan: ");
  print_array(arr, n);

  clock_t t = clock();

  selection_sort(arr, n);

  t = clock() - t;
  double time_taken = (double)t / CLOCKS_PER_SEC;

  printf("\nWaktu yang dihabiskan: %lf detik", time_taken);

  printf("\nArray setelah diurutkan: ");
  print_array(arr, n);

  return 0;
}

// Function Defintiions
void selection_sort(int* arr, int n)
{
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++)
  {
    min_idx = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
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