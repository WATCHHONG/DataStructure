
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q_SIZE   4          /* 순차 큐 / 원형 큐 배열 크기 */
#define CQ_SIZE  4          /* 원형 큐 배열 크기           */

typedef char element;       /* 큐 원소 자료형 */


/* 순차 큐 구조체 */
typedef struct {
    element queue[Q_SIZE];
    int front, rear;
} SeqQueue;

/* 공백 순차 큐 생성 */
SeqQueue* createQueue(void) {
    SeqQueue* Q = (SeqQueue*)malloc(sizeof(SeqQueue));
    Q->front = -1;
    Q->rear  = -1;
    return Q;
}

/* 공백 상태 검사 */
int isQueueEmpty(SeqQueue* Q) {
    if (Q->front == Q->rear) {
        printf(" Queue is empty!\n\t");
        return 1;
    }
    return 0;
}

/* 포화 상태 검사 */
int isQueueFull(SeqQueue* Q) {
    if (Q->rear == Q_SIZE - 1) {
        printf(" Queue is full!\n\t");
        return 1;
    }
    return 0;
}

/* 원소 삽입 (enQueue) */
void enQueue(SeqQueue* Q, element item) {
    if (isQueueFull(Q)) return;
    Q->rear++;
    Q->queue[Q->rear] = item;
}

/* 원소 삭제 (deQueue) */
element deQueue(SeqQueue* Q) {
    if (isQueueEmpty(Q)) return '\0';
    Q->front++;
    return Q->queue[Q->front];
}

/* front 원소 검색 (peek) */
element peekQ(SeqQueue* Q) {
    if (isQueueEmpty(Q)) return '\0';
    return Q->queue[Q->front + 1];
}

/* 큐 출력 */
void printQ(SeqQueue* Q) {
    printf(" Queue : [");
    for (int i = Q->front + 1; i <= Q->rear; i++)
        printf("%3c", Q->queue[i]);
    printf(" ]");
}

/* 예제 6-1 실행 함수 */
void run_ex1(void) {
    printf("\n\n========================================\n");
    printf("  [예제 6-1] 순차 큐 연산\n");
    printf("========================================\n");

    SeqQueue* Q1 = createQueue();
    element data;

    printf("\n 삽입 A>>");  enQueue(Q1, 'A');  printQ(Q1);
    printf("\n 삽입 B>>");  enQueue(Q1, 'B');  printQ(Q1);
    printf("\n 삽입 C>>");  enQueue(Q1, 'C');  printQ(Q1);

    data = peekQ(Q1);
    printf("  peek item : %c\n", data);

    printf("\n 삭제  >>");
    data = deQueue(Q1);  printQ(Q1);
    printf("\t삭제 데이터 : %c", data);

    printf("\n 삭제  >>");
    data = deQueue(Q1);  printQ(Q1);
    printf("\t삭제 데이터 : %c", data);

    printf("\n 삭제  >>");
    data = deQueue(Q1);  printQ(Q1);
    printf("\t\t삭제 데이터 : %c", data);

    printf("\n 삽입 D>>");  enQueue(Q1, 'D');  printQ(Q1);
    printf("\n 삽입 E>>");  enQueue(Q1, 'E');  printQ(Q1);

    free(Q1);
    printf("\n");
}


/* 원형 큐 구조체 */
typedef struct {
    element queue[CQ_SIZE];
    int front, rear;
} CircQueue;

/* 공백 원형 큐 생성 */
CircQueue* createCQueue(void) {
    CircQueue* cQ = (CircQueue*)malloc(sizeof(CircQueue));
    cQ->front = 0;
    cQ->rear  = 0;
    return cQ;
}

/* 공백 상태 검사 */
int isCQueueEmpty(CircQueue* cQ) {
    if (cQ->front == cQ->rear) {
        printf(" Circular Queue is empty! ");
        return 1;
    }
    return 0;
}

/* 포화 상태 검사 */
int isCQueueFull(CircQueue* cQ) {
    if (((cQ->rear + 1) % CQ_SIZE) == cQ->front) {
        printf(" Circular Queue is full! ");
        return 1;
    }
    return 0;
}

/* 원소 삽입 */
void enCQueue(CircQueue* cQ, element item) {
    if (isCQueueFull(cQ)) return;
    cQ->rear = (cQ->rear + 1) % CQ_SIZE;
    cQ->queue[cQ->rear] = item;
}

/* 원소 삭제 */
element deCQueue(CircQueue* cQ) {
    if (isCQueueEmpty(cQ)) return '\0';
    cQ->front = (cQ->front + 1) % CQ_SIZE;
    return cQ->queue[cQ->front];
}

/* front 원소 검색 */
element peekCQ(CircQueue* cQ) {
    if (isCQueueEmpty(cQ)) return '\0';
    return cQ->queue[(cQ->front + 1) % CQ_SIZE];
}

/* 원형 큐 출력 */
void printCQ(CircQueue* cQ) {
    int first = (cQ->front + 1) % CQ_SIZE;
    int last  = (cQ->rear  + 1) % CQ_SIZE;
    printf(" Circular Queue : [");
    int i = first;
    while (i != last) {
        printf("%3c", cQ->queue[i]);
        i = (i + 1) % CQ_SIZE;
    }
    printf(" ]");
}

/* 예제 6-2 실행 함수 */
void run_ex2(void) {
    printf("\n\n========================================\n");
    printf("  [예제 6-2] 원형 큐 연산\n");
    printf("========================================\n");

    CircQueue* cQ = createCQueue();
    element data;

    printf("\n 삽입 A>>");  enCQueue(cQ, 'A');  printCQ(cQ);
    printf("\n 삽입 B>>");  enCQueue(cQ, 'B');  printCQ(cQ);
    printf("\n 삽입 C>>");  enCQueue(cQ, 'C');  printCQ(cQ);

    data = peekCQ(cQ);
    printf("  peek item : %c\n", data);

    printf("\n 삭제  >>");
    data = deCQueue(cQ);  printCQ(cQ);
    printf("\t삭제 데이터 : %c", data);

    printf("\n 삭제  >>");
    data = deCQueue(cQ);  printCQ(cQ);
    printf("\t삭제 데이터 : %c", data);

    printf("\n 삭제  >>");
    data = deCQueue(cQ);  printCQ(cQ);
    printf("\t\t삭제 데이터 : %c", data);

    printf("\n 삽입 D>>");  enCQueue(cQ, 'D');  printCQ(cQ);
    printf("\n 삽입 E>>");  enCQueue(cQ, 'E');  printCQ(cQ);

    free(cQ);
    printf("\n");
}


/* ============================================================
 *  [예제 6-3]  연결 큐 (Linked Queue)
 * ============================================================ */

/* 연결 큐 노드 */
typedef struct LQNode {
    element         data;
    struct LQNode*  link;
} LQNode;

/* 연결 큐 헤더 (front / rear 포인터 묶음) */
typedef struct {
    LQNode* front;
    LQNode* rear;
} LinkedQueue;

/* 공백 연결 큐 생성 */
LinkedQueue* createLinkedQueue(void) {
    LinkedQueue* LQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    LQ->front = NULL;
    LQ->rear  = NULL;
    return LQ;
}

/* 공백 상태 검사 */
int isLQEmpty(LinkedQueue* LQ) {
    if (LQ->front == NULL) {
        printf(" Linked Queue is empty! ");
        return 1;
    }
    return 0;
}

/* 원소 삽입 */
void enLQueue(LinkedQueue* LQ, element item) {
    LQNode* newNode = (LQNode*)malloc(sizeof(LQNode));
    newNode->data = item;
    newNode->link = NULL;

    if (LQ->front == NULL) {          /* 공백 큐인 경우 */
        LQ->rear  = newNode;
        LQ->front = newNode;
    } else {                           /* 노드가 있는 경우 */
        LQ->rear->link = newNode;
        LQ->rear       = newNode;
    }
}

/* 원소 삭제 */
element deLQueue(LinkedQueue* LQ) {
    if (isLQEmpty(LQ)) return '\0';

    LQNode* old  = LQ->front;
    element item = old->data;

    LQ->front = LQ->front->link;     /* front를 다음 노드로 이동 */
    if (LQ->front == NULL)           /* 공백 큐가 된 경우        */
        LQ->rear = NULL;

    free(old);
    return item;
}

/* front 원소 검색 */
element peekLQ(LinkedQueue* LQ) {
    if (isLQEmpty(LQ)) return '\0';
    return LQ->front->data;
}

/* 연결 큐 출력 */
void printLQ(LinkedQueue* LQ) {
    printf(" Linked Queue : [");
    LQNode* p = LQ->front;
    while (p != NULL) {
        printf("%3c", p->data);
        p = p->link;
    }
    printf(" ]");
}

/* 예제 6-3 실행 함수 */
void run_ex3(void) {
    printf("\n\n========================================\n");
    printf("  [예제 6-3] 연결 큐 연산\n");
    printf("========================================\n");

    LinkedQueue* LQ = createLinkedQueue();
    element data;

    printf("\n 삽입 A>>");  enLQueue(LQ, 'A');  printLQ(LQ);
    printf("\n 삽입 B>>");  enLQueue(LQ, 'B');  printLQ(LQ);
    printf("\n 삽입 C>>");  enLQueue(LQ, 'C');  printLQ(LQ);

    data = peekLQ(LQ);
    printf("    peek item : %c\n", data);

    printf("\n 삭제  >>");
    data = deLQueue(LQ);  printLQ(LQ);
    printf("\t삭제 데이터 : %c", data);

    printf("\n 삭제  >>");
    data = deLQueue(LQ);  printLQ(LQ);
    printf("\t삭제 데이터 : %c", data);

    printf("\n 삭제  >>");
    data = deLQueue(LQ);  printLQ(LQ);
    printf("\t\t삭제 데이터 : %c", data);

    printf("\n 삽입 D>>");  enLQueue(LQ, 'D');  printLQ(LQ);
    printf("\n 삽입 E>>");  enLQueue(LQ, 'E');  printLQ(LQ);

    free(LQ);
    printf("\n");
}


/* 이중 연결 리스트 노드 */
typedef struct DQNode {
    element         data;
    struct DQNode*  llink;   /* 이전 노드 */
    struct DQNode*  rlink;   /* 다음 노드 */
} DQNode;

/* 데크 헤더 */
typedef struct {
    DQNode* front;
    DQNode* rear;
} Deque;

/* 공백 데크 생성 */
Deque* createDeque(void) {
    Deque* DQ = (Deque*)malloc(sizeof(Deque));
    DQ->front = NULL;
    DQ->rear  = NULL;
    return DQ;
}

/* 공백 상태 검사 */
int isDeQEmpty(Deque* DQ) {
    if (DQ->front == NULL) return 1;
    return 0;
}

/* front 앞에 삽입 */
void insertFront(Deque* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data  = item;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (isDeQEmpty(DQ)) {
        DQ->front = newNode;
        DQ->rear  = newNode;
    } else {
        newNode->rlink  = DQ->front;   /* 새 노드 → 기존 front */
        DQ->front->llink = newNode;    /* 기존 front ← 새 노드 */
        DQ->front        = newNode;    /* front 갱신            */
    }
}

/* rear 뒤에 삽입 */
void insertRear(Deque* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data  = item;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (isDeQEmpty(DQ)) {
        DQ->front = newNode;
        DQ->rear  = newNode;
    } else {
        newNode->llink  = DQ->rear;    /* 새 노드 ← 기존 rear */
        DQ->rear->rlink = newNode;     /* 기존 rear → 새 노드 */
        DQ->rear         = newNode;    /* rear 갱신            */
    }
}

/* front 삭제 */
element deleteFront(Deque* DQ) {
    if (isDeQEmpty(DQ)) { printf(" Deque is empty!\n"); return '\0'; }

    DQNode* old  = DQ->front;
    element item = old->data;

    DQ->front = DQ->front->rlink;
    if (DQ->front == NULL)
        DQ->rear = NULL;
    else
        DQ->front->llink = NULL;

    free(old);
    return item;
}

/* rear 삭제 */
element deleteRear(Deque* DQ) {
    if (isDeQEmpty(DQ)) { printf(" Deque is empty!\n"); return '\0'; }

    DQNode* old  = DQ->rear;
    element item = old->data;

    DQ->rear = DQ->rear->llink;
    if (DQ->rear == NULL)
        DQ->front = NULL;
    else
        DQ->rear->rlink = NULL;

    free(old);
    return item;
}

/* front 원소 반환 */
element getFront(Deque* DQ) {
    if (isDeQEmpty(DQ)) return '\0';
    return DQ->front->data;
}

/* rear 원소 반환 */
element getRear(Deque* DQ) {
    if (isDeQEmpty(DQ)) return '\0';
    return DQ->rear->data;
}

/* 데크 출력 */
void printDQ(Deque* DQ) {
    printf(" DeQue : [");
    DQNode* p = DQ->front;
    while (p != NULL) {
        printf("%3c", p->data);
        p = p->rlink;
    }
    printf(" ]");
}

/* 예제 6-4 실행 함수 */
void run_ex4(void) {
    printf("\n\n========================================\n");
    printf("  [예제 6-4] 데크 연산\n");
    printf("========================================\n");

    Deque* DQ = createDeque();
    element data;

    /* front 삽입 A */
    printf("\n front 삽입 A>>");
    insertFront(DQ, 'A');  printDQ(DQ);

    /* front 삽입 B */
    printf("\n front 삽입 B>>");
    insertFront(DQ, 'B');  printDQ(DQ);

    /* rear 삽입 C */
    printf("\n rear  삽입 C>>");
    insertRear(DQ, 'C');   printDQ(DQ);

    /* front 삭제 */
    printf("\n front 삭제  >>");
    data = deleteFront(DQ);  printDQ(DQ);
    printf("\t삭제 데이터 : %c", data);

    /* rear 삭제 */
    printf("\n rear  삭제  >>");
    data = deleteRear(DQ);   printDQ(DQ);
    printf("\t삭제 데이터 : %c", data);

    /* rear 삽입 D */
    printf("\n rear  삽입 D>>");
    insertRear(DQ, 'D');   printDQ(DQ);

    /* front 삽입 E */
    printf("\n front 삽입 E>>");
    insertFront(DQ, 'E');  printDQ(DQ);

    /* front 삽입 F */
    printf("\n front 삽입 F>>");
    insertFront(DQ, 'F');  printDQ(DQ);

    printf("\n peek Front item : %c", getFront(DQ));
    printf("\n peek Rear  item : %c", getRear(DQ));

    /* 메모리 해제 */
    while (!isDeQEmpty(DQ)) deleteFront(DQ);
    free(DQ);
    printf("\n");
}


int main(void) {
    run_ex1();   /* 순차 큐   */
    run_ex2();   /* 원형 큐   */
    run_ex3();   /* 연결 큐   */
    run_ex4();   /* 데크      */

    printf("\n");
    return 0;
}
