#ifndef KOTA_H
#define KOTA_H

#include "linked.h"  

#define MAX_KOTA 10  

typedef struct {
    char namaKota[50];  
    List daftarOrang;    
} Kota;

typedef struct {
    Kota kotaArray[MAX_KOTA];  
    int jumlahKota;            
} DataKota;

void EntryData(DataKota *DK, char *namaKota, char *namaOrang);
void HapusKota(DataKota *DK, char *namaKota);
void TampilkanData(DataKota *DK, char *namaKota);
int HitungPenduduk(List *L);

#endif
