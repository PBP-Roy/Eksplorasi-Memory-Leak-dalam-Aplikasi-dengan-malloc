# Eksplorasi Memory Leak dalam Aplikasi dengan malloc

## Identitas
- **Nama:** Luthfi Satrio Wicaksono
- **NIM:** 231524049

## Detail Program
- **Bahasa Pemrograman**: C
- **Platform**: Windows
- **Fungsi Utama**: 
  - Mengalokasikan memori untuk array `int` berukuran 1000 elemen dalam satu juta iterasi.
  - Mencatat dan menampilkan total memori yang dialokasikan setiap 1000 iterasi.
  
## Cara Kerja
1. Program mengalokasikan memori untuk array `int` dalam jumlah yang ditentukan (`size_to_allocate`).
2. Memeriksa apakah alokasi berhasil. Jika tidak, program akan menghentikan proses dan menampilkan pesan kesalahan.
3. Total memori yang dialokasikan ditambahkan setiap kali alokasi berhasil.
4. Output total memori ditampilkan setiap 1000 iterasi.
5. Program tetap berjalan dalam loop tak terbatas setelah mencapai iterasi maksimum untuk memungkinkan pemantauan penggunaan memori.

## Hasil Eksperimen

Pada eksperimen ini, dilakukan eksplorasi terkait potensi terjadinya **memory leak** dalam aplikasi yang menggunakan `malloc` untuk alokasi memori. Eksperimen ini menunjukkan bahwa aplikasi terus menggunakan memori secara berlebihan saat berjalan, meskipun memori tersebut tidak lagi dibutuhkan.

![Memori yang digunakan oleh aplikasi padahal aplikasi tidak sedang melakukan apapun](Screenshot1.png)
### Observasi

- Setelah beberapa kali penggunaan `malloc`, aplikasi menunjukkan peningkatan penggunaan memori yang terus-menerus.
- Meskipun alokasi memori sudah tidak diperlukan, memori tidak dikembalikan ke sistem, mengindikasikan terjadinya memory leak.
- Aplikasi terus mempertahankan memori yang sudah tidak diperlukan, yang dapat menyebabkan masalah serius dalam jangka panjang, seperti kehabisan memori atau penurunan performa.

### Kesimpulan

Eksperimen ini menggarisbawahi pentingnya mengelola memori dengan benar dalam aplikasi, khususnya dengan memastikan bahwa setiap blok memori yang dialokasikan dengan `malloc` harus dilepaskan dengan `free` setelah tidak lagi dibutuhkan. Tanpa manajemen memori yang baik, aplikasi dapat mengalami memory leak, yang berpotensi menyebabkan gangguan operasi dan menurunkan efisiensi sistem.
