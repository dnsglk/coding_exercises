#include "common.h"
#include "my_data_struct.h"

int main() {
    Stack<uint32_t> stack;
   
    string inStr;
    char userActionStr;
 
    while(true) {
        cout << "Enter (a/d/q): ";     
        cin >> userActionStr;
        switch(userActionStr) {
            case 'q': return 0;
            case 'a': {
                cout << "enter the value: ";
                cin >> inStr;
                stack.push(atoi(inStr.c_str()));
                stack.print();
                break; 
            }
            case 'd': {
                stack.pop();
                stack.print();
                break;
            }
        }
    }    


    return 0;
}
