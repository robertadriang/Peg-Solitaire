#ifndef PLAYERVSCOMPUTER_H_INCLUDED
#define PLAYERVSCOMPUTER_H_INCLUDED

#include "SinglePlayer.h"
#include "Menus.h"
#define MAX 20
#define FUNDAL COLOR(32,32,32)
#define SPATIU 0
#define NEGATIV BLUE
#define PIESAGOALA COLOR(32,32,32)
#define MARGINE -1

int verificare_mutari_viitoare(int numar,int linia1,int coloana1, int linia2,int coloana2)
{
    int inferior,superior,exterior;
    int a;
    a=TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2];
    TablaJoc[linia1][coloana1]==SPATIU;
    TablaJoc[linia1][coloana2]==PIESA2;
    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==SPATIU;
    if(numar==7)
    {
      inferior=3;
      superior=5;
      exterior=0;
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
           // if((linia>=inferior&&linia<=superior)||(coloana>=inferior&&coloana<=superior))
                if(TablaJoc[linia][coloana]==PIESA2)
                    nrMutariPosibile+=poti_Muta_Iar(linia,coloana,exterior);
        }
    }
    TablaJoc[linia1][coloana1]=PIESA2;
    TablaJoc[linia2][coloana2]=SPATIU;
    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]=a;

    return nrMutariPosibile;
}

void mutare_computer(int codPiesa)
{

    stiva Piese_Sterse;
    stiva Piese_Desenate;
    initializare_Stiva(Piese_Sterse);
    initializare_Stiva(Piese_Desenate);
    //int linia1,coloana1,linia2,coloana2;
    int mutari_viitoare=0,OK,linia,coloana;
    int linia_aleasa_start,coloana_aleasa_start,linia_aleasa_stop,coloana_aleasa_stop;

    for( linia=1; linia<=numar; linia++)
        for( coloana=1; coloana<=numar; coloana++)
        {
            OK=0;
            MULTIPLU2:
            if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia+1][coloana]==PIESA1||TablaJoc[linia+1][coloana]==PIESA2)&&TablaJoc[linia+2][coloana]==SPATIU&&linia+2<8)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia+2,coloana)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia+2,coloana);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia+2;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana;

                }

            if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia-1][coloana]==PIESA1||TablaJoc[linia-1][coloana]==PIESA2)&&TablaJoc[linia-2][coloana]==SPATIU&&linia-2>0)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia-2,coloana)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia-2,coloana);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia-2;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana;
                }

            if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia][coloana+1]==PIESA1||TablaJoc[linia][coloana+1]==PIESA2)&&TablaJoc[linia][coloana+2]==SPATIU&&coloana+2<8)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia,coloana+2)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia,coloana+2);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana+2;
                }

            if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia][coloana-1]==PIESA1||TablaJoc[linia][coloana-1]==PIESA2)&&TablaJoc[linia][coloana-2]==SPATIU&&coloana-2>0)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia,coloana-2)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia,coloana-2);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana-2;
                }
                 if(OK==1)
                {
                     //OK=0;
                    goto Muta1;
                }


        }
    if(sound==true)
        PlaySound("SunetPiesa.wav", NULL, SND_FILENAME|SND_ASYNC);
        Muta1:
    TablaJoc[linia_aleasa_start][coloana_aleasa_start] = SPATIU;
    TablaJoc[(linia_aleasa_start+linia_aleasa_stop)/2][(coloana_aleasa_start+coloana_aleasa_stop)/2]=SPATIU;
    TablaJoc[linia_aleasa_stop][coloana_aleasa_stop] = codPiesa;
    stergerePiesa(linia_aleasa_start, coloana_aleasa_start,20);
    stergerePiesa((linia_aleasa_start+linia_aleasa_stop)/2,(coloana_aleasa_start+coloana_aleasa_stop)/2,20);
    numarpiese--;
    desenarePiesa(linia_aleasa_stop, coloana_aleasa_stop, codPiesa,20,18,15);
     if(poti_Muta_Iar(linia_aleasa_stop,coloana_aleasa_stop,12)==1)
        {
        linia=linia_aleasa_stop;
        coloana=coloana_aleasa_stop;
        mutari_viitoare=0;
        OK=1;
        goto MULTIPLU2;
        }
}

void mutare_computerMare(int codPiesa)
{

    stiva Piese_Sterse;
    stiva Piese_Desenate;
    initializare_Stiva(Piese_Sterse);
    initializare_Stiva(Piese_Desenate);
    //int linia1,coloana1,linia2,coloana2;
    int mutari_viitoare=0,linia,coloana,OK;
    int linia_aleasa_start,coloana_aleasa_start,linia_aleasa_stop,coloana_aleasa_stop;

    for( linia=1; linia<=numar; linia++)
        for( coloana=1; coloana<=numar; coloana++)
        {  OK=0;
            MULTIPLU:
            if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia+1][coloana]==PIESA1||TablaJoc[linia+1][coloana]==PIESA2)&&TablaJoc[linia+2][coloana]==SPATIU&&linia+2<12)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia+2,coloana)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia+2,coloana);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia+2;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana;

                }

             if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia-1][coloana]==PIESA1||TablaJoc[linia-1][coloana]==PIESA2)&&TablaJoc[linia-2][coloana]==SPATIU&&linia-2>0)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia-2,coloana)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia-2,coloana);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia-2;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana;
                }

             if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia][coloana+1]==PIESA1||TablaJoc[linia][coloana+1]==PIESA2)&&TablaJoc[linia][coloana+2]==SPATIU&&coloana+2<12)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia,coloana+2)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia,coloana+2);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana+2;
                }

          if(TablaJoc[linia][coloana]==codPiesa&&(TablaJoc[linia][coloana-1]==PIESA1||TablaJoc[linia][coloana-1]==PIESA2)&&TablaJoc[linia][coloana-2]==SPATIU&&coloana-2>0)
                if(verificare_mutari_viitoare(numar,linia,coloana,linia,coloana-2)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(numar,linia,coloana,linia,coloana-2);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana-2;
                }
                if(OK==1)
                {
                     //OK=0;
                    goto Muta;
                }

        }
    if(sound==true)
        PlaySound("SunetPiesa.wav", NULL, SND_FILENAME|SND_ASYNC);
        Muta:
    TablaJoc[linia_aleasa_start][coloana_aleasa_start] = SPATIU;
    TablaJoc[(linia_aleasa_start+linia_aleasa_stop)/2][(coloana_aleasa_start+coloana_aleasa_stop)/2]=SPATIU;
    TablaJoc[linia_aleasa_stop][coloana_aleasa_stop] = codPiesa;
    stergerePiesa(linia_aleasa_start, coloana_aleasa_start,13);
    stergerePiesa((linia_aleasa_start+linia_aleasa_stop)/2,(coloana_aleasa_start+coloana_aleasa_stop)/2,13);
    numarpiese--;
    desenarePiesa(linia_aleasa_stop, coloana_aleasa_stop, codPiesa,13,12,11);
     if(poti_Muta_Iar(linia_aleasa_stop,coloana_aleasa_stop,12)==1)
        {
        linia=linia_aleasa_stop;
        coloana=coloana_aleasa_stop;
        mutari_viitoare=0;
        OK=1;
        goto MULTIPLU;
        }
}


#endif // PLAYERVSCOMPUTER_H_INCLUDED
