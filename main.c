#include <stdio.h>
#include <math.h>


double dlzkaStrany(double ax, double ay, double bx, double by) {
/*    double dlzka;
    const int PRESNOST = 1;

    dlzka = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
    if (PRESNOST == 1)
        return dlzka;
    else
        return (round(PRESNOST * dlzka)) / PRESNOST;*/
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

int main() {
    const int PRESNOST = 10000;

    double dlzka[2][3];
    double vrcholy[3][2];
    double o1, o2;                          //obvod
    int i;  // do cyklov
    double tmp;
//    char c;

    for (i = 0; i < 2; ++i) {
        printf("Trojuhelnik #%d:\n", i + 1);
        printf("Bod A:\n");
//        if ((scanf("%lf %lf%c", &vrcholy[0][0], &vrcholy[0][1], &c) != 3) || (c != '\n' && c != ' ')) {
        if ((scanf("%lf %lf", &vrcholy[0][0], &vrcholy[0][1]) < 2)) {
            printf("Nespravny vstup.\n");
            return -1;
        }

        printf("Bod B:\n");
//        if ((scanf("%lf %lf%c", &vrcholy[1][0], &vrcholy[1][1], &c) != 3) || (c != '\n' && c != ' ')) {
        if ((scanf("%lf %lf", &vrcholy[1][0], &vrcholy[1][1]) < 2)) {
            printf("Nespravny vstup.\n");
            return -1;
        }
        //mozem vypocitat 1. dlzku
        dlzka[i][0] = dlzkaStrany(vrcholy[0][0], vrcholy[0][1], vrcholy[1][0], vrcholy[1][1]);

        printf("Bod C:\n");
//        if ((scanf("%lf %lf%c", &vrcholy[2][0], &vrcholy[2][1], &c) != 3) || (c != '\n' && c != ' ')) {
        if ((scanf("%lf %lf", &vrcholy[2][0], &vrcholy[2][1]) < 2)) {
            printf("Nespravny vstup.\n");
            return -1;
        }
        //mozem vypocitat dalsie 2 dlzky a zaroven usporiadat
        if ((dlzka[i][1] = dlzkaStrany(vrcholy[1][0], vrcholy[1][1], vrcholy[2][0], vrcholy[2][1])) > dlzka[i][0]) {
            //dat na zaciatok pola - pozicia 0
            tmp = dlzka[i][1];
            dlzka[i][1] = dlzka[i][0];
            dlzka[i][0] = tmp;
        }

        if ((dlzka[i][2] = dlzkaStrany(vrcholy[2][0], vrcholy[2][1], vrcholy[0][0], vrcholy[0][1])) > dlzka[i][1]) {
            //posunut [1] na koniec na [2] a potom este porovnat s navacsou [0]
            tmp = dlzka[i][2];
            dlzka[i][2] = dlzka[i][1];
            dlzka[i][1] = tmp;

            if (tmp > dlzka[i][0]) {
                //dat na zaciatok pola - pozicia 0
                dlzka[i][1] = dlzka[i][0];
                dlzka[i][0] = tmp;
            }
        }

//        printf("dlzky: %lf %lf %lf  obvod: %lf ", dlzka[i][0], dlzka[i][1], dlzka[i][2], dlzka[i][0]+dlzka[i][1]+dlzka[i][2]);
//        printf("  0-(1+2)= %lf\n", dlzka[i][0] - (dlzka[i][1]+dlzka[i][2]));
        //kedze prva dlzka ( dlzka[i][0] ) je najvacsia, staci skontrolovat len ju
//        if (dlzka[i][0] >= (dlzka[i][1] + dlzka[i][2])) {
        if ((round(PRESNOST * (dlzka[i][0] - (dlzka[i][1] + dlzka[i][2])))) / PRESNOST == 0) {
            printf("Body netvori trojuhelnik.\n");
            return -1;
        }
    }

    //zhodne su, ak maju rovnake dlzky (utriedene podla velkosti)
    if ((dlzka[0][0] == dlzka[1][0]) && (dlzka[0][1] == dlzka[1][1]) && (dlzka[0][2] == dlzka[1][2])) {
        //trojuhelniky su zhodne
        printf("Trojuhelniky jsou shodne.\n");
        return 0;
    }

    o1 = (round(PRESNOST * (dlzka[0][0] + dlzka[0][1] + dlzka[0][2]))) / PRESNOST;
    o2 = (round(PRESNOST * (dlzka[1][0] + dlzka[1][1] + dlzka[1][2]))) / PRESNOST;


    if (o1 < o2)
        printf("Trojuhelnik #2 ma vetsi obvod.\n");
    else if (o1 > o2)
        printf("Trojuhelnik #1 ma vetsi obvod.\n");
    else
        printf("Trojuhelniky nejsou shodne, ale maji stejny obvod.\n");

    return 0;
}




