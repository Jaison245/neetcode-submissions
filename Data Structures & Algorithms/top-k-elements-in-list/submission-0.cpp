class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


        //count the freq of all the numbers
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        //{count, number}
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto & f : freq){

            pq.push({f.second, f.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
