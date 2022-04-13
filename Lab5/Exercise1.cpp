#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

void logic(double x[], double y[], float xmax, float xmin, int n, int i);
int main(){

    float x1min = -15;
    float x1max = 8;
    float x2min = -4;
    float x2max = 10;
    int n1=120;
    int n2=180;
    int i;
    double x1[n1];
    double y1[n1];
    double x2[n2];
    double y2[n2];

    //изчисляване на стъпката на изменение на входните данни, необходима за получаване на n броя //стойности в масива x
    double d1x = (x1max-x1min) / (n1-1);
    double d2x = (x2max-x2min) / (n2-1);

    // попълване навходните масиви с изчислените данни
    for (i = 0; i < n1; i++){
        x1[i] = x1min + i * d1x ;
        y1[i] = x1[i]*x1[i] + 8*x1[i] -10;
    }
    for (i = 0; i < n2; i++){
        x2[i] = x2min + i * d2x ;
        y2[i] = 5 * x2[i] * x2[i] - 3 * x2[i] + 2;
    }
        int winwidth=1000,winheight=800;
        initwindow(winwidth,winheight);

    logic(x1, y1, x1max, x1min, n1, i);
    logic(x2, y2, x2max, x2min, n2, i);

    getch();
    return 0;
}
void logic(double x[], double y[], float xmax, float xmin, int n, int i){
 // параметри на прозореца на графичната система
    int Px=600,Py=400,Dx=60,Dy=50,x0=200,y0=600 ; //параметри на графичния прозорец, в който ще //се изобразят данните (вътре в прозореца на графичната система)

    // намиране на ymin и ymax
    double ymin = y[0];
    double ymax = y[0];
    for(i = 0; i< n; i++) {
        if(y[i] < ymin) ymin = y[i];
        if(y[i] > ymax) ymax = y[i];
    }

    //определяне на скалните коефициенти
    float sx = (xmax - xmin)/Px;
    float sy = (ymax - ymin)/Py;

    // инициализация на графичната система чрез отваряне на графичен прозорец със зададен размер

    //изчертаване на графичния прозорец
    //намиране на x-координатата, съответстваща на стойността x=0 в случай, че xmin<0
    int x0n=x0;
    if (xmin<0) x0n=x0+(0-xmin)/sx;

    //намиране на y-координатата, съответстваща на стойността y=0 в случай, че ymin<0
    int y0n=y0;
    if (ymin<0) y0n=y0-(0-ymin)/sy;
    line(x0,y0n,x0+Px,y0n);//хоризонтaлнa ос
    line(x0n,y0,x0n,y0-Py);//вертикална ос
    int Ip = Px/Dx; int Jp = Py/Dy;//брой деления по хоризонталната и вертикалната ос

    //изчертаване и надписване на деленията по хоризонталната ос
    char text[10];
    for(i = 0; i <= Ip; i++){
        line(x0 + i*Dx, y0n, x0+i*Dx,y0n+3); //изчертаване на деленията
        gcvt(xmin + i*Dx*sx, 5.2,text); //преобразуване на реалната стойност, съответстваща на //делението в символен низ
        settextjustify(1,2);
        outtextxy(x0 + i*Dx-10, y0n+5, text);// извеждане на стойността, съответстваща на делението
    }

    //изчертаване и надписване на деленията по вертикалната ос
    for(i = 0; i <= Jp; i++){
        line(x0n, y0-i*Dy, x0n-3, y0- i * Dy); //изчертаване на деленията
        gcvt(ymin+i*Dy*sy, 4.2,text); //преобразуване на реалната стойност, съответстваща на //делението в символен низ
        settextjustify(2,1);
        outtextxy(x0n-10, y0 - Dy*i+5, text); // извеждане на стойността, съответстваща на делението
    }

    //преобразуване на входните дании в координати на пиксели, които се използват за центрове на //окръжности с радиус 2 пиксела
    for(i = 0 ; i < n; i ++){
        int xprim=x0 + (x[i]-xmin)/sx;
        int yprim=y0 - (y[i]-ymin)/sy;
        circle(xprim,yprim,2);
    }

    //свързване на окръжностите с отсечки и получаване на 2D графика, съответстваща на входните //данни x,y
    for(i = 0; i < n-1; i++) {
        int xa = x0 + (x[i] - xmin)/sx;
        int ya = y0 - (y[i] - ymin)/sy;
        int xb = x0 + (x[i+1] - xmin)/sx;
        int yb = y0 - (y[i+1] - ymin)/sy;
        line(xa, ya, xb, yb);
    }
}
