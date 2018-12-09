#include "node.h"

char* getNodeTokenName(enum nodeTypeEnum newToken){
    switch (newToken) {
        case eProgram: return (char*)"program";
        case eBlock: return (char*)"block";
        case eVars: return (char*)"vars";
        case eExpr: return (char*)"expr";
        case eA: return (char*)"A";
        case eM: return (char*)"M";
        case eR: return (char*)"R";
        case eStats: return (char*)"stats";
        case eMStat: return (char*)"mStat";
        case eStat: return (char*)"stat";
        case eIn: return (char*)"in";
        case eOut: return (char*)"out";
        case eIfGram: return (char*)"ifGram";
        case eLoop: return (char*)"loop";
        case eAssign: return (char*)"assign";
        case eRO: return (char*)"RO";
        default: return (char*)"NULL";
   }
}