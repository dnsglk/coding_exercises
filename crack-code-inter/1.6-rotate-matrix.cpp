#include "common.h"
#include "my_data_struct.h"
 
class Matrix {

    ArrayList<ArrayList<string>> m_matrix;
public:
    
    Matrix(size_t n): m_matrix(n) {
        size_t i = n;
        while(i-- != 0) {
            m_matrix[i-1] = ArrayList<string>(n);
        }
    }

    ArrayList<string>& 
    operator[](size_t n) const { 
        if(n >= m_matrix.size()) {
            ss s;
            s << "Out of bounds: " << n << ", size = " << m_matrix.size();
            throw new std::runtime_error(s.str());
        }


        return m_matrix[n];
    }
};

int main() {

    Matrix M(5);
    ss s;
    for(unsigned i = 0; i < 5; ++i) {
        for (unsigned j = 0; j < 5; ++j) {
            s << (char)('a' + i) << j;
            M[i][j] =  s.str();
            s.str("");
        }
    }

    for(uint32_t i = 0; i < 5; ++i) {
        for(uint32_t j = 0; j < 5; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}       
