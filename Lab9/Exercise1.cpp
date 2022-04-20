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
    for(i = 0; i < (getmaxx()/2 - 50); i++)
    {
        setcolor(15);
        circle(xc, yc, r);
        delay(10);
        setcolor(0);
        circle(xc, yc, r);
        xc++;
    }

    //мащабиране на окръжността спрямо точката с минимална стойност на y - yf и коефициент на //мащабиране Sy=1.2 (мащабиране по y)

    double xf, yf;

    xf = xc;
    yf = yc - r;

    double Sy=1.2,nr;

    while((yc+nr) < winheight-100)

    {
        setcolor(15);
        delay(400);

        nr = (yc-yf) * Sy;

        yc=yf+(yc-yf)*Sy;

        circle(xc, yc, nr);

    }

//въртене на точка около точка - центъра на първата окръжност около центъра на последната с //изчертаване на окръжностите

//и показване на движението

    delay(200);
    cleardevice();
    circle(xc, yc, nr);
    int yc1=yf+r;
    double x, y;

    for(i = 0; i < 360; i ++)

    {

        x = xc + (xc - xc)*cos(i*3.14/180) - (yc1 -yc)*sin(i*3.14/180);

        y = yc + (xc - xc)*sin(i*3.14/180) + (yc1 -yc)*cos(i*3.14/180);

        setcolor(WHITE);

        circle(x, y, r-3);

        delay(50);

        setcolor(BLACK);

        circle(x, y, r-3);

    }

    getch();

    return 0;
}
