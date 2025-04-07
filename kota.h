#ifndef KOTA_H
#define KOTA_H

#include "linked.h"

typedef struct Kota {
    char nama[50];
    List daftarPenduduk;
    struct Kota *next;
} Kota;

typedef struct {
    Kota *first;
} ListKota;

void CreateListKota(ListKota *LK);
Kota *SearchKota(ListKota LK, char *namaKota);
void EntryData(ListKota *LK, char *namaKota, char *namaOrang);
void HapusKota(ListKota *LK, char *namaKota);
void TampilkanData(ListKota LK);
int CountKota(ListKota LK);
void HapusPenduduk(ListKota *LK, char *namaKota, char *namaOrang);
void CariKota(ListKota LK, char *namaKota);
void UbahNamaKota(ListKota *LK, char *namaLama, char *namaBaru);
void PindahkanPenduduk(ListKota *LK, char *namaAsal, char *namaTujuan, char *namaOrang);
int CekPenduduk(Kota *kota, char *namaOrang);

#endif
