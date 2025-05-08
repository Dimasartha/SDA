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

Buku* pilihBuku(Buku* daftarBuku) {
    if (!daftarBuku) {
        printf("\nBelum ada buku terdaftar!\n");
        return NULL;
    }
    
    printf("\n=== DAFTAR BUKU ===\n");
    Buku* current = daftarBuku;
    int i = 1;
    
    while (current) {
        int count = 0;
        Peminjam* p = current->head;
        while (p) {
            count++;
            p = p->next;
        }
        
        printf("%d. %s (Stok: %d, Antrian: %d)\n", 
              i++, current->judul, current->stok, count);
        current = current->next;
    }
    
    printf("\nPilih buku (nomor): ");
    int pilihan;
    if (scanf("%d", &pilihan) != 1) {
        printf("Input tidak valid!\n");
        while (getchar() != '\n');
        return NULL;
    }
    getchar();
    
    if (pilihan < 1) {
        printf("Nomor buku tidak valid!\n");
        return NULL;
    }
    
    current = daftarBuku;
    for (int j = 1; j < pilihan && current; j++) {
        current = current->next;
    }
    
    if (!current) {
        printf("Buku tidak ditemukan!\n");
    }
    
    return current;
}

void bersihkanMemori(Buku* daftarBuku) {
    while (daftarBuku) {
        Buku* next = daftarBuku->next;
        
        Peminjam* current = daftarBuku->head;
        while (current) {
            Peminjam* nextPeminjam = current->next;
            free(current);
            current = nextPeminjam;
        }
        
        free(daftarBuku);
        daftarBuku = next;
    }
}

int main() {
    Buku* daftarBuku = NULL;
    int pilihan;
    
    // Data awal
    insertBuku(&daftarBuku, "Buku1", 1);
    insertBuku(&daftarBuku, "Buku2", 1);
    
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
                
                insertBuku(&daftarBuku, judul, stok);
                printf("\nBuku '%s' berhasil ditambahkan!\n", judul);
                break;
            }
                
            case 2: { // Tampilkan Daftar Buku
                printf("\n=== DAFTAR BUKU ===\n");
                if (!daftarBuku) {
                    printf("Tidak ada buku terdaftar!\n");
                    break;
                }
                
                Buku* current = daftarBuku;
                int i = 1;
                while (current) {
                    // Hitung jumlah peminjam
                    int count = 0;
                    Peminjam* p = current->head;
                    while (p) {
                        count++;
                        p = p->next;
                    }
                    
                    printf("%d. %s (Stok: %d, Antrian: %d)\n", 
                          i++, current->judul, current->stok, count);
                    
                    if (count > 0) {
                        printf("   Antrian terdepan: ");
                        Peminjam* p = current->head;
                        for (int j = 0; j < 3 && p; j++) {
                            printf("%s%s", p->nama, p->next ? ", " : "");
                            p = p->next;
                        }
                        printf("\n");
                    }
                    
                    current = current->next;
                }
                break;
            }
                
            case 3: { // Tambah Peminjam
                Buku* buku = pilihBuku(daftarBuku);
                if (!buku) break;
                
                char nama[100], tipe[20];
                
                printf("\nNama Peminjam: ");
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
                
                // Validasi tipe
                if (strcmp(tipe, "dosen") != 0 && 
                    strcmp(tipe, "mahasiswa") != 0 && 
                    strcmp(tipe, "umum") != 0) {
                    printf("Tipe peminjam tidak valid!\n");
                    break;
                }
                
                int prioritas = prioritasLevel(tipe);
                tambahPeminjam(buku, nama, prioritas);
                printf("\nPeminjam '%s' (%s) berhasil ditambahkan ke antrian '%s'\n", 
                      nama, getTipePrioritas(prioritas), buku->judul);
                break;
            }
                
            case 4: { // Tampilkan Antrian Buku
                Buku* buku = pilihBuku(daftarBuku);
                if (buku) {
                    tampilAntrianBuku(buku);
                }
                break;
            }
                
            case 5: { // Proses Peminjaman
                Buku* buku = pilihBuku(daftarBuku);
                if (!buku) break;
                
                Peminjam* p = prosesPeminjaman(buku);
                if (p) {
                    printf("\n%s (%s) berhasil meminjam %s\n", 
                          p->nama, getTipePrioritas(p->prioritas), buku->judul);
                    printf("Stok tersisa: %d\n", buku->stok);
                    free(p);
                } else {
                    printf("\nGagal memproses peminjaman. Stok habis atau antrian kosong.\n");
                }
                break;
            }
                
            case 6: { // Pengembalian Buku
                Buku* buku = pilihBuku(daftarBuku);
                if (buku) {
                    kembalikanBuku(buku);
                    printf("\nBuku '%s' berhasil dikembalikan. Stok sekarang: %d\n", 
                          buku->judul, buku->stok);
                }
                break;
            }
                
            case 7: { // Batalkan Peminjaman
                Buku* buku = pilihBuku(daftarBuku);
                if (!buku) break;
                
                char nama[100];
                printf("\nNama Peminjam yang akan dibatalkan: ");
                if (!fgets(nama, sizeof(nama), stdin)) {
                    printf("Error membaca input!\n");
                    break;
                }
                nama[strcspn(nama, "\n")] = '\0';
                
                batalkanPeminjaman(buku, nama);
                break;
            }
                
            case 0:
                printf("\nTerima kasih telah menggunakan sistem perpustakaan!\n");
                break;
                
            default:
                printf("\nPilihan tidak valid! Silakan pilih 0-7.\n");
        }
    } while (pilihan != 0);
    
    bersihkanMemori(daftarBuku);
    return 0;
}
