/*
https://www.hackerrank.com/challenges/qheap1/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Heap {

    vector<int> _data;

    public:
        void print() { 
            for_each(_data.begin(), _data.end(), 
                [](int i) { cout << i << " "; } );
                cout << endl;
                cout << endl;
        }
        
        void add(int value) {
            _data.push_back(value);
            
            // bubble up
            size_t newValIdx = _data.size() - 1;
            size_t parentIdx = (newValIdx - 1)/2;
            
            while(newValIdx != 0 && _data[parentIdx] > value) {
                swap(_data[parentIdx], _data[newValIdx]);              
                newValIdx = parentIdx;
                parentIdx = (newValIdx - 1)/2;
            }
        }

        void remove(int value) {

            // Find an index of element to delete
            // TODO Move out to a new method
            auto iter = find(_data.begin(), _data.end(), value);
            if(iter == _data.end()) {
                return;
            }
            auto valueToDelIdx = distance(_data.begin(),iter);
            int downValue = _data.back();
            _data.at(valueToDelIdx) = downValue;
            _data.pop_back();
            
            // Trickle the new substitute down
            size_t downValueIdx = valueToDelIdx;
            size_t leftChildIdx = 2*downValueIdx + 1;
            size_t rightChildIdx = 2*downValueIdx + 2;

            while(leftChildIdx < _data.size() || rightChildIdx < _data.size()) {
                bool shouldSwap = downValue > _data[leftChildIdx] ||
                    downValue > _data[rightChildIdx];

                if (!shouldSwap) {
                    break;
                }

                if (_data[leftChildIdx] < _data[rightChildIdx]) {
                    swap(_data[downValueIdx], _data[leftChildIdx]);              
                    downValueIdx = leftChildIdx;
                } else {
                    swap(_data[downValueIdx], _data[rightChildIdx]);              
                    downValueIdx = rightChildIdx;
                } 

                leftChildIdx = 2*downValueIdx + 1;
                rightChildIdx = 2*downValueIdx + 2;
            }
        }

        int min() const {
            return _data[0];
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Heap heap;
    int op;
    int value;
    int opsNum;

    cin >> opsNum;
    vector<bool> iterations(opsNum);
    for (auto _ : iterations) {
        cin >> op;
        
        //cout << "operation " << op;
        
        if (op != 3) {
            cin >> value;
            //cout << ", value " << value;
        }
        
        //cout << endl;

        switch(op) {
            case 1: heap.add(value); break;
            case 2: heap.remove(value); break;
            case 3: cout << heap.min() << endl; break;
            default: cout << "Unknown operation: " << op 
                          << ", value = " << value << endl; break;
        }
        // heap.print();
    }    
    return 0;
}

