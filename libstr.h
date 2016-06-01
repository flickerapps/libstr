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
    char* substring = (char*)malloc(CHAR_SIZE * ( (end - start) + 2 ) ); /* \0 */
    int  j = 0;
    if(start == end){ /* one char */
        substring[j] = str[start];
        j++;
    }
    else{
        int i;
        for(i = start; i <= end ; i++){
            substring[j] = str[i];
            j++;
        }
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
    char* reverse = (char*)calloc(1, CHAR_SIZE * i + 1);
    int j = 0;
    while(i-1 >= 0){
        reverse[j++] = str[--i]; /* ignoring '\0' */
    }
    reverse[j] = '\0';
    return reverse;
}


char* strslice(char* str, int slice){
    int i = strlen(str);
    int j = 0;
    if(i <= 1 || slice == 0){
        return str;
    }
    char* sliced;
    if(slice < 0 && 0 <= (i + slice) ){ /* negative index */
        sliced = substr(str, 0, (strlen(str) -1) + slice);
    }
    else if(slice > 0 && slice < i){
        sliced = (char*)calloc( (i - slice) + 1, CHAR_SIZE);
        int k = slice;
        while(str[k] != '\0'){
            sliced[j++] = str[k++];
        }
        sliced[j] = '\0';
    }
    else{
        return str;
    }
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


/*
    char* str = (char*)"Hello-World";
    char** splited = strsplit('-', str); => ['Hello','World']

*/

int arraylen(char** array){
    int i = 0;
    while(array[i] != NULL){
        i++;
    }
    return i;
}


char* removechars(const char* rem, char* str){ /*rem is an array of chars*/
    int i = 0;
    int any = 0;
    while(i < strlen(rem)){
        if( indexOf(rem[i], str) < 0){
            any++;
        }
        i++;
    }
    if(any == ( strlen(rem) - 1)  ){ /* no found any char for remove */
        return str;
    }
    i = strlen(str) -1;
    char* removed = (char*)calloc(i + 2, CHAR_SIZE);
    i = 0;
    int found = 0;
    int j = 0;
    while(i < strlen(str)){
        int k = 0;
        while(k < strlen(rem)){
            if( rem[k] == str[i]){
                found = 1;
            }
            k++;
        }
        if( found == 0){
            removed[j++] = str[i];
        }
        i++;
        found = 0;
    }
    removed[i] = '\0';
    return removed;
}
char** strsplit(char split, char* str){
    if(indexOf(split, str) <= 0){
        char** unique = (char**)malloc( CHAR_SIZE * strlen(str) + 1);
        unique[0] = str;
        strcpy(*unique, str);
        return unique;
    }
    char** splited = (char**)malloc(1);
    int idx = 0;
    int i = 0;
    int ini = 0;
    int fin = 0;
    int size = 0;
    while(str[i] != '\0'){
        if(str[i+1] == '\0'){
            fin = i;
            char* last_wor = substr(str, ini, fin);
            size += CHAR_SIZE * strlen(last_wor);
            splited = (char**)realloc(splited, size);
            splited[idx++] = last_wor;
            /* insert */
        }
        else if(str[i] == split){
            fin = i - 1;
            char* wor = substr(str, ini, fin);
            size += CHAR_SIZE * strlen(wor);
            /* insert */
            splited = (char**)realloc(splited, size);
            splited[idx++] = wor;
            ini = fin = i + 1;
        }

        i++;
    }
    return splited;
}


int arraysize( char** array){
    int size = 0;
    int i = 0;
    while(i < arraylen(array)){
        size += strlen(array[i++]); /* space and \0 */
    }
    return size;
}
char** arrayreverse(char** array){
    if(array == NULL){
        return NULL;
    }
    char** reversed = (char**)malloc( arraysize(array) );
    int i = 0;

    int j = arraylen(array);
    while(j--){
        reversed[i++] = array[j];
    }
    return reversed;
}


char* arrayjoin(char** array, char unio){
    if(arraylen(array) == 1){
        return array[0];
    }
    int i = 0;
    int total = arraysize(array); /* total of chars */
    total += arraylen(array) * sizeof(char) + 1; /* counting the unio */
    char* join = (char*)malloc(total);
    i = 0;
    while(i < arraylen(array)){
        strncat(join, array[i], strlen(array[i]));
        if(i+1 < arraylen(array) ) join[strlen(join)] = unio; /*if isnt last char, put the unio */
        i++;
    }
    if(join[strlen(join) -1] != '\0'){
        join[strlen(join)] = '\0';
    }
    return join;
}

int freeStr(char* str){
    if(str != NULL) free(str);
    return 0;
}

int freeArray(char** array){
    if(array == NULL){
        return -1;
    }
    int i = 0;
    while(i < arraylen(array)){
        if(array[i] != NULL) free(array[i++]);
    }
    return 0;
}
#endif
