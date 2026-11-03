class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int, int> mpp;

        for(int i = 0; i < numbers.size(); i++){

            int diff = target - numbers[i];

            if(mpp.find(diff) != mpp.end()){
                return {mpp[diff] + 1, i + 1};
            }
            mpp[numbers[i]] = i;
        }
        return {-1,-1};
        
    }
};
