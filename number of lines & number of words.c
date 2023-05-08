#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename.c\n", argv[0]);
        exit(1);
    }
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(1);
    }
    
    yyrestart(fp);
    yylex();
    
    printf("Number of characters: %ld\n",chars);
    printf("Number of lines: %d\n", yylineno);
    printf("Number of words: %d\n", yywords);
    
    fclose(fp);
    return 0;
}
