#include "perpustakaan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menambahkan buku baru
void insertBuku(Buku** head, const char* judul, int stok) {
    Buku* newBook = (Buku*)malloc(sizeof(Buku));
    if (!newBook) {
        printf("Gagal alokasi memori untuk buku baru\n");
        return;
    }

    strcpy(newBook->judul, judul);
    newBook->stok = stok;
    newBook->head = newBook->tail = NULL;
    newBook->next = newBook->prev = NULL;

    if (!*head) {
        *head = newBook;
    } else {
        Buku* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newBook;
        newBook->prev = current;
    }
}

// Fungsi untuk mencari buku berdasarkan judul
Buku* cariBuku(Buku* head, const char* judul) {
    Buku* current = head;
    while (current) {
        if (strcmp(current->judul, judul) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menampilkan daftar buku
void tampilBuku(Buku* head) {
    if (!head) {
        printf("Tidak ada buku terdaftar\n");
        return;
    }

    printf("\n=== DAFTAR BUKU ===\n");
    Buku* current = head;
    while (current) {
        printf("Judul: %s | Stok: %d | Jumlah Peminjam: ", 
              current->judul, current->stok);
        
        // Hitung jumlah peminjam
        int count = 0;
        Peminjam* p = current->head;
        while (p) {
            count++;
            p = p->next;
        }
        printf("%d\n", count);
        
        current = current->next;
    }
}

// Fungsi untuk menambahkan peminjam ke antrian buku
void tambahPeminjam(Buku* buku, const char* nama, int prioritas) {
    if (!buku) return;

    Peminjam* newPeminjam = (Peminjam*)malloc(sizeof(Peminjam));
    if (!newPeminjam) {
        printf("Gagal alokasi memori untuk peminjam baru\n");
        return;
    }

    strcpy(newPeminjam->nama, nama);
    newPeminjam->prioritas = prioritas;
    newPeminjam->next = newPeminjam->prev = NULL;

    if (!buku->head) {
        buku->head = buku->tail = newPeminjam;
    } else if (prioritas < buku->head->prioritas) {
        newPeminjam->next = buku->head;
        buku->head->prev = newPeminjam;
        buku->head = newPeminjam;
    } else {
        Peminjam* current = buku->head;
        while (current->next && current->next->prioritas <= prioritas) {
            current = current->next;
        }
        
        newPeminjam->next = current->next;
        newPeminjam->prev = current;
        
        if (current->next) {
            current->next->prev = newPeminjam;
        } else {
            buku->tail = newPeminjam;
        }
        current->next = newPeminjam;
    }
}

// Fungsi untuk memproses peminjaman buku
Peminjam* prosesPeminjaman(Buku* buku) {
    if (!buku || !buku->head || buku->stok <= 0) {
        return NULL;
    }

    Peminjam* p = buku->head;
    buku->head = buku->head->next;
    
    if (buku->head) {
        buku->head->prev = NULL;
    } else {
        buku->tail = NULL;
    }
    
    buku->stok--;
    p->next = p->prev = NULL;
    return p;
}

// Fungsi untuk pengembalian buku
void kembalikanBuku(Buku* buku) {
    if (buku) {
        buku->stok++;
    }
}

// Fungsi untuk menampilkan antrian peminjam suatu buku
void tampilAntrianBuku(Buku* buku) {
    if (!buku) return;

    printf("\nAntrian Peminjam untuk Buku '%s':\n", buku->judul);
    if (!buku->head) {
        printf("Antrian kosong\n");
        return;
    }

    Peminjam* current = buku->head;
    int pos = 1;
    while (current) {
        printf("%d. %s (%s)", pos++, current->nama, 
               getTipePrioritas(current->prioritas));
        
        // Tandai head/tail
        if (current == buku->head) printf(" [HEAD]");
        if (current == buku->tail) printf(" [TAIL]");
        printf("\n");
        
        current = current->next;
    }
}

// Fungsi untuk membatalkan peminjaman
void batalkanPeminjaman(Buku* buku, const char* nama) {
    if (!buku || !buku->head) {
        printf("Antrian kosong\n");
        return;
    }

    // Cari peminjam berdasarkan nama
    Peminjam* current = buku->head;
    while (current && strcmp(current->nama, nama) != 0) {
        current = current->next;
    }

    if (!current) {
        printf("Peminjam tidak ditemukan\n");
        return;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        buku->head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        buku->tail = current->prev;
    }

    printf("Peminjaman %s berhasil dibatalkan\n", current->nama);
    free(current);
}

// Fungsi untuk mengkonversi tipe peminjam ke level prioritas
int prioritasLevel(const char* tipe) {
    if (strcmp(tipe, "dosen") == 0) return 1;
    if (strcmp(tipe, "mahasiswa") == 0) return 2;
    return 3; // Umum
}

// Fungsi untuk mendapatkan string tipe prioritas
const char* getTipePrioritas(int level) {
    switch(level) {
        case 1: return "Dosen";
        case 2: return "Mahasiswa";
        case 3: return "Umum";
        default: return "Tidak Dikenal";
    }
}
