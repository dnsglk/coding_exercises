#pragma once

template<class T>
class ListNode {
public:
    ListNode(){}
    ListNode(T data) : m_data(data) {}

    ListNode* m_next = nullptr;
    T m_data;
};

template<class T>
void printList(ListNode<T>& head) {
    auto node = &head;
    while(node != nullptr) {
        cout << node->m_data << " -> ";
        node = node->m_next;
    }   
    
    cout << "END\n";
}

template<class T>
void freeList(ListNode<T>* head) {
    ListNode<T>* next;
    while (head != nullptr) {
        next = head->m_next;
        delete head;
        head = next;
    }
}
