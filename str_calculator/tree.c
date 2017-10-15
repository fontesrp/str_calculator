#include "tree.h"

long lOpPrecedence(long op) {

    if (op == MUL || op == DIV || op == MOD) {
        return 2;
    }

    if (op == SUM || op == SUB) {
        return 1;
    }

    return 0;
}

static struct SNode * pnGetCurrNode(struct SCalcBTree * this) {
    return this->m_pnCurr;
}

static struct SNode * pnGetRoot(struct SCalcBTree * this) {
    return this->m_pnRoot;
}

static void setCurrNode(struct SCalcBTree * this, struct SNode * pnNode) {
    this->m_pnCurr = pnNode;
}

static void setRoot(struct SCalcBTree * this, struct SNode * pnNode) {
    this->m_pnRoot = pnNode;
}

static struct SNode * pnAddNode(struct SCalcBTree * this) {

    this->m_prgnNodes[this->m_uiNodeQtt] = nNewNode();

    struct SNode * pn = &(this->m_prgnNodes[this->m_uiNodeQtt]);

    this->m_uiNodeQtt++;

    return pn;
}

static long lParentOp(struct SCalcBTree * this) {

    struct SNode * pnCurr = this->m_pnCurr;
    struct SNode * pnParent = pnCurr->m_pnParent;
    long lOp;

    if (pnParent == NULL) {
        lOp = NOP;
    } else {
        lOp = pnParent->m_lValue;
    }

    return lOp;
}

// static void postorder(struct SCalcBTree * this, void (* cb)(struct SNode * pnNode)) {}

static void placeOp(struct SCalcBTree * this, enum opearations currOp, long lValue) {

    long lParentOp = this->m_lParentOp(this);
    struct SNode * pnCurr = this->m_pnGetCurrNode(this);
    struct SNode * pnGen;
    struct SNode * pnRoot;

    if (currOp == NOP) {
        pnCurr->m_setValue(pnCurr, lValue);
    } else if (lOpPrecedence(currOp) >= lOpPrecedence(lParentOp)) {

        pnCurr->m_setValue(pnCurr, currOp);

        // Left child
        pnGen = this->m_pnAddNode(this);
        pnGen->m_setValue(pnGen, lValue);
        pnGen->m_setParent(pnGen, pnCurr);

        pnCurr->m_setLChild(pnCurr, pnGen);

        // Right child
        pnGen = this->m_pnAddNode(this);
        pnGen->m_setParent(pnGen, pnCurr);

        pnCurr->m_setRChild(pnCurr, pnGen);

        // Update current node pointer
        this->m_setCurrNode(this, pnGen);
    } else {

        pnCurr->m_setValue(pnCurr, lValue);

        // New root
        pnGen = this->m_pnAddNode(this);
        pnGen->m_setValue(pnGen, currOp);

        pnRoot = this->m_pnGetRoot(this);
        pnRoot->m_setParent(pnRoot, pnGen);

        pnGen->m_setLChild(pnGen, pnRoot);

        this->m_setRoot(this, pnGen);
        pnRoot = pnGen;

        // Right child
        pnGen = this->m_pnAddNode(this);
        pnGen->m_setParent(pnGen, pnRoot);

        pnRoot->m_setRChild(pnRoot, pnGen);

        // Update current node pointer
        this->m_setCurrNode(this, pnGen);
    }
}

static void destroy(struct SCalcBTree * this) {

    free(this->m_prgnNodes);
    this->m_prgnNodes = NULL;

    this->m_uiNodeQtt = 0;

    this->m_pnRoot = NULL;
    this->m_pnCurr = NULL;

    this->m_pnGetCurrNode = NULL;
    this->m_pnGetRoot = NULL;

    this->m_setCurrNode = NULL;
    this->m_setRoot = NULL;

    this->m_pnAddNode = NULL;
    this->m_placeOp = NULL;

    this->m_lParentOp = NULL;
    // this->m_postorder = NULL;

    this->m_destroy = NULL;
    this->m_construct = NULL;
}

static void construct(struct SCalcBTree * this, unsigned int uiMaxNodes) {

    this->m_prgnNodes = (struct SNode *) malloc(uiMaxNodes * sizeof (struct SNode));

    this->m_uiNodeQtt = 0;

    this->m_pnGetCurrNode = pnGetCurrNode;
    this->m_pnGetRoot = pnGetRoot;
    this->m_pnAddNode = pnAddNode;

    this->m_setCurrNode = setCurrNode;
    this->m_setRoot = setRoot;
    this->m_lParentOp = lParentOp;
    // this->m_postorder = postorder;
    this->m_placeOp = placeOp;

    this->m_destroy = destroy;
    this->m_construct = construct;

    struct SNode * pn = this->m_pnAddNode(this);
    pn->m_setValue(pn, NOP);
    this->m_setCurrNode(this, pn);
    this->m_setRoot(this, pn);
}

struct SCalcBTree tNewTree(unsigned int uiNodeQtt) {

    struct SCalcBTree t;

    construct(&t, uiNodeQtt);

    return t;
}
