/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 13: Sorting
 *  Nama File: bubble_sort.c 
 */ 

// Preprocessor
#include <stdio.h>
#include <time.h>

// Function Declarations
void bubble_sort(int* arr, int n);
void print_array(int* arr, int sz);

// Main Entry Point
int main()
{
  int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("\nArray sebelum diurutkan: ");
  print_array(arr, n);

  clock_t t = clock();

  bubble_sort(arr, n);

  t = clock() - t;
  double time_taken = (double)t / CLOCKS_PER_SEC;

  printf("\nWaktu yang dihabiskan: %lf detik", time_taken);

  printf("\nArray setelah diurutkan: ");
  print_array(arr, n);

  return 0;
}

// Function Definitions
void bubble_sort(int* arr, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
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
