#include "node.h"

static long lGetValue(struct SNode * this) {
    return this->m_lValue;
}

static struct SNode * pnGetParent(struct SNode * this) {
    return this->m_pnParent;
}

static struct SNode * pnGetLChild(struct SNode * this) {
    return this->m_pnLChild;
}

static struct SNode * pnGetRChild(struct SNode * this) {
    return this->m_pnRChild;
}

static void setValue(struct SNode * this, long lValue) {
    this->m_lValue = lValue;
}

static void setParent(struct SNode * this, struct SNode * pnParent) {
    this->m_pnParent = pnParent;
}

static void setLChild(struct SNode * this, struct SNode * pnLChild) {
    this->m_pnLChild = pnLChild;
}

static void setRChild(struct SNode * this, struct SNode * pnRChild) {
    this->m_pnRChild = pnRChild;
}

static void destroy(struct SNode * this) {

    this->m_lValue = 0;

    this->m_pnParent = NULL;
    this->m_pnLChild = NULL;
    this->m_pnRChild = NULL;

    this->m_lGetValue = NULL;
    this->m_pnGetParent = NULL;
    this->m_pnGetLChild = NULL;
    this->m_pnGetRChild = NULL;

    this->m_setValue = NULL;
    this->m_setParent = NULL;
    this->m_setLChild = NULL;
    this->m_setRChild = NULL;

    this->m_destroy = NULL;
    this->m_construct = NULL;
}

static void construct(struct SNode * this) {

    this->m_lValue = 0;

    this->m_pnParent = NULL;
    this->m_pnLChild = NULL;
    this->m_pnRChild = NULL;

    this->m_lGetValue = lGetValue;
    this->m_pnGetParent = pnGetParent;
    this->m_pnGetLChild = pnGetLChild;
    this->m_pnGetRChild = pnGetRChild;

    this->m_setValue = setValue;
    this->m_setParent = setParent;
    this->m_setLChild = setLChild;
    this->m_setRChild = setRChild;

    this->m_destroy = destroy;
    this->m_construct = construct;
}

struct SNode nNewNode() {

    struct SNode n;

    construct(&n);

    return n;
}
