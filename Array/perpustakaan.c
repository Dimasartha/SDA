#include "perpustakaan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

void initPerpustakaan() {
    for (int i = 0; i < MAX_BUKU; i++) {
        daftarBuku[i].judul[0] = '\0';
        daftarBuku[i].stok = 0;
        daftarBuku[i].head = daftarBuku[i].tail = NULL;
    }
    jumlahBuku = 0;
}

int tambahBuku(const char* judul, int stok) {
    if (jumlahBuku >= MAX_BUKU) {
        printf("Kapasitas buku penuh!\n");
        return -1;
    }
    
    strncpy(daftarBuku[jumlahBuku].judul, judul, sizeof(daftarBuku[jumlahBuku].judul) - 1);
    daftarBuku[jumlahBuku].stok = stok;
    daftarBuku[jumlahBuku].head = daftarBuku[jumlahBuku].tail = NULL;
    return jumlahBuku++;
}

void tampilSemuaBuku() {
    printf("\n=== DAFTAR BUKU ===\n");
    for (int i = 0; i < jumlahBuku; i++) {
        int count = 0;
        Peminjam* current = daftarBuku[i].head;
        while (current) {
            count++;
            current = current->next;
        }
        
        printf("%d. %s (Stok: %d, Antrian: %d)\n", 
              i+1, daftarBuku[i].judul, daftarBuku[i].stok, count);
    }
}

void tambahPeminjam(int indexBuku, const char* nama, int prioritas) {
    if (indexBuku < 0 || indexBuku >= jumlahBuku) {
        printf("Index buku tidak valid!\n");
        return;
    }
    
    Peminjam* newP = (Peminjam*)malloc(sizeof(Peminjam));
    if (!newP) {
        printf("Gagal alokasi memori untuk peminjam baru\n");
        return;
    }
    
    strncpy(newP->nama, nama, sizeof(newP->nama) - 1);
    newP->prioritas = prioritas;
    newP->next = NULL;

    // antrian prioritas
    if (!daftarBuku[indexBuku].head || prioritas < daftarBuku[indexBuku].head->prioritas) {
        newP->next = daftarBuku[indexBuku].head;
        daftarBuku[indexBuku].head = newP;
        if (!newP->next) {
            daftarBuku[indexBuku].tail = newP;
        }
    } else {
        Peminjam* current = daftarBuku[indexBuku].head;
        while (current->next && current->next->prioritas <= prioritas) {
            current = current->next;
        }
        newP->next = current->next;
        current->next = newP;
        if (!newP->next) {
            daftarBuku[indexBuku].tail = newP;
        }
    }
}

int prosesPeminjaman(int indexBuku) {
    if (indexBuku < 0 || indexBuku >= jumlahBuku) {
        printf("Index buku tidak valid!\n");
        return 0;
    }
    
    if (daftarBuku[indexBuku].stok <= 0) {
        printf("Stok buku habis!\n");
        return 0;
    }
    
    if (!daftarBuku[indexBuku].head) {
        printf("Tidak ada antrian peminjam!\n");
        return 0;
    }
    
    Peminjam* p = daftarBuku[indexBuku].head;
    daftarBuku[indexBuku].head = p->next;
    if (!daftarBuku[indexBuku].head) {
        daftarBuku[indexBuku].tail = NULL;
    }
    
    daftarBuku[indexBuku].stok--;
    printf("%s berhasil meminjam %s\n", p->nama, daftarBuku[indexBuku].judul);
    free(p);
    return 1;
}

void kembalikanBuku(int indexBuku) {
    if (indexBuku < 0 || indexBuku >= jumlahBuku) {
        printf("Index buku tidak valid!\n");
        return;
    }
    
    daftarBuku[indexBuku].stok++;
    printf("Buku %s berhasil dikembalikan. Stok sekarang: %d\n", 
          daftarBuku[indexBuku].judul, daftarBuku[indexBuku].stok);
}

void batalkanPeminjaman(int indexBuku, const char* nama) {
    if (indexBuku < 0 || indexBuku >= jumlahBuku) {
        printf("Index buku tidak valid!\n");
        return;
    }
    
    Peminjam* current = daftarBuku[indexBuku].head;
    Peminjam* prev = NULL;
    
    while (current && strcmp(current->nama, nama) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (!current) {
        printf("Peminjam tidak ditemukan!\n");
        return;
    }
    
    if (prev) {
        prev->next = current->next;
    } else {
        daftarBuku[indexBuku].head = current->next;
    }
    
    if (!current->next) {
        daftarBuku[indexBuku].tail = prev;
    }
    
    printf("Peminjaman %s berhasil dibatalkan\n", current->nama);
    free(current);
}

void tampilAntrianBuku(int indexBuku) {
    if (indexBuku < 0 || indexBuku >= jumlahBuku) {
        printf("Index buku tidak valid!\n");
        return;
    }
    
    printf("\nAntrian Peminjam untuk %s:\n", daftarBuku[indexBuku].judul);
    if (!daftarBuku[indexBuku].head) {
        printf("Antrian kosong\n");
        return;
    }
    
    Peminjam* current = daftarBuku[indexBuku].head;
    int pos = 1;
    while (current) {
        printf("%d. %s (%s)\n", pos++, current->nama, getTipePrioritas(current->prioritas));
        current = current->next;
    }
}

int prioritasLevel(const char* tipe) {
    if (strcasecmp(tipe, "dosen") == 0) return 1;
    if (strcasecmp(tipe, "mahasiswa") == 0) return 2;
    return 3; // Default untuk umum
}

const char* getTipePrioritas(int level) {
    switch(level) {
        case 1: return "Dosen";
        case 2: return "Mahasiswa";
        case 3: return "Umum";
        default: return "Tidak Dikenal";
    }
}
