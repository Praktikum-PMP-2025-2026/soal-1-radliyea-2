/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Amelia Rahma Nurradliyah 13224020
 *   Nama File           : soal1.c
 *   Deskripsi           : Program untuk menentukan penjaga kubah terbaik berdasarkan shift dan kinerja
 * //analogi masalah soal 1 penjaga kubah
jadi ada kubah dimana ada [petugas yang berbeda shift yang menjaganya]
kondisi dan aturannya tuh:
1. SHITNYA PAGI SIANG ATAU MALAM
2. RANKING DALAM SHIFT NYA
*- SKOR LEBIH TINGGI LEBIH BAIK
-JIKA SAMA, ID LEBIH KECIL LEBIH BAIK
JIKA SAMA, NAMA LAFABETIS LEBIH KECIL LEBIH BAIK
3. JIKA SUATU SHIFT TIDAK MEMILIKI PENJAGA CETAK
*/

#include <stdio.h>
#include <string.h>
//masuk struktur penjaganya
typedef struct{
    char nama[100];
    int id;
    char shift[20];
    int skor;
}penjaga;
//pembandingan penjaga yang baik
int lebihbaik(penjaga a, penjaga b){
    if (a.skor > b.skor){
        return 1;
    }
    else if (a.skor < b.skor){
        return 0;
    }
    if (a.id < b.id){
        return 1;
    }
    else if (a.id > b.id){
        return 0;
    }
    if (strcmp(a.nama, b.nama) < 0){
        return 1;
    }
    return 0;
}
//main program masuk
int main(){
    int n;
    scanf("%d", &n);
    penjaga x;
    penjaga pagi, siang, malam;
    int hadir_pagi = 0;
    int hadir_siang = 0;
    int hadir_malam = 0;
    //input data penjaga cke uidah baik apa blm
    for (int i = 0; i < n; i++){
        scanf("%s", x.nama);
        scanf("%d", &x.id);
        scanf("%s", x.shift);
        scanf("%d", &x.skor);
        if (strcmp(x.shift, "PAGI") == 0){ //cek pagi hadir
            if (hadir_pagi == 0 || lebihbaik(x, pagi)){
                pagi = x;
                hadir_pagi = 1;
            }
        }
        else if (strcmp(x.shift, "SIANG") == 0){ //siang hadir
            if (hadir_siang == 0 || lebihbaik(x, siang)){
                siang = x;
                hadir_siang = 1;
            }

        }
        else if (strcmp(x.shift, "MALAM") == 0){ //malam hadir
            if (hadir_malam == 0 || lebihbaik(x, malam)){
                malam = x;
                hadir_malam = 1;
            }
        }
    }
    //cek pagi kondisi
    printf("PAGI ");
    if (hadir_pagi) {
        printf("%s %d %d\n", pagi.nama, pagi.id, pagi.skor);
    } else {
        printf("-\n");
    }
    //cek siang kondisi
    printf("SIANG ");
    if (hadir_siang){
        printf("%s %d %d\n", siang.nama, siang.id, siang.skor);
    } else{
        printf("-\n");
    }
    //cek malam kondisi
    printf("MALAM ");
    if (hadir_malam){
        printf("%s %d %d\n", malam.nama, malam.id, malam.skor);
    } else{
        printf("-\n");
    }
    return 0;
}
