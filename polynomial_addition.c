#include <stdio.h>
#include <stdlib.h>

struct polynomial{
    int coeff;
    int exp;
    struct polynomial *nextTerm;
};

struct polynomial *phead,*qhead,*rhead;

void read_polynomial(struct polynomial *poly) {
    poly = phead;
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
        poly->nextTerm = term;
        poly=term;
    }
}

void display_polynomial(struct polynomial *poly) {
    poly = phead;

    while (poly!=NULL) {
        printf("%dx^%d + ", poly->coeff, poly->exp);
        poly=poly->nextTerm;
    }
}

void add_polynomial(struct polynomial *p1, struct polynomial *q1) {
    int NoOfTermsPoly1,NoOfTermsPoly2,Maxterms,i;

    struct polynomial *r = rhead;
    p1 = phead;
    q1 = qhead;

    while (p1!=NULL) {
        NoOfTermsPoly1++;
        p1=p1->nextTerm;
    }
    while (q1!=NULL) {
        NoOfTermsPoly2++;
        q1=q1->nextTerm;
    }
    Maxterms = NoOfTermsPoly1>NoOfTermsPoly2?NoOfTermsPoly1:NoOfTermsPoly2;

    p1=phead;
    q1=qhead;

    for (i=0;i<Maxterms;i++) {
        if (p1->exp==q1->exp) {
            r->exp=p1->exp;
            r->coeff = p1->coeff+q1->coeff;
        }
        else if(p1->exp>q1->exp) {
            r->exp=p1->exp;
            r->coeff = p1->coeff;
        }
        else {
            r->exp=q1->exp;
            r->coeff = q1->coeff;
        }
    }
}

void main(){
    int i;
    printf("enter the first polynomial\n");
    read_polynomial(phead);
    printf("enter the second polynomial\n");
    read_polynomial(qhead);
    printf("\n\nthe first polynomial is\n");
    display_polynomial(phead);
    printf("\nthe second polynomial is\n");
    display_polynomial(qhead);
    add_polynomial(phead,qhead);
    printf("\n\nthe resultant polynomial is\n");
    display_polynomial(rhead);
}