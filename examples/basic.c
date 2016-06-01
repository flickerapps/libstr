#include "../libstr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[] = "Hello World";
    int W = indexOf('W',str);
    if(W > 0){
        const char* substring = substr(str, W, strlen(str) -1 ); /* => World */
        printf("%s\n",substring);
    }

    char* str1 = (char*)"Hello World";

    char* sliced = strslice(str1, 6);
    char* reverse = strreverse(str1);
    char o = charAt(str1, 4);
    char* replaced = strreplace('e', '3', str1);
        replaced = strreplace('o','0', replaced);

    printf("\nCharAt(4): '%c'\n", o); /* => 'o' */
    printf("Slice: %s\n", sliced); /* => World */
    printf("Reverse: %s\n", reverse); /* => dlroW olleH */
    printf("Replace: %s\n", replaced); /* H3ll0 W0rld */

    char str11[] = "Lorem ipsum dolor sit amet";
    char** splited = strsplit(' ', str11); /* => { "Lorem", "ipsum", "dolor", "sit", "amet" } */

    printf("Splited: ");
    int i;
    for(i = 0 ; i < 5 ; i++){
        printf("[\"%s\"]", splited[i]);
    }
    printf("\n");

    freeStr(sliced);
    freeStr(reverse);
    freeStr(replaced);
    return 0;
}
