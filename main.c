#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
	Queue antrian;
	CreateQueue(&antrian);
	
	int pilihan, nomorAntrian = 1, jumlahTeller;
	
	printf("Masukkan jumlah teller: ");
	scanf(" %d", &jumlahTeller);
	getchar();
	
	Teller tellers[jumlahTeller];
    for (int i = 0; i < jumlahTeller; i++) {
        tellers[i].idTeller = i + 1;
        tellers[i].pelangganSaatIni = -1;
    }
	
	while (1) {
		printf("\n============MENU SIMULASI ANTRIAN BANK============\n\n");
		printf("[1] Ambil Nomor Antrian\n");
		printf("[2] Proses Antrian\n");
		printf("[3] Cetak Daftar Antrian\n");
		printf("[4] Batalkan Nomor Antrian\n");
		printf("[5] Keluar\n");
		printf("\nPilih menu: ");
		scanf(" %d", &pilihan);
		getchar();
		
		if (pilihan == 5) {
			system("cls");
			printf("Terima kasih telah menggunakan sistem antrian bank!\n");
			break;
		}
		
		switch (pilihan) {
			case 1:
				system("cls");
				printf("\n============MENU AMBIL NOMOR ANTRIAN============\n\n");
				Enqueue(&antrian, nomorAntrian);
				nomorAntrian++;
				printf("\nTekan Enter untuk kembali ke menu utama...");
                getchar();
                system("cls");
				break;
			
			case 2:
				system("cls");
				printf("\n============MENU PROSES ANTRIAN============\n\n");
				ProcessQueue(&antrian, tellers, jumlahTeller);
				printf("\nTekan Enter untuk kembali ke menu utama...");
                getchar();
				system("cls");
				break;
				
			case 3:
				system("cls");
				printf("\n============MENU DAFTAR ANTRIAN============\n\n");
				PrintQueue(antrian);
				printf("\nTekan Enter untuk kembali ke menu utama...");
                getchar();
                system("cls");
				break;
				
			case 4:
				system("cls");
				printf("\n============MENU BATALKAN ANTRIAN============\n\n");
				int nomor;
				printf("Masukkan nomor antrian: ");
				scanf(" %d", &nomor);
				getchar();
				CancelQueue(&antrian, nomor);
				printf("\nTekan Enter untuk kembali ke menu utama...");
                getchar();
                system("cls");
				break;
				
			default:
				printf("Pilihan tidak valid, coba lagi!\n");
		}
	}
	
	return 0;
}
