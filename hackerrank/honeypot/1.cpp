#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'rearrangeWord' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING word as parameter.
 */

string rearrangeWord(string word) {
    if (word.empty() || word.size() == 1) {
        return "no answer";
    }

    auto prevIter = word.end();
    auto nextIter = prevIter-1;

    do {
        --prevIter;
        --nextIter;
        cout << (int) *prevIter << " " << (int) *nextIter << endl;
        cout << *prevIter << " " << *nextIter << " " << ios::boolalpha
             << ((int)*prevIter < (int)*nextIter) << endl;

        if (*prevIter > *nextIter) {        
          char tmp = *nextIter;
          *nextIter= *prevIter;
          *prevIter = tmp;
          cout << "Changed: " << word << endl;
          return word;
        } 

    } while (nextIter != word.begin());
    return "no answer";
}

