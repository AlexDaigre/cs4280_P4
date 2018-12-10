#include <string>
#include <iostream>
#include <fstream>
#include "codeGenerator.h"

FILE* targetFile;

void preOrderRecursiveBodyCodeGeneration(Node* node, int level);

void print2Target (char* code);
void createVar(char* code);
char* createTempVar();

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
void generateRO (Node * node);

void generateCode(Node* node) {
        std::cout << "Starting Code Generation:\n";
        if (node == NULL) {
            return; 
        }
        // preOrderRecursiveBodyCodeGeneration(node, 0);
        generateProgram(node);
}

// void preOrderRecursiveBodyCodeGeneration(Node* node, int level){ 
//     if (node == NULL) {
//         return; 
//     }

//     switch(node->nodeType){
//         case eProgram: generateProgram(node); break;
//         case eBlock: generateBlock(node); break;
//         case eVars: generateVars(node); break;
//         case eExpr: generateExpr(node); break;
//         case eA: generateA(node); break;
//         case eM: generateM(node); break;
//         case eR: generateR(node); break;
//         case eStats: generateStats(node); break;
//         case eMStat: generateMStat(node); break;
//         case eStat: generateStat(node); break;
//         case eIn: generateIn(node); break;
//         case eOut: generateOut(node); break;
//         case eIfGram: generateIfGram(node); break;
//         case eLoop: generateLoop(node); break;
//         case eAssign: generateAssign(node); break;
//         case eRO: generateRO(node); break;
//     }

//     preOrderRecursiveBodyCodeGeneration(node->child0, ++level); 
//     preOrderRecursiveBodyCodeGeneration(node->child1, ++level);
//     preOrderRecursiveBodyCodeGeneration(node->child2, ++level); 
//     preOrderRecursiveBodyCodeGeneration(node->child3, ++level);
// } 

void generateProgram (Node * node){
    if (node == NULL) {
        return; 
    }

    generateVars(node);
    generateBlock(node);
    return;
}

void generateBlock (Node * node){
    if (node == NULL) {
        return; 
    }
    
    generateVars(node);
    generateStats(node);
    return;
}

void generateVars (Node * node){
    if (node == NULL) {
        return; 
    }

    if (node->child0 == NULL) {
        return;
    } else {
        createVar(node->token0.tokenInstance);
        return;
    }
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
        if (node->token0.tokenInstance == (char*)"/") {
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
        if (node->token0.tokenInstance == (char*)"+") {
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
    if(node->child0->nodeType == eR){
        generateR(node->child0);
    } else {
        generateM(node->child0);
        fprintf(targetFile, "MULT -1\n");
    }
}

void generateR (Node * node){
    if (node == NULL) {
        return; 
    }
    if(node->child0 != NULL){
        generateExpr(node->child0);
    } else if (node->child0->token0.tokenId == idTk) {
        fprintf(targetFile, "Load %s", node->child0->token0.tokenInstance);
    } else if (node->child0->token0.tokenId == intTk) {
        fprintf(targetFile, "Load %s", node->child0->token0.tokenInstance);
    }
}

void generateStats (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateMStat (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateStat (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateIn (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateOut (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateIfGram (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateLoop (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateAssign (Node * node){
    if (node == NULL) {
        return; 
    }

}

void generateRO (Node * node){
    if (node == NULL) {
        return; 
    }

}

char* createTempVar(){
    return (char*)"x";
}