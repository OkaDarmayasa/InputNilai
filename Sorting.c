#include "Input.c"

void merge(int jenis, int l, int m, int r, int tipe)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    //Array semestara
    struct data L[n1], R[n2];
  
    //Copy data ke array sementara
    for (i = 0; i < n1; i++){
        strcpy(L[i].Nama, mhs[l + i].Nama);
        L[i].NIM = mhs[l + i].NIM;
        L[i].Nilai[0] = mhs[l + i].Nilai[0];
        L[i].Nilai[1] = mhs[l + i].Nilai[1];
    }
    for (j = 0; j < n2; j++){
        strcpy(R[j].Nama, mhs[m + 1 + j].Nama);
        R[j].NIM = mhs[m + 1 + j].NIM;
        R[j].Nilai[0] = mhs[m + 1 + j].Nilai[0];
        R[j].Nilai[1] = mhs[m + 1 + j].Nilai[1];
    }
    /* Menggabungkan kembali array sementara ke array nilai[l..r]*/
    i = 0; //Indeks subarray pertama
    j = 0; //Indeks subarray kedua
    k = l; //Indeks subarray gabungan

    //Sort tipe int
    if(jenis != 6){
        while (i < n1 && j < n2) {
            if ((tipe == 1 && L[i].Nilai[jenis] <= R[j].Nilai[jenis]) || 
                (tipe == 2 && L[i].Nilai[jenis] >= R[j].Nilai[jenis])){
                strcpy(mhs[k].Nama, L[i].Nama);
                mhs[k].NIM = L[i].NIM;
                mhs[k].Nilai[0] = L[i].Nilai[0];
                mhs[k].Nilai[1] = L[i].Nilai[1];
                i++;
            }
            else {
                strcpy(mhs[k].Nama, R[j].Nama);
                mhs[k].NIM = R[j].NIM;
                mhs[k].Nilai[0] = R[j].Nilai[0];
                mhs[k].Nilai[1] = R[j].Nilai[1];
                j++;
            }
            k++;
        }
    }
    //Sort char (Nama)
    else{
        //indeks char
        int a = 0;
        //variabel test
        int test1 = 0;
        int test2 = 0;
        while (i < n1 && j < n2) {
            test1 = L[i].Nama[a];
            test2 = R[j].Nama[a];
            //Menyamakan case (upper ke lower "A => a")
            if(test1 < 'a' && test1 >= 'A'){
                test1 = (test1 + 32);
            }
            if(test2 < 'a' && test2 >= 'A'){
                test2 = (test2 + 32);
            }
            
            if ((tipe == 1 && test1 < test2) ||
                (tipe == 2 && test1 > test2)) {
                strcpy(mhs[k].Nama, L[i].Nama);
                mhs[k].NIM = L[i].NIM;
                mhs[k].Nilai[0] = L[i].Nilai[0];
                mhs[k].Nilai[1] = L[i].Nilai[1];
                i++;
                a = 0;
            }
            else {
                //Jika huruf sama maka dicek ke indeks selanjutnya
                if(test1 == test2){
                    a++;
                    k--;
                }
                else{
                    strcpy(mhs[k].Nama, R[j].Nama);
                    mhs[k].NIM = R[j].NIM;
                    mhs[k].Nilai[0] = R[j].Nilai[0];
                    mhs[k].Nilai[1] = R[j].Nilai[1];
                    j++;
                    a = 0;
                }
            }
            k++;
        }
    }
    //Copy sisa elemen
    while (i < n1) {
        strcpy(mhs[k].Nama, L[i].Nama);
        mhs[k].NIM = L[i].NIM;
        mhs[k].Nilai[0] = L[i].Nilai[0];
        mhs[k].Nilai[1] = L[i].Nilai[1];
        i++;
        k++;
    }
    while (j < n2) {
        strcpy(mhs[k].Nama, R[j].Nama);
        mhs[k].NIM = R[j].NIM;
        mhs[k].Nilai[0] = R[j].Nilai[0];
        mhs[k].Nilai[1] = R[j].Nilai[1];
        j++;
        k++;
    }
}

void mergeSort(int jenis, int l, int r, int tipe)
{
    if (l < r) {
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(jenis, l, m, tipe);
        mergeSort(jenis, m + 1, r, tipe);
  
        merge(jenis, l, m, r, tipe);
    }
}
