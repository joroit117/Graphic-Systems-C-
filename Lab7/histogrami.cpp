#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
    float prihodi[] = {21, 50, 9, 37};
    float razhodi[] = {12, 7, 14, 28};

    int n = sizeof(prihodi) / sizeof(prihodi[0]);
    int winwidth = 1000, winheight = 800;
    int x0 = 200, y0 = 600, D = 50, Ds = 70, Dc = 60, Px = 600, Py = 400;

    initwindow(winwidth, winheight);

    float maxprihod = 0;
    for(int i = 0; i < n; i++){
        if(prihodi[i] > maxprihod)maxprihod = prihodi[i];
    }

    float maxrazhod = 0;
    for(int i = 0; i < n; i++){
        if(razhodi[i] > maxrazhod)maxrazhod = razhodi[i];
    }

    float S = (maxprihod + maxrazhod) / Py;
    float y0n = y0 - (maxrazhod / S);

    line(x0, y0n, x0 + Px, y0n);
    line(x0, y0, x0, y0 - Py);

    float Py1 = maxprihod / S;
    float Py2 = Py - Py1;

    char text[10];

    int Ip = Py1 / D;
    for(int i = 0; i <= Ip; i++){
        line(x0, y0n - i * D, x0 - 3, y0n - i * D);
        gcvt(i * D * S, 5.2, text);
        settextjustify(1, 2);
        outtextxy(x0 - 25, y0n - i * D, text);
    }

    int Ir = Py2 / D;
    for(int i = 0; i <= Ir; i++){
        line(x0, y0n + i * D, x0 - 3, y0n + i * D);
        gcvt(i * D * S, 5.2, text);
        settextjustify(1, 2);
        outtextxy(x0 - 25, y0n + i * D, text);
    }

    for(int i = 1; i <= n; i++){
        setfillstyle(1, i);
        bar(x0 + i * (Ds + Dc) - Ds, y0n - (prihodi[i - 1] / S), x0 + i * (Ds + Dc), y0n);
    }

    for(int i = 1; i <= n; i++){
        setfillstyle(1, i + 4);
        bar(x0 + i * (Ds + Dc) - Ds, y0n + (razhodi[i - 1] / S), x0 + i * (Ds + Dc), y0n);
    }

    getch();

    return 0;
}
