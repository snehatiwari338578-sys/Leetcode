class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int maxlen=0;
        int n=fruits.size();
        map<int,int>mp;
        for(int r=0;r<n;r++){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=2){
                maxlen=max(maxlen,r-l+1);
            }
        }
        return maxlen;
    }
};