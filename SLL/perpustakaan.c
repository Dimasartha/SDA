#include "perpustakaan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk mencetak peminjam
void printPeminjam(void* data) {
    Peminjam* p = (Peminjam*)data;
    printf("- %s (%s)\n", p->nama, getTipePrioritas(p->prioritas));
}

// Fungsi untuk membebaskan memori peminjam
void freePeminjam(void* data) {
    free((Peminjam*)data);
}

// Fungsi untuk menambahkan buku
void insertBuku(Buku** head, const char* judul, int stok) {
    Buku* newBook = (Buku*)malloc(sizeof(Buku));
    strcpy(newBook->judul, judul);
    newBook->stok = stok;
    initQueue(&newBook->antrian);
    newBook->nextBuku = NULL;

    if (!*head) {
        *head = newBook;
    } else {
        Buku* temp = *head;
        while (temp->nextBuku) temp = temp->nextBuku;
        temp->nextBuku = newBook;
    }
}

// Fungsi untuk menambahkan peminjam
void tambahPeminjam(Buku* buku, const char* nama, int prioritas) {
    Peminjam* p = (Peminjam*)malloc(sizeof(Peminjam));
    strcpy(p->nama, nama);
    p->prioritas = prioritas;
    p->nextPeminjam = NULL;

    // Jika antrian kosong, tambahkan peminjam sebagai peminjam pertama
    if (isQueueEmpty(buku->antrian)) {
        enqueue(&buku->antrian, p, prioritas);
    } else {
        // menambahkan peminjam ke dalam antrian berdasarkan prioritas
        QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
        newNode->data = p;
        newNode->priority = prioritas;
        newNode->next = NULL;

        QueueNode* current = buku->antrian.front;
        QueueNode* prev = NULL;

        while (current != NULL && current->priority <= prioritas) {
            prev = current;
            current = current->next;
        }

        if (prev == NULL) {
            newNode->next = buku->antrian.front;
            buku->antrian.front = newNode;
        } else {
            newNode->next = current;
            prev->next = newNode;
        }


        if (newNode->next == NULL) {
            buku->antrian.rear = newNode;
        }
        buku->antrian.size++;
    }
}

// Fungsi untuk memproses peminjaman
Peminjam* prosesPeminjaman(Buku* buku) {
    if (!buku) {
        printf("Buku tidak valid!\n");
        return NULL;
    }

    printf("Memproses peminjaman untuk buku: %s\n", buku->judul);
    
    if (buku->stok <= 0) {
        printf("Stok buku %s habis!\n", buku->judul);
        return NULL;
    }

    if (isQueueEmpty(buku->antrian)) {
        printf("Tidak ada peminjam dalam antrian!\n");
        return NULL;
    }


    Peminjam* p = (Peminjam*)dequeue(&buku->antrian);
    
    if (p) {
        buku->stok--;
        printf("Peminjam %s (%s) berhasil meminjam %s\n", 
              p->nama, getTipePrioritas(p->prioritas), buku->judul);
        printf("Stok tersisa: %d\n", buku->stok);
        return p;
    }
    
    printf("Gagal memproses peminjaman\n");
    return NULL;
}

// Fungsi untuk menampilkan antrian buku
void tampilAntrianBuku(Buku* buku) {
    printf("\nAntrian untuk %s:\n", buku->judul);
    if (isQueueEmpty(buku->antrian)) {
        printf("Antrian kosong\n");
    } else {
        QueueNode* current = buku->antrian.front;
        int i = 1;
        while (current) {
            Peminjam* p = (Peminjam*)current->data;
            printf("%d. %s (%s)\n", i++, p->nama, getTipePrioritas(p->prioritas));
            current = current->next;
        }
    }
}

void batalkanPeminjaman(Buku* buku, const char* nama) {
    if (!buku || isQueueEmpty(buku->antrian)) {
        printf("Tidak ada antrian peminjam untuk buku ini\n");
        return;
    }

    QueueNode* current = buku->antrian.front;
    QueueNode* prev = NULL;
    Peminjam* p = NULL;

    // Cari peminjam berdasarkan nama
    while (current != NULL) {
        p = (Peminjam*)current->data;
        if (strcmp(p->nama, nama) == 0) {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!current) {
        printf("Peminjam dengan nama '%s' tidak ditemukan\n", nama);
        return;
    }

    if (prev == NULL) {
        buku->antrian.front = current->next;
    } else {
        prev->next = current->next;
    }


    if (current == buku->antrian.rear) {
        buku->antrian.rear = prev;
    }


    free(p);
    free(current);
    buku->antrian.size--;

    printf("Peminjaman %s berhasil dibatalkan\n", nama);
}

// Fungsi untuk menentukan level prioritas
int prioritasLevel(const char* tipe) {
    if (strcmp(tipe, "dosen") == 0) {
        return 1; // Prioritas tertinggi
    } else if (strcmp(tipe, "mahasiswa") == 0) {
        return 2; // Prioritas menengah
    } else {
        return 3; // Prioritas terendah
    }
}

// Fungsi untuk mendapatkan tipe prioritas berdasarkan level
const char* getTipePrioritas(int level) {
    switch (level) {
        case 1: return "Dosen";
        case 2: return "Mahasiswa";
        case 3: return "Umum";
        default: return "Tidak Dikenal";
    }
}

