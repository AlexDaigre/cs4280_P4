#include <string>
#include <iostream>
#include <fstream>
#include "codeGenerator.h"

FILE* targetFile;

void createVar(char* code);
char* createTempVar();
char* createLabel();

void generateProgram (Node * node);
void generateBlock (Node * node);
void generateVars (Node * node);
void generateExpr (Node * node);
void generateA (Node * node);
void generateM (Node * node);
void generateR (Node * node);
void generateStats (Node * node);
void generateMStat (Node * node);
void generateStat (Node * node);
void generateIn (Node * node);
void generateOut (Node * node);
void generateIfGram (Node * node);
void generateLoop (Node * node);
void generateAssign (Node * node);

void printNode (Node * node);

void generateCode(Node* node) {
        std::cout << "Starting Code Generation:\n";
        if (node == NULL) {
            return; 
        }
        
        generateProgram(node);
}

void generateProgram (Node * node){
    if (node == NULL) {
        return; 
    }

    generateVars(node->child0);
    generateBlock(node->child1);
    return;
}

void generateBlock (Node * node){
    if (node == NULL) {
        return; 
    }
    
    generateVars(node->child0);
    generateStats(node->child1);
    return;
}

void generateVars (Node * node){
    if (node == NULL) {
        return; 
    }
    // if (strcmp(getTokenDescription(node->token0.tokenId), (char*)"NULL") != 0){
        createVar(node->token0.tokenInstance);
    // }
    return;
}

void generateExpr (Node * node){
    if (node == NULL) {
        return; 
    }

    if (node->child1 != NULL) {
        generateExpr(node->child1);
        char* tempVar = createTempVar();
        fprintf(targetFile, "STORE %s\n", tempVar);
        generateA(node->child0);
        if (strcmp(node->token0.tokenInstance, (char*)"/") == 0) {
            fprintf(targetFile, "DIV %s\n", tempVar);
            return;
        } else {
            fprintf(targetFile, "MULT %s\n", tempVar);
            return;
        }
    } else {
        generateA(node->child0);
        return;
    }
}

void generateA (Node * node) {
    if (node == NULL) {
        return; 
    }

    if (node->child1 != NULL) {
        generateA(node->child1);
        char* tempVar = createTempVar();
        fprintf(targetFile, "STORE %s\n", tempVar);
        generateM(node->child0);
        if (strcmp(node->token0.tokenInstance, (char*)"+") == 0) {
            fprintf(targetFile, "ADD %s\n", tempVar);
            return;
        } else {
            fprintf(targetFile, "SUB %s\n", tempVar);
            return;
        }
    } else {
        generateM(node->child0);
        return;
    }

}

void generateM (Node * node){
    if (node == NULL) {
        return; 
    }
    
    // printNode(node);
    // printNode(node->child0);
    if(node->child0->nodeType == eR){
        generateR(node->child0);
        return;
    } else {
        generateM(node->child0);
        fprintf(targetFile, "MULT -1\n");
        return;
    }
}

void generateR (Node * node){
    if (node == NULL) {
        return; 
    }
    if(node->child0 != NULL){
        generateExpr(node->child0);
        return;
    } else if (node->token0.tokenId == idTk) {
        fprintf(targetFile, "LOAD %s\n", node->token0.tokenInstance);
        return;
    } else if (node->token0.tokenId == intTk) {
        fprintf(targetFile, "LOAD %s\n", node->token0.tokenInstance);
        return;
    }
}

void generateStats (Node * node){
    if (node == NULL) {
        return; 
    }
    
    generateStat(node->child0);
    generateMStat(node->child1);
    return;
}

void generateMStat (Node * node){
    if (node == NULL) {
        return; 
    }

    if (node->child0 != NULL){
        generateStat(node->child0);
        generateMStat(node->child1);
        return;
    }
    return;
}

void generateStat (Node * node){
    if (node == NULL) {
        return; 
    }
    if (node->child0->nodeType == eIn){
        generateIn(node->child0);
        return;
    } else if (node->child0->nodeType == eOut){
        generateOut(node->child0);
        return;
    } else if (node->child0->nodeType == eBlock){
        generateBlock(node->child0);
        return;
    } else if (node->child0->nodeType == eIfGram){
        generateIfGram(node->child0);
        return;
    } else if (node->child0->nodeType == eLoop){
        generateLoop(node->child0);
        return;
    } else if (node->child0->nodeType == eAssign){
        generateAssign(node->child0);
        return;
    }
}

void generateIn (Node * node){
    if (node == NULL) {
        return; 
    }
    fprintf(targetFile, "READ %s\n", node->token0.tokenInstance);
    return;
}

void generateOut (Node * node){
    if (node == NULL) {
        return; 
    }
    generateExpr(node->child0);
    char* tempVar = createTempVar();
    fprintf(targetFile, "STORE %s\n", tempVar);
    fprintf(targetFile, "WRITE %s\n", tempVar);
    return;
}

void generateIfGram (Node * node){
    if (node == NULL) {
        return; 
    }
    generateExpr(node->child2);
    char* tempVar = createTempVar();
    fprintf(targetFile, "STORE %s\n", tempVar);
    generateExpr(node->child0);
    fprintf(targetFile, "SUB %s\n", tempVar);
    char* label = createLabel();
    if ((strcmp(node->child1->token0.tokenInstance, "<") == 0) && (strcmp(node->child1->token1.tokenInstance, "=") == 0)){
        fprintf(targetFile, "BRPOS %s\n", label);
    } else if ((strcmp(node->child1->token0.tokenInstance,  ">") == 0) && (strcmp(node->child1->token1.tokenInstance, "=") == 0)){
        fprintf(targetFile, "BRNEG %s\n", label);
    }  else if ((strcmp(node->child1->token0.tokenInstance, "=") == 0) && (strcmp(node->child1->token1.tokenInstance, "=") == 0)){
        fprintf(targetFile, "BRZERO %s\n", label);
    } else if (strcmp(node->child1->token0.tokenInstance, "<") == 0){
        fprintf(targetFile, "BRZPOS %s\n", label);
    } else if (strcmp(node->child1->token0.tokenInstance,  ">") == 0){
        fprintf(targetFile, "BRZNEG %s\n", label);
    }  else if (strcmp(node->child1->token0.tokenInstance, "=") == 0){ 
        fprintf(targetFile, "BRNEG %s\n", label);
        fprintf(targetFile, "BRPOS %s\n", label);
    } 
    generateStat(node->child3);
    fprintf(targetFile, "%s: NOOP\n", label);
    return;
}

void generateLoop (Node * node){
    if (node == NULL) {
        return; 
    }
    char* label = createLabel();
    fprintf(targetFile, "%s: NOOP\n", label);
    generateExpr(node->child2);
    char* tempVar = createTempVar();
    fprintf(targetFile, "STORE %s\n", tempVar);
    generateExpr(node->child0);
    fprintf(targetFile, "SUB %s\n", tempVar);
    char* label2 = createLabel();
    if ((strcmp(node->child1->token0.tokenInstance, "<") == 0) && (strcmp(node->child1->token1.tokenInstance, "=") == 0)){
        fprintf(targetFile, "BRZNEG %s\n", label2);
    } else if ((strcmp(node->child1->token0.tokenInstance,  ">") == 0) && (strcmp(node->child1->token1.tokenInstance, "=") == 0)){
        fprintf(targetFile, "BRPOS %s\n", label2);
    }  else if ((strcmp(node->child1->token0.tokenInstance, "=") == 0) && (strcmp(node->child1->token1.tokenInstance, "=") == 0)){
        fprintf(targetFile, "BRNEG %s\n", label2);
        fprintf(targetFile, "BRPOS %s\n", label2);
    }else if (strcmp(node->child1->token0.tokenInstance, "<") == 0){
        fprintf(targetFile, "BRNEG %s\n", label2);
    } else if (strcmp(node->child1->token0.tokenInstance,  ">") == 0){
        fprintf(targetFile, "BRPOS %s\n", label2);
    }  else if (strcmp(node->child1->token0.tokenInstance, "=") == 0){
        fprintf(targetFile, "BRZERO %s\n", label2);
    }
    generateStat(node->child3);
    fprintf(targetFile, "BR %s\n", label);
    fprintf(targetFile, "%s: NOOP\n", label2);
    return;
}

void generateAssign (Node * node){
    if (node == NULL) {
        return; 
    }
    generateExpr(node->child0);
    fprintf(targetFile, "STORE %s\n", node->token0.tokenInstance);
    return;
}

char* createTempVar(){
    return (char*)"tempVar";
}

char* createLabel(){
    return (char*)"label";
}

void createVar(char* code){

}

void printNode (Node * node){
    std::cout << getNodeTokenName(node->nodeType)
    << ": " << getTokenName(node->token0.tokenId) 
    << "/" << node->token0.tokenInstance
    << ": " << getTokenName(node->token1.tokenId) 
    << "/" << node->token1.tokenInstance
    << ": " << getTokenName(node->token2.tokenId) 
    << "/" << node->token2.tokenInstance
    << "\n";
}