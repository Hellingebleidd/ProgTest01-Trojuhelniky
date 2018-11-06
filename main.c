#include <stdio.h>
#include <math.h>

const int N = 6;
const int M = 2;
const int OBVOD = 1;
const int ROVNAKE = 0;
const int T1VACSI = 2;
const int T2VACSI = 3;
const int NIE_TROJUHOLNIK = 4;


int trojuholnikySuRovnake(double v[N][M]) {
    double dlzka[2][3] = {{0, 0, 0},
                          {0, 0, 0}};     //vypocitane dlzky stran
    int p1, p2;             //pozicie pre v

    for (int k = 0; k < 2; ++k) {   //najprv 1. potom 2. trojuholnik
        for (int i = 0; i < 3; ++i) {
            p1 = (3 * k) + i;           //hodnota v[p1][] pre prvu suradnicu
            if (p1 == 2) { p2 = 0; }
            else if (p1 == 5) { p2 = 3; }
            else { p2 = p1 + 1; }

            //dlzku strany urcim pytagorovou vetou
            dlzka[k][i] = sqrt(pow((v[p1][0] - v[p2][0]), 2) + pow((v[p1][1] - v[p2][1]), 2));
            printf("pre p1:%d  p2:%d  je dlzka[%d][%d] == %lf\n", p1, p2, k, i, dlzka[k][i]);
        }
    }


    if((dlzka[0][0]+dlzka[0][1]+dlzka[0][2]) == (dlzka[1][0]+dlzka[1][1]+dlzka[1][2]) )
        return OBVOD;

    return NIE_TROJUHOLNIK;
};

int main() {
    char odpovede[5][] ={"Trojuhelniky jsou shodne.", "Trojuhelniky nejsou shodne, ale maji stejny obvod.", "", "", ""};
    double vrcholy[6][2] = {{0,   0},
                            {5,   0},
                            {2.5, 3},
                            {4,   -1},
                            {7,   1.5},
                            {4,   4}};   //vrcholy trojuholnika

    printf("Trojuhelnik #1:\nBod A:\n");
    printf("%s\n", odpovede[trojuholnikySuRovnake(vrcholy)]);




    return 0;
}




