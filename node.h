#ifndef NODE_H
#define NODE_H
    #include "token.h"

    enum nodeTypeEnum{
        eProgram = 0,
        eBlock = 1,
        eVars = 2,
        eExpr = 3, 
        eA = 4,
        eM = 5,
        eR = 6,
        eStats = 7,
        eMStat = 8,
        eStat = 9,
        eIn = 10,
        eOut = 11,
        eIfGram = 12,
        eLoop = 13,
        eAssign = 14,
        eRO = 15
    };


    struct Node {
        enum nodeTypeEnum nodeType;
        struct token token0;
        struct token token1;
        struct token token2;
        Node* child0;
        Node* child1;
        Node* child2;
        Node* child3;
    };

    char* getNodeTokenName(enum nodeTypeEnum newToken);

#endif