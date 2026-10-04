/*--------------------------------------------------------------------*/
/* str.h                                                              */
/*--------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED

#include <stddef.h>

/* Return the length of string pcSrc, not including the trailing
   '\0'. */
size_t Str_getLength(const char *pcSrc);

/* Copy the string pcSrc (including the trailing '\0') to pcDest.
   Return pcDest. */
char *Str_copy(char *pcDest, const char *pcSrc);

/* Append a copy of the string pcSrc (including the trailing '\0')
   to the end of the string pcDest. Return pcDest. */
char *Str_concat(char *pcDest, const char *pcSrc);

/* Compare string pcString1 to string pcString2. Return a value less
   than 0 if pcString1 is less than pcString2, a value greater than
   0 if pcString1 is greater than pcString2, or 0 if pcString1
   equals pcString2. */
int Str_compare(const char *pcString1, const char *pcString2);

/* Search for the first occurrence of string pcString2 within
   string pcString1. Return a pointer to the first character of
   that occurrence, or NULL if pcString2 does not occur within
   pcString1. */
char *Str_search(const char *pcString1, const char *pcString2);

#endif
