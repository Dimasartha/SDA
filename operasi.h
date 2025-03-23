#ifndef OPERASI_H
#define OPERASI_H

#include "queue.h"
#include "stack.h"
#include "customer.h"

void AmbilAntrian(Queue *Antrian, int *pelangganID);
void ProsesAntrian(Queue *Antrian, Stack *RiwayatTransaksi);

#endif

