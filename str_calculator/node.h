#ifndef node_h
#define node_h

#include <stdlib.h>

struct SNode {

    long m_lValue;
    long m_lIdx;

    struct SNode * m_pnParent;
    struct SNode * m_pnLChild;
    struct SNode * m_pnRChild;

    long (* m_lGetValue)(struct SNode * this);
    long (* m_lGetIdx)(struct SNode * this);
    struct SNode * (* m_pnGetParent)(struct SNode * this);
    struct SNode * (* m_pnGetLChild)(struct SNode * this);
    struct SNode * (* m_pnGetRChild)(struct SNode * this);

    void (* m_setValue)(struct SNode * this, long lValue);
    void (* m_setIdx)(struct SNode * this, long lIdx);
    void (* m_setParent)(struct SNode * this, struct SNode * pnParent);
    void (* m_setLChild)(struct SNode * this, struct SNode * pnLChild);
    void (* m_setRChild)(struct SNode * this, struct SNode * pnRChild);

    void (* m_destroy)(struct SNode * this);
    void (* m_construct)(struct SNode * this);
};

struct SNode nNewNode(void);

#endif
