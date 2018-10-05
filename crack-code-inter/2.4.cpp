#include "common.h"
#include "my_data_struct.h"

template<class T>
ListNode<T>* partition(ListNode<T>* head, const T& pivotValue) {
    ListNode<T>* node = head, *prev, * next;
    bool hasReachedPivot = false;

    // for each value less than pivot, move it before current head.
    while(node != nullptr) {

        next = node->m_next;

        if(node->m_data < pivotValue) {
            // skip all values that we shouldn't move to the start
            if (hasReachedPivot && node != head) {
                // move node before head
                prev->m_next = next;           
                node->m_next = head;
                head = node;
            }
        } else {
            hasReachedPivot = true;
        }

        // if move was performed do not change prev value
        prev = head == node ? prev :  node;
        node = next;
    }

    return head;
} 

int main(int argc, char** argv) {

    ListNode<uint32_t> *head, *prev, *node;
    uint32_t arr[] = { 3,5,8,5,10,2,1,6 };
    for  (uint32_t i = 0 ; i < sizeof(arr)/sizeof(uint32_t); ++i) {
        node  = new ListNode<uint32_t> (arr[i]);
        if (i == 0) {      
            head = node;
        } else {
            prev->m_next = node;
        }
        prev = node;
    }

    printList(*head);
    head = partition(head, 5u);
    printList(*head);
    
    freeList(head);

    return 0;
}
