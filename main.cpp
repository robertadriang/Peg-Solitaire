#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <stack>
#include <string>
#include <mmsystem.h>
#include "Menus.h"
#include "SinglePlayer.h"
#include "PlayerVsComputer.h"
using namespace std;
#define MAX 20
#define FUNDAL COLOR(32,32,32)
#define SPATIU 0
#define NEGATIV BLUE
#define PIESAGOALA COLOR(32,32,32)

void afisScor1()
{
    char s[10];
    settextstyle(3,HORIZ_DIR,6);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(x_centru+220,y_centru-25,x_centru+460,y_centru+25);
    setcolor(PIESA1);
    to_string(s,numarpiese);
    if(window_height==600)
        outtextxy(x_centru+265,y_centru-25,s);
    else
        outtextxy(x_centru+300,y_centru-25,s);
}

void afisScor2M()
{
    char s[10];
    settextstyle(3,HORIZ_DIR,6);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(x_centru+250,y_centru-25,x_centru+500,y_centru+25);
    setcolor(WHITE);
    outtextxy(x_centru+405,y_centru-25,":");
    setcolor(PIESA1);
    to_string(s,numar_elemente(PIESA1,numar));
    outtextxy(x_centru+330,y_centru-20,s);
    setcolor(PIESA2);
    to_string(s,numar_elemente(PIESA2,numar));
    outtextxy(x_centru+430,y_centru-20,s);
}

void afisScor2m()
{
    char s[10];
    settextstyle(3,HORIZ_DIR,6);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(window_width-250,window_height-105,window_width,window_height);
    setcolor(WHITE);
    outtextxy(window_width-175,window_height-105,":");
    setcolor(PIESA1);
    to_string(s,numar_elemente(PIESA1,numar));
    outtextxy(window_width-250,window_height-100,s);
    setcolor(PIESA2);
    to_string(s,numar_elemente(PIESA2,numar));
    outtextxy(window_width-150,window_height-100,s);
}

void afisTura2M(int codPiesa,bool COMPUTER)
{
    settextstyle(2,HORIZ_DIR,15);
    setcolor(codPiesa);
    bar(x_centru+250,y_centru-75,x_centru+600,y_centru-25);
    char s[30];
    if(codPiesa==PIESA1)
    {
        strcpy(s,"P1'S TURN");
        outtextxy(x_centru+320,y_centru-70,s);
    }
    else
    {
        strcpy(s,"P2'S TURN");
        if(COMPUTER==1)
           strcpy(s,"ROBOT'S TURN");
        outtextxy(x_centru+320,y_centru-70,s);
    }
}

void afisTura2m(int codPiesa,bool COMPUTER)
{
    settextstyle(2,HORIZ_DIR,15);
    setcolor(codPiesa);
    bar(window_width-300,window_height-170,window_width,window_height-100);
    char s[30];
    if(codPiesa==PIESA1)
    {
        strcpy(s,"P1'S TURN");
        if(COMPUTER==1)
           strcpy(s,"ROBOT'S TURN");
        outtextxy(window_width-260,window_height-150,s);
    }
    else
    {
        strcpy(s,"P2'S TURN");
        outtextxy(window_width-260,window_height-150,s);
    }
}

int main()
{
START:

    x_centru=window_width/2;
    y_centru=window_height/2;
    initwindow(window_width,window_height);
    MainMenu();
RESTART:

    if(res==true)
    {
        res=false;
        goto START;
    }
    if(isExit==false)
    {
        if(GameMode==1)
        {
            afisTextTimp(PIESA1);
            MUTARERESET=clock();
            contormutare=clock();
            timpmutare();
            do
            {
                afisScor1();
                if(isBack==true)
                {
                    isBack=false;
                    goto RESTART;
                }
                if(numar==7)
                mutarePiesa(PIESA1);
                else mutarePiesaMare(PIESA1);
                if(res==true)
                {
                    res=false;
                    goto START;
                }
                afisScor1();
                if(isBack==true)
                {
                    isBack=false;
                    goto RESTART;
                }
                if( verificare_Mutari_posibile(PIESA1,numar)==0)
                    break;
            }
            while(true);
            if(numarpiese==1||verificare_Mutari_posibile(PIESA1,numar)==0)
            {
                delay(500);
                cleardevice();
                if(numarpiese==1&&TablaJoc[4][4]==PIESA1||TablaJoc[6][6]==PIESA1)
                {
                    settextstyle(3,HORIZ_DIR,9);
                    setcolor(LIGHTGREEN);
                    char s[]="YOU WIN!";
                    outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                    timpmutare2();
                    timpmutare3();
                    delay(3000);
                    cleardevice();
                    PlayMenu();
                    goto RESTART;
                }
                else if(verificare_Mutari_posibile(PIESA1,7)==0||TablaJoc[4][4]!=PIESA1)
                {
                    settextstyle(3,HORIZ_DIR,9);
                    setcolor(LIGHTGREEN);
                    char s[]="GAME OVER";
                    outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                    timpmutare2();
                    timpmutare3();
                    delay(5000);
                    cleardevice();
                    PlayMenu();
                    goto RESTART;
                }
                getch();
            }
            getch();
        }
        else if(GameMode==2)
        {
          startmutare1=clock();
          timpramas1=90;
          timpramas2=90;

            int a,b;
            do
            {
                if(window_height==600)
                {
                    afisScor2m();
                    afisTura2m(PIESA1,0);
                }
                else
                {
                    afisScor2M();
                    afisTura2M(PIESA1,0);
                }
                if( verificare_Mutari_posibile_2(PIESA1,numar)==0)
                    break;
                    if(numar==7)
                mutarePiesa2(PIESA1);
                    else mutarePiesa2Mare(PIESA1);
                if(isBack==true)
                {
                    isBack=false;
                    goto RESTART;
                }
                if(window_height==600)
                    afisScor2m();
                else afisScor2M();
                if( verificare_Mutari_posibile_2(PIESA2,numar)==0)
                    break;
                if(window_height==600)
                    afisTura2m(PIESA2,0);
                    else afisTura2M(PIESA2,0);
                    if(numar==7)
                mutarePiesa2(PIESA2);
                else mutarePiesa2Mare(PIESA2);
                if(isBack==true)
                {
                    isBack=false;
                    goto RESTART;
                }
                if(window_height==600)
                    afisScor2m();
                else afisScor2M();
            }
            while(true);
            delay(500);
            cleardevice();
            a=numar_elemente(PIESA1,numar);
            b=numar_elemente(PIESA2,numar);
            if(a<b)
            {
                settextstyle(3,HORIZ_DIR,9);
                setcolor(PIESA2);
                char s[]="PLAYER2 WINS";
                outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                delay(3000);
                cleardevice();
                PlayMenu();
                goto RESTART;
            }
            else    if(a>b)
            {
                settextstyle(3,HORIZ_DIR,9);
                setcolor(PIESA1);
                char s[]="PLAYER1 WINS";
                outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                delay(3000);
                cleardevice();
                PlayMenu();
                goto RESTART;
            }
            else  if(a==b)
            {
                settextstyle(3,HORIZ_DIR,9);
                setcolor(LIGHTGREEN);
                char s[]="DRAW";
                outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                delay(3000);
                cleardevice();
                PlayMenu();
                goto RESTART;
            }
            getch();
        }
        else if (GameMode==4)
        {
            int a,b;
            do
            {
                if(window_height==600)
                {
                    afisScor2m();
                    afisTura2m(PIESA1,1);
                }
                else
                {
                    afisScor2M();
                    afisTura2M(PIESA1,1);
                }
                if(verificare_Mutari_posibile_2(PIESA1,numar)==0)
                    break;
                    if(numar==7)
                mutarePiesa2(PIESA1);
                else mutarePiesa2Mare(PIESA1);

                if(isBack==true)
                {
                    isBack=false;
                    goto RESTART;
                }
                if(window_height==600)
                    afisScor2m();
                else afisScor2M();
                if(verificare_Mutari_posibile_2(PIESA2,numar)==0)
                    break;
                if(window_height==600)
                    afisTura2m(PIESA2,1);
                    else afisTura2M(PIESA2,1);
                delay(1000);
                if(numar==7)
                mutare_computer(PIESA2);
                else mutare_computerMare(PIESA2);
                if(isBack==true)
                {
                    isBack=false;
                    goto RESTART;
                }
                if(window_height==600)
                    afisScor2m();
                else afisScor2M();
            }
            while(true);
            delay(500);
            cleardevice();
            a=numar_elemente(PIESA1,numar);
            b=numar_elemente(PIESA2,numar);
            if(a<b)
            {
                settextstyle(3,HORIZ_DIR,9);
                setcolor(PIESA2);
                char s[]="COMPUTER WINS";
                outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                delay(3000);
                cleardevice();
                PlayMenu();
                goto RESTART;
            }
            else if(a>b)
            {
                settextstyle(3,HORIZ_DIR,9);
                setcolor(PIESA1);
                char s[]="PLAYER1 WINS";
                outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                delay(3000);
                cleardevice();
                PlayMenu();
                goto RESTART;
            }
            else if(a==b)
            {
                settextstyle(3,HORIZ_DIR,9);
                setcolor(LIGHTGREEN);
                char s[]="DRAW";
                outtextxy(x_centru-textwidth(s)/2,y_centru-textheight(s)/2,s);
                delay(3000);
                cleardevice();
                PlayMenu();
                goto RESTART;
            }
            getch();
        }
    }
    return 0;
}
