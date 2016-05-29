#include "../libstr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    char str11[] = "Lorem ipsum dolor sit amet";
    char** splited = strsplit(' ', str11); /* => { "Lorem", "ipsum", "dolor", "sit", "amet" } */

    printf("Splited\n");
    for(int i = 0 ; i < arraylen(splited) ; i++){
        printf("[\"%s\"]", splited[i]);
    }
    printf("\n");

    char** reversedarray = arrayreverse(splited);
    printf("%d vs %d\n", arraysize(splited), arraysize(reversedarray));
    printf("%d vs %d\n", arraylen(splited), arraylen(reversedarray));
    printf("Reversed:\n");
    for(int i = 0 ; i < arraylen(reversedarray); i++){
        printf("[\"%s\"]", reversedarray[i]);
    }
    printf("\n");
    char* join = arrayjoin(splited, ' ');
    printf("%s\n", join);

    freeArray(splited);

    /* do not free a reversed array, the items are pointers to original array, but pointing in reverse order */
    /*  freeArray(reversedarray);   */

    freeStr(join);
    return 0;
}
