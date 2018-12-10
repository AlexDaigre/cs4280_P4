#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "parser.h"
#include "testTree.h"
#include "node.h"
#include "st.h"
#include "codeGenerator.h"

void invokeParserFromFile(char* fileName);

int main (int argc, char* argv[]) {
    if (argc == 2) {
        invokeParserFromFile(argv[1]);
    } else if (argc == 1){
        targetFile = fopen ("out.asm" , "w");
        if (targetFile == NULL){
            printf("Could not open %s: %d\n", "out.asm", errno);
        }
        Node* node = parser(stdin);
        traversePreorder(node);
        checkVarsInTree(node);
        generateCode(node);
    } else {
        printf("A sourcefile is requred as an argument. No additional arguments are allowed.\n");
        return 1;
    }
}

void invokeParserFromFile(char* fileName){
    char sourceFileName[256] = "";
    char targetFileName[256] = "";
    char* fileExtention = (char*)".fs182";
    char* fileOutputExtention = (char*)".asm";
    
    strcpy(sourceFileName, fileName);
    strcat(sourceFileName, fileExtention);
    
    strcpy(targetFileName, fileName);
    strcat(targetFileName, fileOutputExtention);

    FILE* sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL){
        printf("Could not open %s: %d\n", sourceFileName, errno);
    }
    targetFile = fopen (targetFileName, "w");
    if (targetFile == NULL){
        printf("Could not open %s: %d\n", targetFileName, errno);
    }
    Node* node = parser(sourceFile);
    traversePreorder(node);
    checkVarsInTree(node);
    generateCode(node);

    fclose(sourceFile);
}