#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq == NULL || pq->size == 0){
    return NULL;
  }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq == NULL){
    return;
  }
  if(pq->size == pq->capac){
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
  }
  heapElem nuevoElem;
  nuevoElem.data = data;
  nuevoElem.priority = priority;
  int index= pq->size;
  pq->heapArray[index] = nuevoElem;
  pq->size++;

  while(index > 0 && pq->heapArray[index].priority > pq->heapArray[(index-1)/2].priority){
    heapElem temp = pq->heapArray[index];
    pq->heapArray[index]= pq->heapArray[(index-1)/2];
    pq->heapArray[(index-1)/2] = temp;
    index = (index-1)/2;
  }
}


void heap_pop(Heap* pq){
  pq->heapArray[0]= pq->heapArray[pq->size];
  pq->size--;
}

Heap* createHeap(){
  Heap* nuevo= (Heap*)malloc(sizeof(Heap));
  nuevo->capac = 3;
  nuevo->size = 0;
  nuevo->heapArray= (heapElem*)malloc(sizeof(heapElem)*nuevo->capac);
  return nuevo;
}
