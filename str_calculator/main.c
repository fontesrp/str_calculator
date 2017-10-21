#include <stdio.h>

#include "calculator.h"

#define MAX_STR_SIZE 1000

static void jumpWhites(char * szStr, unsigned int * lIdx) {

    while ( \
        szStr[*lIdx] == ' ' \
        || szStr[*lIdx] == '\t' \
        || szStr[*lIdx] == '\n' \
        || szStr[*lIdx] == '\r' \
    ) {
        (*lIdx)++;
    }
}

static unsigned int uiRemoveWhites(char * szStr, unsigned int uiMaxChars) {

    unsigned int uiStrIdx = 0;
    unsigned int uiNewIdx = 0;

    while (uiStrIdx < uiMaxChars && szStr[uiStrIdx] != '\0') {

        jumpWhites(szStr, &uiStrIdx);

        szStr[uiNewIdx] = szStr[uiStrIdx];

        if (szStr[uiNewIdx] == '\0') {
            return uiNewIdx;
        }

        uiStrIdx++;
        uiNewIdx++;
    }

    szStr[uiNewIdx] = '\0';

    return uiNewIdx;
}

int main(int argc, const char * argv[]) {

    char szExpression[MAX_STR_SIZE + 1];

    printf("Please enter expression:\n");
    fgets(szExpression, MAX_STR_SIZE + 1, stdin);

    unsigned int uiLen = uiRemoveWhites(szExpression, MAX_STR_SIZE);

    printf("\n%s = %ld\n", szExpression, lSolveEquation(szExpression, uiLen));

    return 0;
}
