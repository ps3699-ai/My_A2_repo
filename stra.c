/*--------------------------------------------------------------------*/
/* stra.c                                                              */
/* Array-notation implementation of the Str module.                   */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <assert.h>

/* Return the length of string pcSrc, not including the trailing
   '\0'. */
size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

/* Copy the string pcSrc (including the trailing '\0') to pcDest.
   Return pcDest. */
char *Str_copy(char *pcDest, const char *pcSrc)
{
        size_t uIndex = 0 ;
        assert(pcSrc != NULL);
        assert(pcDest != NULL);
         while(pcSrc[uIndex] != '\0')
        {
        pcDest[uIndex] =pcSrc[uIndex];
        uIndex ++;
        }
        pcDest[uIndex] = '\0';
        return pcDest;
}

/* Append a copy of the string pcSrc (including the trailing '\0')
   to the end of the string pcDest. Return pcDest. */
char *Str_concat(char *pcDest, const char *pcSrc)
{
        size_t charPos = Str_getLength(pcDest);
        size_t uIndex = 0;
        assert(pcSrc != NULL);
        assert(pcDest != NULL);
        while(pcSrc[uIndex] != '\0'){
                pcDest[charPos] =pcSrc[uIndex];
                uIndex ++;
                charPos ++;
        }
        pcDest[charPos] = '\0';
        return pcDest;


}


/* Compare string pcString1 to string pcString2. Return a value less
   than 0 if pcString1 is less than pcString2, a value greater than
   0 if pcString1 is greater than pcString2, or 0 if pcString1
   equals pcString2. */
int Str_compare(const char *pcString1, const char *pcString2)
{
   size_t uIndex = 0;
   assert(pcString1 != NULL);
   assert(pcString2 != NULL);

   while (pcString1[uIndex] != '\0' && pcString1[uIndex] == pcString2[uIndex])
      uIndex++;

   return pcString1[uIndex] - pcString2[uIndex];

}


/* Search for the first occurrence of string pcString2 within
   string pcString1. Return a pointer to the first character of
   that occurrence, or NULL if pcString2 does not occur within
   pcString1. */
char *Str_search(const char *pcString1, const char *pcString2)
{
   size_t uIndexH;
   size_t uIndexN;

   assert(pcString1 != NULL);
   assert(pcString2 != NULL);

   if (pcString2[0] == '\0')
      return (char *)pcString1;

   for (uIndexH = 0; pcString1[uIndexH] != '\0'; uIndexH++)
   {
      uIndexN = 0;
      while (pcString1[uIndexH + uIndexN] == pcString2[uIndexN] &&
             pcString2[uIndexN] != '\0')
         uIndexN++;

      if (pcString2[uIndexN] == '\0')
         return (char *)(pcString1 + uIndexH);
   }

   return NULL;
}
~
~
