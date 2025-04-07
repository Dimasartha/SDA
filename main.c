#include <stdio.h>
#include "kota.h"

void InisialisasiKotaAwal(ListKota *LK) {
    EntryData(LK, "Jakarta", "Dimas");
    EntryData(LK, "Bandung", "Budi");
    EntryData(LK, "Klaten", "Robi");
    EntryData(LK, "Medan", "Gerrard");
    EntryData(LK, "Yogyakarta", "Sadio");
}

int main() {
    ListKota LK;
    CreateListKota(&LK);
    InisialisasiKotaAwal(&LK);

    int pilihanUtama, subPilihan;
    char namaKota[50], namaOrang[50];
    char kotaAsal[50], kotaTujuan[50];

    do {
    	system("cls");
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Kelola Penduduk\n");
        printf("2. Kelola Kota\n");
        printf("3. Lihat Seluruh Data\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihanUtama);
        getchar(); // flush newline

        switch (pilihanUtama) {
            case 1:
                do {
                	system("cls");
                    printf("\n-- Kelola Penduduk --\n");
                    printf("1. Tambah penduduk ke kota\n");
                    printf("2. Hapus penduduk dari kota\n");
                    printf("3. Pindahkan penduduk antar kota\n");
                    printf("0. Kembali\n");
                    printf("Sub-pilihan: ");
                    scanf("%d", &subPilihan);
                    getchar();

                    switch (subPilihan) {
                        case 1:
                            printf("Masukkan nama kota: ");
                            fgets(namaKota, sizeof(namaKota), stdin);
                            namaKota[strcspn(namaKota, "\n")] = 0;

                            printf("Masukkan nama penduduk: ");
                            fgets(namaOrang, sizeof(namaOrang), stdin);
                            namaOrang[strcspn(namaOrang, "\n")] = 0;

                            EntryData(&LK, namaKota, namaOrang);
                            printf("\nTekan Enter untuk kembali...");
                            getchar();
                            break;

                        case 2:
                            printf("Masukkan nama kota: ");
                            fgets(namaKota, sizeof(namaKota), stdin);
                            namaKota[strcspn(namaKota, "\n")] = 0;

                            printf("Masukkan nama penduduk yang ingin dihapus: ");
                            fgets(namaOrang, sizeof(namaOrang), stdin);
                            namaOrang[strcspn(namaOrang, "\n")] = 0;

                            HapusPenduduk(&LK, namaKota, namaOrang);
                            printf("\nTekan Enter untuk kembali...");
                            getchar();
                            break;

                        case 3:
                            printf("Masukkan nama kota asal: ");
                            fgets(kotaAsal, sizeof(kotaAsal), stdin);
                            kotaAsal[strcspn(kotaAsal, "\n")] = 0;

                            printf("Masukkan nama kota tujuan: ");
                            fgets(kotaTujuan, sizeof(kotaTujuan), stdin);
                            kotaTujuan[strcspn(kotaTujuan, "\n")] = 0;

                            printf("Masukkan nama penduduk yang ingin dipindahkan: ");
                            fgets(namaOrang, sizeof(namaOrang), stdin);
                            namaOrang[strcspn(namaOrang, "\n")] = 0;

                            PindahkanPenduduk(&LK, kotaAsal, kotaTujuan, namaOrang);
                            printf("\nTekan Enter untuk kembali...");
    						getchar();
                            break;

                        case 0:
                            break;

                        default:
                            printf("Sub-pilihan tidak valid!\n");
                    }

                } while (subPilihan != 0);
                break;

            case 2:
                do {
                	system("cls");
                    printf("\n-- Kelola Kota --\n");
                    printf("1. Hapus kota\n");
                    printf("2. Ubah nama kota\n");
                    printf("3. Cari kota\n");
                    printf("0. Kembali\n");
                    printf("Sub-pilihan: ");
                    scanf("%d", &subPilihan);
                    getchar();

                    switch (subPilihan) {
                        case 1:
                            printf("Masukkan nama kota yang ingin dihapus: ");
                            fgets(namaKota, sizeof(namaKota), stdin);
                            namaKota[strcspn(namaKota, "\n")] = 0;

                            HapusKota(&LK, namaKota);
                            printf("\nTekan Enter untuk kembali...");
                            getchar();
                            break;

                        case 2:
                            printf("Masukkan nama kota yang ingin diubah: ");
                            fgets(namaKota, sizeof(namaKota), stdin);
                            namaKota[strcspn(namaKota, "\n")] = 0;

                            printf("Masukkan nama baru: ");
                            fgets(namaOrang, sizeof(namaOrang), stdin); // namaOrang jadi penampung sementara
                            namaOrang[strcspn(namaOrang, "\n")] = 0;

                            UbahNamaKota(&LK, namaKota, namaOrang);
                            printf("\nTekan Enter untuk kembali...");
                            getchar();
                            break;

                        case 3:
                            printf("Masukkan nama kota yang ingin dicari: ");
                            fgets(namaKota, sizeof(namaKota), stdin);
                            namaKota[strcspn(namaKota, "\n")] = 0;

                            CariKota(LK, namaKota);
                            printf("\nTekan Enter untuk kembali...");
                            getchar();
                            break;

                        case 0:
                            break;

                        default:
                            printf("Sub-pilihan tidak valid!\n");
                    }

                } while (subPilihan != 0);
                break;

            case 3:
                TampilkanData(LK);
                printf("\nTekan Enter untuk kembali...");
                getchar();
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihanUtama != 0);

    return 0;
}
