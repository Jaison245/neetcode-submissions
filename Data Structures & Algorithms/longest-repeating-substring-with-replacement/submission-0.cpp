class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxfreq = 0;
        unordered_map<char, int> freq;
        int maxlen = 0;
        int left = 0;
        int window_size = 0;

        //calculae the max freq first
        for(int right = 0; right < s.size(); right++){
            freq[s[right]]++;
            maxfreq = max(maxfreq, freq[s[right]]);

            window_size = right - left + 1;

            while(window_size - maxfreq > k){
                freq[s[left]]--;
                left++;
                window_size = right - left + 1;
            }

            maxlen = max(maxlen, right - left + 1);

        }
        return maxlen;
     
    }
};
