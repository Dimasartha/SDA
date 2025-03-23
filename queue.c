#include "Queue.h"

#include<stdio.h>
#include<stdlib.h>

void CreateQueue(Queue *Q) {
	CreateList(Q);
}

void Enqueue(Queue *Q, int nomor) {
	Insertlast(Q, nomor);
	printf("Nomor antrian %d telah ditambahkan.\n", nomor);
}

void Dequeue(Queue *Q) {
    if (!IsEmptyQueue(*Q)) {
        printf("Nomor antrian %d selesai diproses.\n", Q->first->info);
        Deletefirst(Q);
    } else {
        printf("Tidak ada antrian yang bisa diproses.\n");
    }
}

int IsEmptyQueue(Queue Q) {
	return (Q.first == Nil);
}

void PrintQueue(Queue Q) {
	if (IsEmptyQueue(Q)) {
		printf("Antrian kosong.\n");
	} else {
		printf("Daftar antrian saat ini: \n");
		PrintList(Q);
	}
}

void ProcessQueue(Queue *Q, Teller *tellers, int jumlahTeller) {
    printf("=== PROSES ANTRIAN ===\n");

    int processed = 0;
    for (int i = 0; i < jumlahTeller; i++) {
        if (!IsEmptyQueue(*Q)) {
            tellers[i].pelangganSaatIni = Q->first->info;
            printf("Teller %d sedang melayani Antrian %d...\n", tellers[i].idTeller, tellers[i].pelangganSaatIni);
            Dequeue(Q);
            processed++;
        } else {
            tellers[i].pelangganSaatIni = -1;  // Tidak ada pelanggan
        }
    }

    if (processed == 0) {
        printf("Tidak ada antrian yang bisa diproses.\n");
    }

    printf("\nSisa antrian setelah proses:\n");
    PrintQueue(*Q);
}

void CancelQueue(Queue *Q, int nomor) {
    if (IsEmptyQueue(*Q)) {
        printf("Antrian kosong, tidak ada yang bisa dibatalkan.\n");
        return;
    }

    address P = Q->first;
    int ditemukan = 0;

    while (P != Nil) {
        if (info(P) == nomor) {
            ditemukan = 1;
            break;
        }
        P = next(P);
    }

    if (ditemukan) {
        printf("Nomor antrian %d telah dibatalkan.\n", nomor);
        Delete(Q, nomor);  // Menggunakan modul Delete dari ADT Linked List
    } else {
        printf("Nomor antrian %d tidak ditemukan dalam antrian.\n", nomor);
    }
}
