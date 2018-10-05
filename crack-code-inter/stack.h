#pragma once
#include <exception>

template <class T>
class StackNode {
public:
    StackNode<T>* m_next = nullptr;
    StackNode<T>* m_nextMin = nullptr;
    T m_data;
};


template <class T>
class Stack {
public:
    Stack() = default;
    ~Stack() {
        auto node = m_top;
        auto next = node;
        while(node != nullptr) {
            next = node->m_next;
            delete node;
            node = next;
        }
    }

    void push(const T& item);
    T&& pop();
    T& peek() const ;
    size_t size() const ;
    void print() const ;
    T& min() const ;

private:
    void assertNonEmpty() const {
        if (m_size == 0) {
            throw new std::runtime_error("Stack is empty");
        }
    }

private:
    StackNode<T>* m_top = nullptr;
    size_t m_size = 0;
};

template <class T>
void Stack<T>::push(const T& item) {
    StackNode<T>* newNode = new StackNode<T>;

    newNode->m_data = item;
    newNode->m_next = m_top;
    newNode->m_nextMin = 
            (m_top == nullptr || item <= m_top->m_nextMin->m_data) ? 
                newNode : m_top->m_nextMin;

    m_top = newNode;
    ++m_size;
}

template <class T>
T&& Stack<T>::pop() {
    assertNonEmpty();

    auto oldTop = m_top;
    T&& data = std::move(oldTop->m_data);    
    m_top = oldTop->m_next;
    --m_size;
    delete oldTop;
    return std::move(data);
}

template <class T>
T& Stack<T>::peek() const {
    assertNonEmpty();
    return m_top->m_data;
}

template <class T> 
size_t Stack<T>::size() const {
    return m_size;
}

template <class T>
T& Stack<T>::min() const {
    assertNonEmpty();
    return m_top->m_nextMin;
}

template <class T>
void Stack<T>::print() const {

    if (m_size == 0) {
        cout << "empty stack\n";
        return;
    }

    StackNode<T>* node = m_top;
    while(node != nullptr) {
        cout << node->m_data << " <- ";
        node = node->m_next;
    }
    cout << "Bottom; Size = " << m_size << " Min = " << m_top->m_nextMin->m_data << endl;
}
