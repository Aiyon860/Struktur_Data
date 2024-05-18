/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 12: Searching
 *  Nama File: search_short_ver.c 
 */ 

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // rest of the code....
  return 0;
}

int main()
{
  int cari, i, n;

  printf("\n");
  printf("Masukkan banyaknya jumlah data: ");
  scanf("%d", &n);
  fflush(stdin);

  int* data = (int*)calloc(n, sizeof(int));

  printf("Input setiap data integer sebanyak %d:\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &data[i]);

  printf("\nInput data yang ingin dicari: ");
  scanf("%d", &cari);

  clock_t t = clock();

  for (i = 0; i < n; i++)
  {
    if (data[i] == cari)
    {
      printf("%d berada di indeks %d", cari, i);
      break;
    }
  }

  if (i == n)
    printf("%d tidak ada.\n", cari);

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("\nWaktu yang dihabiskan: %lf detik", time_taken);

  free(data);
  return 0;
}