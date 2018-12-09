#include <set>
#include <string>
#include <string.h>
#include <stdio.h>
#include "st.h"
#include "node.h"

std::set <std::string> variables;

int verify(char* var){
    if(variables.count(var) == 0){
      return -1;
    }
    return 1;
}

int insert(char* var){
    if(variables.count(var) == 0){
        variables.insert(var);
        return 1;
    }
    return -1;
}

void checkVarsInTree(Node* node){
    if (node == NULL) {
        return; 
    }

    if (node->nodeType == eVars){
        if (insert(node->token0.tokenInstance) < 0){
            printf("Line %d: Variable already initialised.\n", node->token0.lineNum);
            return;
        }
    } else if (node->nodeType == eR){
        if (verify(node->token0.tokenInstance) < 0){
            printf("Line %d: Variable not declaired.\n", node->token0.lineNum);
            return;
        }
    } else if (node->nodeType == eIn){
        if (verify(node->token0.tokenInstance) < 0){
            printf("Line %d: Variable not declaired.\n", node->token0.lineNum);
            return;
        }
    } else if (node->nodeType == eAssign){
        if (verify(node->token0.tokenInstance) < 0){
            printf("Line %d: Variable not declaired.\n", node->token0.lineNum);
            return;
        }
    }

    checkVarsInTree(node->child0); 
    checkVarsInTree(node->child1);
    checkVarsInTree(node->child2); 
    checkVarsInTree(node->child3);
}