#ifndef QUEUE_H
#define QUEUE_H

#include "linked.h"

#include<stdio.h>
#include<stdlib.h>

typedef List Queue;

typedef struct {
    int idTeller;
    int pelangganSaatIni;
} Teller;

void CreateQueue(Queue *Q);
void Enqueue(Queue *Q, int nomor);
void Dequeue(Queue *Q);
int IsEmptyQueue(Queue Q);
void PrintQueue(Queue Q);
void ProcessQueue(Queue *Q, Teller *tellers, int jumlahTeller);
void CancelQueue(Queue *Q, int nomor);

#endif
