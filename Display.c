#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorting.c"

//casenya jadiin 1 ae.
void case1_9();
void display();
int search();

int search(int NIM){
    //mending pake count aja biar gk kebanyakan
    for (int i = 0; i < count; i++){ 
        if (NIM == mhs[i].NIM){
            return i;
        }
    }
    return -1;
}

void data () 
{ printf("| %-10d| %-19s| %-6d| %-5d| %-10d| %-4d| %-4d| %-7d|\n", mhs[a].NIM, mhs[a].Nama, mhs[a].Nilai[0], mhs[a].Nilai[1],
                   mhs[a].Nilai[2], mhs[a].Nilai[3], mhs[a].Nilai[4], mhs[a].Nilai[5]);}

void case1_9(int caseBerapa){
    if(caseBerapa != 9){
        int tipe;
        printf("    Urut Secara :\n"
               "1. Ascending\n"
               "2. Descending\n"
               "Pilihan : ");
        scanf("%d", &tipe);
        if(tipe != 1 && tipe != 2){
            //Default jika input salah, tipe = ASC
            //Teori database v:
            tipe = 1;
        }
        mergeSort(caseBerapa - 1, 0, count-1, tipe);
        printf("|    NIM    |        NAMA        | TUGAS | QUIZ | KEAKTIFAN | UTS | UAS | RERATA |\n");
        for(int a = 0; a < count; a++){
            data();
        }
    }
    else{
        char namaDicari[MAX], NIMDicari[11];
        printf("\n  NIM: ");
        scanf("\n");
        scanf("%[^\n]*c", NIMDicari);
        int in = search(NIMDicari); //in itu indeksDicari
        //indeks 0 tugas, 1 quiz, 2 keaktifan, 3 UTS, 4 UAS, 5 rata-rata.
        if (in != -1){
            printf("|    NIM    |        NAMA        | TUGAS | QUIZ | KEAKTIFAN | UTS | UAS | RERATA |\n");
            data();
        }else {
            printf("    NIM Tidak Ada\n");
            system("pause");
            //Kalo mau ngulang ke menu utama lagi mending
        }
    }
}

void display(){
    int jenis;
    printf("    Tipe Display Data Urut Bedasarkan: \n");
    printf("1. Tugas\n"
            "2. Quiz\n"
            "3. Keaktifan\n"
            "4. UTS\n"
            "5. UAS\n"
            "6. Rata-rata\n"
            "7. NIM\n"
            "8. Nama\n"
            "9. Pencarian NIM\n"
            "Pilihan : ");
    scanf("%d", &jenis);
    if(jenis < 1 && jenis > 9){
        printf("Pilihan Salah !\n");
        display();
    }
    else{
        case1_9(jenis);
    }
}

