#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

void CreateListKota(ListKota *LK) {
    LK->first = NULL;
}

Kota *SearchKota(ListKota LK, char *namaKota) {
    Kota *P = LK.first;
    while (P != NULL && strcmp(P->nama, namaKota) != 0) {
        P = P->next;
    }
    return P;
}

void EntryData(ListKota *LK, char *namaKota, char *namaOrang) {
    Kota *kota = SearchKota(*LK, namaKota);
    if (kota == NULL) {
        kota = (Kota *)malloc(sizeof(Kota));
        strcpy(kota->nama, namaKota);
        CreateList(&(kota->daftarPenduduk));
        kota->next = LK->first;
        LK->first = kota;
    }
    Insertlast(&(kota->daftarPenduduk), namaOrang);
}

void HapusKota(ListKota *LK, char *namaKota) {
    if (CountKota(*LK) <= 5) {
        printf("Tidak bisa menghapus, minimal harus ada 5 kota yang tersedia.\n");
        return;
    }

    Kota *P = LK->first, *prev = NULL;
    while (P != NULL && strcmp(P->nama, namaKota) != 0) {
        prev = P;
        P = P->next;
    }
    if (P != NULL) {
        if (prev == NULL) {
            LK->first = P->next;
        } else {
            prev->next = P->next;
        }
        DeleteAll(&(P->daftarPenduduk));
        free(P);
        printf("Kota %s berhasil dihapus.\n", namaKota);
    } else {
        printf("Kota %s tidak ditemukan.\n", namaKota);
    }
}

void TampilkanData(ListKota LK) {
    Kota *P = LK.first;
    while (P != NULL) {
        printf("Kota: %s\n", P->nama);
        printf("  Penduduk: ");
        PrintList(P->daftarPenduduk);
        P = P->next;
    }
}

int CountKota(ListKota LK) {
    int count = 0;
    Kota *P = LK.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void HapusPenduduk(ListKota *LK, char *namaKota, char *namaPenduduk) {
    Kota *kota = SearchKota(*LK, namaKota);
    if (kota == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    if (!CekPenduduk(kota, namaPenduduk)) {
        printf("Penduduk %s tidak ditemukan di kota %s.\n", namaPenduduk, namaKota);
        return;
    }

    Delete(&(kota->daftarPenduduk), namaPenduduk);
    printf("Penduduk %s telah dihapus dari kota %s.\n", namaPenduduk, namaKota);
}

void CariKota(ListKota LK, char *namaKota) {
    Kota *kota = SearchKota(LK, namaKota);
    if (kota != NULL) {
        printf("Kota ditemukan: %s\n", kota->nama);
        printf("Daftar penduduk: ");
        PrintList(kota->daftarPenduduk);
    } else {
        printf("Kota %s tidak ditemukan.\n", namaKota);
    }
}

void UbahNamaKota(ListKota *LK, char *namaLama, char *namaBaru) {
    Kota *kota = SearchKota(*LK, namaLama);
    if (kota != NULL) {
        strcpy(kota->nama, namaBaru);
        printf("Nama kota berhasil diubah dari %s menjadi %s.\n", namaLama, namaBaru);
    } else {
        printf("Kota %s tidak ditemukan.\n", namaLama);
    }
}

void PindahkanPenduduk(ListKota *LK, char *kotaAsal, char *kotaTujuan, char *namaPenduduk) {
    Kota *asal = SearchKota(*LK, kotaAsal);
    Kota *tujuan = SearchKota(*LK, kotaTujuan);

    if (asal == NULL || tujuan == NULL) {
        printf("Kota asal atau tujuan tidak ditemukan.\n");
        return;
    }

    if (!CekPenduduk(asal, namaPenduduk)) {
        printf("Penduduk %s tidak ditemukan di kota %s.\n", namaPenduduk, kotaAsal);
        return;
    }

    Delete(&(asal->daftarPenduduk), namaPenduduk);
    Insertlast(&(tujuan->daftarPenduduk), namaPenduduk);
    printf("Penduduk %s dipindahkan dari %s ke %s.\n", namaPenduduk, kotaAsal, kotaTujuan);
}

int CekPenduduk(Kota *kota, char *namaPenduduk) {
    address P = kota->daftarPenduduk.first;
    while (P != NULL) {
        if (strcmp(P->info, namaPenduduk) == 0) {
            return 1;
        }
        P = P->next;
    }
    return 0;
}
