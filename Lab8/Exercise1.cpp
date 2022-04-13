#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

int main(){
    int n = 7;
    double a[7] = {10, 21, 3, 6, 17, 9, 29};
    int winwidth = 1000, winheight = 800;
    int Ox = 500, Oy = 400, rx = 300, ry = 200;

    initwindow(winwidth, winheight);
    double A = 0;
    double max = a[0];
    double min = a[0];
    for(int i = 0; i < n; i++){
        A += a[i];
        if(a[i] > max)max = a[i];
        if(a[i] < min)min = a[i];
    }
    for(int k = 0; k < 50; k++){
    double st = 0;
    for(int i = 0; i < n; i++){
        double gama = a[i] / A * 360;
        double end = st + gama;
        char text[10];
        double xi;
        double yi;
        double xi1;
        double yi1;

        setfillstyle(2 + i, i + 1);
        setcolor(i + 9);
        if(a[i] == max || a[i] == min){
            xi = Ox + 0.3 * rx * cos((st + gama / 2) / 180 * M_PI);
            yi = Oy - 0.3 * ry * sin((st + gama / 2) / 180 * M_PI);
            xi1 = Ox + 1.5 * rx * cos((st + gama / 2) / 180 * M_PI);
            yi1 = Oy - 1.5 * ry * sin((st + gama / 2) / 180 * M_PI);
            sector(xi, yi - k, st, end, rx, ry);
        }else{
            xi1 = Ox + 1.3 * rx * cos((st + gama / 2) / 180 * M_PI);
            yi1 = Oy - 1.3 * ry * sin((st + gama / 2) / 180 * M_PI);
            sector(Ox, Oy - k, st, end, rx, ry);
        }

        setcolor(WHITE);
        gcvt(a[i], 5.2, text);
        settextjustify(1, 1);
        outtextxy(xi1, yi1, text);
        st = end;
        delay(3);
    }
    }

    getch();
}
