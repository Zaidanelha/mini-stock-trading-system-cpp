# Mini Stock Trading System (C++)

Proyek ini merupakan simulasi sistem trading saham berbasis console yang mengimplementasikan struktur data fundamental menggunakan bahasa C++ tanpa menggunakan STL container.

Proyek ini dikembangkan sebagai portofolio untuk seleksi Asisten Praktikum Mata Kuliah Struktur Data.

---

## Struktur Data yang Diimplementasikan

### 1️. Linked List – Manajemen Portofolio Saham
Digunakan untuk menyimpan data saham yang dimiliki investor secara dinamis.

Fitur:
- Tambah saham
- Hapus saham
- Cari saham berdasarkan kode
- Tampilkan seluruh portofolio
- Hitung total nilai investasi

Kompleksitas Waktu:
- Insert: O(n)
- Delete: O(n)
- Search: O(n)
- Traversal: O(n)

---

### 2️. Circular Queue – Antrian Transaksi
Digunakan untuk mensimulasikan proses transaksi beli dan jual saham dengan prinsip FIFO (First In First Out).

Fitur:
- Enqueue (Tambah transaksi)
- Dequeue (Proses transaksi)
- Tampilkan antrian

Kompleksitas Waktu:
- Enqueue: O(1)
- Dequeue: O(1)
- Display: O(n)

---

### 3️. Binary Search Tree – Database Saham
Digunakan untuk menyimpan data saham agar proses pencarian lebih efisien dibanding struktur linear.

Fitur:
- Insert saham
- Search saham
- Delete saham
- Inorder traversal (menampilkan data terurut)

Kompleksitas Waktu:
- Rata-rata: O(log n)
- Terburuk (skewed tree): O(n)

---

## Cara Menjalankan Program

1. Buka file `MiniStockTradingSystem.sln` menggunakan Microsoft Visual Studio.
2. Pilih project yang ingin dijalankan.
3. Klik kanan pada project → **Set as Startup Project**.
4. Jalankan program dengan menekan tombol **Local Windows Debugger** atau tekan `F5`.

---

## Konteks Akademik

Proyek ini disusun sebagai bagian dari persyaratan seleksi Calon Asisten Praktikum Struktur Data Semester Genap 2025/2026.
