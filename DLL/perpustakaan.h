#ifndef PERPUSTAKAAN_H
#define PERPUSTAKAAN_H

#include "queue.h"
#include <stdbool.h>

// Struktur Peminjam
typedef struct Peminjam {
    char nama[100];
    int prioritas;
    struct Peminjam* next;  // Pointer ke peminjam berikutnya
    struct Peminjam* prev;  // Pointer ke peminjam sebelumnya
} Peminjam;

// Struktur Buku
typedef struct Buku {
    char judul[100];
    int stok;
    struct Peminjam* head;  // Pointer ke antrian peminjam
    struct Peminjam* tail;  
    struct Buku* next;      // Pointer ke buku berikutnya
    struct Buku* prev;      // Pointer ke buku sebelumnya
} Buku;

// Fungsi buku
void insertBuku(Buku** head, const char* judul, int stok);
Buku* cariBuku(Buku* head, const char* judul);
void tampilBuku(Buku* head);

// Fungsi peminjam
void tambahPeminjam(Buku* buku, const char* nama, int prioritas);
Peminjam* prosesPeminjaman(Buku* buku);
void kembalikanBuku(Buku* buku);
void batalkanPeminjaman(Buku* buku, const char* nama);
void tampilAntrianBuku(Buku* buku);

int prioritasLevel(const char* tipe);
const char* getTipePrioritas(int level);

#endif
