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
        printf("Belum ada buku terdaftar!\n");
        return NULL;
    }
    
    printf("\nDaftar Buku:\n");
    Buku* current = daftarBuku;
    int i = 1;
    while (current) {
        printf("%d. %s (Stok: %d)\n", i++, current->judul, current->stok);
        current = current->nextBuku;
    }
    
    printf("Pilih buku (nomor): ");
    int pilihan;
    scanf("%d", &pilihan);
    getchar();
    
    current = daftarBuku;
    for (int j = 1; j < pilihan && current; j++) {
        current = current->nextBuku;
    }
    
    return current;
}

void bersihkanMemori(Buku* daftarBuku) {
    while (daftarBuku) {
        Buku* next = daftarBuku->nextBuku;
        
        // Hapus semua peminjam dalam antrian
        while (!isQueueEmpty(daftarBuku->antrian)) {
            QueueNode* node = daftarBuku->antrian.front;
            Peminjam* p = (Peminjam*)node->data;
            free(p);
            daftarBuku->antrian.front = node->next;
            free(node);
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
        scanf("%d", &pilihan);
        getchar();
        
        switch(pilihan) {
            case 1: { // Tambah buku
                char judul[100];
                int stok;
                
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = '\0';
                
                printf("Stok: ");
                scanf("%d", &stok);
                getchar();
                
                insertBuku(&daftarBuku, judul, stok);
                printf("Buku berhasil ditambahkan!\n");
                break;
            }
                
            case 2: { // tampilkan buku
                printf("\n=== DAFTAR BUKU ===\n");
                Buku* current = daftarBuku;
                while (current) {
                    printf("%s (Stok: %d, Antrian: %d)\n", 
                          current->judul, current->stok, 
                          queueSize(current->antrian));
                    current = current->nextBuku;
                }
                break;
            }
                
            case 3: { // tambah peminjam
                Buku* buku = pilihBuku(daftarBuku);
                if (!buku) break;
                
                char nama[100], tipe[20];
                
                printf("Nama Peminjam: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                
                printf("Tipe (dosen/mahasiswa/umum): ");
                fgets(tipe, sizeof(tipe), stdin);
                tipe[strcspn(tipe, "\n")] = '\0';
                
                int prioritas = prioritasLevel(tipe);
                tambahPeminjam(buku, nama, prioritas);
                printf("Peminjam ditambahkan ke antrian %s\n", buku->judul);
                break;
            }
                
            case 4: { // tampilkan antrian
                Buku* buku = pilihBuku(daftarBuku);
                if (buku) tampilAntrianBuku(buku);
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
			        printf("\nGagal memproses peminjaman\n");
			    }
			    break;
			}
                
            case 6: { // pengembalian buku
                Buku* buku = pilihBuku(daftarBuku);
                if (buku) {
                    buku->stok++;
                    printf("Stok %s bertambah menjadi %d\n", buku->judul, buku->stok);
                }
                break;
            }
            
            case 7: {  // Batalkan Peminjaman
			    Buku* buku = pilihBuku(daftarBuku);
				    if (!buku) break;
				
				    char nama[100];
				    printf("Nama Peminjam yang akan dibatalkan: ");
				    fgets(nama, sizeof(nama), stdin);
				    nama[strcspn(nama, "\n")] = '\0';
				
				    batalkanPeminjaman(buku, nama);
				    break;
				}
                
            case 0:
                printf("Program selesai\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);
    
    bersihkanMemori(daftarBuku);
    return 0;
}
