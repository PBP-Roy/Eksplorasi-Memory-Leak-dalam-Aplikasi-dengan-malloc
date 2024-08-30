#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // Untuk fungsi Sleep pada Windows

int main() {
    const int N = 1000000;  // Jumlah iterasi besar untuk menunjukkan efek memory leak
    int i;
    int total_allocated = 0;

    for (i = 0; i < N; ++i) {
        int* arr = (int*)malloc(100 * sizeof(int));  // Alokasi memori

        // Cek apakah alokasi berhasil
        if (arr == NULL) {
            printf("Memory allocation failed at iteration %d\n", i);
            break;
        }

        // Tambahkan jumlah memori yang dialokasikan ke total
        total_allocated += 100 * sizeof(int);

        // Tampilkan output setiap kali memori bertambah
        if (i % 1000 == 0) {  // Tampilkan setiap 1000 iterasi
            printf("Iteration %d: Total allocated memory: %d bytes\n", i, total_allocated);
            fflush(stdout);  // Pastikan output segera ditampilkan
        }

        // Loop tambahan untuk memperlambat program tanpa menggunakan sleep
        for (int j = 0; j < 10000; j++) {
            // Loop ini tidak melakukan apa-apa, hanya memperlambat eksekusi
        }

        // Memory leak: tidak ada free(arr);
    }

    printf("Program selesai. Total allocated memory: %d bytes\n", total_allocated);
    printf("Program akan tetap berjalan untuk memantau hasil. Tekan Ctrl+C untuk menghentikannya.\n");

    // Loop idle setelah iterasi selesai
    while (1) {
        // Program akan tetap dalam loop ini hingga dihentikan secara manual
        // Anda dapat menambahkan logika tambahan jika diperlukan
        Sleep(1000);  // Jeda 1 detik untuk mengurangi beban CPU
    }

    return 0;
}
