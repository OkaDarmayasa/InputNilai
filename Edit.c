#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Display.c"

void edit(){
    int NIMEdit;
    char ulang;
    int pilihan;
    printf("\n  NIM: ");
    scanf("\n");
    scanf("%d", &NIMEdit);

    //mencari NIM yang ingin diedit di struct, apakah sudah ada atau belom
    int indeksEdit = search(NIMEdit);
    if (indeksEdit != -1){ //berarti ada
        ulang:
        printf("\n  Menu Input Data Mahasiswa");
        //                 2008561070
        printf("\n         %d", mhs[indeksEdit].NIM);
        printf("\n  ---------------------");
        printf("\n  1. Edit Nilai Tugas");
        printf("\n  2. Edit Nilai Quiz");
        printf("\n  3. Edit Nilai Keaktifan");
        printf("\n  4. Edit Nilai UTS");
        printf("\n  5. Edit Nilai UAS");
        printf("\n  ---------------------");
        printf ("\n Ketik pilihan Anda: ");
        scanf("%d", &pilihan);

        // Pengecekan klo yang dipilih enggak ada di menu
        if (pilihan > 5 || pilihan < 1){
            printf("    Pilihan Tidak Valid!\n");
            goto ulang;
        }

        printf("\n  Nilai    : ");
        scanf("%d", &mhs[indeksEdit].Nilai[pilihan-1]);

        //Menghitung nilai rata-rata
        int rerata = 0;
        for (int i = 0; i < 5; i++){
            rerata += mhs[indeksEdit].Nilai[i];
        }
        mhs[indeksEdit].Nilai[5] = rerata/5;

        printf(" Ingin mengedit data lagi? Ketik 1 jika iya: ");
        scanf("\n");
        scanf("%c", &ulang);
        if (ulang == '1'){
            goto ulang;
        }
    }else {//berarti enggak ada
        printf("    NIM Tidak Ada\n");
        printf("    Masukkan NIM Kembali\n");
        edit();
    }
}
