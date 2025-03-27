# Manajemen Data Kota dan Penduduk

> Deskripsi
Program ini merupakan implementasi struktur data Non-Restricted Linear List menggunakan Linked List dalam bahasa C. Program memungkinkan pengguna untuk menambahkan dan menghapus kota serta mengelola daftar penduduk di setiap kota.

> Tujuan
1. Menerapkan konsep linked list dalam pengelolaan data dinamis.
2. Memahami Abstract Data Type (ADT) non-restricted linear list.
3. Mengembangkan program yang dapat menyimpan dan mengelola daftar kota serta penduduknya.

> Implementasi
- Struct Kota: Menyimpan nama kota dan daftar penduduk menggunakan linked list.
- Struct DataKota: Menyimpan daftar kota dengan kapasitas maksimum.
- Fungsi utama*:
  - EntryData() -> Menambahkan penduduk ke dalam kota.
  - HapusKota() -> Menghapus kota dari daftar.
  - TampilkanData() -> Menampilkan data penduduk sesuai kota yang dicari.
  - HitungPenduduk() -> Menghitung jumlah penduduk dalam kota tertentu.

> Struktur File
 main.c         -> File utama
 kota.c         -> Implementasi fungsi terkait kota
 kota.h         -> Header file kota
 linked.c       -> Implementasi linked list
 linked.h       -> Header file linked list
 README.md      -> Dokumentasi proyek
-------------------------------------------------------------------------------------------------------------------------------------------
