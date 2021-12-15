#include <stdio.h>
#include <stdlib.h>
  

void copy(char filename_in[], char filename_out[]){
    // Open one file for reading
    char c;


    FILE *input = fopen(filename_in, "r");
    if (input == NULL){
        printf("Cannot open file %s \n", filename_in);
        exit(0);
    }
    c = fgetc(input);
    while (c != EOF){
        printf("here");
        printf("%c", c);
        c = fgetc(input);
    }
  
  
    // Open another file for writing
    FILE *output = fopen(filename_out, "w");
    if (output == NULL){
        printf("Cannot open file %s \n", filename_out);
        exit(0);
    }
  
    // Read contents from file
    c = fgetc(input);
    while (c != EOF){
        fputc(c, output);
        c = fgetc(input);
    }
  
    printf("\nContents copied to %s\n", filename_out);
  
    fclose(input);
    fclose(output);
}
int main(int argc, char **argv){
    FILE *input, *output;
    char c;
    if(argc == 3){
        copy(argv[1], argv[2]);
    }
    return 0;
}