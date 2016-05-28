/*
    Name: libstr.h
    Description: A short library for C with usefull functions for strings.
    URL: https://github.com/flickerapps/libstr
    Author: Christopher Ventura <chrisventjs@gmail.com>
    Author URL: http://github.com/flickerapps
*/

#ifndef LIBSTR_H
#define LIBSTR_H

#include <stdlib.h>
#include <string.h>

const int CHAR_SIZE = sizeof(char);

/*

char* str = "Hello World";
char* subs = substr(str, 0, 4) => "Hello"

*/

char* substr(char* str, int start, int end){
    if( (end - start) > strlen(str)){
        return NULL;
    }
    else if( (end - start) == strlen(str)){
        return str;
    }
    char* substring = (char*)malloc(CHAR_SIZE * ( (end - start) + 1 ) ); /* \0 */
    int  j = 0;
    for(int i = start; i <= end ; i++){
        substring[j] = str[i];
        j++;
    }
    substring[j] = '\0';
    return substring;
}


/*

    char* str = "Lorem Ispum";
    char m = charAt(4, str); => m

*/

char charAt(char* str, int index){
    if(index > strlen(str)){
        return 0;
    }
    return str[index];
}

char* strreverse(char* str){
    int i = strlen(str);
    if(i <= 1){
        return str;
    }
    char* reverse = (char*)calloc(i + 1, sizeof(str) );
    int j = 0;
    while(i >= 0){
        reverse[j++] = str[--i]; /* ignoring '\0' */
    }
    reverse[j] = '\0';
    return reverse;
}


char* strslice(char* str, int slice){
    int i = strlen(str);
    if(i <= 1 || slice > i){
        return str;
    }
    char* sliced = (char*)calloc( (i - slice) + 1, CHAR_SIZE);

    int j = 0;
    int k = slice;
    while(str[k] != '\0'){
        sliced[j++] = str[k++];
    }

    sliced[j] = '\0';
    return sliced;

}
int indexOfSub(char match, char* val, int ini){
    int i = ini;
    while(val[i] != match){
        if(val[i] == '\0'){
            i = -1;
            break;
        }
        i++;
    }
    return i;
}

int indexOf(char match, char* val){
    int i = 0;
    while(val[i] != match){
        if(val[i] == '\0'){
            i = -1;
            break;
        }
        i++;
    }
    return i;
}

char* strreplace(char find, char rep, char* str){
    if(indexOf(find, str) <= 0){
        return str;
    }
    int i = 0;
    char* replaced = (char*)calloc(strlen(str) + 1, CHAR_SIZE);
    while(str[i] != '\0'){
        replaced[i] = (str[i] == find) ? rep : str[i];
        i++;
    }
    replaced[i] = '\0';
    return replaced;
}

#endif
