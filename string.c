#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input = fopen("char.txt","r");
    FILE *input2 = fopen("char2.txt","r");
    char line1[50],line2[50];
    char *n1,*n2;
    char *token, *token2;
    const char s[] = "\n";
    if((input == NULL)||(input2 == NULL)){
        printf("ERROR");
        exit(1);
    }
    fseek(input, 0, SEEK_SET);
    // while(1){
    //     n1 = fgets(line1, sizeof(line1), input);
    //     n2 = fgets(line2, sizeof(line2), input2);
    //     if((n1 == NULL) && (n2 == NULL)){
    //         break;
    //     }
    //     token = strtok(n1, s);
    //     token2 = strtok(n2, s);
    //     strcat(token, token2);
    //     puts(token);
    //     // puts(token2);
    // }
    // fclose(input);
    // fclose(input2);
    return 0;
}