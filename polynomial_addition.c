#include <stdio.h>
#include <stdlib.h>

struct polynomial{
    int coeff;
    int exp;
    struct polynomial *nextTerm;
};

struct polynomial *phead,*qhead,*rhead;

void read_polynomial(struct polynomial *poly) {
    struct polynomial *p = phead;
    struct polynomial *term = (struct polynomial*) malloc(sizeof(struct polynomial));

    int no_of_terms,coeff,exp;
    printf("enter the no of terms\n");
    scanf("%d", &no_of_terms);

    for (int i = 1; i <= no_of_terms; i++) {
        printf("enter the coefficient of the %d term\n",i);
        scanf("%d", &coeff);
        printf("enter the exponent of the %d term\n",i);
        scanf("%d", &exp);

        term->coeff = coeff;
        term->exp = exp;
        p->nextTerm = term;
        p=p->nextTerm;
    }
}

void display_polynomial(struct polynomial *poly) {
    struct polynomial *p = phead;

    while (p!=NULL) {
        printf("%dx^%d + ", p->coeff, p->exp);
        p=p->nextTerm;
    }
}

void add_polynomial(struct polynomial *p, struct polynomial *q) {
    int NoOfTermsPoly1,NoOfTermsPoly2,Maxterms,i;

    struct polynomial *r = rhead;
    struct polynomial *p = phead;
    struct polynomial *q = qhead;

    struct polynomial *p = phead;
    struct polynomial *q = qhead;

    while (p!=NULL) {
        NoOfTermsPoly1++;
        p=p->nextTerm;
    }
    while (q!=NULL) {
        NoOfTermsPoly2++;
        q=q->nextTerm;
    }
    Maxterms = NoOfTermsPoly1>NoOfTermsPoly2?NoOfTermsPoly1:NoOfTermsPoly2;

    p=phead;
    q=qhead;

    for (i=0;i<Maxterms;i++) {
        if (p->exp==q->exp) {
            r->exp=p->exp;
            r->coeff = p->coeff+q->coeff;
        }
        else if(p->exp>q->exp) {
            r->exp=p->exp;
            r->coeff = p->coeff;
        }
        else {
            r->exp=q->exp;
            r->coeff = q->coeff;
        }
    }
}