class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        //store all the characters of t
        for(int i = 0; i < t.size(); i++){
            need[t[i]]++;
        }

        int have = 0;
        int left = 0;
        int right = 0;
        int req = need.size();
        int minlen = INT_MAX;
        int start = 0;


        while(right < s.size()){
            char c = s[right];
            window[c]++;

            if(need.count(c) && need[c] == window[c]){
                have++;
            }

            while(req == have){
                //update the min len window size
                if(right - left + 1 < minlen){
                    minlen = right - left + 1;
                    start = left;
                }

                //remove the left most character
                window[s[left]]--;

                if(need.count(s[left]) && window[s[left]] < need[s[left]]){
                    have--;
                }
                left++;
            }
            right++;
        }

        if(minlen == INT_MAX){
            return "";
        }

        return s.substr(start, minlen);

        
    }
};
