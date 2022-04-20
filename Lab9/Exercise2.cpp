
#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

int main()
{
    int winwidth = 1000, winheight = 800;
    double xc = 50, yc = 50, r = 40;
    int i;
    initwindow(winwidth, winheight);
    for(i = 0; i < (getmaxx()/2.5 - 50); i++)
    {
        setcolor(15);
        circle(xc, yc, r);
        delay(10);
        setcolor(0);
        circle(xc, yc, r);
        yc++;
    }

    double xf, yf;
    xf = xc - r;
    yf = yc;
    double Sx=1.2,nr;

    while((xc+nr) < winwidth-300)
    {
        setcolor(15);
        delay(400);
        nr = (xc-xf) * Sx;
        xc=xf+(xc-xf)*Sx;
        circle(xc, yc, nr);
    }

    delay(200);
    cleardevice();
    circle(xc, yc, nr);
    int xc1=xf+r;
    double x, y;

    for(i = 0; i < 360; i ++)
    {
        x = xc + (xc1 - xc)*cos(i*3.14/180) - (xc -xc)*sin(i*3.14/180);
        y = yc + (xc1 - xc)*sin(i*3.14/180) + (xc -xc)*cos(i*3.14/180);
        setcolor(WHITE);
        circle(x, y, r-3);
        delay(50);
        setcolor(BLACK);
        circle(x, y, r-3);
    }
    getch();
    return 0;
}
