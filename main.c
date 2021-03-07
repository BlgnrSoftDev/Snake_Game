#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <unistd.h>
#include <time.h>

typedef struct
{
  int x, y, simge ;
}Nesne;


void OyunBitti(void);
void YemOlustur(void);
void Dongu(void);
void Hareket(void);
void ZitHesapla(void);
void YilanBaslangic(void);
void DuvarOlustur(void);
void ciz(void);
void SetPosition(int X, int Y);

int Harita[20][40];
Nesne Yilan[50], Yem;
int Uzunluk = 5, skor = 0;
char yon = 'd', zit_yon = 'a', anlik_yon, tekrar_mi ;

int main()
{
    srand(time(0));

    DuvarOlustur();
    YilanBaslangic();
    YemOlustur();
    ciz();
    SetPosition(0,0);
    Hareket();
    Dongu();
    return 0;
}

void YemOlustur(void)
{
    tekrar:
    Yem.x = (rand() % 16) + 2 ;
    Yem.y = (rand() % 36) + 2 ;
    Yem.simge = 'E' ;
    for(int i = 0; i < Uzunluk; ++i)
    {
        if(Yem.x == Yilan[i].x || Yem.y == Yilan[i].y)
            goto tekrar;
    }
    Harita[Yem.x][Yem.y] = Yem.simge ;
}

void Dongu(void)
{
    while(1)
    {

    if(yon == 'a')
    {
        int gecicikuyrukkonum[2];

        gecicikuyrukkonum[0] = Yilan[Uzunluk-1].x ;
        gecicikuyrukkonum[1] = Yilan[Uzunluk-1].y ;


        for(int i = (Uzunluk-1); i > 0; --i)
        {
            Yilan[i].x = Yilan[i-1].x ;
            Yilan[i].y = Yilan[i-1].y ;
        }

        Harita[gecicikuyrukkonum[0]][gecicikuyrukkonum[1]] = ' ' ;



        if(((Yilan[0].x) == Yem.x) && ((Yilan[0].y) - 1) == Yem.y )
        {
            skor++ ;
            Uzunluk++ ;
            Yilan[Uzunluk-1].simge = 177 ;
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[0];
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[1];
            YemOlustur();
        }

        for(int i = 1; i < Uzunluk; ++i)
        {
            if(((Yilan[0].x) == Yilan[i].x) && ((Yilan[0].y) - 1) == Yilan[i].y)
                {
                    OyunBitti();
                }

        }


        if((Yilan[0].y - 1) == 0) Yilan[0].y = 38 ;
        else Yilan[0].y -= 1 ;

        for(int i = 0, gecici_x, gecici_y; i < Uzunluk; ++i)
        {
            gecici_x = Yilan[i].x ;
            gecici_y = Yilan[i].y ;

            Harita[gecici_x][gecici_y] = Yilan[i].simge ;
        }



    }

    else if(yon == 'd')
    {
        int gecicikuyrukkonum[2];

        gecicikuyrukkonum[0] = Yilan[Uzunluk-1].x ;
        gecicikuyrukkonum[1] = Yilan[Uzunluk-1].y ;

        for(int i = (Uzunluk-1); i > 0; --i)
        {
            Yilan[i].x = Yilan[i-1].x ;
            Yilan[i].y = Yilan[i-1].y ;
        }

        Harita[gecicikuyrukkonum[0]][gecicikuyrukkonum[1]] = ' ' ;

        if( ((Yilan[0].x ) == Yem.x) && ((Yilan[0].y + 1) == Yem.y))
        {
            skor++ ;
            Uzunluk++ ;
            Yilan[Uzunluk-1].simge = 177 ;
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[0];
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[1];
            YemOlustur();
        }


        for(int i = 1; i < Uzunluk; ++i)
        {
            if(((Yilan[0].x) == Yilan[i].x) && ((Yilan[0].y) + 1) == Yilan[i].y)
                {
                    OyunBitti();
                }
        }


       if((Yilan[0].y + 1) == 39) Yilan[0].y = 1 ;
        else Yilan[0].y += 1 ;

        for(int i = 0, gecici_x, gecici_y; i < Uzunluk; ++i)
        {
            gecici_x = Yilan[i].x ;
            gecici_y = Yilan[i].y ;

            Harita[gecici_x][gecici_y] = Yilan[i].simge ;
        }

    }

    else if(yon == 's')
    {
        int gecicikuyrukkonum[2];

        gecicikuyrukkonum[0] = Yilan[Uzunluk-1].x ;
        gecicikuyrukkonum[1] = Yilan[Uzunluk-1].y ;

        for(int i = (Uzunluk-1); i > 0; --i)
        {
            Yilan[i].x = Yilan[i-1].x ;
            Yilan[i].y = Yilan[i-1].y ;
        }

        Harita[gecicikuyrukkonum[0]][gecicikuyrukkonum[1]] = ' ' ;

        if(((Yilan[0].x + 1) == Yem.x) && ((Yilan[0].y) == Yem.y))
        {
            skor++ ;
            Uzunluk++ ;
            Yilan[Uzunluk-1].simge = 177 ;
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[0];
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[1];
            YemOlustur();
        }

        for(int i = 1; i < Uzunluk; ++i)
        {
            if(((Yilan[0].x + 1) == Yilan[i].x) && ((Yilan[0].y)) == Yilan[i].y)
                {
                    OyunBitti();
                }
        }

        if((Yilan[0].x + 1) == 19) Yilan[0].x = 1 ;
        else Yilan[0].x += 1 ;

        for(int i = 0, gecici_x, gecici_y; i < Uzunluk; ++i)
        {
            gecici_x = Yilan[i].x ;
            gecici_y = Yilan[i].y ;

            Harita[gecici_x][gecici_y] = Yilan[i].simge ;
        }

    }

    else if(yon == 'w')
    {
        int gecicikuyrukkonum[2];

        gecicikuyrukkonum[0] = Yilan[Uzunluk-1].x ;
        gecicikuyrukkonum[1] = Yilan[Uzunluk-1].y ;

        for(int i = (Uzunluk-1); i > 0; --i)
        {
            Yilan[i].x = Yilan[i-1].x ;
            Yilan[i].y = Yilan[i-1].y ;
        }


        Harita[gecicikuyrukkonum[0]][gecicikuyrukkonum[1]] = ' ' ;

        if(((Yilan[0].x - 1) == Yem.x) && ((Yilan[0].y) == Yem.y))
        {
            skor++ ;
            Uzunluk++ ;
            Yilan[Uzunluk-1].simge = 177 ;
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[0];
            Yilan[Uzunluk-1].x = gecicikuyrukkonum[1];
            YemOlustur();
        }


        for(int i = 1; i < Uzunluk; ++i)
        {
            if(((Yilan[0].x - 1) == Yilan[i].x) && ((Yilan[0].y)) == Yilan[i].y)
                {
                    OyunBitti();
                }
        }


        if((Yilan[0].x - 1) == 0) Yilan[0].x = 18 ;
        else Yilan[0].x -= 1 ;


        for(int i = 0, gecici_x, gecici_y; i < Uzunluk; ++i)
        {
            gecici_x = Yilan[i].x ;
            gecici_y = Yilan[i].y ;

            Harita[gecici_x][gecici_y] = Yilan[i].simge ;
        }

    }
    usleep(90000);
    ciz();
    DuvarOlustur();
    SetPosition(0,0);

    if( kbhit())
    {
        Hareket();
    }

    }
}
void Hareket(void)
{
    anlik_yon = getch();
    anlik_yon = tolower(anlik_yon);
    ZitHesapla();

    if(anlik_yon == 'a' && anlik_yon != zit_yon)
    {
        yon = anlik_yon ;

    }
    else if(anlik_yon == 'd' && anlik_yon != zit_yon)
    {
        yon = anlik_yon ;

    }
    else if(anlik_yon == 's' && anlik_yon != zit_yon)
    {
        yon = anlik_yon ;

    }
    else if(anlik_yon == 'w' && anlik_yon != zit_yon)
    {
        yon = anlik_yon ;
    }
}

void ZitHesapla(void)
{
    switch(yon)
    {
    case 'a':
        zit_yon = 'd';
        break;
    case 'd':
        zit_yon = 'a';
        break;
    case 's':
        zit_yon = 'w';
        break;
    case 'w':
        zit_yon = 's';
        break;

    }
}

void YilanBaslangic(void)
{
    Yilan[0].x = 9 ;
    Yilan[0].y = 19 ;
    Yilan[0].simge = 178 ;

    for(int i = 1, temp = 19 ; i < Uzunluk; ++i)
    {
        Yilan[i].x = Yilan[0].x ;
        Yilan[i].y = --temp ;
        Yilan[i].simge = 177;


    }

    for(int i = 0, gecici_x, gecici_y; i < Uzunluk; ++i)
    {
        gecici_x = Yilan[i].x ;
        gecici_y = Yilan[i].y ;

        Harita[gecici_x][gecici_y] = Yilan[i].simge ;
    }

}


void DuvarOlustur(void)
{
    for(int i = 0; i < 40; ++i)
    {
        Harita[0][i] = 205 ;
    }

    for(int i = 1; i < 19; ++i)
    {
        Harita[i][0] = 186 ;
        Harita[i][39] = 186 ;
    }

    for(int i = 0; i < 40; ++i)
    {
        Harita[19][i] = 205 ;
    }

    Harita[19][39] = 188 ;
    Harita[19][0] = 200 ;
    Harita[0][0] = 201 ;
    Harita[0][39] = 187 ;
}

void ciz(void)
{
    for(int i = 0; i < 20; ++i)
    {
        for(int j = 0; j < 40; ++j)
        {
            printf("%c",Harita[i][j]);
        }

        printf("\n");
    }

    printf("\n==================> SKOR : %d  <======================",skor);
}

void SetPosition(int X, int Y)
{
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position={X, Y};

    SetConsoleCursorPosition(Screen, Position);
}

void OyunBitti(void)
{
    system("cls");
    printf("\n\
           #########     ###      ###      #############       ########         \n\
          #########      ###     ###     #################    ##########        \n\
         ###             ###    ###     ####           ####  ####    ###        \n\
          ###            ###   ###      ####           ####  ####    ###        \n\
            ###          ########       ####           ####  ####  ####         \n\
              ###        ########       ####           ####  ########           \n\
                ###      ###   ###      ####           ####  #### ####          \n\
                 ###     ###    ###     ####           ####  ####  ####         \n\
          #########      ###     ###     #################   ####   ####        \n\
        #########        ###      ###      #############     ####    ####       \n"
    );
    printf("\n\n\n===============================================================================================\n\n");
    printf("# Tebrikler !! , %d tane elma yiyebildiniz !!\n\n", skor);
    printf("Herhangi bir tusa basiniz...\n\n");
    getch();
    printf("TESEKKUR EDERIZ !!");
    exit(1);



    exit(1);
}
