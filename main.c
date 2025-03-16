#include "Mahasiswa.h"

int main() {
    List L1, L2;
    CreateList(&L1);
    CreateList(&L2);

    // 1) Tambahkan mahasiswa ke L1 (urutan ascending berdasarkan nama)
    Insertascending(&L1, "Dimas", 78);
    Insertascending(&L1, "Dimas", 85);
    Insertascending(&L1, "Asep", 60);
    Insertascending(&L1, "Robi", 90);
    Insertascending(&L1, "Gerrard", 73);

    // 2) Tampilkan isi L1 (Ascending Nama)
    printf("Isi List L1 (Ascending Nama):\n");
    PrintList(L1);
    printf("\n");

    // 3) Tampilkan isi L1 (Descending Nilai UTS)
    printf("Isi List L1 (Descending Nilai UTS):\n");
    PrintDescendingnilai(L1);
    printf("\n");

    // 4) Hitung jumlah mahasiswa dalam L1
    printf("Jumlah mahasiswa dalam L1: %d\n\n", CountList(L1));

    // 5) Salin mahasiswa dengan nilai UTS > 70 ke L2
    CopyL2(L1, &L2);
    printf("Isi List L2 setelah menyalin mahasiswa dengan nilai > 70:\n");
    PrintList(L2);
    printf("\n");

    // 6) Hapus nama duplikat di L2
    DeleteDuplicate(&L2);
    printf("Isi List L2 setelah menghapus duplikat:\n");
    PrintList(L2);
    printf("\n");

    // 7) Hapus semua elemen dari L1 dan L2
    DeleteAll(&L1);
    DeleteAll(&L2);
    printf("L1 dan L2 telah dihapus.\n");

    return 0;
}

