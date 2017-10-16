#ifndef calculator_h
#define calculator_h

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

#define STACK_DATA_TYPE long

#include "stack.h"

long lSolveEquation(char * szExpression, unsigned int uiMaxExpSize);

#endif
