//reading file

#include <stdio.h>
#include <conio.h>

int main(){
    FILE *input = fopen("char.txt", "r");
    FILE *input2 = fopen("char2.txt", "r");
    // FILE *output = fopen("gray_picture.bmp", "w");

    printf("\033[2J");//clear screen
    char a;
    while((a = fgetc(input)) != EOF){
        printf("%c", a, "\033[1;%dH", 0);
        // printf("%c", a);
    }
    char b;
    while((b = fgetc(input2)) != EOF){
        printf("%c", b, "\033[1;%dH", 0);
    }
}



// moving cursor
void printCard(int col, char symbol)
{
    printf ( "\033[1;%dH", col * 14);//move cursor line 1
    // printf("-------------\n");
    printf ( "\033[2;%dH", col * 14);//move cursor line 2
    // printf("| %c         |\n",name);
    printf ( "\033[3;%dH", col * 14);//move cursor line 3
    // printf("| %c         |\n",symbol);
    printf ( "\033[4;%dH", col * 14);//move cursor line 4
    // printf("|           |\n");
    printf ( "\033[5;%dH", col * 14);//move cursor line 5
    // printf("|           |\n");
    printf ( "\033[6;%dH", col * 14);//move cursor line 6
    // printf("|           |\n");
    printf ( "\033[7;%dH", col * 14);//move cursor line 7
    // printf("|         %c |\n",symbol);
    printf ( "\033[8;%dH", col * 14);//move cursor line 8
    // printf("|         %c |\n",name);
    printf ( "\033[9;%dH", col * 14);//move cursor line 9
    // printf("-------------\n");
}