#include "common.h"
#include "my_data_struct.h"


const list_t* getIntersection(const list_t& l1, const list_t& l2) {
    
    size_t s1 = size(l1);
    size_t s2 = size(l2);

    auto bigger = s1 == s2 ? &l1 : (s1 > s2 ? &l1 : &l2);
    auto smaller = bigger == &l1 ? &l2 : &l1;

    size_t diff = bigger == &l1 ? s1 - s2 : s2 - s1;

    while(diff--) {
        bigger = bigger->m_next;        
    }

    while(bigger && bigger != smaller) {
        bigger = bigger->m_next;
        smaller = smaller->m_next;
    }

    return bigger;
}

int main() {
    
    list_t* list1, *list2, *node, *prev;

    for(uint32_t i = 0; i < 7; ++i) {

        node = new list_t(i);

        if( i == 4) {
            list2 = node;
        }       
        if (i == 0) {
            list1 = node;
        } else {
            prev->m_next = node; 
        }

        prev = node;

    }
    
    if(0) {    
        node = new list_t(8);
        node->m_next = list2;
        list2 = node;
    }

    print(*list1);
    print(*list2);
    cout << "Intersection: \n";
    auto inter = getIntersection(*list2, *list1);
    if (inter) print(*inter);
    
    free(list1);
    free(list2);
    return 0;
}
