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
void free(ListNode<T>* head) {
    ListNode<T>* next;
    while (head != nullptr) {
        next = head->m_next;
        delete head;
        head = next;
    }
}

template <class T>
size_t size(const ListNode<T>& head) {
    size_t size = 0;

    auto node = &head;
    while(node != nullptr) {
        ++size;
        node = node->m_next;
    }

    return size;
}

template<class T>
void print(ListNode<T>& head) {
    auto node = &head;
    while(node != nullptr) {
        cout << node->m_data << " -> ";
        node = node->m_next;
    }   
    
    cout << "END , size = " << size(head) << endl;
}
