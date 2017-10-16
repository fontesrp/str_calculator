#include <stdio.h>

#include "calculator.h"

#define MAX_STR_SIZE 1000

int main(int argc, const char * argv[]) {

    char szExpression[MAX_STR_SIZE + 1];

    printf("Plese enter expression: ");
    fgets(szExpression, MAX_STR_SIZE + 1, stdin);

    printf("\nSolution = %ld\n", lSolveEquation(szExpression, MAX_STR_SIZE));

    return 0;
}
