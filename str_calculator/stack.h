#ifndef stack_h
#define stack_h

#include <stdlib.h>

#ifndef STACK_DATA_TYPE
#define STACK_DATA_TYPE long
#endif

struct Stack {

    long m_lHeadPtr;
    long m_lSize;

    STACK_DATA_TYPE * m_prgElements;

    STACK_DATA_TYPE (* m_pop)(struct Stack * this);
    long (* m_lPush)(struct Stack * this, STACK_DATA_TYPE newElement);

    void (* m_destroy)(struct Stack * this);
    void (* m_constructor)(struct Stack * this, long lStSize);
};

struct Stack newStack(long lStSize);

#endif
