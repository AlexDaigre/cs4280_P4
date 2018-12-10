#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

    #include <stdio.h>
    #include "node.h"

    extern FILE* targetFile;

    void generateCode(Node* node);

#endif