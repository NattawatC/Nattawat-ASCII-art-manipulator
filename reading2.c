#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i = 1;
    FILE *input = fopen("char.txt","r");
    FILE *input2 = fopen("char2.txt","r");
    char line1[50],line2[50];
    char *n1,*n2;
    if((input == NULL)||(input2 == NULL)){
        printf("ERROR");
        exit(1);
    }
    while(1){

        n1 = fgets(line1, sizeof(line1), input);
        n2 = fgets(line2, sizeof(line2), input2);
        if((n1 == NULL)||(n2 == NULL)){
            break;
        }
        int len = strlen(line1);
        if (len > 0 && line1[len-1] == '\n'){
            line1[len-1] = 0;
        }
        printf("%s", n1);
        printf("%s", n2);
    }
    fclose(input);
    fclose(input2);
    return 0;
}