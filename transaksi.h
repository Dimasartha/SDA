#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include "stack.h"

void SetorTunai(Stack *Riwayat, int id, int jumlah);
void TarikTunai(Stack *Riwayat, int id, int jumlah);
void TampilkanRiwayat(Stack S);

#endif

