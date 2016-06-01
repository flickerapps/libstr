#include "../libstr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    char str[] = "Lorem ipsum dolor sit amet";
    char** toArray = strsplit(' ', str);
    toArray = arrayreverse(toArray);
    char* join = arrayjoin(toArray, ' ');
    printf("Reversed: %s\n", join); /* => amet sit dolor ipsum Lorem */
    printf("%d == %d\n", strlen(str), strlen(join)); /* => 26 == 26 */
    return 0;
}
