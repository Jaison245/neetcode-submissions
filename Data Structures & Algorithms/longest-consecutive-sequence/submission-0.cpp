class Solution {
public:

    int max(int a, int b){
        if(a>b) return a;
        return b;
    }
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        //insert all elements in the set.
        for(int x : nums){
            st.insert(x);
        }
        int longest = 0;

        for(int x : st){
            //see if it is the first element.
            if(st.find(x-1) == st.end()){
                int count = 1;
                int n = x;

                while(st.find(n+1) != st.end()){
                    count++;
                    n++;
                }
                longest = max(longest,count);
            }
            
        }
        return longest;
        
    }
};
