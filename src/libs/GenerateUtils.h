#ifndef SAMPLE_GENERATE_UTILS_H
#define SAMPLE_GENERATE_UTILS_H

//#include "CommonLibs.h"

class GenerateUtils{
public:

    static string generateRandomLowerCaseString(int length){
        string s="";
        for (int i = 0; i < length; ++i) {
            s+='a' + rand()%26;
        }
        return s;
    }

    static string generateRandomUpperCaseString(int length){
        string s="";
        rep(length){
            s+='A' + rand()%26;
        }
        return s;
    }

    static int generateRandomInt(int limit){
        return rand()%limit;
    }

};

#endif

