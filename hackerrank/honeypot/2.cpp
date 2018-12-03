#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'rearrange' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY elements as parameter.
 */

/*
class Heap {
    vector<int> _data;
    public:
        void add() {
            
        }
}
*/

inline size_t numberOfOnes(int value) {
  size_t result = 0;
  unsigned int mask = 1;
  while (mask) {
    if(value & mask) { 
        ++result;
    }
    mask <<= 1;
  }
  return result;
}

inline bool lhvHasLessOnes(int lhv, int rhv){
    return numberOfOnes(lhv) < numberOfOnes(rhv); 
}

vector<int> rearrange(vector<int> elements) {
    // Create map to track only those num-of-1-groups of elements which exist 
    map<size_t, vector<int>> groupsByOnes;

    // Go through all numbers and put in the correct heap
    for (int i : elements) {
        groupsByOnes[numberOfOnes(i)].push_back(i);
    }

    // Reorganize each group into a heap
    for(auto pair : groupsByOnes) {
        auto& group = pair.second;
        cout << "Group " << pair.first << ": ";
        for_each(group.begin(), group.end(), [](int i){ cout << i << " ";});
        make_heap(group.begin(), group.end(), lhvHasLessOnes);
        cout << endl;
    }

    // Populate resulted vector
    vector<int> result;
    auto curPos = result.begin();
    for(auto pair : groupsByOnes) {
      auto& group = pair.second;

      cout << "Group " << pair.first << ": ";
      for_each(group.begin(), group.end(), [](int i) { cout << i << " "; });

      for(int i : group) {
          result.push_back(i);
      }
      //result.insert(curPos, group.begin(), group.end());
      curPos = result.end();
    } 

    cout << "Input elemenents num : " << elements.size() << ". Result elements num: " << result.size() << endl; 
    // assert(elements.size() == result.size());

    return result;
}

