class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int ws = s1.size(); //window_size

        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        //store the frequencies of s1
        for(int i = 0; i < s1.size(); i++){
            freq1[s1[i]-'a']++;
        }


         //create the first window
        for(int i = 0; i < ws; i++){
            freq2[s2[i] - 'a']++;
        }

        if(freq1 == freq2) return true; 

        int left = 0;

       
        for(int right = ws; right < s2.size(); right++){
            freq2[s2[right] - 'a']++;
            freq2[s2[left] - 'a']--;
            left++;

            if(freq1 == freq2) return true;
        }

        return false;






        
    }
};
