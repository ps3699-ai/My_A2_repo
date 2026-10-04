/*--------------------------------------------------------------------*/
/* strp.c                                                              */
/* Pointer-notation implementation of the Str module.                  */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <assert.h>

/* Return the length of string pcSrc, not including the trailing
   '\0'. */
size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

/* Copy the string pcSrc (including the trailing '\0') to pcDest.
   Return pcDest. */
char *Str_copy(char *pcDest, const char *pcSrc)
{
   char *pcDestStart;
   assert(pcSrc != NULL);
   assert(pcDest != NULL);

   pcDestStart = pcDest;

   while (*pcSrc != '\0')
   {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
   }
   *pcDest = '\0';
   return pcDestStart;
}

/* Append a copy of the string pcSrc (including the trailing '\0')
   to the end of the string pcDest. Return pcDest. */
char *Str_concat(char *pcDest, const char *pcSrc)
{
   char *pcDestStart;
   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   pcDestStart = pcDest;

   while (*pcDest != '\0')
      pcDest++;

   while (*pcSrc != '\0')
   {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
   }
   *pcDest = '\0';

   return pcDestStart;
}

/* Compare string pcString1 to string pcString2. Return a value less
   than 0 if pcString1 is less than pcString2, a value greater than
   0 if pcString1 is greater than pcString2, or 0 if pcString1
   equals pcString2. */
int Str_compare(const char *pcString1, const char *pcString2)
{
   assert(pcString1 != NULL);
   assert(pcString2 != NULL);

   while (*pcString1 != '\0' && *pcString1 == *pcString2)
   {
      pcString1++;
      pcString2++;
   }
   return *pcString1 - *pcString2;
}


/* Search for the first occurrence of string pcString2 within
   string pcString1. Return a pointer to the first character of
   that occurrence, or NULL if pcString2 does not occur within
   pcString1. */
char *Str_search(const char *pcString1, const char *pcString2)
{
   const char *pcH;
   const char *pcInnerH;
   const char *pcInnerN;

   assert(pcString1 != NULL);
   assert(pcString2 != NULL);

   if (*pcString2 == '\0')
      return (char *)pcString1;

   for (pcH = pcString1; *pcH != '\0'; pcH++)
   {
      pcInnerH = pcH;
      pcInnerN = pcString2;

      while (*pcInnerH == *pcInnerN && *pcInnerN != '\0')
      {
         pcInnerH++;
         pcInnerN++;
      }

      if (*pcInnerN == '\0')
         return (char *)pcH;
   }
   return NULL;
}


