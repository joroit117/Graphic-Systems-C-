#include <graphics.h>
#include <iostream>
#include <dos.h>
#include <math.h>

using namespace std;
int main()
{
    int winwidth=1000,winheight=800; // параметри на прозореца на графичната система
// инициализация на графичната система чрез отваряне на графичен прозорец със зададен размер
    initwindow(winwidth,winheight);
    int ax = 300, ay = 500, mx = 400, my = 450, a = 200, b = 100, i; //зададени данни, необходими за изчертаване на фигурата
//определяне координатите на останалите върхове
    int bx=ax+a;
    int by=ay;
    int cx=bx;
    int cy=by-b;
    int dx=ax;
    int dy=ay-b;

    double sx = 1.5, sy = 1.5;
    //int mx=ax+a/2;
    //int my=ay-3./2*a;
    //горен ляв
    int dxc = cx+ (dx-cx)*sx;
    int dyc = cy+ (dy-cy)*sy;

//долен десен
    int bxc = cx+ (bx-cx)*sx;
    int byc = cy+ (by-cy)*sy;

//тези мащабирани точки са ни необходими за въртенето
    int axc = cx+ (ax-cx)*sx;
    int ayc = cy+ (ay-cy)*sy;


    for(i=1; i<=360; i+=60)
    {
        int axr = cx + (axc - cx)*cos(i*M_PI/180) - (ayc - cy)*sin(i*M_PI/180);
        int ayr = cy + (axc - cx)*sin(i*M_PI/180) + (ayc - cy)*cos(i*M_PI/180);
        int bxr = cx + (bxc - cx)*cos(i*M_PI/180) - (byc - cy)*sin(i*M_PI/180);
        int byr = cy + (bxc - cx)*sin(i*M_PI/180) + (byc - cy)*cos(i*M_PI/180);
        int dxr = cx + (dxc - cx)*cos(i*M_PI/180) - (dyc - cy)*sin(i*M_PI/180);
        int dyr = cy + (dxc - cx)*sin(i*M_PI/180) + (dyc- cy)*cos(i*M_PI/180);

        setcolor(15);
        moveto(axr,ayr);
        lineto(bxr, byr);
        lineto(dxr,dyr);
        lineto(axr,ayr);
        line(cx, cy, bxr, byr);
        line(cx, cy, dxr, dyr);
        delay(40);

    }

//изчертаване
    //rectangle(dx,dy,bx,by);
    //line(dx,dy,mx,my);
    //line(mx,my,cx,cy);
    delay(500);
/*
// при изчертаването може да се използва и drawpoly
//мащабиране спямо т.М и зададени мащабни коефициенти sx = 1.2, sy = 0.7;
    double sx = 1.2, sy = 0.7; // мащабни коефициенти

//горен ляв
    int dxm = mx+ (dx-mx)*sx;
    int dym = my+ (dy-my)*sy;

//долен десен
    int bxm = mx+ (bx-mx)*sx;
    int bym = my+ (by-my)*sy;

//тези мащабирани точки са ни необходими за въртенето
    int axm = mx+ (ax-mx)*sx;
    int aym = my+ (ay-my)*sy;
    int cxm = mx+ (cx-mx)*sx;
    int cym = my+ (cy-my)*sy;

    rectangle(dxm,dym,bxm,bym);
    line(dxm,dym,mx,my);
    line(mx,my,cxm,cym);
    delay(500);
    cleardevice();

//завъртане около т.М на 360 градуса. Показва се движението като се изчертава завъртяната фигура през 1 градус
    for(i=1; i<=360; i+=60)
    {
        int axr = mx + (axm - mx)*cos(i*M_PI/180) - (aym - my)*sin(i*M_PI/180);
        int ayr = my + (axm - mx)*sin(i*M_PI/180) + (aym - my)*cos(i*M_PI/180);
        int bxr = mx + (bxm - mx)*cos(i*M_PI/180) - (bym - my)*sin(i*M_PI/180);
        int byr = my + (bxm - mx)*sin(i*M_PI/180) + (bym - my)*cos(i*M_PI/180);
        int cxr = mx + (cxm - mx)*cos(i*M_PI/180) - (cym - my)*sin(i*M_PI/180);
        int cyr = my + (cxm - mx)*sin(i*M_PI/180) + (cym - my)*cos(i*M_PI/180);
        int dxr = mx + (dxm - mx)*cos(i*M_PI/180) - (dym - my)*sin(i*M_PI/180);
        int dyr = my + (dxm - mx)*sin(i*M_PI/180) + (dym- my)*cos(i*M_PI/180);

        setcolor(15);
        moveto(axr,ayr);
        lineto(bxr, byr);
        lineto(cxr,cyr);
        lineto(dxr,dyr);
        lineto(axr,ayr);
        line(mx, my, cxr, cyr);
        line(mx, my, dxr, dyr);
        delay(40);

    }
*/
    getch();

    return 0;

}
