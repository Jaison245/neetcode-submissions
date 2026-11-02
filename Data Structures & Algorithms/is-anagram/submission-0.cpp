class Solution {
public:
    bool isAnagram(string s, string t) {

        int ns = s.size();
        int ts = t.size();

        if(ts != ns) return false;

        unordered_map<int,int> mpp;

        for(int i = 0; i < ns; i++){
            mpp[s[i]]++;
        }

        for(int i = 0; i < ns; i++){

            mpp[t[i]]--;
            
            if(mpp[t[i]] < 0) return false;

            
        }
        return true;
    }
};
