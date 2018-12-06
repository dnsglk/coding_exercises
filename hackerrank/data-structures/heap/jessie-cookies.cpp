#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

template<class T>
class MinHeap {
    
    public:

        void add(T value) {
            _data.emplace_back(move(value));

            // Bubble up the new value until it is less than parent
            size_t newValIdx = _data.size() - 1;
            size_t parentIdx = (newValIdx - 1)/2;
            bool isNotParent = newValIdx != 0;
            bool parentIsBigger = isNotParent && _data.at(parentIdx) > _data.at(newValIdx);

            while(parentIsBigger) {
                swap(_data.at(parentIdx), _data.at(newValIdx));

                newValIdx = parentIdx;
                parentIdx = (newValIdx - 1)/2;
                isNotParent = newValIdx != 0;
                parentIsBigger = isNotParent && _data.at(parentIdx) > _data.at(newValIdx);
            }
        }

        T popMin() {

            T topMin = _data.at(0);
            T valueToDown = _data.back(); 
            _data.at(0) = valueToDown;
            _data.pop_back();

            // Trickle down the root
            size_t valueToDownIdx = 0;
            size_t leftChildIdx = 2 * valueToDownIdx + 1;
            size_t rightChildIdx = 2 * valueToDownIdx + 2;

            bool leftExists = leftChildIdx < _data.size();
            bool leftLess = leftExists && _data.at(leftChildIdx) < valueToDown;
            bool rightExists = rightChildIdx < _data.size();
            bool rightLess = rightExists && _data.at(rightChildIdx) < valueToDown;
            
            // It is only enough to check the left one
            while(leftLess || rightLess) {
        
                bool swapWithRight = rightExists && _data.at(leftChildIdx) > _data.at(rightChildIdx);
                
                if(swapWithRight) {
                    swap(_data.at(valueToDownIdx), _data.at(rightChildIdx));
                    valueToDownIdx = rightChildIdx;
                } else {
                    swap(_data.at(valueToDownIdx), _data.at(leftChildIdx));
                    valueToDownIdx = leftChildIdx;                 
                }
                  
                leftChildIdx = 2 * valueToDownIdx + 1;
                rightChildIdx = 2 * valueToDownIdx + 2;
            
                leftExists = leftChildIdx < _data.size();
                leftLess = leftExists && _data.at(leftChildIdx) < valueToDown;
                rightExists = rightChildIdx < _data.size();
                rightLess = rightExists && _data.at(rightChildIdx) < valueToDown;
            }

            return topMin;
        }

        T min() const {
            return _data.at(0);
        }

        size_t size() const {
            return _data.size();
        }

        void print() const {
            cout << "Heap: ";
            for_each(_data.begin(), _data.end(), [](T i) {cout << i << " ";});
            cout << endl;
        }
    private:
        vector<T> _data;
};

/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) {
    
    MinHeap<int> heap;

    for_each(A.begin(), A.end(), [&heap](int i){ heap.add(i);});
    // heap.print();
    
    int result = 0;
    int newCookie;
    
    while(heap.size() > 1 && heap.min() < k) {
        newCookie = heap.popMin();
        newCookie += 2 * heap.popMin();

        heap.add(newCookie);
        
        // heap.print();
        ++result;
    }

    return heap.min() >= k ? result : -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

