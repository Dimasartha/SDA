#include <stdio.h>
#include "kota.h"

void InisialisasiKotaAwal(DataKota *DK) {
    EntryData(DK, "Jakarta", "Dimas");
    EntryData(DK, "Bandung", "Budi");
    EntryData(DK, "Klaten", "Robi");
    EntryData(DK, "Medan", "Gerrard");
    EntryData(DK, "Yogyakarta", "Sadio");
}

int main() {
    DataKota DK;
    DK.jumlahKota = 0; // Inisialisasi jumlah kota

    InisialisasiKotaAwal(&DK); // Tambahan 5 kota awal

    int pilihan;
    char namaKota[50], namaOrang[50];

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah penduduk ke kota\n");
        printf("2. Hapus kota\n");
        printf("3. Tampilkan data\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;

                printf("Masukkan nama penduduk: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;

                EntryData(&DK, namaKota, namaOrang);
                break;

            case 2:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;

                HapusKota(&DK, namaKota);
                break;

            case 3:
                TampilkanData(&DK, "*");
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
