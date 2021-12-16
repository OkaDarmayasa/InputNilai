#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorting.c"

void case1_6();
void case8();
void display();
int search(char NIM[]){
    for (int i = 0; i < MAX; i++){
        if (strcmp(NIM, mhs[i].NIM) == 0){
            return i;
        }
    }
    return -1;
}
void case1_6(int caseBerapa){
    mergeSort(caseBerapa, 0, count-1);
    for(int a = 0; a < count; a++){
        printf("|    NIM    |        NAMA        | TUGAS | QUIZ | KEAKTIFAN | UTS | UAS | RERATA |\n");
        printf("| %-10s| %-19s| %-6d| %-5d| %-10d| %-4d| %-4d| %-7d|\n", mhs[a].NIM, mhs[a].Nama, mhs[a].Nilai[0], mhs[a].Nilai[1],
               mhs[a].Nilai[2], mhs[a].Nilai[3], mhs[a].Nilai[4], mhs[a].Nilai[5]);
    }
}
void case8(){
    char namaDicari[MAX], NIMDicari[11];

    printf("\n  NIM: ");
    scanf("\n");
    scanf("%[^\n]*c", NIMDicari);
    int in = search(NIMDicari); //in itu indeksDicari
        //indeks 0 tugas, 1 quiz, 2 keaktifan, 3 UTS, 4 UAS, 5 rata-rata.
    if (in != -1){
        printf("|    NIM    |        NAMA        | TUGAS | QUIZ | KEAKTIFAN | UTS | UAS | RERATA |\n");
        printf("| %-10s| %-19s| %-6d| %-5d| %-10d| %-4d| %-4d| %-7d|\n", mhs[in].NIM, mhs[in].Nama, mhs[in].Nilai[0], mhs[in].Nilai[1],
               mhs[in].Nilai[2], mhs[in].Nilai[3], mhs[in].Nilai[4], mhs[in].Nilai[5]);
    }else {
        printf("    NIM Tidak Ada\n");
        printf("    Masukkan NIM Kembali\n");
        system("cls");
        display();
    }
}
void display(){
    int jenis;
    printf("    Tipe Display Data yang Diinginkan\n");
    printf("1. Tugas\n"
            "2. Quiz\n"
            "3. Keaktifan\n"
            "4. UTS\n"
            "5. UAS\n"
            "6. Rata-rata\n"
            "7. Nama\n"
            "8. Pencarian NIM\n"
            "Pilihan : ");
    scanf("%d", &jenis);
    switch(jenis){
        case 1:
            case1_6(0);
            break;
        case 2:
            case1_6(1);
            break;
        case 3:
            case1_6(2);
            break;
        case 4:
            case1_6(3);
            break;
        case 5:
            case1_6(4);
            break;
        case 6:
            case1_6(5);
            break;
        case 7:
            //case7
            break;
        case 8:
            case8();
            break;
        default:
            printf("    Pilihan Anda Salah\n");
            display();
    }
}

