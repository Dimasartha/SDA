#include "kota.h"
#include <stdio.h>
#include <string.h>

void EntryData(DataKota *DK, char *namaKota, char *namaOrang) {
    for (int i = 0; i < DK->jumlahKota; i++) {
        if (strcmp(DK->kotaArray[i].namaKota, namaKota) == 0) {
            Insertlast(&(DK->kotaArray[i].daftarOrang), namaOrang);
            return;
        }
    }

    if (DK->jumlahKota < MAX_KOTA) {
        strcpy(DK->kotaArray[DK->jumlahKota].namaKota, namaKota);
        CreateList(&(DK->kotaArray[DK->jumlahKota].daftarOrang));
        Insertlast(&(DK->kotaArray[DK->jumlahKota].daftarOrang), namaOrang);
        DK->jumlahKota++;
    } else {
        printf("Kapasitas kota penuh!\n");
    }
}

void HapusKota(DataKota *DK, char *namaKota) {
    if (DK->jumlahKota <= 5) {
        printf("Minimal harus ada 5 kota, tidak bisa menghapus lagi!\n");
        return;
    }

    for (int i = 0; i < DK->jumlahKota; i++) {
        if (strcmp(DK->kotaArray[i].namaKota, namaKota) == 0) {
            DeleteAll(&(DK->kotaArray[i].daftarOrang));

            for (int j = i; j < DK->jumlahKota - 1; j++) {
                DK->kotaArray[j] = DK->kotaArray[j + 1];
            }

            DK->jumlahKota--;
            printf("Kota %s berhasil dihapus.\n", namaKota);
            return;
        }
    }

    printf("Kota tidak ditemukan!\n");
}

void TampilkanData(DataKota *DK, char *namaKota) {
    int totalPenduduk = 0;

    // Jika nama kota kosong atau "*", tampilkan semua kota
    if (strcmp(namaKota, "*") == 0) {
        printf("\n===== DATA PENDUDUK PER KOTA =====\n");
        for (int i = 0; i < DK->jumlahKota; i++) {
            int jumlahPenduduk = HitungPenduduk(&(DK->kotaArray[i].daftarOrang));
            totalPenduduk += jumlahPenduduk;

            printf("\nKota: %s\n", DK->kotaArray[i].namaKota);
            printf("Jumlah Penduduk: %d\n", jumlahPenduduk);
            PrintList(DK->kotaArray[i].daftarOrang);
        }

        printf("\n===== RINGKASAN =====\n");
        printf("Total jumlah kota  : %d\n", DK->jumlahKota);
        printf("Total jumlah nama  : %d\n", totalPenduduk);
        return;
    }

    // Jika mencari kota tertentu
    for (int i = 0; i < DK->jumlahKota; i++) {
        if (strcmp(DK->kotaArray[i].namaKota, namaKota) == 0) {
            int jumlahPenduduk = HitungPenduduk(&(DK->kotaArray[i].daftarOrang));
            printf("\nKota: %s\n", namaKota);
            printf("Jumlah Penduduk: %d\n", jumlahPenduduk);
            PrintList(DK->kotaArray[i].daftarOrang);
            return;
        }
    }

    printf("Kota %s tidak ditemukan!\n", namaKota);
}

int HitungPenduduk(List *L) {
    int count = 0;
    address P = L->first;

    while (P != Nil) {
        count++;
        P = next(P);
    }

    return count;
}
