#include "str.h"
#include <stdlib.h>
#include <string.h>


void str_free(char** strptr)
{
    free(*strptr);
    *strptr = NULL;
}

char* str_cpy(char** dst, const char* src)
{
    size_t srcsize;
    char *newdst;
#ifdef STR_CHECK_NULL_SRC
    if (src==NULL)
        newdst = NULL;
    else 
#endif
    {
        srcsize = strlen(src);
        newdst = malloc(srcsize+1);
        if (newdst==NULL)
            return NULL;
        memmove(newdst, src, srcsize+1);
    }
    if (*dst!=NULL)
        str_free(dst);
    *dst = newdst;
    return newdst;
}

char* str_cat(char** dst, const char* src)
{
    size_t dstsize, srcsize, newdstsize;
    char *olddst = *dst;
    char *newdst;

#ifdef STR_CHECK_NULL_SRC
    if (src==NULL)
        return olddst;
#endif
#ifdef STR_CHECK_NULL_DST
    if (dst==NULL || olddst==NULL)
        return olddst;
#endif
    dstsize = strlen(olddst);
    srcsize = strlen(src);
    newdstsize = dstsize+srcsize;
    if (newdstsize==0)
        return olddst;
    newdst = malloc(newdstsize+1);
    if (newdst==NULL)
        return NULL;
    memmove(newdst, olddst, dstsize);
    memmove(newdst+dstsize, src, srcsize+1); 
    str_free(dst);
    *dst = newdst;
    return newdst;
}


int str_printf(char** dst, const char* fmt, ...)
{
    return 0;
}


