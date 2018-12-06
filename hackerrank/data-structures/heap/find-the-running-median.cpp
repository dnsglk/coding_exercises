/*
https://www.hackerrank.com/challenges/find-the-running-median/problem
*/
#include <bits/stdc++.h>

using namespace std;

template<class T, bool isMin=true>
class Heap {
    
    public:
        void add(T newValue) {
            _data.emplace_back(move(newValue));
            size_t newValIdx = _data.size()-1;
            size_t parentIdx = (newValIdx-1)/2;
            while(newValIdx != 0 && !parentHasPriority(_data.at(parentIdx), newValue)) {
                swap(_data.at(parentIdx), _data.at(newValIdx));
                newValIdx = parentIdx;
                parentIdx = (newValIdx-1)/2;
            }
        }

        T pop() {
            T downVal = _data.back();
            T topVal = _data.at(0);
            _data.pop_back();

            if (_data.empty()) {
                return topVal;
            }

            _data.at(0) = downVal;

            size_t downValIdx = 0;
            size_t leftChIdx = 2*downValIdx+1;
            size_t rightChIdx = 2*downValIdx+2;
            
            while(leftChIdx < _data.size()) 
            {
                bool swapRight = rightChIdx < _data.size() &&
                  !parentHasPriority(_data.at(downValIdx),_data.at(rightChIdx)) && 
                  parentHasPriority(_data.at(rightChIdx), _data.at(leftChIdx));
                
                bool swapLeft =
                    !parentHasPriority(_data.at(downValIdx),_data.at(leftChIdx));

                if (swapRight) {
                    swap(_data.at(rightChIdx), _data.at(downValIdx));
                    downValIdx = rightChIdx;
                } else if (swapLeft) {
                    swap(_data.at(leftChIdx), _data.at(downValIdx));
                    downValIdx = leftChIdx;
                } else {
                    break;
                }
                
                leftChIdx = 2*downValIdx+1;
                rightChIdx = 2*downValIdx+2;
            
            }

            return topVal;
        }

        const T& peek() const {
            return _data.at(0);
        }

        size_t size() const {
            return _data.size();
        }

        void print() const {
            cout << "heap: ";
            for (T i : _data) {
                cout << i << " ";
            }
            cout << endl;
        }
    private:
        bool parentHasPriority(const T& parent, const T& child) const {
            return isMin ? parent < child : parent > child;
        }

    private:
        vector<T> _data;
        bool _isMin = isMin;
};

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    /*
     * Write your code here.
     */
    // Store the 2nd half of the array
    Heap<int> minHeap;
    // Store the 1st half of the array
    Heap<int,false> maxHeap;

    vector<double> medians;
    for(int i : a) {
        
        if(minHeap.size() == 0) {
            minHeap.add(i);
        } else  
        if (i > minHeap.peek() && (maxHeap.empty() || !maxHeap.empty() && i > maxHeap.peek())) {
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.add(minHeap.pop());
            }   
            minHeap.add(i);
        } else
        if (i < minHeap.peek() && (maxHeap.empty() || !maxHeap.empty() && i < maxHeap.peek())) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.add(maxHeap.pop());
            }
            maxHeap.add(i);
        } else if (maxHeap.size() > minHeap.size()){
                minHeap.add(i);
        } else {
             maxHeap.add(i);
        }        

        // If heap sizes differ, median is the root of the biggest heap
        if (maxHeap.size() != minHeap.size()) {
            int median = maxHeap.size() > minHeap.size() ? 
                maxHeap.peek() : minHeap.peek();
            medians.emplace_back(move(median));
        } else {
            medians.emplace_back((maxHeap.peek() + minHeap.peek())/2.0);
        }


        // cout << "----\nValue: " << i << endl;
        // minHeap.print();
        // maxHeap.print();
        // cout << "Median: " << medians.back() << endl;
    }

    return medians;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

