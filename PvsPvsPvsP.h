#ifndef PVSPVSPVSP_H_INCLUDED
#define PVSPVSPVSP_H_INCLUDED
#include "SinglePlayer.h"
#include "Menus.h"
#define MAX 20
#define FUNDAL COLOR(32,32,32)
#define SPATIU 0
#define PIESA1 RED
#define NEGATIV BLUE
#define PIESAGOALA COLOR(32,32,32)
#define MARGINE -1

int verificare_mutari_viitoare(int linia1,int coloana1, int linia2,int coloana2)
{
    TablaJoc[linia1][coloana1]==SPATIU;
    TablaJoc[linia1][coloana2]==PIESA2;
    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==SPATIU;
    int numar=7;
    int nrMutariPosibile=0;
    int linia,coloana;
    for(linia=1; linia<=numar; linia++)
    {
        for(coloana=1; coloana<=numar; coloana++)
        {
            if((linia>=3&&linia<=5)||(coloana>=3&&coloana<=5))
                if(TablaJoc[linia][coloana]==PIESA2)
                    nrMutariPosibile+=poti_Muta_Iar(linia,coloana);
        }
    }
    TablaJoc[linia1][coloana1]==PIESA2;
    TablaJoc[linia2][coloana2]==SPATIU;
    TablaJoc[(linia1+linia2)/2][(coloana1+coloana2)/2]==PIESA1;

    return nrMutariPosibile;
}

void mutare_computer(int codPiesa)
{

    stiva Piese_Sterse;
    stiva Piese_Desenate;
    initializare_Stiva(Piese_Sterse);
    initializare_Stiva(Piese_Desenate);
    //int linia1,coloana1,linia2,coloana2;
    int mutari_viitoare=0;
    int linia_aleasa_start,coloana_aleasa_start,linia_aleasa_stop,coloana_aleasa_stop;

    for(int linia=1; linia<=numar; linia++)
        for(int coloana=1; coloana<=numar; coloana++)
        {
            if(TablaJoc[linia][coloana]==codPiesa&&TablaJoc[linia+1][coloana]==PIESA1&&TablaJoc[linia+2][coloana]==SPATIU&&linia+2<8)
                if(verificare_mutari_viitoare(linia,coloana,linia+2,coloana)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(linia,coloana,linia+2,coloana);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia+2;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana;

                }

            if(TablaJoc[linia][coloana]==codPiesa&&TablaJoc[linia-1][coloana]==PIESA1&&TablaJoc[linia-2][coloana]==SPATIU&&linia-2>0)
                if(verificare_mutari_viitoare(linia,coloana,linia-2,coloana)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(linia,coloana,linia-2,coloana);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia-2;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana;
                }

            if(TablaJoc[linia][coloana]==codPiesa&&TablaJoc[linia][coloana+1]==PIESA1&&TablaJoc[linia][coloana+2]==SPATIU&&coloana+2<8)
                if(verificare_mutari_viitoare(linia,coloana,linia,coloana+2)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(linia,coloana,linia,coloana+2);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana+2;
                }

            if(TablaJoc[linia][coloana]==codPiesa&&TablaJoc[linia][coloana-1]==PIESA1&&TablaJoc[linia][coloana-2]==SPATIU&&coloana-2>0)
                if(verificare_mutari_viitoare(linia,coloana,linia,coloana-2)>mutari_viitoare)
                {
                    mutari_viitoare=verificare_mutari_viitoare(linia,coloana,linia,coloana-2);
                    linia_aleasa_start=linia;
                    linia_aleasa_stop=linia;
                    coloana_aleasa_start=coloana;
                    coloana_aleasa_stop=coloana-2;
                }

        }

    TablaJoc[linia_aleasa_start][coloana_aleasa_start] = SPATIU;
    TablaJoc[(linia_aleasa_start+linia_aleasa_stop)/2][(coloana_aleasa_start+coloana_aleasa_stop)/2]=SPATIU;
    TablaJoc[linia_aleasa_stop][coloana_aleasa_stop] = codPiesa;
    stergerePiesa(linia_aleasa_start, coloana_aleasa_start);
    stergerePiesa((linia_aleasa_start+linia_aleasa_stop)/2,(coloana_aleasa_start+coloana_aleasa_stop)/2);
    numarpiese--;
    desenarePiesa(linia_aleasa_stop, coloana_aleasa_stop, codPiesa);
}

#endif // PVSPVSPVSP_H_INCLUDED
