#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Edit.c"

void loading()
{
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 20; i++) {
        printf("%c", 9); // kalau mau simbol lain tinggal ubah angkanya
        sleep(100);
    }
}

int main(){
    int pil, ul;

    loading();
    do{
        system("cls");
        menu:
        printf("\n  Program Input Nilai");
        printf("\n  ---------------------");
        printf("\n  1. Input Data");
        printf("\n  2. Edit Data");
        printf("\n  3. Display Data");
        printf("\n  4. Keluar");
        printf("\n  ---------------------");
        printf ("\n Ketik pilihan Anda: ");

        scanf  ("%d", &pil);
        system("cls");

        switch (pil)
        {
            case 1:
                input();
                break;
            case 2:
                edit();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("\n   Maaf, pilihan tidak tersedia\n");
                sleep(5);
                fflush (stdin);
                goto menu;
                break;
        }
        fflush (stdin);
        printf("\n\n Apakah anda ingin mengulang? Ketik 1 jika iya: ");
        scanf("%d", &ul);
    }while(ul==1);

    return 0;
}
