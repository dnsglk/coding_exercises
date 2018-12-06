/*
ATTENTION: problem description is very misleading! Test cases are incorrect!

https://www.hackerrank.com/challenges/minimum-average-waiting-time/problem

*/
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Customer {
    public:

        Customer(int arrival, int makeTime):
            _arrival(arrival),
            _makeTime(makeTime)
        {}
        
        int _arrival;
        int _makeTime;
        

        long long waitTime() const {
            return Customer::nextSlot - _arrival + _makeTime;
        }
        bool hasMorePriorityThan(const Customer& rhv) {
            return waitTime() < rhv.waitTime();
        }

        string toStr() const {
            ostringstream s;
            s << _arrival << " " << _makeTime;
            return s.str();
        }
        static long long nextSlot; 
};

long long Customer::nextSlot = 0;

template<class T >
class Heap {
    public:
        void add(T newVal) {
            _data.emplace_back(move(newVal));
            size_t newValIdx = _data.size() -1 ;
            size_t parentIdx = (newValIdx - 1)/2;
            while(newValIdx != 0 && 
                 _data.at(newValIdx).hasMorePriorityThan(_data.at(parentIdx)))
            {
                swap(_data.at(newValIdx), _data.at(parentIdx));
                newValIdx =  parentIdx;
                parentIdx = (newValIdx - 1)/2;
            }
        }

        T pop() {
            T minVal = _data.at(0);
            _data.at(0) = _data.back();
            _data.pop_back();

            if (_data.size() == 0) {
                return minVal;
            }
            
            const T& downVal = _data.at(0); 
            
            size_t downValIdx = 0;
            size_t leftIdx = 2*downValIdx + 1;
            size_t rightIdx = 2*downValIdx + 2;

            while(leftIdx < _data.size()) {
                bool swapRight = rightIdx < _data.size() && 
                    _data.at(rightIdx).hasMorePriorityThan(downVal) &&
                    _data.at(rightIdx).hasMorePriorityThan(_data.at(leftIdx));
                
                bool swapLeft = !swapRight &&
                     _data.at(leftIdx).hasMorePriorityThan(downVal);

                if (swapRight) {
                    swap(_data.at(rightIdx), _data.at(downValIdx));
                    downValIdx = rightIdx;
                } else if (swapLeft) {
                    swap(_data.at(leftIdx), _data.at(downValIdx));
                    downValIdx = leftIdx;
                } else {
                    break;
                }

                leftIdx = 2 * downValIdx + 1;
                rightIdx = 2 * downValIdx + 2;

            }

            return minVal;
        }

        size_t size() const {
            return _data.size();
        }

        void print() const {
            cout << "heap: \n";
            for(auto i : _data) {
                cout << i.toStr() << "\n";
            }
            cout << "-------\n";
        }
    private :
    vector<T> _data;

};

/*
 * Complete the minimumAverage function below.
 */
 using CustInput = const vector<int>&;
unsigned long minimumAverage(vector<vector<int>> customers) {
    /*
     * Write your code here.
     */

    /* Sort customers by arrival time */
    sort(customers.begin(), customers.end(), 
        [](CustInput cust1, CustInput cust2) {return cust1[0] < cust2[0];});

    /* Sort first customers who arrived at the same time. 
    Sort by the time needed to make pizza */

    auto cust = customers.begin();
    // int firstClientArrivalTime = cust->at(0); 
    // while(cust->at(0) <= firstClientArrivalTime) { 
    //     ++cust;
    // }

    // sort(customers.begin(), cust);
    // for(auto i : customers) {
    //     cout << i[0] << " " << i[1] << endl;
    // }

    long long sum = 0;
    Heap<Customer> heap;
    auto end = customers.end();
    cust = customers.begin();
    Customer::nextSlot = cust->at(0);

    while(cust != end || heap.size() != 0) {
       
        if(cust != end && cust->at(0) <= Customer::nextSlot) {
            heap.add(Customer{cust->at(0), cust->at(1)});
            ++cust;
            continue;
        } 
       
        if (heap.size() == 0) {
            heap.add(Customer{cust->at(0), cust->at(1)});
            Customer::nextSlot = cust->at(0);
            ++cust;
            continue;
        } 

        // cout << "=========================\nTaking new order: \n";
        // heap.print();
        Customer&& nextCust = heap.pop(); 
        // heap.print();
        // cout << "Customer: " << nextCust._arrival << " " 
        //      << nextCust._makeTime << endl;
        
        Customer::nextSlot += nextCust._makeTime;
        sum += Customer::nextSlot - nextCust._arrival;

        // cout << "Slot: " << Customer::nextSlot 
        //      << ", sum: " << sum << endl;
    }

    cout << "Sum : " << sum << " " << Customer::nextSlot << endl;
    return sum / customers.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> customers(n);
    for (int customers_row_itr = 0; customers_row_itr < n; customers_row_itr++) {
        customers[customers_row_itr].resize(2);

        for (int customers_column_itr = 0; customers_column_itr < 2; customers_column_itr++) {
            cin >> customers[customers_row_itr][customers_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    auto result = minimumAverage(customers);

    fout << result << "\n";

    fout.close();

    return 0;
}

