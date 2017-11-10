#ifndef tree_h
#define tree_h

#include <stdlib.h>

#include "node.h"
#include "stack.h"

enum opearations {
    NOP = -6,
    SUM,
    SUB,
    MUL,
    DIV,
    MOD
};

long lOpPrecedence(long op);

struct SCalcBTree {

    struct SNode * m_prgnNodes;

    unsigned int m_uiNodeQtt;

    struct SNode * m_pnRoot;
    struct SNode * m_pnCurr;

    struct SNode * (* m_pnGetCurrNode)(struct SCalcBTree * this);
    struct SNode * (* m_pnGetCurrPar)(struct SCalcBTree * this);
    struct SNode * (* m_pnGetRoot)(struct SCalcBTree * this);
    struct SNode * (* m_pnGetNodeByIdx)(struct SCalcBTree * this, long lIdx);
    struct SNode * (* m_pnAddNode)(struct SCalcBTree * this);

    void (* m_setCurrNode)(struct SCalcBTree * this, struct SNode * pnNode);
    void (* m_setRoot)(struct SCalcBTree * this, struct SNode * pnNode);
    long (* m_lParentOp)(struct SCalcBTree * this);
    void (* m_postorder)(struct SCalcBTree * this, void (* cb)(long lNodeVal));
    void (* m_placeOp)(struct SCalcBTree * this, enum opearations op, long lValue);

    void (* m_destroy)(struct SCalcBTree * this);
    void (* m_construct)(struct SCalcBTree * this, unsigned int uiMaxNodes);
};

struct SCalcBTree tNewTree(unsigned int uiNodeQtt);

#endif
