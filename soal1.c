//PRAK PMP MODUL 3 EA
//EL2008 Praktikum Pemecahan Maslaah dengan Pemrograman 2025/2026 
//MOdul : 3 - Structures and Dynamic Arrays
//Soal : Soal 1 Array Dinamis
//Hari dan Tanggal : Selasa, 28 April 2026
//Pembuat : Amelia Rahma Nurradliyah
//NIM : 13224020

//analogi masalah soal 1 penjaga kubah
//jadi ada kubah dimana ada [petugas yang berbeda shift yang menjaganya]
//kondisi dan aturannya tuh:
// 1. SHITNYA PAGI SIANG ATAU MALAM
// 2. RANKING DALAM SHIFT NYA
/*- SKOR LEBIH TINGGI LEBIH BAIK
-JIKA SAMA, ID LEBIH KECIL LEBIH BAIK
JIKA SAMA, NAMA LAFABETIS LEBIH KECIL LEBIH BAIK*/
//3. JIKA SUATU SHIFT TIDAK MEMILIKI PENJAGA CETAK -

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
 
//menyimpan data penjaga dlu karena ini make array dinamis maka biikin struck buat nyimpen data 
typedef struct{
    char nama [100];
    int id;
    char shift[20];
    int skor;
} penjaga;
int main(){
    int n;
    scanf("%d", &n);

    //ini make array dinamis disini agar gampang penyimpanan datanya
    penjaga*data = (penjaga*)malloc(n*sizeof(penjaga));
    for (int i = 0; i < n; i++){
        scanf("%s", data[i].nama);
        scanf("%d", &data[i].id);
        scanf("%s", data[i].shift);
        scanf("%d", &data[i].skor);
    }
    
    //indeks untuk shift pagi, siang, malam
    int pagi = -1, siang = -1, malam = -1;
    for (int i = 0; i < n; i++){
                // cek shift pagi
        if (strcmp(data[i].shift, "PAGI") == 0) {
            if (pagi == -1 ||
                data[i].skor > data[pagi].skor ||
                (data[i].skor == data[pagi].skor &&  data[i].id < data[pagi].id) ||
                (data[i].skor == data[pagi].skor && data[i].id == data[pagi].id &&
                 strcmp(data[i].nama, data[pagi].nama) < 0)) {
                pagi = i;
            }
        }

        // cek shift siang
        else if (strcmp(data[i].shift, "SIANG") == 0) {
            if (siang == -1 ||
                data[i].skor > data[siang].skor ||
                (data[i].skor == data[siang].skor && data[i].id < data[siang].id) ||
                (data[i].skor == data[siang].skor && data[i].id == data[siang].id &&
                 strcmp(data[i].nama, data[siang].nama) < 0)) {
                siang = i;
            }
        }

        // cek shift malam
        else if (strcmp(data[i].shift, "MALAM") == 0) {
            if (malam == -1 ||
                data[i].skor > data[malam].skor ||
                (data[i].skor == data[malam].skor && data[i].id < data[malam].id) ||
                (data[i].skor == data[malam].skor && data[i].id == data[malam].id &&
                 strcmp(data[i].nama, data[malam].nama) < 0)) {
                malam = i;
            }
        }
    }

    // output pagi
    if (pagi == -1)
        printf("PAGI -\n");
    else
        printf("PAGI %s %d %d\n", data[pagi].nama, data[pagi].id, data[pagi].skor);

    // output siang
    if (siang == -1)
        printf("SIANG -\n");
    else
        printf("SIANG %s %d %d\n", data[siang].nama, data[siang].id, data[siang].skor);

    // output malam
    if (malam == -1)
        printf("MALAM -\n");
    else
        printf("MALAM %s %d %d\n", data[malam].nama, data[malam].id, data[malam].skor);

    // beres dipake, balikin memori
    free(data);
    return 0;
}
