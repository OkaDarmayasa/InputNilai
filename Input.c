#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int count = 0; //variabel global sebagai penghitung banyak mahasiswa yang sudah di-input

//Struktur data yang akan menyimpan data mahasiswa
struct data
{
    int NIM;
    char Nama[30];
    int Nilai[6];
    //indeks 0 tugas, 1 quiz, 2 keaktifan, 3 UTS, 4 UAS, 5 rata-rata.
};

struct data mhs[MAX];

void input(){
    int pilihan;
    char ulang;
///*
    printf("\n  NIM: ");
    scanf("\n");
    scanf("%[^\n]*c", mhs[count].NIM);
    printf("\n  Nama: ");
    scanf("\n");
    scanf("%[^\n]*c", mhs[count].Nama);

    ulang:
    printf("\n  Menu Input Data Mahasiswa");
    //                 2008561070
    printf("\n         %s", mhs[count].NIM);
    printf("\n  ---------------------");
    printf("\n  1. Input Nilai Tugas");
    printf("\n  2. Input Nilai Quiz");
    printf("\n  3. Input Nilai Keaktifan");
    printf("\n  4. Input Nilai UTS");
    printf("\n  5. Input Nilai UAS");
    printf("\n  ---------------------");
    printf ("\n Ketik pilihan Anda: ");
    scanf("%d", &pilihan);

    // Pengecekan klo yang dipilih engggak ada di menu
    if (pilihan > 5 || pilihan < 1){
        printf("    Pilihan Tidak Valid!\n");
        goto ulang;
    }

    printf("\n  Nilai    : ");
    scanf("%d", &mhs[count].Nilai[pilihan-1]);//mhs[count] berarti mahasiswa ke-berapa
                                           //.nilai[pilihan] berarti data akan ditaruh di indeks array sesuai pilihan
                                           // pilihan - 1 karena yang diinput user dimulai dari 1, sedangkan array mulai dari 0

//*/
/* //Klo capek nginput wkwk
    mhs[0].NIM = 2008561065;
    strcpy(mhs[0].Nama, "Rian");
    mhs[0].Nilai[0] = 80;
    mhs[0].Nilai[1] = 70;
    mhs[0].Nilai[2] = 100;
    mhs[0].Nilai[3] = 80;
    mhs[0].Nilai[4] = 90;

    mhs[1].NIM = 2008561070;
    strcpy(mhs[1].Nama, "Oka");
    mhs[1].Nilai[0] = 100;
    mhs[1].Nilai[1] = 20;
    mhs[1].Nilai[2] = 90;
    mhs[1].Nilai[3] = 78;
    mhs[1].Nilai[4] = 95;

    mhs[2].NIM = 2008561060;
    strcpy(mhs[2].Nama, "Chelsy");
    mhs[2].Nilai[0] = 90;
    mhs[2].Nilai[1] = 50;
    mhs[2].Nilai[2] = 60;
    mhs[2].Nilai[3] = 100;
    mhs[2].Nilai[4] = 70;
*/
    //Menghitung nilai rata-rata
    int rerata = 0;
    for (int i = 0; i < 5; i++){
        rerata += mhs[count].Nilai[i];
    }
    mhs[count].Nilai[5] = rerata/5;

///*
    printf(" Ingin menambahkan data lagi? Ketik 1 jika iya: ");
    scanf("\n");
    scanf("%c", &ulang);
    if (ulang == '1'){
        goto ulang;
    }
//*/
    count++; //saat dipanggil fungsi ini lagi, maka
                 //data akan disimpan di array struct selanjutnya
}

