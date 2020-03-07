#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <stack>
#include "SinglePlayer.h"
#include "PlayerVsPlayer.h"
#include "PlayerVsComputer.h"
using namespace std;
#define MAX 20
#define FUNDAL COLOR(32,32,32)
#define SPATIU 0
#define NEGATIV BLUE
#define PIESAGOALA COLOR(32,32,32)

bool isExit=false;
void MainMenu();
void SettingsMenum();
///numar,extins
int inf,sup;


void Square(int x,int y,int l,int color)
{
    int l2=l/2;
    setcolor(color);
    line(x-l2,y-l2,x+l2,y-l2);  //linia horiz sus;
    line(x+l2,y-l2,x+l2,y+l2);  //linie vert dr;
    line(x+l2,y+l2,x-l2,y+l2);  //linie oriz jos;
    line(x-l2,y+l2,x-l2,y-l2);  //linie vert dr;
}

void Button(int x,int y,int L,int l,char s[],int text_size,int color)
{
    setcolor(color);
    int L2=L/2,l2=l/2;
    line(x-L2,y-l2,x+L2,y-l2);  //linia horiz sus;
    line(x+L2,y-l2,x+L2,y+l2);  //linie vert dr;
    line(x+L2,y+l2,x-L2,y+l2);  //linie oriz jos;
    line(x-L2,y+l2,x-L2,y-l2);  //linie vert dr;
    settextstyle(2,HORIZ_DIR,text_size);
    int text_x=textwidth(s),text_y=textheight(s);
    outtextxy(x-text_x/2,y-text_y/2,s);
}


void desenPiesaJoc(int x,int y,int r,int culoare)
{
    setcolor(culoare);
    setfillstyle(SOLID_FILL,culoare);
    circle(x,y,r);
    fillellipse(x,y,r,r);
}

void desenTablaScale(int x,int y,int scale,int mode)
{
    int startx=x;
    int starty=y;
    if(mode==1)
    {
        for(int i=1; i<=7; i++)
        {
            for(int j=1; j<=7; j++)
            {
                if((i>=3 && i<=5)||(j>=3&&j<=5))
                {
                    Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
                    desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,RED);
                }
            }
            startx=startx+1*scale;
        }
    }
    else if(mode==2)
    {
        for(int i=1; i<=7; i++)
        {
            for(int j=1; j<=7; j++)
            {
                if((i>=3 && i<=5)||(j>=3&&j<=5))
                {
                    Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
                    if(i%2==j%2)
                        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,RED);
                    else
                        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,YELLOW);
                }
            }
            startx=startx+1*scale;
        }
    }
    else if(mode==4)
    {
        for(int i=1;i<=2;i++)
        {
            for(int j=3;j<=5;j++)
            {
                Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
                desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,RED);
            }
            startx=startx+1*scale;
        }
        startx+=24;
        for(int i=6;i<=7;i++)
        {
            for(int j=3;j<=5;j++)
            {
                Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
                desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,YELLOW);
            }
            startx=startx+1*scale;
        }
        startx-=40;
        for(int i=3;i<=5;i++)
        {
            for(int j=1;j<=2;j++)
            {
                Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
                desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,CYAN);
            }
            startx=startx+1*scale;
        }
        startx-=24;
        for(int i=3;i<=5;i++)
        {
            for(int j=6;j<=7;j++)
            {
                Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
                desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,LIGHTGREEN);
            }
            startx=startx+1*scale;
        }

        startx=x;
        int i=5,j=3;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,RED);
        i=5;j=4;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,RED);

        i=9,j=4;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,YELLOW);
        i=9;j=5;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,YELLOW);

        i=7;j=3;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,CYAN);

        i=9;j=3;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,CYAN);

        i=5;j=5;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,LIGHTGREEN);

        i=7;j=5;
        Square(startx+i*1*scale,starty+j*2*scale,2*scale,WHITE);
        desenPiesaJoc(startx+i*1*scale,starty+j*2*scale,scale-4,LIGHTGREEN);

    }
}

void TablePhoto(int numar,int extins)
{
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(x_centru-190,y_centru-190,x_centru-190,y_centru-190);
    if(GameMode==1)
    {
        if(numar==7)
        {
            if(extins==0)
                readimagefile("SSinglePlayer 7x7.bmp",x_centru-150,y_centru-60-150,x_centru+150,y_centru-60+150);
            else if(extins==1)
                readimagefile("SSinglePlayer 7x7E.bmp",x_centru-152,y_centru-60-150,x_centru+152,y_centru-60+150);
        }
        else if(numar==11)
        {
            if(extins==0)
                readimagefile("SSinglePlayer 11x11.bmp",x_centru-170,y_centru-60-170,x_centru+170,y_centru-60+170);
            else if(extins==1)
                readimagefile("SSinglePlayer 11x11E.bmp",x_centru-170,y_centru-60-170,x_centru+170,y_centru-60+170);
        }
    }
    else
    {
        if(numar==7)
        {
            if(extins==0)
                readimagefile("PvP 7x7.bmp",x_centru-156,y_centru-60-155,x_centru+155,y_centru-60+155);
            else if(extins==1)
                readimagefile("PvP 7x7E.bmp",x_centru-153,y_centru-60-150,x_centru+152,y_centru-60+150);
        }
        else if(numar==11)
        {
            if(extins==0)
                readimagefile("PvP 11x11.bmp",x_centru-170,y_centru-60-170,x_centru+170,y_centru-60+170);
            else if(extins==1)
                readimagefile("PvP 11x11E.bmp",x_centru-170,y_centru-60-170,x_centru+170,y_centru-60+170);
        }
    }
}

void TableMode()
{
    int resDim;
    if(window_height==600)
        resDim=50;
    else resDim=0;
    setcolor(LIGHTGREEN);
    char s[]="Choose table mode:";
    settextstyle(3,HORIZ_DIR,7);
    int text_x=textwidth(s),text_y=textheight(s);
    outtextxy(x_centru-text_x/2,y_centru-300,s);
    Button(40,35,50,35,"<- ",14,WHITE);
    Button(x_centru,window_height-100,200,50,"Start game",14,WHITE);
    TablePhoto(numar,extins);
    if(numar==7)
            Button(x_centru-250,window_height-220,300-resDim,50,"  Dimension: 7x7  ",14,WHITE);
    else if(numar==11)
            Button(x_centru-250,window_height-220,300-resDim,50,"Dimension: 11x11",14,WHITE);

    if(extins==0)
        Button(x_centru+250,window_height-220,300-resDim,50,"Extended: OFF",14,WHITE);
    else if(extins==1)
        Button(x_centru+250,window_height-220,300-resDim,50,"  Extended: ON  ",14,WHITE);


    while(1)
    {

        int mx=mousex(),my=mousey();
        if(ismouseclick(WM_LBUTTONDOWN))clearmouseclick(WM_LBUTTONDOWN);    //click in afara butoanelor - anulat

        while(inInterior(mx,my,x_centru-100,window_height-100-50,x_centru+100,window_height-100+50))   //hover pe buton de Start Game;
        {
            mx=mousex(),my=mousey();
            Button(x_centru,window_height-100,200,50,"Start game",14,LIGHTGREEN);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                mx=mousex(),my=mousey();
                clearmouseclick(WM_LBUTTONDOWN);
                if(inInterior(mx,my,x_centru-100,window_height-100-50,x_centru+100,window_height-100+50))    //click pe buton de Start Game;
                {
                    Button(x_centru,window_height-100,200,50,"Start game",14,CYAN);
                    delay(100);
                    cleardevice();
                    if(GameMode==1)
                    {
                        if(numar==11&&extins==1)
                            numarpiese=96;
                        else if(numar==11&&extins==0)
                            numarpiese=84;
                        else if(numar==7&&extins==0)
                            numarpiese=32;
                        else if(numar==7&&extins==1)
                            numarpiese=36;
                        if(numar==7)
                        {
                            inf=3;
                            sup=5;
                        }
                        else if(numar==11)
                        {
                            inf=4;
                            sup=8;
                        }
                        initializareTabla(numar,extins,inf,sup);
                        desenareTabla(numar,extins,inf,sup);
                        return;
                    }
                    else if(GameMode==2)
                    {
                        initializareTabla2(numar,extins);
                        desenareTabla2(extins);
                        return;
                    }
                    else if(GameMode==4)
                    {
                        initializareTabla2(numar,extins);
                        desenareTabla2(extins);
                        return;
                    }
                }

            }
        }
        Button(x_centru,window_height-100,200,50,"Start game",14,WHITE);

        while(inInterior(mx,my,x_centru-250-150+resDim,window_height-220-25,x_centru-250+150-resDim,window_height-220+25)) //hover pe buton de Table Dim;
        {
            mx=mousex(),my=mousey();
            if(numar==7)
                Button(x_centru-250,window_height-220,300-resDim,50,"  Dimension: 7x7  ",14,LIGHTGREEN);
            else if(numar==11)
                Button(x_centru-250,window_height-220,300-resDim,50,"Dimension: 11x11",14,LIGHTGREEN);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                mx=mousex(),my=mousey();
                clearmouseclick(WM_LBUTTONDOWN);
                if(inInterior(mx,my,x_centru-250-150+resDim,window_height-220-25,x_centru-250+150-resDim,window_height-220+25))  //click pe buton de Table Dim;
                {

                    if(numar==7)
                    {
                        Button(x_centru-250,window_height-220,300-resDim,50,"  Dimension: 7x7  ",14,CYAN);
                        delay(100);
                        numar=11;
                        Button(x_centru-250,window_height-220,300-resDim,50,"  Dimension: 7x7  ",14,LIGHTGREEN);
                        TablePhoto(numar,extins);

                    }
                    else if(numar==11)
                    {
                        Button(x_centru-250,window_height-220,300-resDim,50,"Dimension: 11x11",14,CYAN);
                        delay(100);
                        numar=7;
                        Button(x_centru-250,window_height-220,300-resDim,50,"Dimension: 11x11",14,LIGHTGREEN);
                        TablePhoto(numar,extins);
                    }
                }
            }
        }
        if(numar==7)
            Button(x_centru-250,window_height-220,300-resDim,50,"  Dimension: 7x7  ",14,WHITE);
        else if(numar==11)
            Button(x_centru-250,window_height-220,300-resDim,50,"Dimension: 11x11",14,WHITE);


        while(inInterior(mx,my,x_centru+250-150+resDim,window_height-220-25,x_centru+250+150-resDim,window_height-220+25)) //hover pe buton de Extended;
        {
            mx=mousex(),my=mousey();
            if(extins==0)
                Button(x_centru+250,window_height-220,300-resDim,50,"Extended: OFF",14,LIGHTGREEN);
            else if(extins==1)
                Button(x_centru+250,window_height-220,300-resDim,50,"  Extended: ON  ",14,LIGHTGREEN);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                mx=mousex(),my=mousey();
                clearmouseclick(WM_LBUTTONDOWN);
                if(inInterior(mx,my,x_centru+250-150+resDim,window_height-220-25,x_centru+250+150-resDim,window_height-220+25))  //click pe buton de Extended;
                {
                    if(extins==0)
                    {
                        Button(x_centru+250,window_height-220,300-resDim,50,"  Extended: ON  ",14,CYAN);
                        delay(100);
                        extins=1;
                        Button(x_centru+250,window_height-220,300-resDim,50,"  Extended: ON  ",14,LIGHTGREEN);
                        TablePhoto(numar,extins);
                    }
                    else if(extins==1)
                    {
                        Button(x_centru+250,window_height-220,300-resDim,50,"Extended: OFF",14,CYAN);
                        delay(100);
                        extins=0;
                        Button(x_centru+250,window_height-220,300-resDim,50,"Extended: OFF",14,LIGHTGREEN);
                        TablePhoto(numar,extins);
                    }
                }

            }

        }
        if(extins==0)
            Button(x_centru+250,window_height-220,300-resDim,50,"Extended: OFF",14,WHITE);
        else if(extins==1)
            Button(x_centru+250,window_height-220,300-resDim,50,"  Extended: ON  ",14,WHITE);


        while(inInterior(mx,my,40-25,35-17,40+25,35+17)) //hover pe buton de back;
        {
            Button(40,35,50,35,"<- ",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                if(inInterior(mx,my,40-25,35-17,40+25,35+17))    //click pe buton de back;
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(40,35,50,35,"<- ",14,CYAN);
                    delay(100);
                    Button(40,35,50,35,"<- ",14,WHITE);
                    cleardevice();
                    PlayMenu();
                    return;
                }
            }
        }
        Button(40,35,50,35,"<- ",14,WHITE);
    }
}

void PlayMenu()
{
    setcolor(LIGHTGREEN);
    char s[]="Choose game mode:";
    settextstyle(3,HORIZ_DIR,7);
    int text_x=textwidth(s),text_y=textheight(s);
    outtextxy(x_centru-text_x/2,y_centru-240,s);
    Button(40,35,50,35,"<- ",14,WHITE);

    Button(window_width/3-121,y_centru-100,200,50,"SinglePlayer",14,WHITE);
    line(window_width/3-121-100,y_centru-100-25,window_width/3-121-100,y_centru+70);
    line(window_width/3-121-100,y_centru+70,window_width/3-121+100,y_centru+70);
    line(window_width/3-121+100,y_centru+70,window_width/3-121+100,y_centru-100-25);
    desenTablaScale(window_width/3-179,y_centru-70,8,1);

    setcolor(WHITE);
    Button(x_centru,y_centru-100,230,50,"PlayerVsPlayer",14,WHITE);
    line(x_centru-115,y_centru-100-25,x_centru-115,y_centru+70);
    line(x_centru-115,y_centru+70,x_centru+115,y_centru+70);
    line(x_centru+115,y_centru+70,x_centru+115,y_centru-100-25);
    desenTablaScale(x_centru-55,y_centru-70,8,2);

    setcolor(WHITE);
    Button(2*window_width/3+121,y_centru-100,200,50,"PlayerVsPC",14,WHITE);
    line(2*window_width/3+111-90,y_centru-100-25,2*window_width/3+111-90,y_centru+70);
    line(2*window_width/3+111-90,y_centru+70,2*window_width/3+131+90,y_centru+70);
    line(2*window_width/3+131+90,y_centru+70,2*window_width/3+131+90,y_centru-100-25);
    desenTablaScale(2*window_width/3+65,y_centru-70,8,2);

    while(1)
    {
        int mx=mousex(),my=mousey();
        if(ismouseclick(WM_LBUTTONDOWN))clearmouseclick(WM_LBUTTONDOWN);    //click in afara butoanelor - anulat
        while(inInterior(mx,my,window_width/3-121-90,y_centru-125,window_width/3-121+90,y_centru-75))   //hover pe buton de SinglePlayer;
        {
            Sleep(10);
            mx=mousex(),my=mousey();
            Button(window_width/3-121,y_centru-100,200,50,"SinglePlayer",14,LIGHTGREEN);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                mx=mousex(),my=mousey();
                clearmouseclick(WM_LBUTTONDOWN);
                if(inInterior(mx,my,window_width/3-121-90,y_centru-125,window_width/3-121+90,y_centru-75))    //click pe buton de SinglePlayer;
                {
                    GameMode=1;
                    Button(window_width/3-121,y_centru-100,200,50,"SinglePlayer",14,CYAN);
                    delay(100);
                    cleardevice();
                        ///MODIFICA MANUAL DIMENSIUNEA TABLEI (NUMAR =7 SAU 11 EXTINS=1 SAU 0)

                    TableMode();
                    //  initializareTabla();
                    //desenareTabla();
                    return;
                }
            }
        }
        Button(window_width/3-121,y_centru-100,200,50,"SinglePlayer",14,WHITE);

        while(inInterior(mx,my,x_centru-55,y_centru-125,x_centru+55,y_centru-75))       //hover pe buton de PlayerVsPlayer;
        {
            Sleep(10);
            mx=mousex(),my=mousey();
            Button(x_centru,y_centru-100,230,50,"PlayerVsPlayer",14,LIGHTGREEN);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                mx=mousex(),my=mousey();
                clearmouseclick(WM_LBUTTONDOWN);
                if(inInterior(mx,my,x_centru-55,y_centru-125,x_centru+55,y_centru-75))    //click pe buton de PlayerVsPlayer;
                {
                    GameMode=2;
                    Button(x_centru,y_centru-100,230,50,"PlayerVsPlayer",14,CYAN);
                    delay(100);
                    cleardevice();
                    TableMode();
                    return;
                }
            }
        }
        Button(x_centru,y_centru-100,230,50,"PlayerVsPlayer",14,WHITE);

        while(inInterior(mx,my,2*window_width/3+121-90,y_centru-125,2*window_width/3+121+90,y_centru-75))   //hover pe buton de PlayerVsPC;
        {
            Sleep(10);
            mx=mousex(),my=mousey();
            Button(2*window_width/3+121,y_centru-100,200,50,"PlayerVsPC",14,LIGHTGREEN);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                mx=mousex(),my=mousey();
                clearmouseclick(WM_LBUTTONDOWN);
                if(inInterior(mx,my,2*window_width/3+121-90,y_centru-125,2*window_width/3+121+90,y_centru-75))    //click pe buton de PlayerVsPC;
                {
                    GameMode=4;
                    Button(2*window_width/3+121,y_centru-100,200,50,"PlayerVsPC",14,CYAN);
                    delay(100);
                    cleardevice();
                    TableMode();

                    return;
                }
            }
        }
        Button(2*window_width/3+121,y_centru-100,200,50,"PlayerVsPC",14,WHITE);

        while(inInterior(mx,my,40-25,35-17,40+25,35+17)) //hover pe buton de back;
        {
            Sleep(10);
            Button(40,35,50,35,"<- ",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                if(inInterior(mx,my,40-25,35-17,40+25,35+17))    //click pe buton de back;
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(40,35,50,35,"<- ",14,CYAN);
                    delay(100);
                    Button(40,35,50,35,"<- ",14,WHITE);
                    cleardevice();
                    MainMenu();
                    return;
                }
            }
        }
        Button(40,35,50,35,"<- ",14,WHITE);
    }
}

void colorBoardP1()
{
   for(int i=8;i<=15;i++)
    {
        if(window_width==1280)
            Square(x_centru-330+60*i,window_height-200,60,WHITE);
        else if(window_width==1920)
            Square(x_centru-330+60*i,window_height-300,60,WHITE);
        if(i==LIGHTRED)
        {
            setcolor(RED);
            setfillstyle(SOLID_FILL,RED);
        }
        else
        {
            setcolor(i);
            setfillstyle(SOLID_FILL,i);
        }
        if(window_width==1280)
            fillellipse(x_centru-330+60*i,window_height-200,20,20);
        else if(window_width==1920)
            fillellipse(x_centru-330+60*i,window_height-300,20,20);
    }
}

void colorBoardP2()
{
    for(int i=8;i<=15;i++)
    {
        if(window_width==1280)
            Square(x_centru-330+60*i,window_height-100,60,WHITE);
        else if(window_width==1920)
            Square(x_centru-330+60*i,window_height-200,60,WHITE);
        if(i==LIGHTRED)
        {
            setcolor(RED);
            setfillstyle(SOLID_FILL,RED);
        }
        else
        {
            setcolor(i);
            setfillstyle(SOLID_FILL,i);
        }
        if(window_width==1280)
            fillellipse(x_centru-330+60*i,window_height-100,20,20);
        else if(window_width==1920)
            fillellipse(x_centru-330+60*i,window_height-200,20,20);
    }
}

void SettingsMenuM()
{
    int resdim=0;
    if(window_width==1920)resdim=100;
    setbkcolor(FUNDAL);
    setcolor(LIGHTGREEN);
    char s[]="Settings",r[]="Resolution",t[]="Sound",c[]="Color",p1[]="P1: ",p2[]="P2: ";
    settextstyle(3,HORIZ_DIR,9);
    int text_x=textwidth(s),text_y=textheight(s);
    outtextxy(x_centru-text_x/2,y_centru-300,s);
    settextstyle(3,HORIZ_DIR,6);
    outtextxy(x_centru-textwidth(r)/2-400,y_centru-150-textheight(r)/2,r);
    outtextxy(x_centru-textwidth(r)/2+400,y_centru-150-textheight(r)/2,t);
    outtextxy(x_centru-textwidth(c)/2+355,y_centru+65+resdim-textheight(r)/2,c);
    if(window_width==1280)
    {
        outtextxy(x_centru-textwidth(p1)/2+70,window_height-200-textheight(p1)/2,p1);
        outtextxy(x_centru-textwidth(p2)/2+70,window_height-100-textheight(p2)/2,p2);
    }
    else if(window_width==1920)
    {
        outtextxy(x_centru-textwidth(p1)/2+70,window_height-300-textheight(p1)/2,p1);
        outtextxy(x_centru-textwidth(p2)/2+70,window_height-200-textheight(p2)/2,p2);
    }

    Button(40,35,50,35,"<- ",14,WHITE);
    Button(x_centru-400,y_centru-60,200,50,"Small",14,WHITE);
    Button(x_centru-400,y_centru+10,200,50,"Medium",14,WHITE);
    Button(x_centru-400,y_centru+80,200,50,"Large",14,WHITE);
    Button(x_centru+350,y_centru-60,300,50,"  Sound Effects ON  ",14,WHITE);
    colorBoardP1();
    colorBoardP2();

    while(1)
    {
        int mx=mousex(),my=mousey();
        if(ismouseclick(WM_LBUTTONDOWN))clearmouseclick(WM_LBUTTONDOWN);    //click in afara butoanelor - anulat

        while (inInterior(mx,my,x_centru-400-100,y_centru-60-25,x_centru-400+100,y_centru-60+25))
        {
            Sleep(10);
            Button(x_centru-400,y_centru-60,200,50,"Small",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru-400-100,y_centru-60-25,x_centru-400+100,y_centru-60+25))    //click pe buton de back;
                {
                    res=true;
                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(x_centru-400,y_centru-60,200,50,"Small",14,CYAN);
                    delay(100);
                    Button(x_centru-400,y_centru-60,200,50,"Small",14,WHITE);
                    cleardevice();
                    closegraph();
                    window_width=800;
                    x_centru=window_width/2;
                    window_height=600;
                    y_centru=window_height/2;

                    return;
                }
            }
        }
        Button(x_centru-400,y_centru-60,200,50,"Small",14,WHITE);

        while (inInterior(mx,my,x_centru-400-100,y_centru+10-25,x_centru-400+100,y_centru+10+25))   //hover buton medium
        {
            Sleep(10);
            Button(x_centru-400,y_centru+10,200,50,"Medium",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru-400-100,y_centru+10-25,x_centru-400+100,y_centru+10+25))   //hover buton medium
                {
                    Sleep(10);
                    res=true;
                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(x_centru-400,y_centru+10,200,50,"Medium",14,CYAN);
                    delay(100);
                    Button(x_centru-400,y_centru+10,200,50,"Medium",14,WHITE);
                    cleardevice();
                    closegraph();
                    window_width=1280;
                    x_centru=window_width/2;
                    window_height=720;
                    y_centru=window_height/2;

                    return;
                }
            }
        }
        Button(x_centru-400,y_centru+10,200,50,"Medium",14,WHITE);

        while (inInterior(mx,my,x_centru-400-100,y_centru+80-25,x_centru-400+100,y_centru+80+25))   //hover buton Large
        {
            Sleep(10);
            Button(x_centru-400,y_centru+80,200,50,"Large",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru-400-100,y_centru+80-25,x_centru-400+100,y_centru+80+25))   //hover buton Large
                {
                    Sleep(10);
                    res=true;
                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(x_centru-400,y_centru+80,200,50,"Large",14,CYAN);
                    delay(100);
                    Button(x_centru-400,y_centru+80,200,50,"Large",14,WHITE);
                    cleardevice();
                    closegraph();
                    window_width=1920;
                    x_centru=window_width/2;
                    window_height=1080;
                    y_centru=window_height/2;

                    return;
                }
            }
        }
        Button(x_centru-400,y_centru+80,200,50,"Large",14,WHITE);

        while (inInterior(mx,my,x_centru+350-150,y_centru-60-25,x_centru+350+150,y_centru-60+25))   //hover buton Sound
        {
            Sleep(10);
            if(sound==true)
                Button(x_centru+350,y_centru-60,300,50,"  Sound Effects ON  ",14,LIGHTGREEN);
            else
                Button(x_centru+350,y_centru-60,300,50,"Sound Effects OFF",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru+350-150,y_centru-60-25,x_centru+350+150,y_centru-60+25))   //hover buton Sound
                {
                    Sleep(10);
                    if(sound==true)
                    {
                        sound=false;
                        clearmouseclick(WM_LBUTTONDOWN);
                        Button(x_centru+350,y_centru-60,300,50,"Sound Effects OFF",14,CYAN);
                        delay(100);
                        Button(x_centru+350,y_centru-60,300,50,"Sound Effects OFF",14,WHITE);
                    }
                    else if (sound==false)
                    {
                        sound=true;
                        clearmouseclick(WM_LBUTTONDOWN);
                        Button(x_centru+350,y_centru-60,300,50,"  Sound Effects ON  ",14,CYAN);
                        delay(100);
                        Button(x_centru+350,y_centru-60,300,50,"  Sound Effects ON  ",14,WHITE);
                    }
                }
            }
        }
        if(sound==true)
            Button(x_centru+350,y_centru-60,300,50,"  Sound Effects ON  ",14,WHITE);
        else
            Button(x_centru+350,y_centru-60,300,50,"Sound Effects OFF",14,WHITE);

        while(inInterior(mx,my,40-25,35-17,40+25,35+17)) //hover pe buton de back;
        {
            Sleep(10);
            Button(40,35,50,35,"<- ",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,40-25,35-17,40+25,35+17))    //click pe buton de back;
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(40,35,50,35,"<- ",14,CYAN);
                    delay(100);
                    Button(40,35,50,35,"<- ",14,WHITE);
                    cleardevice();
                    MainMenu();
                    return;
                }
            }
        }
        Button(40,35,50,35,"<- ",14,WHITE);

        ///CULORI P1:

        for(int i=8;i<=15;i++)
        {
            while(inInterior(mx,my,x_centru-330+60*i-30,window_height-200-resdim-30,x_centru-330+60*i+30,window_height-resdim-200+30))
            {
                Square(x_centru-330+60*i,window_height-200-resdim,60,LIGHTGREEN);
                mx=mousex(),my=mousey();
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    if(inInterior(mx,my,x_centru-330+60*i-30,window_height-200-resdim-30,x_centru-330+60*i+30,window_height-resdim-200+30))
                    {

                        clearmouseclick(WM_LBUTTONDOWN);
                        Square(x_centru-330+60*i,window_height-200-resdim,60,CYAN);
                        delay(100);
                        Square(x_centru-330+60*i,window_height-200-resdim,60,WHITE);
                        PIESA1=i;
                    }
                }
            }
            Square(x_centru-330+60*i,window_height-200-resdim,60,WHITE);
        }

        ///CULORI P2:

        for(int i=8;i<=15;i++)
        {
            while(inInterior(mx,my,x_centru-330+60*i-30,window_height-100-resdim-30,x_centru-330+60*i+30,window_height-100-resdim+30))
            {
                Square(x_centru-330+60*i,window_height-100-resdim,60,LIGHTGREEN);
                mx=mousex(),my=mousey();
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    if(inInterior(mx,my,x_centru-330+60*i-30,window_height-100-resdim-30,x_centru-330+60*i+30,window_height-100-resdim+30))
                    {

                        clearmouseclick(WM_LBUTTONDOWN);
                        Square(x_centru-330+60*i,window_height-100-resdim,60,CYAN);
                        delay(100);
                        Square(x_centru-330+60*i,window_height-100-resdim,60,WHITE);
                        PIESA2=i;
                    }
                }
            }
            Square(x_centru-330+60*i,window_height-100-resdim,60,WHITE);
        }
    }
    getch();
}

void colorBoardP1m()
{
   for(int i=8;i<=15;i++)
    {
        Square(x_centru-660+60*i,y_centru+170,60,WHITE);
        if(i==LIGHTRED)
        {
            setcolor(RED);
            setfillstyle(SOLID_FILL,RED);
        }
        else
        {
            setcolor(i);
            setfillstyle(SOLID_FILL,i);
        }
        fillellipse(x_centru-660+60*i,y_centru+170,20,20);
    }
}

void colorBoardP2m()
{
   for(int i=8;i<=15;i++)
    {
        Square(x_centru-660+60*i,y_centru+255,60,WHITE);
        if(i==LIGHTRED)
        {
            setcolor(RED);
            setfillstyle(SOLID_FILL,RED);
        }
        else
        {
            setcolor(i);
            setfillstyle(SOLID_FILL,i);
        }
        fillellipse(x_centru-660+60*i,y_centru+255,20,20);
    }
}

void SettingsMenum()
{
    setbkcolor(FUNDAL);
    setcolor(LIGHTGREEN);
    char s[]="Settings",r[]="Resolution",t[]="Sound",c[]="Color",p1[]="P1: ",p2[]="P2: ";
    settextstyle(3,HORIZ_DIR,9);
    int text_x=textwidth(s),text_y=textheight(s);
    outtextxy(x_centru-text_x/2,y_centru-300,s);
    settextstyle(3,HORIZ_DIR,6);
    outtextxy(x_centru-textwidth(r)/2-200,y_centru-150-textheight(r)/2,r);
    outtextxy(x_centru-textwidth(r)/2+200,y_centru-150-textheight(r)/2,t);
    outtextxy(x_centru-textwidth(p1)/2-280,y_centru+170-textheight(p1)/2,p1);
    outtextxy(x_centru-textwidth(p2)/2-280,y_centru+255-textheight(p2)/2,p2);
    Button(40,35,50,35,"<- ",14,WHITE);
    Button(x_centru-200,y_centru-60,200,50,"Small",14,WHITE);
    Button(x_centru-200,y_centru+10,200,50,"Medium",14,WHITE);
    Button(x_centru-200,y_centru+80,200,50,"Large",14,WHITE);
    Button(x_centru+150,y_centru-60,300,50,"  Sound Effects ON  ",14,WHITE);
    colorBoardP1m();
    colorBoardP2m();
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))clearmouseclick(WM_LBUTTONDOWN);    //click in afara butoanelor - anulat
        int mx=mousex(),my=mousey();

        while (inInterior(mx,my,x_centru-200-100,y_centru-60-25,x_centru-200+100,y_centru-60+25)) //hover buton small
        {
            Button(x_centru-200,y_centru-60,200,50,"Small",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru-200-100,y_centru-60-25,x_centru-200+100,y_centru-60+25))    //click buton small
                {
                    res=true;
                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(x_centru-200,y_centru-60,200,50,"Small",14,CYAN);
                    delay(100);
                    Button(x_centru-200,y_centru-60,200,50,"Small",14,WHITE);
                    cleardevice();
                    closegraph();
                    window_width=800;
                    x_centru=window_width/2;
                    window_height=600;
                    y_centru=window_height/2;

                    return;
                }
            }
        }
        Button(x_centru-200,y_centru-60,200,50,"Small",14,WHITE);

        while (inInterior(mx,my,x_centru-200-100,y_centru+80-25,x_centru-200+100,y_centru+80+25))   //hover buton Large
        {
            Button(x_centru-200,y_centru+80,200,50,"Large",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru-200-100,y_centru+80-25,x_centru-200+100,y_centru+80+25))   //hover buton Large
                {
                    res=true;
                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(x_centru-200,y_centru+80,200,50,"Large",14,CYAN);
                    delay(100);
                    Button(x_centru-200,y_centru+80,200,50,"Large",14,WHITE);
                    cleardevice();
                    closegraph();
                    window_width=1920;
                    x_centru=window_width/2;
                    window_height=1080;
                    y_centru=window_height/2;

                    return;
                }
            }
        }
        Button(x_centru-200,y_centru+80,200,50,"Large",14,WHITE);

        while (inInterior(mx,my,x_centru-200-100,y_centru+10-25,x_centru-200+100,y_centru+10+25))   //hover buton medium
        {
            Button(x_centru-200,y_centru+10,200,50,"Medium",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru-200-100,y_centru+10-25,x_centru-200+100,y_centru+10+25))   //hover buton medium
                {
                    res=true;
                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(x_centru-200,y_centru+10,200,50,"Medium",14,CYAN);
                    delay(100);
                    Button(x_centru-200,y_centru+10,200,50,"Medium",14,WHITE);
                    cleardevice();
                    closegraph();
                    window_width=1280;
                    x_centru=window_width/2;
                    window_height=720;
                    y_centru=window_height/2;

                    return;
                }
            }
        }
        Button(x_centru-200,y_centru+10,200,50,"Medium",14,WHITE);

        while (inInterior(mx,my,x_centru+150-150,y_centru-60-25,x_centru+350+150,y_centru-60+25))   //hover buton Sound
        {
            if(sound==true)
                Button(x_centru+150,y_centru-60,300,50,"  Sound Effects ON  ",14,LIGHTGREEN);
            else
                Button(x_centru+150,y_centru-60,300,50,"Sound Effects OFF",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,x_centru+150-150,y_centru-60-25,x_centru+150+150,y_centru-60+25))   //hover buton Sound
                {
                    if(sound==true)
                    {
                        sound=false;
                        clearmouseclick(WM_LBUTTONDOWN);
                        Button(x_centru+150,y_centru-60,300,50,"Sound Effects OFF",14,CYAN);
                        delay(100);
                        Button(x_centru+150,y_centru-60,300,50,"Sound Effects OFF",14,WHITE);
                    }
                    else if (sound==false)
                    {
                        sound=true;
                        clearmouseclick(WM_LBUTTONDOWN);
                        Button(x_centru+150,y_centru-60,300,50,"  Sound Effects ON  ",14,CYAN);
                        delay(100);
                        Button(x_centru+150,y_centru-60,300,50,"  Sound Effects ON  ",14,WHITE);
                    }
                }
            }
        }
        if(sound==true)
            Button(x_centru+150,y_centru-60,300,50,"  Sound Effects ON  ",14,WHITE);
        else
            Button(x_centru+150,y_centru-60,300,50,"Sound Effects OFF",14,WHITE);

        while(inInterior(mx,my,40-25,35-17,40+25,35+17)) //hover pe buton de back;
        {
            Button(40,35,50,35,"<- ",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,40-25,35-17,40+25,35+17))    //click pe buton de back;
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(40,35,50,35,"<- ",14,CYAN);
                    delay(100);
                    Button(40,35,50,35,"<- ",14,WHITE);
                    cleardevice();
                    MainMenu();
                    return;
                }
            }
        }
        Button(40,35,50,35,"<- ",14,WHITE);


        ///CULORI P1:

        for(int i=8;i<=15;i++)
        {
            while(inInterior(mx,my,x_centru-660+60*i-30,y_centru+170-30,x_centru-660+60*i+30,y_centru+170+30))
            {
                Square(x_centru-660+60*i,y_centru+170,60,LIGHTGREEN);
                mx=mousex(),my=mousey();
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    if(inInterior(mx,my,x_centru-660+60*i-30,y_centru+170-30,x_centru-660+60*i+30,y_centru+170+30))
                    {

                        clearmouseclick(WM_LBUTTONDOWN);
                        Square(x_centru-660+60*i,y_centru+170,60,CYAN);
                        delay(100);
                        Square(x_centru-660+60*i,y_centru+170,60,WHITE);
                        PIESA1=i;
                    }
                }
            }
            Square(x_centru-660+60*i,y_centru+170,60,WHITE);
        }

        ///CULORI P2:

        for(int i=8;i<=15;i++)
        {
            while(inInterior(mx,my,x_centru-660+60*i-30,y_centru+255-30,x_centru-660+60*i+30,y_centru+255+30))
            {
                Square(x_centru-660+60*i,y_centru+255,60,LIGHTGREEN);
                mx=mousex(),my=mousey();
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    if(inInterior(mx,my,x_centru-660+60*i-30,y_centru+255-30,x_centru-660+60*i+30,y_centru+255+30))
                    {

                        clearmouseclick(WM_LBUTTONDOWN);
                        Square(x_centru-660+60*i,y_centru+255,60,CYAN);
                        delay(100);
                        Square(x_centru-660+60*i,y_centru+255,60,WHITE);
                        PIESA2=i;
                    }
                }
            }
            Square(x_centru-660+60*i,y_centru+255,60,WHITE);
        }

    }
    getch();
}

void tutorial()
{
    if(window_width==800)
        readimagefile("Tutorial.bmp",0,0,800,600);
    else if(window_width==1280)
        readimagefile("Tutorial.bmp",0,0,1280,720);
    else
        readimagefile("Tutorial.bmp",0,0,1920,1080);
    Button(40,35,50,35,"<- ",14,WHITE);
    while(1)
    {
        int mx=mousex(),my=mousey();
        while(inInterior(mx,my,40-25,35-17,40+25,35+17)) //hover pe buton de back;
        {
            Button(40,35,50,35,"<- ",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(inInterior(mx,my,40-25,35-17,40+25,35+17))    //click pe buton de back;
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    Button(40,35,50,35,"<- ",14,CYAN);
                    delay(100);
                    Button(40,35,50,35,"<- ",14,WHITE);
                    cleardevice();
                    MainMenu();
                    return;
                }
            }
        }
        Button(40,35,50,35,"<- ",14,WHITE);
    }
}

void MainMenu()
{
    setbkcolor(FUNDAL);
    setcolor(LIGHTGREEN);
    char s[]="Soli",s1[]="taire";
    settextstyle(3,HORIZ_DIR,9);
    int text_x=textwidth(s),text_y=textheight(s);
    for(int i=1;i<=500;i+=20)
    {
        cleardevice();
        outtextxy(x_centru-text_x/2-570+i,y_centru-255,s);
        outtextxy(x_centru-text_x/2+550-i,y_centru-255,s1);
        delay(45);
    }

    Button(x_centru,y_centru-100,200,50,"Play Game",14,WHITE);
    Button(x_centru,y_centru-20,200,50,"How to play",14,WHITE);
    Button(x_centru,y_centru+60,200,50,"Settings",14,WHITE);
    Button(x_centru,y_centru+140,200,50,"Exit",14,WHITE);

    int i=1;
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))clearmouseclick(WM_LBUTTONDOWN);    //click in afara butoanelor - anulat
        desenTablaScale(x_centru+245,y_centru-265,8,i);
        desenTablaScale(x_centru-360,y_centru-265,8,i);
        if(i==4) i=1;
        else i*=2;
        delay(100);
        int mx=mousex(),my=mousey();
        while(inInterior(mx,my,x_centru-100,y_centru-125,x_centru+100,y_centru-75))    //hover pe buton de play;
        {
            Button(x_centru,y_centru-100,200,50,"Play Game",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                if(inInterior(mx,my,x_centru-100,y_centru-125,x_centru+100,y_centru-75))    //click pe buton de play;
                {
                    Button(x_centru,y_centru-100,200,50,"Play Game",14,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);
                    Button(x_centru,y_centru-100,200,50,"Play Game",14,WHITE);
                    cleardevice();
                    PlayMenu();
                    return;
                }
            }
        }
        Button(x_centru,y_centru-100,200,50,"Play Game",14,WHITE);

        while(inInterior(mx,my,x_centru-100,y_centru+60-25,x_centru+100,y_centru+60+25)) //hover pe buton de setari;
        {
            Button(x_centru,y_centru+60,200,50,"Settings",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                if(inInterior(mx,my,x_centru-100,y_centru+60-25,x_centru+100,y_centru+60+25))    //click pe buton de setari;
                {

                    Button(x_centru,y_centru+60,200,50,"Settings",14,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);
                    Button(x_centru,y_centru+60,200,50,"Settings",14,WHITE);
                    cleardevice();
                    if(window_height==600)
                        SettingsMenum();
                    else SettingsMenuM();
                    return;
                }
            }
        }
        Button(x_centru,y_centru+60,200,50,"Settings",14,WHITE);

        while(inInterior(mx,my,x_centru-100,y_centru-20-25,x_centru+100,y_centru-20+25)) //hover pe buton de how to play;
        {
            Button(x_centru,y_centru-20,200,50,"How to play",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                if(inInterior(mx,my,x_centru-100,y_centru-20-25,x_centru+100,y_centru-20+25))    //click pe buton de how to play;
                {

                    Button(x_centru,y_centru-20,200,50,"How to play",14,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);
                    Button(x_centru,y_centru-20,200,50,"How to play",14,WHITE);
                    cleardevice();
                    tutorial();
                    return;
                }
            }
        }
        Button(x_centru,y_centru-20,200,50,"How to play",14,WHITE);

        while(inInterior(mx,my,x_centru-100,y_centru+140-25,x_centru+100,y_centru+140+25)) //hover pe buton de exit;
        {
            Button(x_centru,y_centru+140,200,50,"Exit",14,LIGHTGREEN);
            mx=mousex(),my=mousey();
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                if(inInterior(mx,my,x_centru-100,y_centru+140-25,x_centru+100,y_centru+140+25))    //click pe buton de exit;
                {

                    Button(x_centru,y_centru+140,200,50,"Exit",14,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);

                    Button(x_centru,y_centru+140,200,50,"Exit",14,WHITE);
                    isExit=true;
                    closegraph();
                    return;
                }
            }
        }
        Button(x_centru,y_centru+140,200,50,"Exit",14,WHITE);
    }
}

#endif // MENUS_H_INCLUDED
