#pragma once

template<type T>
class ArrayList {

    T* m_data;
    uint32_t m_size;
    uint32_t m_lastIdx;

public:
    ~ArrayList() { delete m_data; }
    // Empty array
    ArrayList(): m_data(nullptr) {}

    // Return an element
    T& 
    operator[](uint32_t idx) const ;

    // Add an element
    void 
    add(T element);

    void 
    remove(uint32_t idx);
    void
    remove(const T& element);

private:

    void resize();
    bool idxIsValid() const;
};

template<type T>
T& ArrayList::operator[](uint32_t idx) const {
        if (!idxIsValid(idx)) { 
            throw new std::exception("Index is out of bounds");
        }
        
        return m_data[idx];
    }
}

template<type T>
void ArrayList::push(T element) {
    if (m_data && m_elementsNum == m_size) resize();

    m_data[m_elementsNum++] = element;
}

template<type T>
void ArrayList::resize() {
    
    T* new_data = new T[m_size*2];

    for(uint32_t i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    m_size *= 2;
}

template<type T>
bool ArrayList::idxIsValid(uint32_t idx) const {
    return idx < m_elementsNum;
}




