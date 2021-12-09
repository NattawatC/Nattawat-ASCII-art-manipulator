#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input = fopen("C:\\Users\\USER\\Desktop\\input.txt","r");
    FILE *input2 = fopen("C:\\Users\\USER\\Desktop\\after.txt","r");
    char line1[50],line2[50];
    char *n1,*n2;
    char *ptr, *ptr2;
    if((input == NULL)||(input2 == NULL)){
        printf("ERROR");
        exit(1);
    }
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
//    printf("%d", size);
    fseek(input, 0, SEEK_SET);

    fseek(input2, 0L, SEEK_END);
    int size2 = ftell(input2);
//    printf("%d", size2);
    fseek(input2, 0, SEEK_SET);

    ptr = (char*)malloc(size);
    ptr2 = (char*)malloc(size2);

    while(1){
        n1 = fgets(line1, sizeof(line1), input);
        n2 = fgets(line2, sizeof(line2), input2);
        if((n1 == NULL) && (n2 == NULL)){
            break;
        }
        strncpy(ptr, n1, strlen(n1));
        ptr[strlen(n1) - 1] = '\0';
//        strncpy(ptr2, n2, strlen(n2));
//        ptr[strlen(n2) - 1] = '\0';
//        ptr2 = n2;
//        if (*ptr == '\n'){
//            ptr = 0;
//        }
        puts(ptr);
//        puts(ptr2);


//        int len = strlen(line1);
//        if (len > 0 && line1[len - 1] == '\n'){
//            line1[len - 1] = 0;
//        }

//         if (n1 == NULL){
//             *n1 = '\0';
//         }
//        printf("%s", n1);
//        printf("%s", n2);
    }
    free(ptr);
    free(ptr2);
    fclose(input);
    fclose(input2);
    return 0;
}