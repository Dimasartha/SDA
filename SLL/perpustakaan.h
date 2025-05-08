#ifndef PERPUSTAKAAN_H
#define PERPUSTAKAAN_H

#include "queue.h"
#include <stdbool.h>

typedef struct {
    char nama[100];
    int prioritas;
    struct Peminjam* nextPeminjam;
} Peminjam;

typedef struct Buku {
    char judul[100];
    int stok;
    PriorityQueue antrian;
    struct Buku* nextBuku;
} Buku;

// Fungsi buku
void insertBuku(Buku** head, const char* judul, int stok);
Buku* cariBuku(Buku* head, const char* judul);
void tampilBuku(Buku* head);

// Fungsi peminjam
void tambahPeminjam(Buku* buku, const char* nama, int prioritas);
Peminjam* prosesPeminjaman(Buku* buku);
void kembalikanBuku(Buku* buku);
void tampilAntrianBuku(Buku* buku);
void batalkanPeminjaman(Buku* buku, const char* nama);

int prioritasLevel(const char* tipe);
const char* getTipePrioritas(int level);
void freePeminjam(void* data);

#endif
