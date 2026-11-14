#include "types.h"

typedef struct DVDCommandBlock {
    struct DVDCommandBlock *next;
    struct DVDCommandBlock *prev;
} DVDCommandBlock;

typedef struct DVDWaitingQueue {
    DVDCommandBlock head;
    DVDCommandBlock block1;
    DVDCommandBlock block2;
    DVDCommandBlock block3;
} DVDWaitingQueue;

extern DVDWaitingQueue WaitingQueue;

void __DVDClearWaitingQueue(void) {
    DVDCommandBlock *queue = &WaitingQueue.head;
    DVDCommandBlock *block2 = &WaitingQueue.block2;
    DVDCommandBlock *block1 = &WaitingQueue.block1;
    DVDCommandBlock *block3 = &WaitingQueue.block3;

    queue->next = queue;
    queue->prev = queue;
    block1->next = block1;
    block1->prev = block1;
    block2->next = block2;
    block2->prev = block2;
    block3->next = block3;
    block3->prev = block3;
}
