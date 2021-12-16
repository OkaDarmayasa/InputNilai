#include "Input.c"

void merge(int jenis, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //Array sementara
    struct data L[n1], R[n2];

    //Copy data ke array sementara
    for (i = 0; i < n1; i++){
        strcpy(L[i].NIM, mhs[l + i].NIM);
        strcpy(L[i].Nama, mhs[l + i].Nama);
        L[i].Nilai[0] = mhs[l + i].Nilai[0];
        L[i].Nilai[1] = mhs[l + i].Nilai[1];
        L[i].Nilai[2] = mhs[l + i].Nilai[2];
        L[i].Nilai[3] = mhs[l + i].Nilai[3];
        L[i].Nilai[4] = mhs[l + i].Nilai[4];
        L[i].Nilai[5] = mhs[l + i].Nilai[5];
    }
    for (j = 0; j < n2; j++){
        strcpy(R[j].NIM, mhs[m + 1 + j].NIM);
        strcpy(R[j].Nama, mhs[m + 1 + j].Nama);
        R[j].Nilai[0] = mhs[m + 1 + j].Nilai[0];
        R[j].Nilai[1] = mhs[m + 1 + j].Nilai[1];
        R[j].Nilai[2] = mhs[m + 1 + j].Nilai[2];
        R[j].Nilai[3] = mhs[m + 1 + j].Nilai[3];
        R[j].Nilai[4] = mhs[m + 1 + j].Nilai[4];
        R[j].Nilai[5] = mhs[m + 1 + j].Nilai[5];
    }
    /* Menggabungkan kembali array sementara ke array nilai[l..r]*/
    i = 0; //Indeks subarray pertama
    j = 0; //Indeks subarray kedua
    k = l; //Indeks subarray gabungan
    while (i < n1 && j < n2) {
        if (L[i].Nilai[jenis] <= R[j].Nilai[jenis]) {
            strcpy(mhs[k].NIM, L[i].NIM);
            strcpy(mhs[k].Nama, L[i].Nama);
            mhs[k].Nilai[0] = L[i].Nilai[0];
            mhs[k].Nilai[1] = L[i].Nilai[1];
            mhs[k].Nilai[2] = L[i].Nilai[2];
            mhs[k].Nilai[3] = L[i].Nilai[3];
            mhs[k].Nilai[4] = L[i].Nilai[4];
            mhs[k].Nilai[5] = L[i].Nilai[5];
            i++;
        }
        else {
            strcpy(mhs[k].NIM, R[j].NIM);
            strcpy(mhs[k].Nama, R[j].Nama);
            mhs[k].Nilai[0] = R[j].Nilai[0];
            mhs[k].Nilai[1] = R[j].Nilai[1];
            mhs[k].Nilai[2] = R[j].Nilai[2];
            mhs[k].Nilai[3] = R[j].Nilai[3];
            mhs[k].Nilai[4] = R[j].Nilai[4];
            mhs[k].Nilai[5] = R[j].Nilai[5];
            j++;
        }
        k++;
    }

    //Copy sisa elemen
    while (i < n1) {
        strcpy(mhs[k].NIM, L[i].NIM);
        strcpy(mhs[k].Nama, L[i].Nama);
        mhs[k].Nilai[0] = L[i].Nilai[0];
        mhs[k].Nilai[1] = L[i].Nilai[1];
        mhs[k].Nilai[2] = L[i].Nilai[2];
        mhs[k].Nilai[3] = L[i].Nilai[3];
        mhs[k].Nilai[4] = L[i].Nilai[4];
        mhs[k].Nilai[5] = L[i].Nilai[5];
        i++;
        k++;
    }
    while (j < n2) {
        strcpy(mhs[k].NIM, R[j].NIM);
        strcpy(mhs[k].Nama, R[j].Nama);
        mhs[k].Nilai[0] = R[j].Nilai[0];
        mhs[k].Nilai[1] = R[j].Nilai[1];
        mhs[k].Nilai[2] = R[j].Nilai[2];
        mhs[k].Nilai[3] = R[j].Nilai[3];
        mhs[k].Nilai[4] = R[j].Nilai[4];
        mhs[k].Nilai[5] = R[j].Nilai[5];
        j++;
        k++;
    }
}
void mergeSort(int jenis, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(jenis, l, m);
        mergeSort(jenis, m + 1, r);

        merge(jenis, l, m, r);
    }
}
