#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int count = 0; //variabel global count

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

    printf("\n  &NIM: ");
    scanf("\n");
    scanf("%d", mhs[count].NIM);
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

    printf(" Ingin menambahkan data lagi? Ketik 1 jika iya: ");
    scanf("\n");
    scanf("%c", &ulang);
    if (ulang == '1'){
        goto ulang;
    }
    count++; //saat dipanggil fungsi ini lagi, maka
                 //data akan disimpan di array struct selanjutnya
}

