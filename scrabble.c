#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"util/scrabble.h"
#include"util/print_board.h"

#define max 100


void setboard(char board[15][15]) // funcție pentru umplerea matricei cu puncte
{
    for (int i=0; i<15; i++) {
        for (int j=0; j<15; j++) {
            board[i][j] = '.';
        }
    }
}

void task0()
{
    char board[15][15];

    setboard(board);

    print_board(board);
}

void setword(char board[15][15], char *array, int x, int y, int d)
{
    char *q = array;

    if (d==0)
    {
        for (int i=0; i<strlen(array); i++)
            board[x][y+i] = q[i];
    }
    else
    {
        for (int i=0; i<strlen(array); i++)
            board[x+i][y] = q[i];
    }
}

void task1()
{
    char game_board[15][15];

    setboard(game_board);

    char line[max];
    fgets(line, max, stdin); // numărul de cuvinte
    int nr = atoi(line);

    for (int n=0; n<nr; n++) {

        fgets(line, max, stdin);

        char *p;
        p = strtok(line, " \n");

        char *array[3]; // pointer către cuvânt
        int i = 0;

        while (p != NULL)
        {
            array[i++] = p;
            p = strtok (NULL, " \n");
        }

        int x = atoi(array[0]);
        int y = atoi(array[1]);
        int d = atoi(array[2]);

        setword(game_board, array[3], x, y, d);    
    }
    
    print_board(game_board);
}



int score (int s, char *array) // funcție pentru calcularea scorului
{
    char *q = array; // pointer către literele cuvântului

    for (int I=0; I<strlen(array); I++) {

        if (q[I]=='A' || q[I]=='E' || q[I]=='I' || q[I]=='L' || q[I]=='N' || 
            q[I]=='O' || q[I]=='R' || q[I]=='S' || q[I]=='T' || q[I]=='U')
                s+=1;
        else
        {
            if (q[I]=='D' || q[I]=='G')
                s+=2;
            else
            {
                if (q[I]=='B' || q[I]=='C' || q[I]=='M' || q[I]=='P')
                        s+=3;
                else
                {
                    if (q[I]=='F' || q[I]=='H' || q[I]=='V' || q[I]=='W' || q[I]=='Y')
                        s+=4;
                    else
                    {
                        if (q[I]=='K')
                            s+=5;
                        else
                        {
                            if (q[I]=='J' || q[I]=='X')
                                s+=8;
                            else
                            {
                                if (q[I]=='Q' || q[I]=='Z')
                                    s+=10;
                            }
                        }
                    }
                }
            }
        }
    }

    return s;
}

void task2()
{
    char line[max];
    fgets(line, max, stdin); // numărul de cuvinte
    int nr = atoi(line);
    
    int s1 = 0, s2 = 0;

    for (int n=0; n<nr; n++) {

        fgets(line, max, stdin);

        char *p;
        p = strtok(line, " \n");

        char *array[3]; // pointer către cuvânt
        int i = 0;

        while (p != NULL)
        {
            array[i++] = p;
            p = strtok (NULL, " \n");
        }

        if (n%2 == 0)
            s1 = score(s1, array[3]);
        else
            s2 = score(s2, array[3]);
}

    printf("Player 1: %d Points", s1);
    printf("\nPlayer 2: %d Points", s2);
}

// funcție pentru adăugarea bonusurilor la scor

int bonus (int s, int d, int x, int y, char *array, char c1, char c2, char c3, char c4)
{
    char *q = array; // pointer către literele cuvântului

    for (int i=0; i<strlen(array); i++) {

        if ( q[i] == c1 && q[i+1] == c2 )
        {
            if (d == 0)
            {
                for (int j=0; j<strlen(array); j++) {
                    if( bonus_board[x][y+j] == 1 )
                        s*=2;
                }        
            }
            else
            {
                for (int j=0; j<strlen(array); j++)
                    if ( bonus_board[x+j][y] == 1 )
                        s*=2;
            }
        }
    }

        if ( q[strlen(array)-2] == c3 && q[strlen(array)-1] == c4 ) 
        {
            if (d==0)
            {
                for (int j=0; j<strlen(array); j++) {
                    if( bonus_board[x][y+j] == 2 )
                        s*=3;    
                }
            }
            else
            {
                for (int j=0; j<strlen(array); j++)
                    if ( bonus_board[x+j][y] == 2 )
                        s*=3;
            }
        }
    
    return s;
}

void task3()
{
    char line[max];

    fgets(line, max, stdin);
    char substring1[2];
    strcpy(substring1, line);
    char c1 = substring1[0];
    char c2 = substring1[1];

    fgets(line, max, stdin);
    char substring2[2];
    strcpy(substring2, line);
    char c3 = substring2[0];
    char c4 = substring2[1];

    fgets(line, max, stdin); // numărul de cuvinte
    int nr = atoi(line);

    int p1 = 0, p2 = 0;

    for (int n=0; n<nr; n++) {
    
        int s1=0, s2=0;

        fgets(line, max, stdin);

        char *p;
        p = strtok(line, " \n");

        char *array[3]; // pointer către cuvânt
        int i = 0;

        while (p != NULL)
        {
            array[i++] = p;
            p = strtok (NULL, " \n");
        }

        int x = atoi(array[0]);
        int y = atoi(array[1]);
        int d = atoi(array[2]);

        if (n%2 == 0) 
        {
            s1=score(s1, array[3]);
            s1=bonus(s1, d, x, y, array[3], c1, c2, c3, c4);
            p1+=s1; // adun scorul unui cuvânt la punctele Player-ului 1
        }
        else 
        {
            s2=score(s2, array[3]);
            s2=bonus(s2, d, x, y, array[3], c1, c2, c3, c4);
            p2+=s2; // adun scorul unui cuvânt la punctele Player-ului 2
        }
    }

    printf("Player 1: %d Points", p1);
    printf("\nPlayer 2: %d Points", p2);
}

void task4()
{
   char game_board[15][15];

    setboard(game_board);

    char line[max];
    fgets(line, max, stdin); // nu e nevoie de substrings la acest task
    fgets(line, max, stdin);
    fgets(line, max, stdin); // numărul de cuvinte
    int nr = atoi(line);

    char *used[max]; // stochez cuvintele din words care se află deja pe tablă
    int count = 0;

    for (int n=0; n<nr; n++) {

        fgets(line, max, stdin);

        char *p;
        p = strtok(line, " \n");

        char *array[3]; // pointer către cuvânt
        int i = 0;

        while (p != NULL)
        {
            array[i++]=p;
            p = strtok (NULL, " \n");
        }

        int x = atoi(array[0]);
        int y = atoi(array[1]);
        int d = atoi(array[2]);

        for (int k=0; k<100; k++) { // folosesc k pt contorizarea cuvintelor din words
            if (strcmp(words[k],array[3]) == 0)
                used[count++] = words[k];
        }

        setword(game_board, array[3], x, y, d);
    }

    int un_cuvant = 0; // variabilă booleană - testarea se oprește după un singur cuvânt

    for (int k=0; k<100; k++) {
        int ok = 1; // variabilă booleană - devine 0 dacă cuvântul este deja pe tablă

        for (int I=0; I<count; I++) {
            if (words[k] == used[I])
                ok = 0;
        }

        if (ok == 1)
        {
            char *w;
            w = words[k]; // pointer către literele cuvântului

            for (int i=0; i<15; i++) {
                for (int j=0; j<15; j++) {

                    if ( w[0] == game_board[i][j] )
                    {
                        int ok_orizontal = 1; // variabile booleene - devin 0 dacă cuvântul nu are loc
                        int ok_vertical = 1;

                        for (int loc=1; loc<strlen(words[k]); loc++) { // loc pe tablă
                            if (game_board[i][j+loc] != '.')
                                ok_orizontal = 0;
                        }

                        if (ok_orizontal == 1)
                        {
                            for (int litera=0; litera<strlen(words[k]); litera++) { 
                                 if (j+strlen(words[k]) <= 15)
                                {
                                    setword(game_board, words[k], i, j, 0);
                                    un_cuvant = 1;
                                }
                            }
                        }
                           
                        for (int loc=1; loc<strlen(words[k]); loc++) { // loc pe tablă
                            if (game_board[i+loc][j] != '.')
                                ok_vertical = 0;
                        }

                        if (ok_vertical == 1)
                        {
                            for (int litera=0; litera<strlen(words[k]); litera++) {
                                if (i+strlen(words[k]) <= 15)
                                {
                                    setword(game_board, words[k], i, j, 1);
                                    un_cuvant = 1;
                                }
                            }
                        }
                    }

                    if (un_cuvant == 1)
                        break;
                }

                if (un_cuvant == 1)
                    break;
            }
        }
    }

    print_board(game_board);
}

void task5()
{
    char game_board[15][15];

    setboard(game_board);

    char line[max];

    fgets(line, max, stdin);
    char substring1[3];
    strcpy(substring1, line);
    char c1 = substring1[0];
    char c2 = substring1[1];

    fgets(line, max, stdin);
    char substring2[3];
    strcpy(substring2, line);
    char c3 = substring2[0];
    char c4 = substring2[1];

    fgets(line, max, stdin); // numărul de cuvinte
    int nr = atoi(line);

    int p1 = 0, p2 = 0;

    char *used[max];
    int count = 0;

    for (int n=0; n<nr; n++) {

        int s1=0, s2=0;

        fgets(line, max, stdin);

        char *p;
        p = strtok(line, " \n");

        char *array[3]; // pointer către cuvânt
        int i = 0;

        while (p != NULL)
        {
            array[i++] = p;
            p = strtok (NULL, " \n");
        }

        int x = atoi(array[0]);
        int y = atoi(array[1]);
        int d = atoi(array[2]);

        for (int i=0; i<100; i++) {

            if (strcmp(words[i],array[3]) == 0)
                used[count++] = words[i];
        }

        setword(game_board, array[3], x, y , d);

        if (n%2 == 0)
        {
            s1=score(s1, array[3]);
            s1=bonus(s1, d, x, y, array[3], c1, c2, c3, c4);
            p1+=s1; // adun scorul unui cuvânt la punctele Player-ului 1
        }
        else
        {
            s2=score(s2, array[3]);
            s2=bonus(s2, d, x, y, array[3], c1, c2, c3, c4);
            p2+=s2; // adun scorul unui cuvânt la punctele Player-ului 2
        }
    }

    int maxim = 0, poz_orizontala, poz_verticala, directie, h = 0;

    for (int k=0; k<100; k++) {

        int s = 0;

        int ok = 1; // variabilă booleană - devine 0 dacă cuvântul este deja pe tablă

        for (int I=0; I<count; I++) {
            if (words[k] == used[I])
                ok = 0;
        }

        if (ok == 1)
        {
            char *w;
            w = words[k]; // pointer către literele cuvântului

            for (int i=0; i<15; i++) {
                for (int j=0; j<15; j++) {

                    if ( w[0] == game_board[i][j] )
                    {
                        int ok_orizontal = 1; // variabile booleene - devin 0 dacă cuvântul nu are loc
                        int ok_vertical = 1;

                        for (int loc=1; loc<strlen(words[k]); loc++) { // loc pe tablă
                            if (game_board[i][j+loc] != '.')
                                ok_orizontal = 0;
                        }

                        if (ok_orizontal == 1)
                        {
                            if (j + strlen(words[k]) <= 15)
                            {
                                /* scorul + bonsurile fiecărui cuvânt care 
                                   se poate pune pe tablă pe orizontală */

                                s = score(s, words[k]);
                                s = bonus(s, 0, i, j, words[k], c1, c2, c3, c4);

                                if (s > maxim || (s == maxim && i < poz_orizontala) )
                                {
                                    /* verific să fie scorul cel mai 
                                    mare și poziția cea mai de sus */

                                    maxim = s;
                                    poz_orizontala = i;
                                    poz_verticala = j;
                                    directie = 0;
                                    h = k;
                                }
                                
                                s = 0;
                            }
                        }

                        for (int loc=1; loc<strlen(words[k]); loc++) { // loc pe tablă
                            if (game_board[i+loc][j] != '.')
                                ok_vertical = 0;
                        }

                        if (ok_vertical == 1)
                        {
                            if (i + strlen(words[k]) <= 15)
                            {
                                /* scorul + bonsurile fiecărui cuvânt care 
                                   se poate pune pe tablă pe verticală */

                                s = score(s, words[k]);
                                s = bonus(s, 1, i, j, words[k], c1, c2, c3, c4);
                                
                                if (s > maxim || ( s == maxim && i < poz_orizontala) )
                                {
                                    /* verific să fie scorul cel mai 
                                    mare și poziția cea mai de sus */

                                    maxim = s;
                                    poz_orizontala = i;
                                    poz_verticala = j;
                                    directie = 1;
                                    h = k;
                                }
                                    
                                s = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if (maxim + p2 >= p1)
    {
        setword(game_board, words[h], poz_orizontala, poz_verticala, directie);
        print_board(game_board);
    }
    else
        printf("Fail!");       
}

int main()
{
    char task[max];
    fgets(task, max, stdin);
    int nr = atoi(task);

    switch (nr)
    {
        case 0: task0(); break;
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
    }

    return 0;
}