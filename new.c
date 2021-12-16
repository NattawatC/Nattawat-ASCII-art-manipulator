#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input = fopen("char.txt","r");        //read file one
    FILE *input2 = fopen("char2.txt","r");      //read file two
    FILE *output = NULL;
    char *ptr, *ptr2;
    char line[50];
    char height, width;
    char height2, width2;

    if((input == NULL)||(input2 == NULL)){      // check for the end of file
        printf("Can't find a File"); 
        exit(1);
    }
// FILE 1
    fgets(line, sizeof(line), input);
    for(int i = 0; i < strlen(line); i++){
        if (i == '\n'){
            break;
        }
        if(line[i] >= '0' && line[i] <= '9'){
            height = line[i];
        }
    }

    fgets(line, sizeof(line), input);
    for(int i = 0; i < strlen(line); i++){
        if (i == '\n'){
            break;
        }
        if(line[i] >= '0' && line[i] <= '9'){
            width = line[i];
        }
    }

// FILE 2
    char line2[50];


    fgets(line2, sizeof(line2), input2);
    for(int i = 0; i < strlen(line2); i++){
        if (i == '\n'){
            break;
        }
        if(line2[i] >= '0' && line2[i] <= '9'){
            height2 = line2[i];
        }
    }

    fgets(line2, sizeof(line2), input2);
    for(int i = 0; i < strlen(line2); i++){
        if (i == '\n'){
            break;
        }
        if(line2[i] >= '0' && line2[i] <= '9'){
            width2 = line2[i];
        }
    }

    int height_n = height - '0';
    int width_n = width - '0';

    int height_n2 = height2 - '0';
    int width_n2 = width2 - '0';

    int size = height_n * width_n;
    int size2 = height_n2 * width_n2;

    int newline = height_n - 1;
    int newline2 = height_n2- 1;

    ptr = (char*)malloc(size);
    ptr2 = (char*)malloc(size2);

    int p_size = fread(ptr, 1, size + newline, input);
    int p_size2 = fread(ptr2, 1, size2 + newline2, input2);

    char *ptr3;
    ptr3 = (char*)malloc(p_size);
    for(int i = 0; i <= size; i++){
        if (*(ptr + i) == '\n'){
            *(ptr + i) = 0;
        }
        memcpy(&ptr3[i], &ptr[i], size);
    }

    char *ptr4;
    ptr4 = (char*)malloc(size2);
    for(int i = 0; i <= size2; i++){
        if (*(ptr2 + i) == '\n'){
            *(ptr2 + i) = 0;
        }
        memcpy(&ptr4[i], &ptr2[i], size2);
    }

    // for(int i = 0; i <= size; i++){
    //     printf("%c", *(ptr3 + i));
    // }

    output = fopen("Final_char.txt", "w");
    fwrite(ptr3, 1, 2, output);
    fwrite(ptr4, 1, 3, output);
    fputc('\n', output);
    fwrite(ptr3 + 3, 1, 2, output);
    fwrite(ptr4 + 4, 1, 3, output);
    fputc('\n', output);
    fprintf(output, "  ");
    fwrite(ptr4 + 8, 1, 3, output);
    


}