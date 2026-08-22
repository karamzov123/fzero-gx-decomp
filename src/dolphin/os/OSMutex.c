extern void OSWakeupThread(register void* queue);

typedef struct OSThreadQueue {
    void* head;
    void* tail;
} OSThreadQueue;

typedef struct OSMutex {
    OSThreadQueue queue;          /* 0x00 */
    void* thread;                 /* 0x08 */
    int count;                    /* 0x0C */
    struct OSMutex* next;         /* 0x10 link.next */
    struct OSMutex* prev;         /* 0x14 link.prev */
} OSMutex;

typedef struct OSMutexQueue {
    OSMutex* head;
    OSMutex* tail;
} OSMutexQueue;

typedef struct OSThread {
    unsigned char pad[0x2F4];
    OSMutexQueue queueMutex;      /* 0x2F4 */
} OSThread;

void __OSUnlockAllMutex(OSThread* thread)
{
    OSMutex* mutex;

    while (thread->queueMutex.head) {
        OSMutex* next;

        mutex = thread->queueMutex.head;
        next = mutex->next;
        if (next == 0) {
            thread->queueMutex.tail = 0;
        } else {
            next->prev = 0;
        }
        thread->queueMutex.head = next;
        mutex->count = 0;
        mutex->thread = 0;
        OSWakeupThread(&mutex->queue);
    }
}
