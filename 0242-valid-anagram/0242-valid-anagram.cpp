class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        for (char ch : t) {
            mp[ch]--;
        }
        for (auto x : mp) {
            if (x.second != 0) //first is character second is frequency so agar frequecy 0 nhi h 
                return false;
        }
        return true;
    }
};