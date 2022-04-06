#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
    float prihodi[] = {21, 50, 9, 37};
    float razhodi[] = {12, 7, 14, 28};

    int n = sizeof(prihodi) / sizeof(prihodi[0]);
    int winwidth = 1000, winheight = 800;
    int x0 = 200, y0 = 600, D = 50, Ds = 50, Dc = 40, Px = 600, Py = 400;

    initwindow(winwidth, winheight);

    float maxprihod = 0;
    for(int i = 0; i < n; i++){
        if(prihodi[i] > maxprihod)maxprihod = prihodi[i];
    }

    float maxrazhod = 0;
    for(int i = 0; i < n; i++){
        if(razhodi[i] > maxrazhod)maxrazhod = razhodi[i];
    }

    float S = (maxprihod + maxrazhod) / Px;
    float x0n = x0 + (maxrazhod / S);

    line(x0, y0, x0 + Px, y0);
    line(x0n, y0, x0n, y0 - Py);

    float Px1 = maxprihod / S;
    float Px2 = Px - Px1;

    char text[10];

    int Ip = Px1 / D;
    for(int i = 0; i <= Ip; i++){
        line(x0n + i * D, y0, x0n + i * D, y0 + 3);
        gcvt(i * D * S, 5.2, text);
        settextjustify(1, 2);
        outtextxy(x0n + i * D, y0 - 25, text);
    }

    int Ir = Px2 / D;
    for(int i = 0; i <= Ir; i++){
        line(x0n - i * D, y0, x0n - i * D, y0 + 3);
        gcvt(i * D * S, 5.2, text);
        settextjustify(1, 2);
        outtextxy(x0n - i * D, y0 - 25, text);
    }

    for(int i = 1; i <= n; i++){
        setfillstyle(1, i);
        bar(x0n, y0 - i * (Ds + Dc), x0n + (prihodi[i - 1] / S), y0 - i * (Ds + Dc) + Ds);
    }

    for(int i = 1; i <= n; i++){
        setfillstyle(1, i + 4);
        bar(x0n, y0 - i * (Ds + Dc), x0n - (razhodi[i - 1] / S), y0 - i * (Ds + Dc) + Ds);
    }

    getch();

    return 0;
}

