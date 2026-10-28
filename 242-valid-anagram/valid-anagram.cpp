class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> pres(26,0);
        int n = s.length();
        int m = t.length();

        if(n != m) return false;

        for(int i=0; i<n; i++){
            pres[s[i] - 'a']++;
            pres[t[i] - 'a']--;
        }

        for(int i=0; i<pres.size(); i++){
            if(pres[i]!=0) return false;
        }

        return true;
    }
};