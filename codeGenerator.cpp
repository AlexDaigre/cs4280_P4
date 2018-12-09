#include <string>
#include <iostream>
#include <fstream>
#include "codeGenerator.h"

void preOrderRecursiveBodyCodeGeneration(Node* node, int level);

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
    // switch(node->nodeType){

    // }
    preOrderRecursiveBodyCodeGeneration(node->child0, ++level); 
    preOrderRecursiveBodyCodeGeneration(node->child1, ++level);
    preOrderRecursiveBodyCodeGeneration(node->child2, ++level); 
    preOrderRecursiveBodyCodeGeneration(node->child3, ++level);
} 