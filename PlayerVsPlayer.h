#ifndef PLAYERVSPLAYER_H_INCLUDED
#define PLAYERVSPLAYER_H_INCLUDED
#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <stack>
#include "SinglePlayer.h"
#include "Menus.h"
#define MARGINE -1
void PlayMenu();

clock_t startmutare1,stopmutare1,startmutare2,stopmutare2,auxsec;
int timpmutaresecunde,timpmutare2secunde,timpramas1,timpramas2;

int cronometru(int timp)
{
    if(90-timp<=0)
        return 0;
    else
        return 1;
}

void timpmutareMP(int timp,int codPiesa)
{
    char s[10];
    settextstyle(3,HORIZ_DIR,6);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(x_centru-250,y_centru-25,x_centru-500,y_centru+25);
    setcolor(codPiesa);
    if(codPiesa==PIESA1)
    to_string(s,94-timp);
    else    to_string(s,90-timp);
    outtextxy(x_centru-370,y_centru-20,s);
}

struct nod
{
    int coordonata_x;
    int coordonata_y;
    nod* urm;
};

struct stiva
{
    nod* prim;
};

void initializare_Stiva(stiva& L)
{
    L.prim = NULL;
}

void Push(stiva& L, int x, int y)
{
    if (L.prim == NULL)
    {
        nod* p;
        p = L.prim = new nod;
        L.prim->coordonata_x = x;
        L.prim->coordonata_y = y;
        p->urm = NULL;
    }
    else
    {
        nod* p;
        p = new nod;
        p->coordonata_x = x;
        p->coordonata_y = y;
        p->urm = L.prim;
        L.prim = p;
    }
}

void Pop(stiva& L)
{
    nod* q;
    nod* p;
    p = L.prim;
    q = p;
    L.prim = p->urm;
    delete(q);
}

int Top_X(stiva& L)
{
    return L.prim->coordonata_x;
}

int Top_Y(stiva& L)
{
    return L.prim->coordonata_y;
}

int numar_elemente(int codPiesa,int numar)
{
    int     suma=0;
    for(int linia=1; linia<=numar; linia++)
        for(int coloana=1; coloana<=numar; coloana++)
                if( TablaJoc[linia][coloana]==codPiesa)
                    suma++;
    return suma;
}

void initializareTabla2(int numar,bool extins)
{
  int inferior,superior;
  if(numar==7)
  {
      inferior=3;
      superior=5;
  }
  else if(numar==11)
  {
      inferior=4;
      superior=8;
  }
    int linia,coloana;
    for(linia=1; linia<=numar; linia++)
        for(coloana=1; coloana<=numar; coloana++)
        {
            if((linia>=inferior&&linia<=superior)||(coloana>=inferior&&coloana<=superior))
                if(linia%2==coloana%2)
                    TablaJoc[linia][coloana]=PIESA1;
                else
                    TablaJoc[linia][coloana]=PIESA2;
            else
                TablaJoc[linia][coloana]=MARGINE;
        }
        if(numar==7&&extins==1)
        {
            TablaJoc[2][2]=PIESA1;
            TablaJoc[2][6]=PIESA2;
            TablaJoc[6][2]=PIESA2;
            TablaJoc[6][6]=PIESA1;
        }
        if(numar==11&&extins==1)
        {
            TablaJoc[2][3]=PIESA1;
            TablaJoc[3][2]=PIESA1;
            TablaJoc[3][3]=PIESA2;
            TablaJoc[2][9]=PIESA2;
            TablaJoc[3][9]=PIESA1;
            TablaJoc[3][10]=PIESA2;
            TablaJoc[9][2]=PIESA2;
            TablaJoc[9][3]=PIESA1;
            TablaJoc[10][3]=PIESA2;
            TablaJoc[9][9]=PIESA2;
            TablaJoc[9][10]=PIESA1;
            TablaJoc[10][9]=PIESA1;
        }
}

int verificare_Mutari_posibile_2(int codPiesa,int numar)
{
    int inferior,superior,exterior;
     if(numar==7)
  {
      inferior=3;
      superior=5;
      exterior=8;
  }
  else if(numar==11)
  {
      inferior=4;
      superior=8;
      exterior=12;
  }
    int nrMutariPosibile=0;
    int linia,coloana;
    for(linia=1; linia<=numar; linia++)
    {
        for(coloana=1; coloana<=numar; coloana++)
        {
            if((linia>=inferior&&linia<=superior)||(coloana>=inferior&&coloana<=superior))
                if(TablaJoc[linia][coloana]==codPiesa)
                    nrMutariPosibile+=poti_Muta_Iar(linia,coloana,exterior);
        }
    }
    return nrMutariPosibile;
}

void desenareTabla2(bool extins)
{
    int superior,inferior,lungime,elipsax,elipsay;
    if(numar==7)
    {
        inferior=3;
        superior=5;
        lungime=20;
        elipsax=18;
        elipsay=15;
    }
    else if(numar==11)
    {
        inferior=4;
        superior=8;
        lungime=13;
        elipsax=12;
        elipsay=11;
    }
    initializareDimensiuni(numar);
    setbkcolor(FUNDAL);
    clearviewport();
    int linia,coloana;
    for (linia = 1; linia <= numar; linia++)
        for (coloana = 1; coloana <= numar; coloana++)
        {
            if((linia>=inferior&&linia<=superior)||(coloana>=inferior&&coloana<=superior))
                desenarePiesa(linia,coloana,TablaJoc[linia][coloana],lungime,elipsax,elipsay);
        }
    if (numar==7)
    {
        stergerePiesa(4,4,lungime);
        TablaJoc[4][4]=SPATIU;
    }
    else if(numar==11)
    {
        stergerePiesa(6,6,13);
        TablaJoc[6][6]=SPATIU;
    }
    if(numar==7&&extins==1)
    {
        desenarePiesa(2,2,PIESA1,20,18,15);
        desenarePiesa(6,6,PIESA1,20,18,15);
        desenarePiesa(6,2,PIESA2,20,18,15);
        desenarePiesa(2,6,PIESA2,20,18,15);
    }
    if(numar==11&&extins==1)
    {
        desenarePiesa(2,3,PIESA1,13,12,11);
        desenarePiesa(3,2,PIESA1,13,12,11);
        desenarePiesa(3,3,PIESA2,13,12,11);
        desenarePiesa(2,9,PIESA2,13,12,11);
        desenarePiesa(3,9,PIESA1,13,12,11);
        desenarePiesa(3,10,PIESA2,13,12,11);
        desenarePiesa(9,2,PIESA2,13,12,11);
        desenarePiesa(9,3,PIESA1,13,12,11);
        desenarePiesa(10,3,PIESA2,13,12,11);
        desenarePiesa(9,9,PIESA2,13,12,11);
        desenarePiesa(9,10,PIESA1,13,12,11);
        desenarePiesa(10,9,PIESA1,13,12,11);
    }
    Button(getmaxx()-50,50,70,50,"UNDO",13,WHITE);
    Button(getmaxx()-80,110,130,50,"END TURN",13,WHITE);
    Button(40,35,50,35,"<- ",14,WHITE);
}

void mutarePiesa2(int codPiesa)
{
    stiva Piese_Sterse;
    stiva Piese_Desenate;
    initializare_Stiva(Piese_Sterse);
    initializare_Stiva(Piese_Desenate);
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

        if(numarpiese==1)
        {
            cleardevice();
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            if(inInterior(x = mousex(), y = mousey(), stanga, sus, stanga + width, sus + height))
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
                            linia2 = (y - sus) / latura + 1;
                            coloana2 = (x - stanga) / latura + 1;
                            if(coloana1==coloana2&&linia1==linia2)
                            {
                                clearmouseclick(WM_LBUTTONDOWN);
                                desenarePiesa(linia1, coloana1, codPiesa,20,18,15);
                                goto MUTAREINCORECTA;
                            }
                            if(TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==PIESA1||TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==PIESA2)
                                if (TablaJoc[linia2][coloana2] == SPATIU&&linia2<=7&&coloana2<=7&&(((linia2-linia1==2||linia2-linia1==-2)&&coloana2-coloana1==0)||((coloana2-coloana1==2||coloana2-coloana1==-2)&&linia2-linia1==0)))
                                {
                                    if(sound==true)
                                        PlaySound("SunetPiesa.wav", NULL, SND_FILENAME|SND_ASYNC);
                                    mutareCorecta = true;
                                    TablaJoc[linia1][coloana1] = SPATIU;
                                    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]=SPATIU;
                                    TablaJoc[linia2][coloana2] = codPiesa;
                                    stergerePiesa(linia1, coloana1,20);
                                    stergerePiesa((linia1+linia2)/2,(coloana1+coloana2)/2,20);
                                    numarpiese--;
                                    desenarePiesa(linia2, coloana2, codPiesa,20,18,15);
                                    Push(Piese_Sterse,linia1,coloana1);
                                    Push(Piese_Sterse,(linia1+linia2)/2,(coloana1+coloana2)/2);
                                    Push(Piese_Desenate,linia2,coloana2);

                                    if(poti_Muta_Iar(linia2,coloana2,8)==1)
                                    {
                                        desenarePiesa(linia2, coloana2, NEGATIV,20,18,15);
                                        goto MUTI_IAR;
                                    }
                                    clearmouseclick(WM_LBUTTONDOWN);
                                }
                        }
                        else if(inInterior(mousex(),mousey(),getmaxx()-135,100,getmaxx()-15,150)) ///click pe end turn;
                        {
                            desenarePiesa(linia1, coloana1, codPiesa,20,18,15);
                            clearmouseclick(WM_LBUTTONDOWN);
                            {
                                Button(getmaxx()-80,110,130,50,"END TURN",13,CYAN);
                                clearmouseclick(WM_LBUTTONDOWN);
                                delay(100);
                                Button(getmaxx()-80,110,130,50,"END TURN",13,WHITE);
                                break;
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
                     if(Piese_Desenate.prim!=NULL)
                    {
                        if(codPiesa==PIESA1)
                        {
                            stergerePiesa(Top_X(Piese_Desenate),Top_Y(Piese_Desenate),20);
                            TablaJoc[Top_X(Piese_Desenate)][Top_Y(Piese_Desenate)]=SPATIU;
                            Pop(Piese_Desenate);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA2,20,18,15);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA2;
                            Pop(Piese_Sterse);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA1,20,18,15);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA1;
                            Pop(Piese_Sterse);
                            numarpiese++;
                        }
                        else
                        {
                            stergerePiesa(Top_X(Piese_Desenate),Top_Y(Piese_Desenate),20);
                            TablaJoc[Top_X(Piese_Desenate)][Top_Y(Piese_Desenate)]=SPATIU;
                            Pop(Piese_Desenate);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA1,20,18,15);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA1;
                            Pop(Piese_Sterse);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA2,20,18,15);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA2;
                            Pop(Piese_Sterse);
                            numarpiese++;
                        }
                    }
                }
            }
            else if(inInterior(mousex(),mousey(),getmaxx()-135,100,getmaxx()-15,150)) ///click pe end turn;
            {
                clearmouseclick(WM_LBUTTONDOWN);
                {
                    Button(getmaxx()-80,110,130,50,"END TURN",13,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);
                    Button(getmaxx()-80,110,130,50,"END TURN",13,WHITE);
                     if(Piese_Desenate.prim!=NULL)
                    break;
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
    }
    while (!mutareCorecta);
}

void mutarePiesa2Mare(int codPiesa)
{
    stiva Piese_Sterse;
    stiva Piese_Desenate;
    initializare_Stiva(Piese_Sterse);
    initializare_Stiva(Piese_Desenate);
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
        if(numarpiese==1)
        {
            cleardevice();
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            if(inInterior(x = mousex(), y = mousey(), stanga, sus, stanga + width, sus + height))
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
                            linia2 = (y - sus) / latura + 1;
                            coloana2 = (x - stanga) / latura + 1;

                            if(coloana1==coloana2&&linia1==linia2)
                            {
                                clearmouseclick(WM_LBUTTONDOWN);
                                desenarePiesa(linia1, coloana1, codPiesa,13,12,11);
                                goto MUTAREINCORECTA;
                            }
                            if(TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==PIESA1||TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==PIESA2)
                                if (TablaJoc[linia2][coloana2] == SPATIU&&linia2<=11&&coloana2<=11&&(((linia2-linia1==2||linia2-linia1==-2)&&coloana2-coloana1==0)||((coloana2-coloana1==2||coloana2-coloana1==-2)&&linia2-linia1==0)))
                                {
                                    if(sound==true)
                                        PlaySound("SunetPiesa.wav", NULL, SND_FILENAME|SND_ASYNC);
                                    mutareCorecta = true;
                                    TablaJoc[linia1][coloana1] = SPATIU;
                                    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]=SPATIU;
                                    TablaJoc[linia2][coloana2] = codPiesa;
                                    stergerePiesa(linia1, coloana1,13);
                                    stergerePiesa((linia1+linia2)/2,(coloana1+coloana2)/2,13);
                                    numarpiese--;
                                    desenarePiesa(linia2, coloana2, codPiesa,13,12,11);
                                    Push(Piese_Sterse,linia1,coloana1);
                                    Push(Piese_Sterse,(linia1+linia2)/2,(coloana1+coloana2)/2);
                                    Push(Piese_Desenate,linia2,coloana2);

                                    if(poti_Muta_Iar(linia2,coloana2,12)==1)
                                    {
                                        desenarePiesa(linia2, coloana2, NEGATIV,13,12,11);
                                        goto MUTI_IAR;
                                    }
                                    clearmouseclick(WM_LBUTTONDOWN);
                                }
                        }
                        else if(inInterior(mousex(),mousey(),getmaxx()-135,100,getmaxx()-15,150)) ///click pe end turn;
                        {
                            desenarePiesa(linia1, coloana1, codPiesa,13,12,12);
                            clearmouseclick(WM_LBUTTONDOWN);
                            {
                                Button(getmaxx()-80,110,130,50,"END TURN",13,CYAN);
                                clearmouseclick(WM_LBUTTONDOWN);
                                delay(100);
                                Button(getmaxx()-80,110,130,50,"END TURN",13,WHITE);
                                break;
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

                     if(Piese_Desenate.prim!=NULL)
                    {
                        if(codPiesa==PIESA1)
                        {
                            stergerePiesa(Top_X(Piese_Desenate),Top_Y(Piese_Desenate),13);
                            TablaJoc[Top_X(Piese_Desenate)][Top_Y(Piese_Desenate)]=SPATIU;
                            Pop(Piese_Desenate);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA2,13,12,11);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA2;
                            Pop(Piese_Sterse);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA1,13,12,11);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA1;
                            Pop(Piese_Sterse);
                            numarpiese++;
                        }
                        else
                        {
                            stergerePiesa(Top_X(Piese_Desenate),Top_Y(Piese_Desenate),13);
                            TablaJoc[Top_X(Piese_Desenate)][Top_Y(Piese_Desenate)]=SPATIU;
                            Pop(Piese_Desenate);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA1,13,12,11);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA1;
                            Pop(Piese_Sterse);
                            desenarePiesa(Top_X(Piese_Sterse),Top_Y(Piese_Sterse),PIESA2,13,12,11);
                            TablaJoc[Top_X(Piese_Sterse)][Top_Y(Piese_Sterse)] = PIESA2;
                            Pop(Piese_Sterse);
                            numarpiese++;
                        }
                    }
                }
            }
            else if(inInterior(mousex(),mousey(),getmaxx()-135,100,getmaxx()-15,150)) ///click pe end turn;
            {
                clearmouseclick(WM_LBUTTONDOWN);
                {
                    Button(getmaxx()-80,110,130,50,"END TURN",13,CYAN);
                    clearmouseclick(WM_LBUTTONDOWN);
                    delay(100);
                    Button(getmaxx()-80,110,130,50,"END TURN",13,WHITE);
                     if(Piese_Desenate.prim!=NULL)
                    break;
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
    }
    while (!mutareCorecta);
}

#endif // PLAYERVSPLAYER_H_INCLUDED
