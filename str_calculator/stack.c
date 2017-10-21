#include "stack.h"

static STACK_DATA_TYPE pop(struct Stack * this) {

    STACK_DATA_TYPE tmp;

    if (this->m_lHeadPtr >= 0) {

        tmp = this->m_prgElements[this->m_lHeadPtr];

        this->m_lHeadPtr--;
    }

    return tmp;
}

static long lPush(struct Stack * this, STACK_DATA_TYPE newElement) {

    this->m_lHeadPtr++;

    if (this->m_lHeadPtr >= this->m_lSize) {

        this->m_lHeadPtr--;

        return -1;
    }

    this->m_prgElements[this->m_lHeadPtr] = newElement;

    return this->m_lHeadPtr;
}

static int bIsEmpty(struct Stack * this) {
    return (this->m_lHeadPtr < 0);
}

static void destroy(struct Stack * this) {

    this->m_lHeadPtr = -1;
    this->m_lSize = 0;

    free(this->m_prgElements);
    this->m_prgElements = NULL;

    this->m_pop = NULL;
    this->m_lPush = NULL;
    this->m_bIsEmpty = NULL;

    this->m_destroy = NULL;
    this->m_constructor = NULL;
}

static void constructor(struct Stack * this, long lStSize) {

    this->m_lHeadPtr = -1;
    this->m_lSize = lStSize;

    this->m_prgElements = (STACK_DATA_TYPE *) malloc(lStSize * sizeof (STACK_DATA_TYPE));

    this->m_pop = pop;
    this->m_lPush = lPush;
    this->m_bIsEmpty = bIsEmpty;

    this->m_destroy = destroy;
    this->m_constructor = constructor;
}

struct Stack newStack(long lStSize) {

    struct Stack st;

    constructor(&st, lStSize);

    return st;
}
