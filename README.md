libstr.h
====
A short library for C with usefull functions for strings.

libstr.h includes `<string.h>`.

 Functions:

 * `substr()`: return a sub-string of a string
 * `indexOf()`: return the index of a char in a string
 * `indexOfSub()`: return the index of a char in a sub-string
 * `strreverse()` : return a reversed string
 * `strreplace()` : method searches a string for a specified value and returns a new string where the specified values are replaced.
 * `charAt()` : return char in specified index of a string.
 * `strslice()`:  extracts a section of a string and returns a new string.
 * `strsplit()`: Split a string into an array of substrings.
 * `removechars()`: receives a string with chars to remove in specified string
 * `arrayreverse()`: return a reversed array
 * `arraylen()`: return the num of elements of specified array
 * `arrayjoin()`: Join the elements of an array into a string.


Basic
====
```c

char str1[] = "Hello World";

char* substring = substr(str1, 0, indexOf('o',str1));
printf("Substring: %s\n", substring); /* => Hello */

char* sliced = strslice(str1, 6);
printf("Slice: %s\n", sliced); /* => World */

char* sliced2 = strslice(str1, -1);
printf("Slice2: %s\n", sliced2); /* => Hello Worl */

char* reverse = strreverse(str1);
printf("Reverse: %s\n", reverse); /* => dlroW olleH */

char o = charAt(str1, 4);
printf("CharAt(4): '%c'\n", o); /* => 'o' */

char* replaced = strreplace('e', '3', str1);
    replaced = strreplace('o', '0', replaced);
printf("Replace: %s\n", replaced); /* H3ll0 W0rld */

char str[] = "H%e(l^-&lo- W*o^r-$^l*()d--_";
const char* toRemove = "-&_^*/%($)";
char* removed = removechars(toRemove, str);
printf("Remove: %s\n", removed); /* => Hello World */

```

LICENSE
====
[MIT](LICENSE)
