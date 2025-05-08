#include "perpustakaan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void tampilMenu() {
    printf("\n===== SISTEM PERPUSTAKAAN =====\n");
    printf("1. Tambah Buku\n");
    printf("2. Tampilkan Daftar Buku\n");
    printf("3. Tambah Peminjam\n");
    printf("4. Tampilkan Antrian Buku\n");
    printf("5. Proses Peminjaman\n");
    printf("6. Pengembalian Buku\n");
    printf("7. Batalkan Peminjaman\n");
    printf("0. Keluar\n");
    printf("Pilihan: ");
}

void bersihkanMemori() {
    for (int i = 0; i < jumlahBuku; i++) {
        Peminjam* current = daftarBuku[i].head;
        while (current) {
            Peminjam* next = current->next;
            free(current);
            current = next;
        }
    }
}

int main() {
    initPerpustakaan();
    int pilihan;
    
    // Data awal untuk testing
    tambahBuku("Buku1", 1);
    tambahBuku("Buku2", 1);
    
    do {
        tampilMenu();
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid! Silakan masukkan angka.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();
        
        switch(pilihan) {
            case 1: { // Tambah Buku
                char judul[100];
                int stok;
                
                printf("\nJudul Buku: ");
                if (!fgets(judul, sizeof(judul), stdin)) {
                    printf("Error membaca input!\n");
                    break;
                }
                judul[strcspn(judul, "\n")] = '\0';
                
                printf("Stok: ");
                if (scanf("%d", &stok) != 1) {
                    printf("Stok harus berupa angka!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();
                
                if (tambahBuku(judul, stok) != -1) {
                    printf("Buku berhasil ditambahkan!\n");
                }
                break;
            }
                
            case 2: { // Tampilkan Daftar Buku
                tampilSemuaBuku();
                break;
            }
                
            case 3: { // Tambah Peminjam
                int index;
                char nama[100], tipe[20];
                
                tampilSemuaBuku();
                if (jumlahBuku == 0) break;
                
                printf("Pilih buku (nomor): ");
                if (scanf("%d", &index) != 1) {
                    printf("Input tidak valid!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();
                index--;
                
                if (index < 0 || index >= jumlahBuku) {
                    printf("Nomor buku tidak valid!\n");
                    break;
                }
                
                printf("Nama Peminjam: ");
                if (!fgets(nama, sizeof(nama), stdin)) {
                    printf("Error membaca input!\n");
                    break;
                }
                nama[strcspn(nama, "\n")] = '\0';
                
                printf("Tipe (dosen/mahasiswa/umum): ");
                if (!fgets(tipe, sizeof(tipe), stdin)) {
                    printf("Error membaca input!\n");
                    break;
                }
                tipe[strcspn(tipe, "\n")] = '\0';
                
                tambahPeminjam(index, nama, prioritasLevel(tipe));
                break;
            }
                
            case 4: { // Tampilkan Antrian Buku
                int index;
                
                tampilSemuaBuku();
                if (jumlahBuku == 0) break;
                
                printf("Pilih buku (nomor): ");
                if (scanf("%d", &index) != 1) {
                    printf("Input tidak valid!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();
                index--;
                
                tampilAntrianBuku(index);
                break;
            }
                
            case 5: { // Proses Peminjaman
                int index;
                
                tampilSemuaBuku();
                if (jumlahBuku == 0) break;
                
                printf("Pilih buku (nomor): ");
                if (scanf("%d", &index) != 1) {
                    printf("Input tidak valid!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();
                index--;
                
                prosesPeminjaman(index);
                break;
            }
                
            case 6: { // Pengembalian Buku
                int index;
                
                tampilSemuaBuku();
                if (jumlahBuku == 0) break;
                
                printf("Pilih buku (nomor): ");
                if (scanf("%d", &index) != 1) {
                    printf("Input tidak valid!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();
                index--;
                
                kembalikanBuku(index);
                break;
            }
                
            case 7: { // Batalkan Peminjaman
                int index;
                char nama[100];
                
                tampilSemuaBuku();
                if (jumlahBuku == 0) break;
                
                printf("Pilih buku (nomor): ");
                if (scanf("%d", &index) != 1) {
                    printf("Input tidak valid!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();
                index--;
                
                printf("Nama Peminjam yang akan dibatalkan: ");
                if (!fgets(nama, sizeof(nama), stdin)) {
                    printf("Error membaca input!\n");
                    break;
                }
                nama[strcspn(nama, "\n")] = '\0';
                
                batalkanPeminjaman(index, nama);
                break;
            }
                
            case 0:
                printf("\nTerima kasih telah menggunakan sistem perpustakaan!\n");
                break;
                
            default:
                printf("\nPilihan tidak valid! Silakan pilih 0-7.\n");
        }
    } while (pilihan != 0);
    
    bersihkanMemori();
    return 0;
}
