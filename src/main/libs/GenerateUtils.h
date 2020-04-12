#ifndef SAMPLE_GENERATE_UTILS_H
#define SAMPLE_GENERATE_UTILS_H

#include "CommonLibs.h"

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

void testGenerateUtils(){
    string s = GenerateUtils::generateRandomLowerCaseString(10);
    assert(s.length()==10);

    string s2 = GenerateUtils::generateRandomUpperCaseString(20);
    assert(s2.length()==20);

    assert(GenerateUtils::generateRandomInt(100) <= 100);

}
#endif

