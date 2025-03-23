#include <stdio.h>
#include <stdlib.h>
#include "transaksi.h"
#include "customer.h"

// Setor Tunai
void SetorTunai(Stack *Riwayat, int id, int jumlah) {
    CustomerData* pelanggan = CariPelanggan(id);
    if (pelanggan != NULL) {
        pelanggan->saldo += jumlah;

        Push(Riwayat, id);

        printf("Setor tunai berhasil untuk ID %d (%s) sebesar Rp %d\n", id, pelanggan->nama, jumlah);
    } else {
        printf("Pelanggan tidak ditemukan!\n");
    }
}

// Tarik Tunai
void TarikTunai(Stack *Riwayat, int id, int jumlah) {
    CustomerData* pelanggan = CariPelanggan(id);
    if (pelanggan != NULL && pelanggan->saldo >= jumlah) {
        pelanggan->saldo -= jumlah;

        Push(Riwayat, id);

        printf("Tarik tunai berhasil untuk ID %d (%s) sebesar Rp %d\n", id, pelanggan->nama, jumlah);
    } else {
        printf("Saldo tidak cukup atau pelanggan tidak ditemukan!\n");
    }
}

// Menampilkan Riwayat Transaksi
void TampilkanRiwayat(Stack S) {
    if (IsEmpty(S)) {
        printf("Tidak ada riwayat transaksi.\n");
        return;
    }

    printf("=== RIWAYAT TRANSAKSI ===\n");
    printf("| %-5s | %-10s | %-10s |\n", "ID", "Nama", "Saldo");
    printf("|------|------------|------------|\n");

    Stack temp;
    CreateStack(&temp);

    while (!IsEmpty(S)) {
        int id = Pop(&S);

        CustomerData* pelanggan = CariPelanggan(id);
        if (pelanggan != NULL) {
            printf("| %-5d | %-10s | Rp %-8d |\n", pelanggan->id, pelanggan->nama, pelanggan->saldo);
        }

        Push(&temp, id);
    }

    while (!IsEmpty(temp)) {
        Push(&S, Pop(&temp));
    }
}

