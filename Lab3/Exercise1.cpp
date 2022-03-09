#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
    initwindow(1000, 800);

    int x = 400;
    int y = 300;

    int st = 20;
    int st1 = 20;
    do{
        setlinestyle(0, 0, 3);

        arc(x + 100, y - 100, 135, 315, 141);
        arc(x + 100, y + 100, 45, 225, 141);
        arc(x - 100, y + 100, 315, 135, 141);
        arc(x - 100, y - 100, 225, 45, 141);

        setfillstyle(1, 2);
        floodfill(x, y - 100, 15);
        setfillstyle(1, 4);
        floodfill(x, y + 100, 15);
        setfillstyle(1, 6);
        floodfill(x - 100, y, 15);
        setfillstyle(1, 8);
        floodfill(x + 100, y, 15);

        circle(x, y - 100, 15);
        circle(x, y + 100, 15);
        circle(x - 100, y, 15);
        circle(x + 100, y, 15);

        settextjustify(1, 1);

        outtextxy(x, y - 100, "Flower");
        outtextxy(x, y + 100, "Flower");
        outtextxy(x - 100, y, "Flower");
        outtextxy(x + 100, y, "Flower");


        cleardevice();
        x+=st;
        y+=st1;

        if(x<200||x>800){
            st*=-1;
        }
        if(y<200||y>600){
            st1*=-1;
        }

    }while(!kbhit());


    getch();
}
