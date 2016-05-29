#include "../libstr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*Task: find the index of 'e' in 'I have...' */
    char msg[] = "The Life is a game and I have the ball";

    /* Without indexOfSub: */

    int I = indexOf('I', msg); /* I in 'I have...' */
    int len = strlen(msg);
    char* sentence = substr(msg, I, len); /* => I have the ball */
    int e = indexOf('e',sentence); /* e in 'have' */
    e = ( len - strlen(sentence) ) + e; /* => 28 */
    printf("Index Of 'e': %d\n", e);

    /* Using indexOfSub: */

    I = indexOf('I', msg);
    e = indexOfSub('e', msg, I); /* find in 'I have the ball' */
    printf("Index Of 'e': %d\n", e); /* => 28*/

    return 0;
}
