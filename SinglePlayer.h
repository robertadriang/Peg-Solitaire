#ifndef SINGLEPLAYER_H_INCLUDED
#define SINGLEPLAYER_H_INCLUDED
#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <time.h>
#include "Menus.h"
#include<fstream>
using namespace std;

#define MAX 20
#define FUNDAL COLOR(32,32,32)
#define SPATIU 0

#define NEGATIV BLUE
#define PIESAGOALA COLOR(32,32,32)
#define MARGINE -1

int GameMode=0,PIESA1=LIGHTRED,PIESA2=YELLOW,culoarePiesa=1;
int TablaJoc[MAX][MAX];
int MutariPosibile[MAX][MAX];
void Button(int x,int y,int L,int l,char s[],int text_size,int color);
void PlayMenu();
bool isBack=false;
bool res=false;
bool sound=true;
int sus,stanga,width,height,latura,window_width=1280,window_height=720,x_centru=window_width/2,y_centru=window_height/2,numar=7,extins=0;
int diferentaliniimutare,diferentacoloanemutare;
int numarpiese;
clock_t contormutare,contormutare2,MUTARERESET;
int contormutare3;

void to_string(char s[],int n)
{

    int m=0;
    char c;
    while(n)
    {
        c=n%10+'0';
        s[m++]=c;
        n/=10;
    }
    s[m]='\0';
    strrev(s);
    s[m]='\0';
}

void timpmutare()
{
    char s[10];
    settextstyle(3,HORIZ_DIR,6);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(x_centru-250,y_centru-25,x_centru-500,y_centru+25);
    setcolor(PIESA1);
    to_string(s,contormutare3);
    outtextxy(x_centru-370,y_centru-20,s);
}

void timpmutare2()
{
    char s[10];
    settextstyle(3,HORIZ_DIR,6);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(x_centru,y_centru+70,x_centru,y_centru+75);
    setcolor(PIESA1);
    to_string(s,contormutare3);
    outtextxy(x_centru+100,y_centru+70,s);
}

void timpmutare3()
{
    char s[10];
    settextstyle(3,HORIZ_DIR,6);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(x_centru-250,y_centru+70,x_centru,y_centru+75);
    setcolor(PIESA1);
    outtextxy(x_centru-250,y_centru+70,"TIMP JUCAT:");
}

void afisTextTimp(int cod)
{
    settextstyle(2,HORIZ_DIR,15);
    if(cod==PIESA1)
    setcolor(PIESA1);
    else
        setcolor(PIESA2);
    bar(x_centru-350,y_centru-75,x_centru-600,y_centru-25);
    char s[30];
        strcpy(s,"TIME:");
        outtextxy(x_centru-380,y_centru-70,s);

}

int validare_Mutare(int linie,int coloana,int codPiesa)
{
    if(TablaJoc[linie+1][coloana]==codPiesa&&TablaJoc[linie+2][coloana]==SPATIU)
        return 1;
    if(TablaJoc[linie-1][coloana]==codPiesa&&TablaJoc[linie-2][coloana]==SPATIU)
        return 1;
    if(TablaJoc[linie][coloana+1]==codPiesa&&TablaJoc[linie][coloana+2]==SPATIU)
        return 1;
    if(TablaJoc[linie][coloana-1]==codPiesa&&TablaJoc[linie][coloana-2]==SPATIU)
        return 1;
    return 0;
}

int verificare_Mutari_posibile(int codPiesa,int numar)
{
    int nrMutariPosibile=0;
    int linia,coloana;
    for(linia=1; linia<=numar; linia++)
        for(coloana=1; coloana<=numar; coloana++)
            // if((linia>=4&&linia<=8)||(coloana>=4&&coloana<=8))
            if(TablaJoc[linia][coloana]==codPiesa)
                nrMutariPosibile+=validare_Mutare(linia,coloana,codPiesa);
    return nrMutariPosibile;
}

bool inInterior(int x, int y, int x1, int y1, int x2, int y2)
{
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int poti_Muta_Iar(int linia,int coloana,int superior)
{
    if(TablaJoc[linia+1][coloana]!=SPATIU&&TablaJoc[linia+2][coloana]==SPATIU&&TablaJoc[linia+2][coloana]!=MARGINE)
        if(linia+2<superior)
            return 1;
    if(TablaJoc[linia-1][coloana]!=SPATIU&&TablaJoc[linia-2][coloana]==SPATIU&&TablaJoc[linia-2][coloana]!=MARGINE)
        if(linia-2>0)
            return 1;
    if(TablaJoc[linia][coloana+1]!=SPATIU&&TablaJoc[linia][coloana+2]==SPATIU&&TablaJoc[linia][coloana+2]!=MARGINE)
        if(coloana+2<superior)
            return 1;
    if(TablaJoc[linia][coloana-1]!=SPATIU&&TablaJoc[linia][coloana-2]==SPATIU&&TablaJoc[linia][coloana-2]!=MARGINE)
        if(coloana-2>0)
            return 1;
    return 0;
}

void initializareTabla(int numar,bool extins,int inferior,int superior)
{
    int linia,coloana;
    for(linia=1; linia<=numar; linia++)
        for(coloana=1; coloana<=numar; coloana++)
        {
            if((linia>=inferior&&linia<=superior)||(coloana>=inferior&&coloana<=superior))
                TablaJoc[linia][coloana]=PIESA1;
            else
                TablaJoc[linia][coloana]=MARGINE;
        }
    if(numar==7&&extins==1)
    {
        TablaJoc[2][2]=PIESA1;
        TablaJoc[2][6]=PIESA1;
        TablaJoc[6][2]=PIESA1;
        TablaJoc[6][6]=PIESA1;
    }

    if(numar==11&&extins==1)
    {
        TablaJoc[2][3]=PIESA1;
        TablaJoc[3][2]=PIESA1;
        TablaJoc[3][3]=PIESA1;
        TablaJoc[2][9]=PIESA1;
        TablaJoc[3][9]=PIESA1;
        TablaJoc[3][10]=PIESA1;
        TablaJoc[9][2]=PIESA1;
        TablaJoc[9][3]=PIESA1;
        TablaJoc[10][3]=PIESA1;
        TablaJoc[9][9]=PIESA1;
        TablaJoc[9][10]=PIESA1;
        TablaJoc[10][9]=PIESA1;
    }

}

void golireTabla(int numar,int inferior,int superior)
{
    int linia,coloana;
    for(linia=1; linia<=numar; linia++)
        for(coloana=1; coloana<=numar; coloana++)
        {
            if((linia>=inferior&&linia<=superior)||(coloana>=inferior&&coloana<=superior))
                TablaJoc[linia][coloana]=SPATIU;
        }
}

void initializareDimensiuni(int numar)
{
    width=420;
    height=420;
    latura=width/numar;
    sus = (getmaxy() - width) / 2;
    stanga = (getmaxx() - height) / 2;
}

void stergerePiesa(int linia,int coloana,int lungime)   //lungime= 20 pt 7x7 si 13 pt11x11
{
    int x1, y1, x2, y2, xmijloc, ymijloc;
    x1 = stanga + latura * (coloana - 1);
    y1 = sus + latura * (linia - 1);
    x2 = x1 + latura;
    y2 = y1 + latura;
    xmijloc = (x1 + x2) / 2;
    ymijloc = (y1 + y2) / 2;
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    setcolor(FUNDAL);
    setfillstyle(SOLID_FILL, FUNDAL);
    bar(xmijloc - lungime, ymijloc - lungime, xmijloc + lungime, ymijloc + lungime);
}

void desenarePiesa(int linia,int coloana,int codPiesa,int lungime,int elipsax,int elipsay)//lungime= 20 pt 7x7 si 13 pt11x11
{
                                                                                            //elipsax=18 pt 7x7 si 12 pt 11x11
    int x1, y1, x2, y2, xmijloc, ymijloc;                                                  //elipsay=15 pt 7x7 si 11 pt 11x11
    x1 = stanga + latura * (coloana - 1);
    y1 = sus + latura * (linia - 1);
    x2 = x1 + latura;
    y2 = y1 + latura;
    xmijloc = (x1 + x2) / 2;
    ymijloc = (y1 + y2) / 2;
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    setcolor(FUNDAL);
    setfillstyle(SOLID_FILL, FUNDAL);
    bar(xmijloc -lungime, ymijloc - lungime, xmijloc + lungime, ymijloc + lungime);
    setcolor(codPiesa);
    setfillstyle(SOLID_FILL, codPiesa);
    fillellipse(xmijloc, ymijloc, elipsax, elipsay);
}

void desenareTabla(int numar,bool extins,int inferior,int superior)
{
    int elipsax,elipsay,lungime;
    initializareDimensiuni(numar);
    setbkcolor(FUNDAL);
    clearviewport();
    int linia,coloana;
    if (numar==7)
    {
        lungime=20;
        elipsax=18;
        elipsay=15;
    }
    else if(numar==11)
    {
        lungime=13;
        elipsax=12;
        elipsay=11;
    }
    for (linia = 1; linia <= numar; linia++)
        for (coloana = 1; coloana <= numar; coloana++)
        {
            if((linia>=inferior&&linia<=superior)||(coloana>=inferior&&coloana<=superior))
                desenarePiesa(linia,coloana,TablaJoc[linia][coloana],lungime,elipsax,elipsay);
        }
      if(numar==7&&extins==1)
    {
        desenarePiesa(2,2,TablaJoc[2][2],lungime,elipsax,elipsay);
        desenarePiesa(2,6,TablaJoc[2][6],lungime,elipsax,elipsay);
        desenarePiesa(6,2,TablaJoc[6][2],lungime,elipsax,elipsay);
        desenarePiesa(6,6,TablaJoc[6][6],lungime,elipsax,elipsay);
    }

    if(numar==11&&extins==1)
    {
        desenarePiesa(2,3,TablaJoc[2][3],lungime,elipsax,elipsay);
        desenarePiesa(3,2,TablaJoc[3][2],lungime,elipsax,elipsay);
        desenarePiesa(3,3,TablaJoc[3][3],lungime,elipsax,elipsay);
        desenarePiesa(2,9,TablaJoc[2][9],lungime,elipsax,elipsay);
        desenarePiesa(3,9,TablaJoc[3][9],lungime,elipsax,elipsay);
        desenarePiesa(3,10,TablaJoc[3][10],lungime,elipsax,elipsay);
        desenarePiesa(9,2,TablaJoc[9][2],lungime,elipsax,elipsay);
        desenarePiesa(9,3,TablaJoc[9][3],lungime,elipsax,elipsay);
        desenarePiesa(10,3,TablaJoc[10][3],lungime,elipsax,elipsay);
        desenarePiesa(9,9,TablaJoc[9][9],lungime,elipsax,elipsay);
        desenarePiesa(9,10,TablaJoc[9][10],lungime,elipsax,elipsay);
        desenarePiesa(10,9,TablaJoc[10][9],lungime,elipsax,elipsay);
    }
    if(numar==7)
    {
    stergerePiesa(4,4,lungime);
    TablaJoc[4][4]=SPATIU;
    }

    if(numar==11)
    {
    stergerePiesa(6,6,lungime);
    TablaJoc[6][6]=SPATIU;
    }
    Button(40,35,50,35,"<- ",14,WHITE);
}

void mutarePiesa(int codPiesa)
{
    int linia1,coloana1,linia2,coloana2,x,y;
    int x1,y1,x2,y2;
    int xmijloc,ymijloc;
    bool mutareCorecta;
    mutareCorecta=false;
    do
    {
MUTAREINCORECTA:
MUTI_IAR:
        mutareCorecta = false;

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            if (inInterior(x = mousex(), y = mousey(), stanga, sus, stanga + width, sus + height))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                linia1 = (y - sus) / latura + 1;
                coloana1 = (x - stanga) / latura + 1;
                if (TablaJoc[linia1][coloana1] == codPiesa)
                {
                    desenarePiesa(linia1, coloana1, NEGATIV,20,18,15);
                    do
                    {
                        if (ismouseclick(WM_LBUTTONDOWN) && inInterior(x = mousex(), y = mousey(), stanga, sus, stanga + width, sus + height))
                        {
                            //clearmouseclick(WM_LBUTTONDOWN);
                            linia2 = (y - sus) / latura + 1;
                            coloana2 = (x - stanga) / latura + 1;

                            if(coloana1==coloana2&&linia1==linia2)
                            {
                                clearmouseclick(WM_LBUTTONDOWN);
                                desenarePiesa(linia1, coloana1, codPiesa,20,18,15);
                                goto MUTAREINCORECTA;
                            }
                            if(TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==codPiesa)
                                if (TablaJoc[linia2][coloana2] == SPATIU&&(((linia2-linia1==2||linia2-linia1==-2)&&coloana2-coloana1==0)||((coloana2-coloana1==2||coloana2-coloana1==-2)&&linia2-linia1==0)))
                                {
                                    if(sound==true)
                                        PlaySound("SunetPiesa.wav", NULL, SND_FILENAME|SND_ASYNC);
                                    mutareCorecta = true;
                                    TablaJoc[linia1][coloana1] = SPATIU;
                                    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]=SPATIU;
                                    TablaJoc[linia2][coloana2] = codPiesa;
                                    stergerePiesa(linia1, coloana1,20);
                                    stergerePiesa((linia1+linia2)/2,(coloana1+coloana2)/2,20);
                                    desenarePiesa(linia2, coloana2, codPiesa,20,18,15);
                                    numarpiese--;
                                    if(poti_Muta_Iar(linia2,coloana2,8)==1)
                                    {
                                        desenarePiesa(linia2, coloana2, NEGATIV,20,18,15);
                                        goto MUTI_IAR;

                                    }
                                    clearmouseclick(WM_LBUTTONDOWN);
                                }
                        }
                    }
                    while (!mutareCorecta);
                }
            }
            else if(inInterior(mousex(),mousey(),getmaxx()-85,25,getmaxx()-15,75)) ///click pe undo;
            {

                clearmouseclick(WM_LBUTTONDOWN);
                {
                    Button(getmaxx()-50,50,70,50,"UNDO",13,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);
                    Button(getmaxx()-50,50,70,50,"UNDO",13,WHITE);

                    ///adauga aici functiile pe care vrei sa le apeleze butonul
                }
            }
            else if(inInterior(mousex(),mousey(),40-25,35-17,40+25,35+17))    ///click pe buton de MainMenu;
            {
                isBack=true;
                clearmouseclick(WM_LBUTTONDOWN);
                {
                    Button(40,35,50,35,"<- ",14,CYAN);
                    delay(100);
                    Button(40,35,50,35,"<- ",14,WHITE);
                    cleardevice();
                    PlayMenu();
                    return;
                }
            }
        }
contormutare2=clock()-contormutare;
        contormutare3=(int)(contormutare2/CLOCKS_PER_SEC);
        timpmutare();
        Sleep(100);
    }
    while (!mutareCorecta);


}


void mutarePiesaMare(int codPiesa)
{
    int linia1,coloana1,linia2,coloana2,x,y;
    int x1,y1,x2,y2;
    int xmijloc,ymijloc;
    bool mutareCorecta;
    mutareCorecta=false;
    do
    {
MUTAREINCORECTA:
MUTI_IAR:
        mutareCorecta = false;

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            if (inInterior(x = mousex(), y = mousey(), stanga, sus, stanga + width, sus + height))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                linia1 = (y - sus) / latura + 1;
                coloana1 = (x - stanga) / latura + 1;
                if (TablaJoc[linia1][coloana1] == codPiesa)
                {
                    desenarePiesa(linia1, coloana1, NEGATIV,13,12,11);
                    do
                    {
                        if (ismouseclick(WM_LBUTTONDOWN) && inInterior(x = mousex(), y = mousey(), stanga, sus, stanga + width, sus + height))
                        {
                            //clearmouseclick(WM_LBUTTONDOWN);
                            linia2 = (y - sus) / latura + 1;
                            coloana2 = (x - stanga) / latura + 1;

                            if(coloana1==coloana2&&linia1==linia2)
                            {
                                clearmouseclick(WM_LBUTTONDOWN);
                                desenarePiesa(linia1, coloana1, codPiesa,13,12,11);
                                goto MUTAREINCORECTA;
                            }
                            if(TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==codPiesa)
                                if (TablaJoc[linia2][coloana2] == SPATIU&&(((linia2-linia1==2||linia2-linia1==-2)&&coloana2-coloana1==0)||((coloana2-coloana1==2||coloana2-coloana1==-2)&&linia2-linia1==0)))
                                {
                                    if(sound==true)
                                        PlaySound("SunetPiesa.wav", NULL, SND_FILENAME|SND_ASYNC);
                                    mutareCorecta = true;
                                    TablaJoc[linia1][coloana1] = SPATIU;
                                    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]=SPATIU;
                                    TablaJoc[linia2][coloana2] = codPiesa;
                                    stergerePiesa(linia1, coloana1,13);
                                    stergerePiesa((linia1+linia2)/2,(coloana1+coloana2)/2,13);
                                    desenarePiesa(linia2, coloana2, codPiesa,13,12,11);
                                    numarpiese--;
                                    if(poti_Muta_Iar(linia2,coloana2,8)==1)
                                    {
                                        desenarePiesa(linia2, coloana2, NEGATIV,13,12,11);
                                        goto MUTI_IAR;

                                    }
                                    clearmouseclick(WM_LBUTTONDOWN);
                                }
                        }
                    }
                    while (!mutareCorecta);
                }
            }
            else if(inInterior(mousex(),mousey(),getmaxx()-85,25,getmaxx()-15,75)) ///click pe undo;
            {

                clearmouseclick(WM_LBUTTONDOWN);
                {
                    Button(getmaxx()-50,50,70,50,"UNDO",13,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);
                    Button(getmaxx()-50,50,70,50,"UNDO",13,WHITE);

                    ///adauga aici functiile pe care vrei sa le apeleze butonul
                }
            }
            else if(inInterior(mousex(),mousey(),40-25,35-17,40+25,35+17))    ///click pe buton de MainMenu;
            {
                isBack=true;
                clearmouseclick(WM_LBUTTONDOWN);
                {
                    Button(40,35,50,35,"<- ",14,CYAN);
                    delay(100);
                    Button(40,35,50,35,"<- ",14,WHITE);
                    cleardevice();
                    PlayMenu();
                    return;
                }
            }
        }
  contormutare2=clock()-contormutare;
        contormutare3=(int)(contormutare2/CLOCKS_PER_SEC);
        timpmutare();
        Sleep(100);
    }
    while (!mutareCorecta);


}


#endif // SINGLEPLAYER_H_INCLUDED
