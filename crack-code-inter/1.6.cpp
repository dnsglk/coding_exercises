#include "common.h"
#include "my_data_struct.h"
 
template <class T>
void rotateMatrix(Matrix<T>& M) {
    size_t matrixWidth = M.size() - 1;
    size_t layerWidth = M.size()/2;
    for (size_t i = 0 ; i < layerWidth; ++i) {
        for(size_t j = i; j < matrixWidth - i  ; ++j) {
            T& topLeft = M[i][j];
            T& botLeft = M[matrixWidth - j][i];
            T& botRigh = M[matrixWidth - i][matrixWidth - j];
            T& topRigh = M[j][matrixWidth - i];

            T tmp = topLeft;
            topLeft = botLeft;
            botLeft = botRigh;
            botRigh = topRigh;
            topRigh = tmp;
        }
    }
}

int main(int argc, char** argv) {
    
    size_t matrixSize = 6;
    if (argc == 2) {
        matrixSize = atoi(argv[1]);
    }

    Matrix<string> M = createMatrix<string>(matrixSize);
    ss s;
    for(unsigned i = 0; i < matrixSize; ++i) {
        for (unsigned j = 0; j < matrixSize; ++j) {
            s << (char)('a' + i) << j;
            M[i][j] = s.str();
            s.str("");
        }
    }

    cout << "Matrix before:\n" << M;
    rotateMatrix(M);
    cout << "Matrix after rotation:\n" << M;


    return 0;
}       
