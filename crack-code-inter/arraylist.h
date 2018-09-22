#pragma once
//#include <exception>

namespace {
constexpr size_t INITIAL_SIZE = 10;
}

/**
 TODO add shrinking when memory is not used
*/
template<typename T>
class ArrayList {

    T* m_data = nullptr;
    size_t m_dataSize = 0;
    size_t m_elementsNum = 0;

public:

    ~ArrayList() { 
        std::cout << "~ArrayList()\n";
        delete[] m_data; 
    }


    // Empty array
    ArrayList() {
        std::cout << "Created new ArrayList()\n";
    }

    ArrayList(ArrayList&& rhv) {
        m_data =  rhv.m_data;
        rhv.m_data = nullptr;;
        m_dataSize = rhv.m_dataSize;
        m_elementsNum = rhv.m_elementsNum;
    }

    // TODO can it be optimized?
    ArrayList(const ArrayList& rhv) {
        m_data = new T[rhv.m_dataSize];
        m_dataSize = rhv.m_dataSize;
        m_elementsNum = rhv.m_elementsNum;

        for (size_t i = 0; i < m_dataSize; ++i) {
            m_data[i] = rhv.m_data[i];
        }
    }

    ArrayList& operator=(const ArrayList& rhv) {
        m_data = new T[rhv.m_dataSize];
        m_dataSize = rhv.m_dataSize;
        m_elementsNum = rhv.m_elementsNum;

        for (size_t i = 0; i < m_dataSize; ++i) {
            m_data[i] = rhv.m_data[i];
        }
        return *this;
    }
    
    ArrayList& operator=(ArrayList&& rhv) {
        m_data =  rhv.m_data;
        rhv.m_data = nullptr;;
        m_dataSize = rhv.m_dataSize;
        m_elementsNum = rhv.m_elementsNum;
        return *this;
    }
    // Return an element
    T& 
    operator[](size_t idx) const ;

    // Add an element
    void 
    add(const T& element);
    // Add an element
    void 
    add(T&& element);

    T& 
    get(size_t idx) const;

    void 
    remove(size_t idx);

    /* Not implemented yet 
    void
    remove(const T& element);
    */
    size_t size() const { return m_elementsNum; }
private:

    void resize();
    bool idxIsValid(size_t idx) const;
    void assertIdxIsValid(size_t idx) const;
};

// ---------------------
// Consider moving to tpp

template <class T>
void  ArrayList<T>::assertIdxIsValid(size_t idx) const {
    if (!idxIsValid(idx))  std::runtime_error("Index is out of bounds");
}

template<class T>
bool ArrayList<T>::idxIsValid(size_t idx) const {
    return idx >= 0 && idx < m_elementsNum;
}

template<typename T>
void ArrayList<T>::add(const T& element) {
    if (nullptr == m_data || m_elementsNum == m_dataSize) {
        resize();
    }

    m_data[m_elementsNum++] = element;
}

template<typename T>
void ArrayList<T>::add(T&& element) {
    if (nullptr == m_data || m_elementsNum == m_dataSize) {
        resize();
    }

    m_data[m_elementsNum++] = std::move(element);
}

template <typename T>
void ArrayList<T>::remove(size_t idx) {
    assertIdxIsValid(idx);

    for(size_t i = idx; i < m_elementsNum - 1; ++i) {
        m_data[i] = m_data[i+1];
    }
    --m_elementsNum;
}

template<typename T>
T& ArrayList<T>::operator[](size_t idx) const {
    assertIdxIsValid(idx);

    return m_data[idx];
}

template <class T>
T& ArrayList<T>::get(size_t idx) const {
    return (*this)[idx]; 
}

template<class T>
void ArrayList<T>::resize() {
   
    size_t newSize = m_data == nullptr ? INITIAL_SIZE :  m_dataSize * 2;
    T* new_data = new T[newSize];

    for(size_t i = 0; i < m_dataSize; ++i) {
        new_data[i] = m_data[i];
    }

    delete[] m_data;
    m_data = new_data;
    m_dataSize = newSize;
}

