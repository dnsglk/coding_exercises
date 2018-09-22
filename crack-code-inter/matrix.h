#include <iostream>

#include "arraylist.h"

template <class T>
using Matrix=ArrayList<ArrayList<T>>;

template <class T> 
Matrix<T> createMatrix(size_t width, size_t height) {
    Matrix<T> m_matrix;

    size_t i = 0;
    while(i != width) {
        m_matrix.add(move(ArrayList<T>()));
        for (size_t j = 0; j < height; ++j) {
            m_matrix[i].add(T());
        }
        ++i;
    }
    return m_matrix;
}

template <class T> 
Matrix<T> createMatrix(size_t width) {
    return createMatrix<T>(width,width);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& M) {
    for(uint32_t i = 0; i < M.size(); ++i) {
        for(uint32_t j = 0; j < M[i].size(); ++j) {
            os << M[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
