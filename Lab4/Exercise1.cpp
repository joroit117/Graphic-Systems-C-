#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

int main(){
    initwindow(1000,800);
    int x0 = 200;
    int y0 = 600;

    int Px = 600;
    int Py = 400;

    int Dx = 60;
    int Dy = 50;

    float xArray[] = {25, -40, 68, -87, 100, 141, -180, 209, 340, 467};
    float yArray[] = {70, -50, 65, 97, 450, 101, -90, 279, 40, 260};

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(xArray[j] > xArray[i]){

                float tempX = xArray[j];
                float tempY = yArray[j];

                xArray[j] = xArray[i];
                yArray[j] = yArray[i];

                xArray[i] = tempX;
                yArray[i] = tempY;
            }
        }
    }

    float xMin = xArray[0];
    float xMax = xArray[0];

    for(int i = 1; i < 10; i++){
        if(xArray[i] < xMin)xMin = xArray[i];
        if(xArray[i] > xMax)xMax = xArray[i];
    }

    float yMin = yArray[0];
    float yMax = yArray[0];

    for(int i = 1; i < 10; i++){
        if(yArray[i] < yMin)yMin = yArray[i];
        if(yArray[i] > yMax)yMax = yArray[i];
    }

    float Sx = (xMax - xMin) / Px;
    float Sy = (yMax - yMin) / Py;

    line(x0, y0, x0 + Px, y0);
    line(x0, y0, x0, y0 - Py);

    int I = Px / Dx;
    int J = Py / Dy;

    for(int i = 0; i <= I; i++){
        line(x0 + i * Dx, y0, x0 + i * Dx, y0 + 3);
    }
    for(int j = 0; j <= J; j++){
        line(x0, y0 - j * Dy, x0 - 3, y0 - j * Dy);
    }

    char text[10];

    for(int i = 0; i <= I; i++){
        gcvt(xMin + i * Dx * Sx, 5.2, text);
        settextjustify(1, 2);
        outtextxy(x0 + i * Dx, y0 + 3, text);
    }

    for(int j = 0; j <= J; j++){
        gcvt(yMin + j * Dy * Sy, 5.2, text);
        settextjustify(2, 1);
        outtextxy(x0 - 3, y0 - j * Dy, text);
    }

    moveto(x0, y0 - ((yArray[0] - yMin) / Sy));
    for(int i = 0; i < 10; i++){
        int xi = x0 + ((xArray[i] - xMin) / Sx);
        int yi = y0 - ((yArray[i] - yMin) / Sy);

        circle(xi, yi, 2);
        lineto(xi, yi);

    }

    getch();

    return 0;
}
