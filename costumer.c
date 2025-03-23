#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customer.h"

List ListCustomers;

// Menambahkan pelanggan baru ke daftar
void TambahPelanggan(int id, char nama[], int saldoAwal) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        CustomerData *cust = (CustomerData*)malloc(sizeof(CustomerData));
        cust->id = id;
        strcpy(cust->nama, nama);
        cust->saldo = saldoAwal;
        info(P) = (infotype)cust;
        next(P) = Nil;
        
        Insertlast(&ListCustomers, (infotype)cust);
    }
}

// Mencari pelanggan berdasarkan ID
CustomerData* CariPelanggan(int id) {
    address P = ListCustomers.first;
    while (P != Nil) {
        CustomerData* cust = (CustomerData*)info(P);
        if (cust->id == id) {
            return cust;
        }
        P = next(P);
    }
    return NULL;
}

// Mendapatkan nama pelanggan
char* GetNamaPelanggan(int id) {
    CustomerData* pelanggan = CariPelanggan(id);
    return pelanggan != NULL ? pelanggan->nama : "Tidak Ditemukan";
}

// Mendapatkan saldo pelanggan
int GetSaldoPelanggan(int id) {
    CustomerData* pelanggan = CariPelanggan(id);
    return pelanggan != NULL ? pelanggan->saldo : -1;
}

// Menampilkan seluruh daftar pelanggan
void TampilkanPelanggan() {
    system("cls");
    if (IsEmpty(ListCustomers)) {
        printf("Tidak ada pelanggan terdaftar.\n");
    } else {
        printf("=== DAFTAR PELANGGAN ===\n");
        address P = ListCustomers.first;
        while (P != Nil) {
            CustomerData* cust = (CustomerData*)info(P);
            printf("ID: %d | Nama: %s | Saldo: Rp %d\n", cust->id, cust->nama, cust->saldo);
            P = next(P);
        }
    }

    printf("\n[0] Kembali ke Menu Utama\n");
    int kembali;
    scanf("%d", &kembali);
}

