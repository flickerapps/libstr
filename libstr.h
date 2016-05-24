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

char* substr(char* str, int start, int end){
    char* substring = (char*)malloc(sizeof(char) * (end - start));
    int  j = 0;
    for(int i = start; i <= end ; i++){
        substring[j] = str[i];
        j++;
    }
    return substring;
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

#endif
