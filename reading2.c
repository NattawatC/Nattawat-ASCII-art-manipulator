#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input = fopen("C:\\Users\\USER\\Desktop\\input.txt","r");
    FILE *input2 = fopen("C:\\Users\\USER\\Desktop\\after.txt","r");
    // char line1[50],line2[50];
    // char *n1,*n2;
    char *ptr, *ptr2;

    if((input == NULL)||(input2 == NULL)){
        printf("Can't find a File");
        exit(1);
    }
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    fseek(input, 0, SEEK_SET);

    fseek(input2, 0, SEEK_END);
    int size2 = ftell(input2);
    fseek(input2, 0, SEEK_SET);
    int size_t = size + size2;

    ptr = (char*)malloc(size);
    ptr2 = (char*)malloc(size2);
    
    int arr1 = fread(ptr, 1, size, input);
    int arr2 = fread(ptr2, 1, size2, input2);
    if((arr1 != size) || (arr2 != size2)){
        printf("ERROR\n");
    }

    char *ptr3;
    ptr3 = (char*)malloc(size_t);
    memcpy(ptr3, ptr, size_t);

    ptr3 = (char*)realloc(ptr3, size_t);
    memcpy(ptr3 + (size_t), ptr2, size_t);

    // memcpy(ptr3 + (size_t * 2),ptr3, size_t * 2);
    strcat(ptr3, ptr3 + (size_t));
    puts(ptr3);

    free(ptr);
    free(ptr2);
    free(ptr3);
    fclose(input);
    fclose(input2);
    return 0;
}


//    while(1){
//         n1 = fgets(line1, sizeof(line1), input);
//         n2 = fgets(line2, sizeof(line2), input2);
//         if((n1 == NULL) && (n2 == NULL)){
//             break;
//         }

//         ptr = n1;
//         for(int i = 0; i < strlen(n1); i++){
//             token[strlen(n1) - (i - 1)] = '\0';
//         }
        
//         ptr2 = n2;
//         for(int i = 0; i < strlen(n2); i++){
//             token2[strlen(n2) - (i - 2)] = '\0';
//         }

//         strcat(token, token2);
//         puts(token);
//         // puts(token2);
//         // printf("%s%s\n", ptr, ptr2);
// //        int len = strlen(line1);
// //        if (len > 0 && line1[len - 1] == '\n'){
// //            line1[len - 1] = 0;
// //        }
//     }
//     free(token);
//     free(token2);
//     fclose(input);
//     fclose(input2);
//     return 0;