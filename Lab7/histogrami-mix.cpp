#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
    float h[] = {21, 50, 9, 37};
    float s[] = {12, 7, 14, 28};

    int n = sizeof(h) / sizeof(h[0]);
    int winwidth = 1000, winheight = 800;
    int x0 = 200, y0 = 600, D = 50, Ds = 70, Dc = 60, Px = 600, Py = 400;

    initwindow(winwidth, winheight);

    float suma[n];
    for(int i = 0; i < n; i++){
        suma[i] = h[i] + s[i];
    }

    float maxsum = 0;
    for(int i = 0; i < n; i++){
        if(suma[i] > maxsum)maxsum = suma[i];
    }


    float S = maxsum / Py;

    line(x0, y0, x0 + Px, y0);
    line(x0, y0, x0, y0 - Py);

    //float Py1 = maxprihod / S;
    //float Py2 = Py - Py1;

    char text[10];

    int I = Py / D;
    for(int i = 0; i <= I; i++){
        line(x0, y0 - i * D, x0 - 3, y0 - i * D);
        gcvt(i * D * S, 5.2, text);
        settextjustify(1, 2);
        outtextxy(x0 - 25, y0 - i * D, text);
    }

    for(int i = 1; i <= n; i++){
        setfillstyle(1, i);
        bar(x0 + i * (Ds + Dc) - Ds, y0 - (h[i - 1] / S), x0 + i * (Ds + Dc), y0);
    }

    for(int i = 1; i <= n; i++){
        setfillstyle(1, i + 2);
        bar(x0 + i * (Ds + Dc) - Ds, y0 - (s[i - 1] + h[i - 1]) / S, x0 + i * (Ds + Dc), y0 - (h[i - 1] / S));
    }

    getch();

    return 0;
}

