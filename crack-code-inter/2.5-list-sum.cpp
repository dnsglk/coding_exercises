#include "common.h"
#include "my_data_struct.h"

uint32_t reverseSum(const list_t& l1, const list_t& l2) {
    uint32_t sum = 0, val1 = 0, val2 = 0;
    uint32_t currentDigit = 0;

    const list_t*  node1 = &l1;
    const list_t*  node2 = &l2;

    while (node1 || node2) {
        val1 = node1 ? node1->m_data : 0;
        val2 = node2 ? node2->m_data : 0;

        sum += pow(10, currentDigit++) * (val1 + val2);

        node1 = node1 ? node1->m_next : nullptr;
        node2 = node2 ? node2->m_next : nullptr;
    }

    return sum;
}

uint32_t forwardSum(const list_t* l1, size_t size1, uint32_t val1,
                    const list_t* l2, size_t size2, uint32_t val2, 
                    uint32_t& curLevel) 
{
    ++curLevel;

    if (l1 == nullptr && l2 == nullptr) {
        // Reset curLevel to be used for digit's place calculation
        curLevel = 0;
        return val1 + val2;
    }

    const list_t* nextL1 = l1->m_next; 
    const list_t* nextL2 = l2->m_next; 

    uint32_t nextval1 = nextL1 ? nextL1->m_data : 0;
    uint32_t nextval2 = nextL2 ? nextL2->m_data : 0;
    
    // If one of the list_t*s is shorter than do not advance its head and 
    // use 0 for the current digits' sum
    if(size1 < size2) {
        if ((size2 - size1) >= curLevel) {
            val1 = 0;  
            nextL1 = l1;
            nextval1 = l1->m_data;
        }   
    } else if(size2 < size1) {
         if ((size1 - size2) >= curLevel) {
            val2 = 0;  
            nextL2 = l2;
            nextval2 = l2->m_data;
        }   
    } 

    uint32_t sum = forwardSum(nextL1, size1, nextval1, 
                              nextL2, size2, nextval2, 
                              curLevel);

    return pow(10,curLevel++) * (val1 + val2) + sum;
}

uint32_t forwardSum(const list_t& l1, const list_t& l2) {
    uint32_t curLevel = 0;

    return forwardSum(&l1, size(l1), l1.m_data,  &l2, size(l2), l2.m_data, curLevel);
}

int main() {

    list_t *list1 , *list2;

    for(uint32_t i = 0; i < 2; ++i) {
        cout << "Enter list #" << i+1 << endl;
        (i == 0 ? list1 : list2)  = createListFromInput<uint32_t>();
    }
    print(*list1);
    print(*list2);
    
    cout << "Backward sum: " << reverseSum(*list1, *list2) << endl;
    cout << "Forward sum: " << forwardSum(*list1, *list2) << endl;

    free(list1);
    free(list2);

    return 0;
}
