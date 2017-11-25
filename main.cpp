#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cmath>
#include <stack>

using namespace std;

int vvod ( )
{
    bool Flag = true;
    stack <char> number;
    char x;
    int N = 1, a = 0;

    while ( Flag == true )
    {
        Flag = false;
        do
        {
            scanf ( "%c", &x );
            if ( ( ( int ( x )  > 47 ) && ( int ( x ) < 58 ) ) || ( x == '-' ) || ( x == ' ' ) || ( x == '\n') )
            {
                if ( ( x == ' ' ) || ( x == '\n') )
                    break;
                number.push( x );
            }
            else
            {
                Flag = true;
                break;
            }

        }while ( true );

        if ( Flag == false )
        {
                while( !number.empty ( ) )
                {
                    if ( number.top ( ) == '-' )
                    {
                        x = 't';
                        number.pop();
                        continue;
                    }
                    a += int ( number.top ( ) - 48 ) * N;
                    N *= 10;
                    number.pop();
                }
                break;
        }
        else
        {
            system("cls");
            printf( "Ââåäèòå ÷èñëî\n" );
            while( !number.empty() )
            {
                number.pop();
            }
        }
        }
        if ( x == 't' )
            return a * ( -1 );
        else
            return a;
}

void delet ( int num, int num2, int** &mass )
{
    if ( mass != NULL )
    {
        for ( int i = 0; i < num; i ++ )
            delete []mass[i];
        delete []mass;
    }

    return;

}

void sozdat ( int num, int num2, int** &mass )
{
    mass = new int*[num];

    for ( int i = 0; i < num; i ++ )
        mass[i] = new int[num2];

    return;

}

void vvod_mass( int &num, int &num2, int** &mass, bool &Flag )
{
    system("cls");

    delet( num, num2, mass ); // î÷èùàåì ïàìÿòü åñëè ìàññèâ óæå çàïîëíÿëñÿ

    while(true)
    {
        system("cls");

        printf("Ââåäèòå êîë-âî ñòðîê\n");

        num = vvod ( );

        if ( ( num > 0 ) && ( num < 1000 ) )
        {
            break;
        }
        else
        {
            printf("Ââåäèòå ïðàâèëüíîå çíà÷åíèå\n");
        }
    }
    while(true)
    {
        system("cls");

        printf("Ââåäèòå êîë-âî ñòîëáöîâ\n");

        num2 = vvod ( );

        if /*(*/ ( num2 > 0 ) //&& ( num2 < 1000 ) )
        {
            break;
        }
        else
        {
            printf("Ââåäèòå ïðàâèëüíîå çíà÷åíèå\n");
        }
    }

    sozdat ( num, num2, mass ); // âûäåëÿåì ïàìÿòü ïîä ìàññèâ

    while( Flag == true )
    {
        system("cls");

        printf( "êàê ââåñòè ýëåìåíòû?\n" );
        printf( "íàæìèòå 1 åñëè âðó÷íóþ\n" );
        printf( "íàæìèòå 2 åñëè ñëó÷àéíûì îáðàçîì\n" );

        int v = vvod ( );
        Flag = false;

        switch ( v )
        {
            case 1:

                printf( "Ââîäèòå ýëåìåíòû\n" );

                for(int i = 0; i < num; i++)
                    for( int j = 0; j < num2; j ++ )
                        mass[i][j] = vvod ( );

                break;

            case 2:

                srand( time ( NULL ) );

                for( int i = 0; i < num; i ++ )
                    for( int j = 0; j < num2; j ++ )
                        mass[i][j] = ( rand ( ) % 100 ) * pow ( ( - 1 ), ( rand ( ) % 2 ) );

                break;

            default:

                Flag = true;

                break;
        }
    }
    Flag = true;
    return;
}

void vyvod_mass( int num, int num2,int** mass, bool &Flag )
{
    system("cls");
    while(true)
    {
        if ( mass != NULL )
        {
            printf("Ýëåìåíòû ìàññèâà:\n");

            for( int i = 0; i < num; i ++ )
            {
                printf("\n");
                for( int j = 0; j < num2; j ++ )
                {
                    printf( "[%i, %i] ", ( i + 1 ), ( j + 1 ) );
                    printf ( "%i", mass[i][j] );
                    printf("\t");
                }
            }

            system("pause");

            break;

        }
        else
        {
            printf ( "Ìàññèâ íå çàïîëíåí\n" );

            Flag = true;

            system("pause");

            break;
        }
    }
    return;
}

void proverka( int num, int num2, bool &Flag, int** mass )
{
    system("cls");

    while( true )
    {
        if ( mass != NULL )
        {
            int mn = 0, mx = 0, i1, j1, i2, j2;

            for( int j = 0; j < num2; j ++ )
            {
                mn = mass[0][j];
                mx = mass[0][j];
                i1 = 0;
                j1 = j;
                i2 = 0;
                j2 = j;

                for( int i = 0; i < num; i ++ )
                {

                    if ( mass[i][j] > mx )
                        {
                            mx = mass[i][j];
                            i1 = i;
                            j1 = j;
                        }
                    else if ( mass[i][j] < mn )
                    {
                        mn = mass[i][j];
                        i2 = i;
                        j2 = j;
                    }

                }

                mass[i2][j2] = mx;
                mass[i1][j1] = mn;
            }
            break;
        }
        else
        {

            printf("Ìàññèâ íå çàïîëíåí\n");

            Flag = true;

            system("pause");

            break;
        }
    }
        return;
}

void escape()
{
    system("cls");

    printf("Âû õîòèòå âûéòè ? :(\nÅñëè äà, ââåäèòå 1\nÅñëè íåò äðóãîå çíà÷åíèå\n");

    int a = vvod();

    if ( a == 1)
        exit( 0 );

    return;
}

int main ()
{
    setlocale(0, "");

    int a = 0;
    bool Flag = true;
    int num = 0;
    int num2 = 0;
    int **mass = NULL;

    while( Flag == true )

    {

        system("cls");

        printf( "Ìåíþ\n1: ââåñòè ìàññèâ\n2: îáðàáîòàòü ìàññèâ\n3: âûâåñòè ìàññèâ\n4: âûéòè\n" );

        a = vvod ( );

        switch ( a )

        {
            case 1:

                vvod_mass ( num, num2, mass, Flag );

                break;

            case 2:

                proverka ( num, num2, Flag, mass );

                break;

            case 3:

                vyvod_mass ( num, num2, mass, Flag );

                break;

            case 4:

                escape ( );

                break;
          }
      }

    return 0;
}
