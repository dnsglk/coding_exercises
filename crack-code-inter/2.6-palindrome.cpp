#include "common.h"
#include "my_data_struct.h"

/*
 Recursively go to the end of a list, then compare last node with head and
 return and acuumulate result when unwinding. When unwiding happens than head is 
 moved ahead to match current end value in the unwinded stack frame.
 
 @param counter - show current position in list relative to the both ends. 
                  When is equal to size/2 stops recursion
*/
bool compareHeadWithEnd(const list_char_t*& head, const list_char_t* end, bool& stop) {

    // Stop going to end 
    if (end->m_next == nullptr) {
        return head->m_data == end->m_data; 
    }

    bool endsAreEqual = compareHeadWithEnd(head,end->m_next,stop);

    if (head == end || stop) {
        return endsAreEqual; 
    }
    
    head = head->m_next;
    if (head->m_next == end) {
        stop = true;
    }

    return endsAreEqual & (head->m_data == end->m_data);
}

bool isPalindrome(const list_char_t& head) {
    bool stop = false;
    const list_char_t* start = &head;
    return compareHeadWithEnd(start, &head, stop);

}

int main() {
    
    cout << "Enter a list:\n";
    list_char_t* list = createListFromInput<char>();
    cout << (isPalindrome(*list) ? "Is palindrome" : "Not a palindrome") << endl;

    return 0;
}
