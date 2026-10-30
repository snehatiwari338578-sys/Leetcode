class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1="qwertyuiop";
        string row2="asdfghjkl";
        string row3="zxcvbnm";
        vector<string>ans;
        for(string word:words){
            string temp=word;
            for(char &ch:temp){
                ch=tolower(ch);
            }
            bool a=true,b=true,c=true;
            for(char ch:temp){
                if(row1.find(ch)==string::npos){
                    a=false;
                }
                if(row2.find(ch)==string::npos){
                    b=false;
                }
                if(row3.find(ch)==string::npos){
                    c=false;
                }
            }
            if(a||b||c){
                ans.push_back(word);
            }
        }
        return ans;
    }
};