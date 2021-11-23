#include<stdio.h>

void printCard( int col, char name, char symbol);

int main()
{
    printf ( "\033[2J");//clear screen
    printCard( 2, 'J','*');
    printCard( 3, 'K','&');
    return 0;
}
void printCard(int col, char name, char symbol)
{
    printf ( "\033[1;%dH", col * 14);//move cursor line 1
    printf("-------------\n");
    printf ( "\033[2;%dH", col * 14);//move cursor line 2
    printf("| %c         |\n",name);
    printf ( "\033[3;%dH", col * 14);//move cursor line 3
    printf("| %c         |\n",symbol);
    printf ( "\033[4;%dH", col * 14);//move cursor line 4
    printf("|           |\n");
    printf ( "\033[5;%dH", col * 14);//move cursor line 5
    printf("|           |\n");
    printf ( "\033[6;%dH", col * 14);//move cursor line 6
    printf("|           |\n");
    printf ( "\033[7;%dH", col * 14);//move cursor line 7
    printf("|         %c |\n",symbol);
    printf ( "\033[8;%dH", col * 14);//move cursor line 8
    printf("|         %c |\n",name);
    printf ( "\033[9;%dH", col * 14);//move cursor line 9
    printf("-------------\n");
}