class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        //product of left
        vector<int>left(n+1,1);

        for(int i = 1; i <= n; i++){
            left[i] = left[i-1] * nums[i-1];
        }

        //product of right
        vector<int> right(n+1, 1);
        for(int i = n-1; i >= 0; i--){
            right[i] = right[i+1] * nums[i];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] =left[i] * right[i+1];
        }
        return ans;
    }
};
