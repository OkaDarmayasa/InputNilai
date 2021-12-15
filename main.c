#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Struktur data yang akan menyimpan data mahasiswa
struct data 
{
    char NIM[10];
    char Nama[30];
    int Nilai[6]; 
    //indeks 0 tugas, 1 quiz, 2 keaktifan, 3 UTS, 4 UAS, 5 rata-rata.
};

struct data mhs[MAX];

//Deklarasi fungsi
void landing_page();
int input_data();
void edit_data();
void display();
int search();
int sort_nilai();
int sort_nama();

int main(){
    printf("\nHello Word\n");
    return 0;
}