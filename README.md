
# Grade Tracker

Program ini adalah aplikasi berbasis teks yang digunakan untuk mencatat, menampilkan, menghitung statistik, dan mencari data mahasiswa berdasarkan NIM atau nama. Program ini dibuat menggunakan bahasa pemrograman **C++**.

## Fitur Utama
1. **Tambah Mahasiswa**:
    - Memasukkan **NIM**, **nama**, dan **nilai** mahasiswa dengan validasi.
        - **NIM**: Maksimal 12 digit, hanya angka.
        - **Nilai**: Rentang 0 hingga 100.
    - Menyimpan data mahasiswa yang valid ke dalam daftar.

2. **Tampilkan Daftar Mahasiswa**:
    - Menampilkan data mahasiswa dalam format tabel.
    - Menampilkan pesan jika tidak ada data mahasiswa.

3. **Hitung Statistik Nilai**:
    - Menghitung dan menampilkan:
        - Nilai rata-rata.
        - Nilai tertinggi dan nama mahasiswa.
        - Nilai terendah dan nama mahasiswa.

4. **Cari Mahasiswa**:
    - Mencari mahasiswa berdasarkan:
        - **NIM**
        - **Nama**
    - Menampilkan detail mahasiswa jika ditemukan.

5. **Keluar**:
    - Mengakhiri program.

## Cara Penggunaan
1. **Tampilkan Menu Utama**:
   Program menampilkan menu dengan pilihan:
    - Tambah Mahasiswa
    - Tampilkan Daftar Mahasiswa
    - Hitung Statistik Nilai
    - Cari Mahasiswa
    - Keluar

2. **Pilih Opsi**:
   Masukkan angka sesuai pilihan (1-5). Jika input salah, ulangi hingga benar.

3. **Eksekusi Fitur**:
   Pilih fitur untuk dijalankan:
    - Masukkan data mahasiswa dengan benar untuk menambahkan.
    - Lihat data mahasiswa, hitung statistik, atau cari berdasarkan NIM/Nama.

4. **Ulangi atau Keluar**:
   Setelah menjalankan fitur, program kembali ke menu hingga memilih "Keluar".

## Contoh Output
### Tambah Mahasiswa
**Input**:
- NIM: `123456789012`
- Nama: `Juan`
- Nilai: `85`

**Output**:
```
Mahasiswa berhasil ditambahkan!
```

### Tampilkan Daftar Mahasiswa
**Output**:
```
No.   NIM             Nama                      Nilai
-------------------------------------------------------
1     123456789012    Juan                      85
```

### Hitung Statistik Nilai
**Output**:
```
Statistik                  Nilai
---------------------------------
Nilai Rata-rata            85
Nilai Tertinggi (Nama)     85 (Juan)
Nilai Terendah (Nama)      85 (Juan)
```

### Cari Mahasiswa
**Input**: NIM `123456789012`

**Output**:
```
Mahasiswa Ditemukan:
NIM: 123456789012
Nama: Juan
Nilai: 85
```

## Struktur Program
- **Kelas `GradeTracker`**:
    - `addStudent`: Menambahkan mahasiswa.
    - `displayStudents`: Menampilkan daftar mahasiswa.
    - `calculateStatistics`: Menghitung statistik nilai.
    - `searchStudent`: Mencari mahasiswa.

- **Fungsi `main`**:
    - Menampilkan menu utama dan memproses pilihan.

## Manfaat
- **Validasi Input**: Memastikan data sesuai format.
- **Manajemen Data**: Mengelola data dengan struktur `std::vector`.
- **Statistik Data**: Menghitung rata-rata, nilai tertinggi, dan nilai terendah.
- **Interaktivitas**: Menyediakan pengalaman pengguna yang mudah.

## Catatan
Program ini hanya menggunakan **C++ Standard Library** tanpa dependensi tambahan.
