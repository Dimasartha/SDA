#include <stdio.h>
#include "customer.h"
#include "transaksi.h"
#include "operasi.h"

Queue Antrian;
Stack RiwayatTransaksi; 
List ListCustomers;
int pelangganID = 1;

int main() {
    CreateQueue(&Antrian);
    CreateStack(&RiwayatTransaksi);
    CreateList(&ListCustomers);

    int pilihan;
    while (1) {
        system("cls");
        printf("\n=== SIMULASI BANK ===\n");
        printf("[1] Ambil Antrian\n");
        printf("[2] Proses Antrian\n");
        printf("[3] Tampilkan Pelanggan\n");
        printf("[4] Tampilkan Riwayat\n");
        printf("[5] Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: AmbilAntrian(&Antrian, &pelangganID); break;
            case 2: ProsesAntrian(&Antrian, &RiwayatTransaksi); break;
            case 3: TampilkanPelanggan(); break;
            case 4: TampilkanRiwayat(RiwayatTransaksi); getchar(); getchar(); break;
            case 5: return 0;
            default: printf("Pilihan tidak valid!\n");
        }
    }
}

