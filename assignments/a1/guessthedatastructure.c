#include <stdio.h>
#include <stdlib.h>

int main() {
    int *stack = malloc(1000*sizeof(int));
    int *queue = malloc(1000*sizeof(int));
    int *heap = malloc(1001*sizeof(int));
    int stack_ptr, queue_hd, queue_tl, heap_ptr;

    int num_lines, is_stack, is_queue, is_heap;
    while(scanf("%d", &num_lines) != EOF) {

        stack_ptr = queue_hd = queue_tl = 0;
        heap_ptr = 1;

        is_stack = is_queue = is_heap = 1;

        int type, val;
        for (int i=0; i<num_lines; ++i) {
            scanf("%d %d", &type, &val);

            if (type == 1) {
                if (is_stack) {
                    stack[stack_ptr++] = val;
                }
                if (is_queue) {
                    queue[queue_tl++] = val;
                }
                if (is_heap) {
                    heap[heap_ptr] = val;
                    int j = heap_ptr++;

                    /* swim the new element up the heap */
                    while (j > 1) {
                        if (heap[j] > heap[j/2]) {
                            int temp = heap[j];
                            heap[j] = heap[j/2];
                            heap[j/2] = temp;
                            j = j/2;
                        } else {
                            break;
                        }
                    }

                }
            } else {
                /* type == 2 */
                if ((is_stack && stack_ptr == 0) || val != stack[--stack_ptr]) {
                    is_stack = 0;
                }
                if ((is_queue && queue_hd == queue_tl) || val != queue[queue_hd++]) {
                    is_queue = 0;
                }
                if (heap_ptr == 1) {
                    /* heap is empty */
                    is_heap = 0;
                } else {
                    if (is_heap) {
                        if (val == heap[1]) {
                            heap[1] = heap[--heap_ptr];
                            int j = 1;

                            /* sink the root down the heap */
                            while (j*2 < heap_ptr) {
                                int max;
                                if (j*2+1 < heap_ptr) {
                                    max = (heap[j*2] > heap[j*2+1]) ? j*2 : j*2+1;
                                } else {
                                    max = j*2;
                                }
                                if (heap[j] < heap[max]) {
                                    int temp = heap[j];
                                    heap[j] = heap[max];
                                    heap[max] = temp;
                                    j = max;
                                } else {
                                    break;
                                }
                            }
                        } else {
                            is_heap = 0;
                        }
                    }
                }
            }
        }

        int sum = is_stack + is_heap + is_queue;
        if (sum > 1) {
            printf("not sure\n");
        } else if (sum == 0) {
            printf("impossible\n");
        } else {
            if (is_stack) {
                printf("stack\n");
            }
            if (is_queue) {
                printf("queue\n");
            }
            if (is_heap) {
                printf("priority queue\n");
            }
        }
    }
}
