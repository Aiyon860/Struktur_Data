/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 12: Searching
 *  Nama File: search_long_ver.c 
 */ 

// Preprocessor
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Function Declarations
bool sequential_search(int* arr, int size, int value);
void print_array(int* arr, int size);

// Main Entry Point
int main()
{
  clock_t t;
  t = clock();

  int data[28] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
  
  printf("\n");
  print_array(data, 28);
  printf("\nNilai 5 %s", sequential_search(data, 28, 5) ? "ditemukan" : "tidak ditemukan");
  printf("\nNilai 10202 %s", sequential_search(data, 28, 10202) ? "ditemukan" : "tidak ditemukan");
  printf("\nNilai 900 %s", sequential_search(data, 28, 900) ? "ditemukan" : "tidak ditemukan");
  printf("\nNilai -100 %s", sequential_search(data, 28, -100) ? "ditemukan" : "tidak ditemukan");
  
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("\n\nWaktu yang dihabiskan: %lf detik", time_taken);

  return 0;
}

// Function Definitions
bool sequential_search(int* arr, int size, int value)
{
  int pos = 0;
  bool found = false;
  while (pos < size && !found)
  {
    if (arr[pos] == value)
      found = true;
    else
      pos++;
  }
  return found;
}

void print_array(int* arr, int size)
{
  printf("Isi Array:\n");
  printf("[ ");
  for (int i = 0; i < size; i++)
  {
    printf(
      "%d%s", 
      arr[i], 
      (i + 1 != size ? ", " : " ")
    );
  }
  printf("]\n");
}


