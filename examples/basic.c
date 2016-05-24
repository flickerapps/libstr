#include "../libstr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char* str = (char*)"Hello World";
    int W = indexOf('W',str);
    if(W > 0){
        const char* substring = substr(str, W, strlen(str) -1 ); /* => World */
        printf("%s\n",substring);
    }
    return 0;
}
