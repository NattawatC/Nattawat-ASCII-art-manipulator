#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Image{       //still don't know how to use this!!
    size_t height;
    size_t width;
    char* data;
};

int main(){
    FILE *input = fopen("char.txt","r");
    FILE *input2 = fopen("char2.txt","r");
    FILE *outfile = NULL;
    char *ptr, *ptr2;

    if((input == NULL)||(input2 == NULL)){
        printf("Can't find a File");
        exit(1);
    }

    fseek(input, 0, SEEK_END);      //set the end of file
    int size = ftell(input);    //find the size of file(input)
    fseek(input, 0, SEEK_SET);      //set to beginning of the file

    fseek(input2, 0, SEEK_END);
    int size2 = ftell(input2);    //find the size of file(input2)
    fseek(input2, 0, SEEK_SET);

    int size_t = size + size2;      //total file's size

    ptr = (char*)malloc(size);
    ptr2 = (char*)malloc(size2);

    int arr1 = fread(ptr, 1, size, input);      //put char into pointer(ptr)
    int arr2 = fread(ptr2, 1, size2, input2);       //put char2 into pointer(ptr2)
    if((arr1 != size) || (arr2 != size2)){      //error checking
        printf("ERROR\n");
    }

    char *ptr3;
    ptr3 = (char*)malloc(size_t);
    memcpy(ptr3, ptr, size_t);      //copy content ptr into ptr3

    ptr3 = (char*)realloc(ptr3, size_t);
    memcpy(ptr3 + strlen(ptr3), ptr2, size_t);      //copy content ptr2 into ptr3 + 10(new_dest)

    for(int i = 0; i < strlen(ptr3); i++){       //char checking
        printf("%c", *(ptr3 + i));
    }

//<still wrong>
    outfile = fopen("Final_char.txt", "w");     //new file to write
    fwrite(ptr3, 1, sizeof(size) + 1, outfile);        //write ptr3
    fwrite(ptr3 + size_t, 1, size_t, outfile);      //write ptr3 + 10

    free(ptr);
    free(ptr2);
    free(ptr3);
    fclose(input);
    fclose(input2);
    fclose(outfile);
    return 0;
}