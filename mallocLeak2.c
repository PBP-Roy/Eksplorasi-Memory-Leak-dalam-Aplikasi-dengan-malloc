#include <stdio.h>
#include <stdlib.h>

void heapIntensiveFunction(int n) {
    int *heapArray = (int*)malloc(1000000 * sizeof(int));  // Lebih besar
    if (heapArray == NULL) {
        printf("Gagal mengalokasikan memori pada heap!\n");
        return;
    }

    // Isi semua memori untuk memaksa penggunaan fisik
    for (int i = 0; i < 1000000; i++) {
        heapArray[i] = i;
    }

    if (n > 0) {
        heapIntensiveFunction(n - 1);
    }
}


int main() {
    // Panggil fungsi dengan alokasi memori yang intensif
    heapIntensiveFunction(150000);  // Ubah angka ini untuk uji coba lebih dalam
    printf("Program selesai menggunakan heap.\n");
    system("pause");
    return 0;
}