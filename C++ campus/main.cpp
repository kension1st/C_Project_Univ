#include <iostream>
#include <math.h>
#include <stdlib.h>

    using namespace std;
    double luas(double sisi), keliling(double sisi);

    int main()
    {
        int sisi;
        cout<<"Masukan Sisi :";
        cin>> sisi;

        cout<<"Luas :"<< luas(sisi)<<"cm"<<endl;
        cout<<"Keliling :"<< keliling(sisi)<<"cm";

    }

    double luas (double sisi)
    {
     double hasil = sisi * sisi;
     return hasil;
    }

    double keliling (double sisi)
    {
     double hasil= sisi*4;
     return hasil;
    }
