class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        int count = 0;
        for(char c : s) {
            if(c == '(')
                count++;
            else if(c == ')') {
                count--;
                if(count < 0)
                    return false;
            }
        }
        return count == 0;
    }

    void solve(string s, int start, int leftRemove, int rightRemove) {
        if(leftRemove == 0 && rightRemove == 0) {
            if(isValid(s))
                ans.push_back(s);

            return;
        }
        for(int i = start; i < s.size(); i++) {
            if(i > start && s[i] == s[i-1])
                continue;

            if(leftRemove + rightRemove > s.size() - i)
                return;
            if(leftRemove > 0 && s[i] == '(') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                solve(temp, i, leftRemove - 1, rightRemove);
            }
            if(rightRemove > 0 && s[i] == ')') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                solve(temp, i, leftRemove, rightRemove - 1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;
        for(char c : s) {

            if(c == '(') {
                leftRemove++;
            }
            else if(c == ')') {

                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }
        solve(s, 0, leftRemove, rightRemove);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};