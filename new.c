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
    fgets(line, sizeof(line), input);       //find height of the file1
    for(int i = 0; i < strlen(line); i++){
        if (i == '\n'){
            break;
        }
        if(line[i] >= '0' && line[i] <= '9'){
            height = line[i];
        }
    }

    fgets(line, sizeof(line), input);       //find width of the file1
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
    fgets(line2, sizeof(line2), input2);        //find height of the file2
    for(int i = 0; i < strlen(line2); i++){
        if (i == '\n'){
            break;
        }
        if(line2[i] >= '0' && line2[i] <= '9'){
            height2 = line2[i];
        }
    }

    fgets(line2, sizeof(line2), input2);        //find width of the file2
    for(int i = 0; i < strlen(line2); i++){
        if (i == '\n'){
            break;
        }
        if(line2[i] >= '0' && line2[i] <= '9'){
            width2 = line2[i];
        }
    }

    int height_n = height - '0';        //change char into int for height1
    int width_n = width - '0';      //change char into int for width1

    int height_n2 = height2 - '0';      //change char into int for height2
    int width_n2 = width2 - '0';        //change char into int for width2

    int t_width = width_n + width_n2;

    int size = height_n * width_n;      //get size of the file1
    int size2 = height_n2 * width_n2;       //get the size of file2

    int newline = height_n - 1;     //find how many newline in file1
    int newline2 = height_n2- 1;        //find how many newline in file1

    ptr = (char*)malloc(size);
    ptr2 = (char*)malloc(size2);

    fread(ptr, 1, size + newline, input);      //copy content from file1 into ptr
    fread(ptr2, 1, size2 + newline2, input2);     //copy content from file2 into ptr2

    char *ptr3;
    ptr3 = (char*)malloc(size);     
    for(int i = 0; i <= size; i++){
        if (*(ptr + i) == '\n'){        //get rid of newline
            *(ptr + i) = 0;
        }
        memcpy(&ptr3[i], &ptr[i], 1);        //copy content from ptr into ptr3
    }

    for(int i = size + 1; i <= size2 + size + 3; i++){      //put content from file2 in ptr3
        if (*(ptr2 + (i - (size + 1))) == '\n'){       
            *(ptr2 + (i - (size + 1))) = 0;
        }
        memcpy(&ptr3[i], &ptr2[i - (size + 1)], 1);     
    }

    output = fopen("Final_char.txt", "w");      //writing a new file
    fwrite(ptr3, 1, width_n, output);
    fwrite(ptr3 + t_width, 1, width_n2, output);
    fputc('\n', output);
    fwrite(ptr3 + (width_n + 1), 1, width_n, output);
    fwrite(ptr3 + (width_n2 + 2), 1, width_n2, output);
    fputc('\n', output);
    fprintf(output, "  ");
    fwrite(ptr3 + (width_n2 + 2), 1, width_n2, output);
    
    free(ptr);      //free pointer
    free(ptr2);
    free(ptr3);
    fclose(input);      //close file
    fclose(input2);
    fclose(output);
    return 0;
}