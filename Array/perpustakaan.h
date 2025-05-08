#ifndef PERPUSTAKAAN_H
#define PERPUSTAKAAN_H

#define MAX_BUKU 100 // Maksimal buku yang dapat disimpan

typedef struct Peminjam {
    char nama[100];
    int prioritas; // 1=Dosen, 2=Mahasiswa, 3=Umum
    struct Peminjam* next;
} Peminjam;

typedef struct {
    char judul[100];
    int stok;
    Peminjam* head; // Pointer ke antrian peminjam
    Peminjam* tail;
} Buku;

// Fungsi manajemen buku
void initPerpustakaan();
int tambahBuku(const char* judul, int stok);
void tampilSemuaBuku();

// Fungsi manajemen peminjam
void tambahPeminjam(int indexBuku, const char* nama, int prioritas);
int prosesPeminjaman(int indexBuku);
void kembalikanBuku(int indexBuku);
void batalkanPeminjaman(int indexBuku, const char* nama);
void tampilAntrianBuku(int indexBuku);

// Fungsi utilitas
int prioritasLevel(const char* tipe);
const char* getTipePrioritas(int level);

extern Buku daftarBuku[MAX_BUKU];
extern int jumlahBuku;

#endif
