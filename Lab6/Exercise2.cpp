#include<iostream>
#include<graphics.h>
using namespace std;
int main(){
    float a[] = {-7, 19, 4, 12};
    int n = sizeof(a) / sizeof(a[0]);
    int winwidth = 1000, winheight = 800;
    int x0 = 200, y0 = 600, D = 50, Ds = 50, Dc = 40, Px = 600, Py = 400;
    int i, x1, y1, x2, y2;
    char t[][20] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};

    initwindow(winwidth, winheight);

    float amin = a[0];
    float amax = a[0];

    for(i = 0; i < n; i++){
        if(amin > a[i])amin = a[i];
        if(amax < a[i])amax = a[i];
    }

    if(amin > 0) amin = 0;
    if(amax < 0) amax = 0;

    float S = (amax - amin) / Px;
    float x0n = x0 - (amin / S);

    line(x0, y0, x0 + Px, y0);
    line(x0n, y0, x0n, y0 - Py);

    int I = Px / D;

    char text[10];

    for(i = 0; i <= I; i++){
        line(x0 + i * D, y0, x0 + i * D, y0 + 3);
        gcvt(amin + i * D * S, 3.2, text);
        settextjustify(1, 2);
        outtextxy(x0 + i * D, y0 - 25, text);
    }

    for(int i = 1; i <= n; i++){
        outtextxy(x0 - 10, y0 - i * (Dc + Ds) + Ds / 2, t[i - 1]);
        setfillstyle(1, i);
        bar(x0n, y0 - i * (Ds + Dc), x0n + (a[i - 1] / S), y0 - i * (Ds + Dc) + Ds);
    }


    getch();

    return 0;
}
