#include "calculator.h"

static struct Stack stOps;

static long lPerformOp(long lOperand1, long lOperand2, enum opearations op) {

    switch (op) {
    case SUM:
        return lOperand1 + lOperand2;
    case SUB:
        return lOperand1 - lOperand2;
    case MUL:
        return lOperand1 * lOperand2;
    case DIV:
        return lOperand1 / lOperand2;
    case MOD:
        return lOperand1 % lOperand2;
    case NOP:
    default:
        return 0;
    }
}

static void handleTreeNodes(long lNodeVal) {

    long lOperand1;
    long lOperand2;

    if (lNodeVal < 0) {
        // If lNodeVal is operation, perform it and store result
        lOperand2 = stOps.m_pop(&stOps);
        lOperand1 = stOps.m_pop(&stOps);
        stOps.m_lPush(&stOps, lPerformOp(lOperand1, lOperand2, lNodeVal));
    } else {
        // Else, store lNodeVal to be a future operand
        stOps.m_lPush(&stOps, lNodeVal);
    }
}

static enum opearations opGet(char cLetter) {

    switch (cLetter) {
    case '+':
        return SUM;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    default:
        return NOP;
    }
}

static int bIsNumeric(char cLetter) {
    return (cLetter >= '0' && cLetter <= '9');
}

static long lStr2num(char * szStr, long * lIdx) {

    long lNum = 0;

    while (bIsNumeric(szStr[*lIdx])) {

        lNum = lNum * 10 + szStr[*lIdx] - '0';

        (*lIdx)++;
    }

    return lNum;
}

static void formTree(struct SCalcBTree * tCalc, char * szExpression, unsigned int uiExpSize) {

    long lIdx = 0;
    long lNum;
    enum opearations op;

    while (lIdx < uiExpSize && szExpression[lIdx] != '\0') {

        lNum = lStr2num(szExpression, &lIdx);

        op = opGet(szExpression[lIdx]);

        tCalc->m_placeOp(tCalc, op, lNum);

        lIdx++;
    }
}

long lSolveEquation(char * szExpression, unsigned int uiExpSize) {

    struct SCalcBTree tCalc = tNewTree(uiExpSize);

    formTree(&tCalc, szExpression, uiExpSize);

    // TODO: what's the best size here?
    stOps = newStack(tCalc.m_uiNodeQtt);

    tCalc.m_postorder(&tCalc, handleTreeNodes);

    long result = stOps.m_pop(&stOps);

    tCalc.m_destroy(&tCalc);
    stOps.m_destroy(&stOps);

    return result;
}
