#include "common.h"
#include "my_data_struct.h"

template<class T>
ListNode<T>* partition(ListNode<T>* head, const T& pivotValue) {
    ListNode<T>* node = head, *prev, * next;
    bool hasReachedPivot = false;
    while(node != nullptr) {
        next = node->m_next;
        if(node->m_data < pivotValue) {
            if (hasReachedPivot && node != head) {
                // move node before head
                prev->m_next = next;           
                node->m_next = head;
                head = node;
            }
        } else {
            hasReachedPivot = true;
        }

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
