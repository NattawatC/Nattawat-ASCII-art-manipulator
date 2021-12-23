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

    int t_size = size + size2;

    int newline = height_n - 1;     //find how many newline in file1
    int newline2 = height_n2- 1;        //find how many newline in file2
    int max_newline;

    if(newline < newline2){
        max_newline = newline2;
    }
    else{
        max_newline = newline;
    }

    
    ptr = (char*)malloc(size);
    ptr2 = (char*)malloc(size2);

    fread(ptr, 1, size + newline, input);      //copy content from file1 into ptr
    fread(ptr2, 1, size2 + newline2, input2);     //copy content from file2 into ptr2
    
    int index_ptr1 = 0;
    int index_ptr2 = 0;
    int index_ptr3 = 0;
    int newline_n = 0;
    char *ptr3;
    ptr3 = (char*)malloc(size);   
    for (int i = 0; i <= max_newline; i++){
        for(int j = 0; j <= width_n; j++){
            if (j == width_n){
                for(int k = 0; k <= width_n2; k++){
                    memcpy(&ptr3[index_ptr3++], &ptr2[index_ptr2++], 1);        //ptr3[index_ptr3++] == ptr2[index_ptr2++];
                }
                index_ptr1++;
            }
            else{
                memcpy(&ptr3[index_ptr3++], &ptr[index_ptr1++], 1);     //ptr3[index_ptr3++] == ptr[index_ptr1];
            }       
        }   
    }

    output = fopen("Final_char.txt", "w");      //writing a new file
    for(int i = 0; i <= index_ptr3; i++){
        if(*(ptr3 + i) == '\0'){
            fprintf(output, " ");
        }
        else{
            fprintf(output, "%c", *(ptr3 + i));
        }
    }

    free(ptr);      //free pointer
    free(ptr2);
    free(ptr3);
    fclose(input);      //close file
    fclose(input2);
    fclose(output);
    return 0;
}