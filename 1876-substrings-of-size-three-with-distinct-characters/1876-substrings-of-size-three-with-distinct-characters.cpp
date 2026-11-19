class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0;
        int l=0;
        for(int r=0;r<s.length();r++){
            if(r-l+1==3){
                if(s[l]!=s[l+1] && s[l]!=s[l+2] && s[l+1]!=s[l+2]){
                    ans++;
                }
                l++;
            }
        }
        return ans;
    }
};