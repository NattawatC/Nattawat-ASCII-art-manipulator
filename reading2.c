//#include <stdio.h>
//#include <math.h>
//
//int main(){
//    float fa, c;
//    printf("Enter degree fahrenheit:");
//    scanf("%f", &fa);
//    c = (fa - 32) * 5 / 9;
//    printf("%f", c);
//    return 0;
//}

//    float c, r;
//    printf("radius: ");
//    scanf("%f", &r);
//    int r = 2;
//    c = 2 * 3.1416 * r;
//    printf("%f", c);

//int isRightTriangle(float a, float b, float c){
//    if (c * c == (a * a) + (b * b))
//        return 1;
//    else
//        return 0;
//}
//
//float calculateArea(float a, float b, float c){
//    float s, area;
//    s = (a + b + c)/2;
//    area = sqrt(s*(s-a)*(s-b)*(s-c));
//    return area;
//}
//
//int main(){
//
//    float a, b, c;
//    printf("Enter side a:");
//    scanf("%f", &a);
//    printf("Enter side b:");
//    scanf("%f", &b);
//    printf("Enter side c:");
//    scanf("%f", &c);
//
//
//    float area = calculateArea(a, b, c);
//    printf("The area is %.2lf\n", area);
//
//    if (isRightTriangle(a, b, c)){
//        printf("It is a right triangle");
//    }
//    else {
//        printf("It is not a right triangle");
//    }
//    return 0;
//}

//int main(){
//    int x, z;
//    printf("Enter the number:");
//    scanf("%d", &x);
//    int y = 0;
//    while (x > 0){
//        z = x % 10;
//        y = y * 10 + z;
//        x /= 10;
//    }
//    printf("Reverse= %d", y);
//    return 0;
//}



//
//int main() {
//
//    int r;
//    double volume;
//
//    printf("Enter radius:");
//    scanf("%d", &r);
//
//    volume = calculateSphereVolume(r);
//    printf("%lf", volume);
//
//    return 0;
//}
//float calculateSphereVolume(r){
//    double volume;
//    volume = (r * r * r) * 3.14 * 4/3;
//    return volume;
//}

//    int num = 1;
//    printf("%d\n", num);
//        for (int x = 2; x < 4; x++) {
//                printf("%d", x);
//        }
//    printf("\n");
//        for (int i = 4; i < 7; i++) {
//            printf("%d", i);
//    }
//    printf("\n");
//    for (int i = 7; i < 11; i++) {
//        printf("%d", i);
//    }
//    return 0;


//float calculateSphereVolume(int r);
//
//int main() {
//
//    int r;
//    double volume;
//
//    printf("Enter radius:");
//    scanf("%d", &r);
//
//    volume = calculateSphereVolume(r);
//    printf("%lf", volume);
//
//    return 0;
//}
//float calculateSphereVolume(r){
//    double volume;
//    volume = (r * r * r) * 3.14 * 4/3;
//    return volume;
//}



//    int number, sum, add;
//    printf("Enter N:");
//    scanf("%d", &number);
//    sum = 0;
//    add = 0;
//    while (sum < number) {
//        sum++;
//        add += sum;
//    }
//    printf("the sum of all numbers to %d is %d", number, add);
//    return 0;
//#include <stdio.h>
//int
//{   FILE *in_File = fopen("count.txt", "r");
//int n = 0;
//int c;
//    while ((c = fgetc(in_File)) != EOF){
//    fputc(c,in_File);
//    if(c ==' '){
//    n++;}
//    else if(c =='\t'){
//    n++;}
//    else if (c=='\n'){
//    n++;}}
//    printf("%d", n);
//    fclose(in_File);





// project C
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(){
//    FILE *input = fopen("C:\\Users\\USER\\Desktop\\input.txt","r");
//    FILE *input2 = fopen("C:\\Users\\USER\\Desktop\\after.txt","r");
//    char line1[50],line2[50];
//    char *n1,*n2;
//    char *ptr, *ptr2;
//    if((input == NULL)||(input2 == NULL)){
//        printf("Can't find a File");
//        exit(1);
//    }
//    fseek(input, 0, SEEK_END);
//    int size = ftell(input);
////    printf("%d", size);
//    fseek(input, 0, SEEK_SET);
//
//    fseek(input2, 0L, SEEK_END);
//    int size2 = ftell(input2);
////    printf("%d", size2);
//    fseek(input2, 0, SEEK_SET);
//
//    ptr = (char*)malloc(size);
//    ptr2 = (char*)malloc(size2);
//
//    while(1){
//        n1 = fgets(line1, sizeof(line1), input);
//        n2 = fgets(line2, sizeof(line2), input2);
//        if((n1 == NULL) && (n2 == NULL)){
//            break;
//        }
//        ptr = n1;
//        for(int i = 0; i < strlen(n1); i++){
//            ptr[strlen(n1) - (i - 1)] = '\0';
//        }
//
//        ptr2 = n2;
//        for(int i = 0; i < strlen(n2); i++){
//            ptr2[strlen(n2) - (i - 2)] = '\0';
//        }
//
//        printf("%s%s\n", ptr, ptr2);
//        int len = strlen(line1);
//        if (len > 0 && line1[len - 1] == '\n'){
//            line1[len - 1] = 0;
//        }
//    }
//    free(ptr);
//    free(ptr2);
//    fclose(input);
//    fclose(input2);
//    return 0;
//}


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
    memcpy(ptr3 + (size_t), ptr2, size_t);      //copy content ptr2 into ptr3 + 10(new_dest)

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