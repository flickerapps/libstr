#include <stdio.h>
#include "../libstr.h"

int main(int argc, char const *argv[])
{
    char str1[] = "Hello World";

    char* substring = substr(str1, 0, indexOf('o',str1));
    printf("Substring: %s\n", substring); /* => Hello */

    char* sliced = strslice(str1, 6);
    printf("Slice: %s\n", sliced); /* => World */

    char* reverse = strreverse(str1);
    printf("Reverse: %s\n", reverse); /* => dlroW olleH */

    char o = charAt(str1, 4);
    printf("CharAt(4): '%c'\n", o); /* => 'o' */

    char* replaced = strreplace('e', '3', str1);
        replaced = strreplace('o', '0', replaced);
    printf("Replace: %s\n", replaced); /* H3ll0 W0rld */

    char* sliced2 = strslice(str1, -1);
    printf("Slice2: %s\n", sliced2); /* => Hello Worl */

    char str[] = "H%e(l^-&lo- W*o^r-$^l*()d--_";
    const char* toRemove = "-&_^*/%($)";
    char* removed = removechars(toRemove, str);
    printf("Remove: %s\n", removed); /* => Hello World */
    return 0;
}
