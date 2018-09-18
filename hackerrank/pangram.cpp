/*
Link:
https://www.hackerrank.com/challenges/pangrams/problem
*/

#include <bits/stdc++.h>



using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {

    constexpr uint32_t letterNum = (int)('z'-'a') + 1;
    bool hit[letterNum] = {false};
    uint32_t hits_num = sizeof(hit)/sizeof(bool);

    cout << hits_num << endl;
    
    std::for_each(s.begin(), s.end(), [&hit](char a) {
        if(a == ' ') return;

        uint32_t offset = int(a) >= (int)'a' ? int('a') : int('A');
        hit[int(a)-offset] = true;
    });

    for (uint32_t i = 0; i < hits_num; ++i) {
        if(!hit[i]) return "not pangram";
    }

    return "pangram";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
