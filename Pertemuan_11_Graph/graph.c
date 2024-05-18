/*
 *  Nama: Daniel Adi Pratama
 *  NIM: 4.33.23.0.07
 *  Kelas: TI-1A
 *  Mata Kuliah: Struktur Data
 *  Dosen: Eri Eli Lavindi, M.Kom
 *  Pertemuan 11: Graph
 *  Nama File: graph.c 
 */ 

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Simpul Simpul;
typedef struct Jalur Jalur;

// Node Definition
typedef struct Simpul {
  char* infoSimpul;     // Node name
  Simpul* nextSimpul;   // Reference to next Node in list
  Jalur* jalur;         // Reference to next edge the Node have
} Simpul;

// Edge Definition
typedef struct Jalur {
  int bebanJalur;       // load or weight of edge
  Jalur* nextJalur;     // Reference to next edge in edge list
  Simpul* simpul;       // Reference to destination Node from edge
} Jalur;

// Graph Definition
typedef struct Graph {
  int jumlahSimpul;     // Amounts of Node in Graph
  Simpul* firstSimpul;  // Reference to first Node in Node list
  Jalur* firstJalur;    // Reference to first edge in edge list (not used in these code)
} Graph;

// Functions Declaration
Simpul* createSimpul(const char* infoSimpul);
Jalur* createJalur(int bebanJalur, Jalur* nextJalur, Simpul* simpul);
Graph* createGraph();
void addNode(Graph* graph, const char* name);
void addEdge(Graph* graph, const char* src, const char* dest, int weight);
void printGraph(Graph* graph);

// Main Entry Point
int main()
{
  // Create new Graph
  Graph* G = createGraph();

  // Add Nodes into Graph
  addNode(G, "A");
  addNode(G, "B");
  addNode(G, "C");
  addNode(G, "D");

  // Add Edges into Graph
  addEdge(G, "A", "B", 3);
  addEdge(G, "B", "C", 2);
  addEdge(G, "C", "D", 1);
  addEdge(G, "D", "A", 5);
  addEdge(G, "B", "D", 4);
  
  // Print-out Graph to show all nodes and edges
  printGraph(G);

  return EXIT_SUCCESS;
}

// Functions Definition
// Use: Create new node with certain name.
Simpul* createSimpul(const char* infoSimpul)
{
  Simpul* simpul = (Simpul*)malloc(sizeof(Simpul));
  simpul->infoSimpul = strdup(infoSimpul);
  simpul->nextSimpul = NULL;
  simpul->jalur = NULL;
  return simpul;
}

// Use: Create new edge with certain height and direction.
Jalur* createJalur(int bebanJalur, Jalur* nextJalur, Simpul* simpul)
{
  Jalur* jalur = (Jalur*)malloc(sizeof(Jalur));
  jalur->bebanJalur = bebanJalur;
  jalur->nextJalur = nextJalur;
  jalur->simpul = simpul;
  return jalur;
}

// Use: Create new Graph
Graph* createGraph()
{
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->jumlahSimpul = 0;
  graph->firstSimpul = NULL;
  graph->firstJalur = NULL;   // not used
  return graph;
}

// Use: Adding Node into Graph
void addNode(Graph* graph, const char* name)
{
  // Create new node with certain name
  Simpul* newNode = createSimpul(name);

  // If first node is empty, adjust newNode as first node
  if (graph->firstSimpul == NULL)
  {
    graph->firstSimpul = newNode;
  }
  else
  {
    // If not, do iteration through a list of nodes and add new node in the end
    Simpul* node = graph->firstSimpul;
    while (node->nextSimpul != NULL)
    {
      node = node->nextSimpul;
    }
    node->nextSimpul = newNode;
  }

  // Add the amount of nodes
  (graph->jumlahSimpul)++;
  printf("Tambah Simpul %s pada Graph\n", name);
}

// Use: Adding Edge into Graph
void addEdge(Graph* graph, const char* src, const char* dest, int weight)
{
  // Searching source node and destination node based on name
  Simpul* begin = graph->firstSimpul;
  Simpul* end = graph->firstSimpul;
  while (begin != NULL && strcmp(begin->infoSimpul, src) != 0)
  {
    begin = begin->nextSimpul;
  }
  while (end != NULL && strcmp(end->infoSimpul, dest) != 0)
  {
    end = end->nextSimpul;
  }

  // If source node AND destination node found
  if (begin != NULL && end != NULL)
  {
    // Do iteration through a list of edges from source node to check whether the edge already exist.
    Jalur* jalur = begin->jalur;
    bool ada = false;
    while (jalur != NULL)
    {
      if (strcmp(jalur->simpul->infoSimpul, dest) == 0)
      {
        ada = true;    // Edge already exist.
        break;
      }
      jalur = jalur->nextJalur;
    }

    if (ada)
    {
      printf("Sudah ada jalur dari %s ke %s\n", src, dest);
    }
    else
    {
      // If there isn't any edge yet, add new edge
      Jalur* newJalur = createJalur(weight, begin->jalur, end);
      begin->jalur = newJalur;
      printf("Tambah jalur dari %s ke %s dengan bobot %d\n", src, dest, weight);
    }
  }
}

// Use: Print-out Graph
void printGraph(Graph* graph)
{
  // Do iteration through a list of nodes
  Simpul* node = graph->firstSimpul;
  while (node != NULL)
  {
    printf("\nSimpul: %s\n", node->infoSimpul);
    
    // Do iteration through a list of edges from a node
    Jalur* jalur = node->jalur;
    while (jalur != NULL)
    {
      printf("Ada jalur ke simpul: %s dengan beban: %d\n", jalur->simpul->infoSimpul, jalur->bebanJalur);
      jalur = jalur->nextJalur;
    }
    node = node->nextSimpul;
  }
}