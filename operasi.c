#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operasi.h"

// Ambil Antrian
void AmbilAntrian(Queue *Antrian, int *pelangganID) {
    system("cls");
    printf("Masukkan nama pelanggan: ");
    char nama[50];
    scanf("%s", nama);

    TambahPelanggan(*pelangganID, nama, 100000);
    Enqueue(Antrian, *pelangganID);
    (*pelangganID)++;

    printf("\nAntrian saat ini:\n");
    PrintQueue(*Antrian);
    
    printf("\n[0] Kembali ke Menu Utama\n");
    int kembali;
    scanf("%d", &kembali);
}

// Proses Antrian
void ProsesAntrian(Queue *Antrian, Stack *RiwayatTransaksi) {
    system("cls");
    if (!IsEmptyQueue(*Antrian)) {
        int id = Antrian->first->info;
        printf("Proses pelanggan ID %d (%s)\n", id, GetNamaPelanggan(id));
        Dequeue(Antrian);

        int jumlah, pilihan;
        printf("\nPilih jenis transaksi:\n");
        printf("[1] Setor Tunai\n");
        printf("[2] Tarik Tunai\n");
        printf("[0] Kembali ke Menu Utama\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 0) return;

        printf("Masukkan jumlah transaksi: ");
        scanf("%d", &jumlah);

        if (pilihan == 1) {
            SetorTunai(RiwayatTransaksi, id, jumlah);
        } else if (pilihan == 2) {
            TarikTunai(RiwayatTransaksi, id, jumlah);
        } else {
            printf("Jenis transaksi tidak valid!\n");
        }

        printf("\n[0] Kembali ke Menu Utama\n");
        int kembali;
        scanf("%d", &kembali);
    } else {
        printf("Antrian kosong!\n");
    }
}

