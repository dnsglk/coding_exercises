#include "common.h"


using namespace std;

namespace {
constexpr uint32_t ALPHABET_SIZE = 1 << (sizeof(char)*8);
constexpr bool ALLOW_SPACE = false;
}

bool permutationNoSpace(string& B,string& A) {

    sort(B.begin(), B.end());
    sort(A.begin(), A.end());

    return B == A; 
}

bool permutationSpace(const string& B, const string& A) {

    if (B.size() != A.size()) return false;

    char charsInA[ALPHABET_SIZE] = {0};
    char charsInB[ALPHABET_SIZE] = {0};

    for (uint32_t i = 0; i < B.size(); ++i) {
        ++charsInA[(int)A[i]];
        ++charsInB[(int)B[i]];
    }

    for(uint32_t i = 0; i < ALPHABET_SIZE; ++i) {
        if( charsInA[i] != charsInB[i] ) {
            return false;
        }
    }

    return true;
}

bool isPermutation(string& B, string& A) {
    if (ALLOW_SPACE) 
        return permutationSpace(B,A);
    else
        return permutationNoSpace(B,A);
}

int main(int argc, char** argv) {
    
    string B = "permutation";
    string A = "noitatumrep";

    if (argc == 3) {
        B = argv[1];
        A = argv[2];
    }

    if(isPermutation(B, A)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }    
    return 0;
}
