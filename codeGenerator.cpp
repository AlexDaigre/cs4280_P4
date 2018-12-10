#include <string>
#include <iostream>
#include <fstream>
#include "codeGenerator.h"

void preOrderRecursiveBodyCodeGeneration(Node* node, int level);

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
        preOrderRecursiveBodyCodeGeneration(node, 0);
}

void preOrderRecursiveBodyCodeGeneration(Node* node, int level){ 
    if (node == NULL) {
        return; 
    }

    switch(node->nodeType){
        case eProgram: generateProgram(node); break;
        case eBlock: generateBlock(node); break;
        case eVars: generateVars(node); break;
        case eExpr: generateExpr(node); break;
        case eA: generateA(node); break;
        case eM: generateM(node); break;
        case eR: generateR(node); break;
        case eStats: generateStats(node); break;
        case eMStat: generateMStat(node); break;
        case eStat: generateStat(node); break;
        case eIn: generateIn(node); break;
        case eOut: generateOut(node); break;
        case eIfGram: generateIfGram(node); break;
        case eLoop: generateLoop(node); break;
        case eAssign: generateAssign(node); break;
        case eRO: generateRO(node); break;
    }
    
    preOrderRecursiveBodyCodeGeneration(node->child0, ++level); 
    preOrderRecursiveBodyCodeGeneration(node->child1, ++level);
    preOrderRecursiveBodyCodeGeneration(node->child2, ++level); 
    preOrderRecursiveBodyCodeGeneration(node->child3, ++level);
} 

void generateProgram (Node * node){

}

void generateBlock (Node * node){

}

void generateVars (Node * node){

}

void generateExpr (Node * node){

}

void generateA (Node * node){

}

void generateM (Node * node){

}

void generateR (Node * node){

}

void generateStats (Node * node){

}

void generateMStat (Node * node){

}

void generateStat (Node * node){

}

void generateIn (Node * node){

}

void generateOut (Node * node){

}

void generateIfGram (Node * node){

}

void generateLoop (Node * node){

}

void generateAssign (Node * node){

}

void generateRO (Node * node){

}
