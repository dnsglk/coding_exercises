// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {

    if (arr.empty() || arr.size() == 1) {
        return vector<int>();
    }

    sort(arr.begin(), arr.end());

    vector<int> result;
    size_t curDiff = arr[1] - arr[0];
    size_t minDiff = curDiff;

    for(size_t i = 0; i < arr.size()-2; ++i) {
        
        curDiff = arr[i+1] - arr[i];

        if(curDiff <= minDiff) {
            if(curDiff < minDiff) {
               result.clear();
            }

            minDiff = curDiff;

            result.push_back(arr[i]);
            result.push_back(arr[i+1]);
        }
    }
    return result;
}
