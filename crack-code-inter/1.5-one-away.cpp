#include "common.h"


using namespace std;

bool areOneEditAway(const string& A, const string& B) {

    if (A.size() != B.size() && ( pow(A.size()- B.size(),2) > 1 )) {
        return false;
    }

    bool aBigger = A.size() > B.size();
    bool bBigger = A.size() < B.size();
    bool sizeDiff = A.size() != B.size();


    uint32_t size = sizeDiff ? (aBigger ? A.size() : B.size()) : A.size();
    uint32_t i, j, edits = 0;

    while(i < size && j < size && edits < 2) {
        if (A[i] == B[i]) {
            continue;
        }

        ++edits;
        if(sizeDiff) {
            if(aBigger) {
                ++i;
            } else {
                ++j;
            }
        } else  {
            ++i; ++j;
        }

    } 
    return edits < 2;
}       

int main(int argc, char** argv) {

    string A,B;
    cout << "Enter two words:\n";
    cin >> A >> B ;

    cout << "You entered: A: " << A << ", B: " << B << endl;

    cout << "One edit away?: " << (areOneEditAway(A,B) ? "Yes" : "No") << endl;

    return 0;
}
