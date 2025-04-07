# Program Manajemen Kota dan Penduduk (C Language)

Program ini merupakan implementasi struktur data *linked list* ganda dalam bahasa C, yang digunakan untuk mengelola data kota beserta daftar penduduk di setiap kota. Program dibuat sebagai bagian dari studi kasus pembelajaran struktur data dan pemrograman modular.

## Struktur Project

Project
├── main.c
├── kota.c
├── kota.h
├── linked.c
├── linked.h

## Fitur Utama

- Tambah penduduk ke kota
- Hapus kota (jika jumlah kota > 5)
- Tampilkan seluruh data kota dan penduduk
- Hapus penduduk tertentu dari kota
- Cari kota berdasarkan nama
- Ubah nama kota
- Pindahkan penduduk dari satu kota ke kota lain

## Struktur Data

- ListKota: menyimpan daftar kota (linked list dinamis)
- List: menyimpan daftar penduduk dalam setiap kota (linked list dinamis juga)
- File header dan source:
  - linked → berisi operasi dasar list penduduk
  - kota → berisi operasi terhadap list kota dan integrasi dengan list penduduk

## Tampilan Menu

=== MENU UTAMA ===
1. Tampilkan semua data kota & penduduk
2. Kelola Kota
3. Kelola Penduduk
0. Keluar

Submenu seperti Kelola Kota dan Kelola Penduduk memiliki fitur-fitur turunan sesuai fungsionalitasnya.
