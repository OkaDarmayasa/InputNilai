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
        for(int x = 0; x < 6; x++){
            L[i].Nilai[x] = mhs[l + i].Nilai[x];
        }
    }
    for (j = 0; j < n2; j++){
        strcpy(R[j].Nama, mhs[m + 1 + j].Nama);
        R[j].NIM = mhs[m + 1 + j].NIM;
        for(int x = 0; x < 6; x++){
            R[j].Nilai[x] = mhs[m + 1 + j].Nilai[x];
        }
    }
    /* Menggabungkan kembali array sementara ke array nilai[l..r]*/
    i = 0; //Indeks subarray pertama
    j = 0; //Indeks subarray kedua
    k = l; //Indeks subarray gabungan

    //Sort tipe int
    if(jenis <= 5){
        while (i < n1 && j < n2) {
            if ((tipe == 1 && L[i].Nilai[jenis] <= R[j].Nilai[jenis]) || 
                (tipe == 2 && L[i].Nilai[jenis] >= R[j].Nilai[jenis])){
                strcpy(mhs[k].Nama, L[i].Nama);
                mhs[k].NIM = L[i].NIM;
                for(int x = 0; x < 6; x++){
                    mhs[k].Nilai[x] = L[i].Nilai[x];
                }
                i++;
            }
            else {
                strcpy(mhs[k].Nama, R[j].Nama);
                mhs[k].NIM = R[j].NIM;
                for(int x = 0; x < 6; x++){
                    mhs[k].Nilai[x] = R[j].Nilai[x];
                }
                j++;
            }
            k++;
        }
    }
    //Sort NIM
    else if(jenis == 6){
        while (i < n1 && j < n2) {
            if ((tipe == 1 && L[i].NIM <= R[j].NIM) || 
                (tipe == 2 && L[i].NIM >= R[j].NIM)){
                strcpy(mhs[k].Nama, L[i].Nama);
                mhs[k].NIM = L[i].NIM;
                for(int x = 0; x < 6; x++){
                    mhs[k].Nilai[x] = L[i].Nilai[x];
                }
                i++;
            }
            else {
                strcpy(mhs[k].Nama, R[j].Nama);
                mhs[k].NIM = R[j].NIM;
                for(int x = 0; x < 6; x++){
                    mhs[k].Nilai[x] = R[j].Nilai[x];
                }
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
                for(int x = 0; x < 6; x++){
                    mhs[k].Nilai[x] = L[i].Nilai[x];
                }
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
                    for(int x = 0; x < 6; x++){
                        mhs[k].Nilai[x] = R[j].Nilai[x];
                    }
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
        for(int x = 0; x < 6; x++){
            mhs[k].Nilai[x] = L[i].Nilai[x];
        }
        i++;
        k++;
    }
    while (j < n2) {
        strcpy(mhs[k].Nama, R[j].Nama);
        mhs[k].NIM = R[j].NIM;
        for(int x = 0; x < 6; x++){
            mhs[k].Nilai[x] = R[j].Nilai[x];
        }
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
