#include <stdio.h>
#include "circular_queue.h"

boolean CQIsEmpty (CQueue Q) {
    return (CQIDX_HEAD(Q) == IDX_UNDEF) && (CQIDX_TAIL(Q) == IDX_UNDEF);
}

boolean CQIsFull (CQueue Q) {
    if (CQIDX_HEAD(Q) > CQIDX_TAIL(Q)) {
        return CQIDX_HEAD(Q) - CQIDX_TAIL(Q) == 1;
    } else {
        return CQIDX_HEAD(Q) == 0 && CQIDX_TAIL(Q) == IDX_MAX; 
    }
}

int CQLength (CQueue Q) {
    if (CQIsEmpty(Q)) {
        return 0;
    } else if (CQIDX_HEAD(Q) > CQIDX_TAIL(Q)) {
        return IDX_MAX - CQIDX_HEAD(Q) + CQIDX_TAIL(Q) + 2;
    } else {
        return CQIDX_TAIL(Q) - CQIDX_HEAD(Q) + 1;
    }
}

void CreateCCQueue (CQueue * Q) {
    CQIDX_HEAD(*Q) = IDX_UNDEF;
    CQIDX_TAIL(*Q) = IDX_UNDEF;
}

void CQenCqueue (CQueue * Q, ElType X) {
    if (CQIsEmpty(*Q)) {
        CQIDX_HEAD(*Q) = 0;
        CQIDX_TAIL(*Q) = 0;
    } else {
        if (CQIDX_TAIL(*Q) == IDX_MAX) {
            CQIDX_TAIL(*Q) = 0;
        } else {
            CQIDX_TAIL(*Q)++;
        }
    }
    CQTAIL(*Q) = X;
}

ElType CQdeCqueue (CQueue * Q) {
    ElType X = CQHEAD(*Q);
    if (CQIDX_HEAD(*Q) == CQIDX_TAIL(*Q)) {
        CQIDX_HEAD(*Q) = IDX_UNDEF;
        CQIDX_TAIL(*Q) = IDX_UNDEF;
    } else {
        if (CQIDX_HEAD(*Q) == IDX_MAX) {
            CQIDX_HEAD(*Q) = 0;
        } else {
            CQIDX_HEAD(*Q)++;
        }
    }
    return X;
}

void displayCCQueue (CQueue Q) {
    if (CQIsEmpty(Q)) {
        printf("[]\n");
    } else {
        int i = CQIDX_HEAD(Q);
        printf("[");
        while (i != CQIDX_TAIL(Q)) {
            printf("%d,", Q.Tab[i]);
            if (i == IDX_MAX) {
                i = 0;
            } else {
                i++;
            }
        }
        printf("%d]\n", Q.Tab[i]);
    }
}