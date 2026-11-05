class Solution {
public:
    int findMin(vector<int> &nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left)/2;

            if(nums[mid] > nums[right]){
                //minimum lies in the right half
                left = mid + 1;
            }else{
                //minimum lies in the part [left......mid]
                right = mid;
            }
        }
        return nums[left];
        
    }
};
