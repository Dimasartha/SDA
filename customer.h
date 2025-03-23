#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "linked.h"

typedef struct {
    int id;
    char nama[50];
    int saldo;
} CustomerData;

void TambahPelanggan(int id, char nama[], int saldoAwal);
CustomerData* CariPelanggan(int id);
char* GetNamaPelanggan(int id);
int GetSaldoPelanggan(int id);
void TampilkanPelanggan();

#endif

