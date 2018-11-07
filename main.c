#include <stdio.h>
#include <math.h>

const int N = 3;
const int M = 2;
const int NIE_TROJUHOLNIK = 4;
const int SU_ZHODNE = 13;


int rozmerTrojuholnika(double v[N][M], double *dlzka) {
    int p2;             //pozicie pre v

    for (int i = 0; i < 3; ++i) {
        if (i == 2) { p2 = 0; } else { p2 = i + 1; }

        //dlzku strany urcim pytagorovou vetou
        dlzka[i] = sqrt(pow((v[i][0] - v[p2][0]), 2) + pow((v[i][1] - v[p2][1]), 2));
//        printf("pre p1:%d  p2:%d  je dlzka[%d] == %lf\n", p1, p2, i, dlzka[i]);
    }
    if ((dlzka[0] >= (dlzka[1] + dlzka[2])) || (dlzka[1] >= (dlzka[2] + dlzka[0])) ||
        (dlzka[2] >= (dlzka[0] + dlzka[1])))
        return NIE_TROJUHOLNIK;
    return 0;
}

int nacitajSuradnice(double *x, double *y) {
    //pokusi sa nacitat hodnoty. Ak sa nepodari nacitat obe, tak vrati -1
    int vysledok;
    vysledok = scanf("%lf %lf", x, y);
    if (vysledok < 2) {
        printf("Nespravny vstup.\n");
        return -1;
    }
    return 2;
}

void triedDlzkyZostupne(double *d) {
    //jednoduche triedenie 3 prvkov
    double tmp;
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (d[i] < d[j]) {
                tmp = d[i];
                d[i] = d[j];
                d[j] = tmp;
            }
        }
    }
}

int suTrojuholnikyZhodne(double *dlzka1, double *dlzka2) {
    //porovnam utriedene dlzk trojuholnikov
//    printf("\nA> Su zhodne ? Dlzka1 %lf %lf %lf\n", dlzka1[0], dlzka1[1], dlzka1[2]);
//    printf("A> Su zhodne ? Dlzka2 %lf %lf %lf\n", dlzka2[0], dlzka2[1], dlzka2[2]);

    triedDlzkyZostupne(dlzka1);
    triedDlzkyZostupne(dlzka2);
//    printf("\nSu zhodne ? Dlzka1 %lf %lf %lf\n", dlzka1[0], dlzka1[1], dlzka1[2]);
//    printf("Su zhodne ? Dlzka2 %lf %lf %lf\n", dlzka2[0], dlzka2[1], dlzka2[2]);

    if ((dlzka1[0] == dlzka2[0]) && (dlzka1[1] == dlzka2[1]) && (dlzka1[2] == dlzka2[2]))
        return SU_ZHODNE;

    return 0;
}

int main() {
    double dlzka1[3] = {0, 0, 0}, dlzka2[3] = {0, 0, 0};
//    double vrcholy1[3][2], vrcholy2[3][2];   //vrcholy trojuholnika};
//    double vrcholy1[3][2] = {{0,   0},
//                             {5,   0},
//                             {2.5, 3}};
//    double vrcholy2[3][2] = {{4, -1},
//                             {7, 1.5},
//                             {4, 4}};   //vrcholy trojuholnika};
    double vrcholy1[3][2] = {{0,   0},
                             {10,   0},
                             {0, 10}};
    double vrcholy2[3][2] = {{-5, 3},
                             {12, 8},
                             {37, 15}};   //vrcholy trojuholnika};
    double o1, o2;      //obvod


    printf("Trojuhelnik #1:\n");
//    printf("Bod A:\n");
//    if (nacitajSuradnice(&vrcholy1[0][0], &vrcholy1[0][1]) < 2)
//        return -1;
//    printf("Bod B:\n");
//    if (nacitajSuradnice(&vrcholy1[1][0], &vrcholy1[1][1]) < 2)
//        return -1;
//    printf("Bod C:\n");
//    if (nacitajSuradnice(&vrcholy1[2][0], &vrcholy1[2][1]) < 2)
//        return -1;

    if (rozmerTrojuholnika(vrcholy1, dlzka1) == NIE_TROJUHOLNIK) {
        printf("Body netvori trojuhelnik.\n");
        return -1;
    }

    printf("Trojuhelnik #2:\n");
//    printf("Bod A:\n");
//    if (nacitajSuradnice(&vrcholy2[0][0], &vrcholy2[0][1]) < 2)
//        return -1;
//    printf("Bod B:\n");
//    if (nacitajSuradnice(&vrcholy2[1][0], &vrcholy2[1][1]) < 2)
//        return -1;
//    printf("Bod C:\n");
//    if (nacitajSuradnice(&vrcholy2[2][0], &vrcholy2[2][1]) < 2)
//        return -1;

    if (rozmerTrojuholnika(vrcholy2, dlzka2) == NIE_TROJUHOLNIK) {
        printf("Body netvori trojuhelnik.\n");
        return -1;
    }

    if (suTrojuholnikyZhodne(dlzka1, dlzka2) == SU_ZHODNE) {
        printf("Trojuhelniky jsou shodne.\n");
        return 0;
    }
    o1 = dlzka1[0] + dlzka1[1] + dlzka1[2];
    o2 = dlzka2[0] + dlzka2[1] + dlzka2[2];

    if (o1 == o2)
        printf("Trojuhelniky nejsou shodne, ale maji stejny obvod.\n");
    else if (o1 > o2)
        printf("Trojuhelnik #1 ma vetsi obvod.\n");
    else
        printf("Trojuhelnik #2 ma vetsi obvod.\n");

    return 0;
}




