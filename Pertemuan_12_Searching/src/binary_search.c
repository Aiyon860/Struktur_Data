/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 12: Searching
 *  Nama File: binary_search.c 
 */ 

// Preprocessor
#include <stdio.h>
#include <time.h>

// Function Declarations
int binary_search(int* arr, int n, int k);

// Main Entry Point
int main()
{
  int arr[28] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };

  int data;
  printf("\nEnter element to find (iterative binary search): ");
  scanf("%d", &data);
  fflush(stdin);

  clock_t t;
  t = clock();

  int result = binary_search(arr, 28, data);

  if (result != -1)
    printf("\nElement Found at Position: %d, Index: %d\n", result + 1, result);
  else
  printf("\nElement Not Found");

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("\n\nWaktu yang dihabiskan: %lf detik", time_taken);

  return 0;
}

// Function Definitions
int binary_search(int* arr, int n, int k)
{
  int start = 0, end = n - 1, mid;

  while (start <= end)
  {
    mid = start + ((end - start) / 2);
    if (k == arr[mid])
      return mid;
    else if (k < arr[mid])
      end = mid - 1;
    else if (k > arr[mid])
      start = mid + 1;
  }

  return -1;
}