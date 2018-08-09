#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.size() <= 0) return res;
        set<string> s;
        vector<bool> vis(str.size(), false);
        vector<char> temp;
        getPermutation(res, s, str, temp, vis);
        return res;
    }
    void getPermutation(vector<string>& res, set<string>& s, string str, vector<char>& temp, vector<bool>& vis) {
        if (temp.size() == str.size()) {
            string ss = "";
            for (int i = 0; i < temp.size(); ++i) {
                ss+=temp[i];
            }
            ss+='\0';
            if (s.find(ss) == s.end()) {
                res.push_back(ss);
                s.insert(ss);
            }
            return ;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (!vis[i]) {
                vis[i] = true;
                temp.push_back(str[i]);
                getPermutation(res, s, str, temp, vis);
                temp.pop_back();
                vis[i] = false;
            }
        }
    }
};

class Solution2 {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.size() <= 0) return res;
        sort(str.begin(), str.end());
        getPermutation(res, str, 0);
        sort(res.begin(), res.end());
        return res;
    }
    void getPermutation(vector<string>& res, string str, int start) {
        if (start == str.size()-1) {
            res.push_back(str);
            return ;
        }
        for (int i = start; i < str.size(); ++i) {
            if (i!=start && str[i] == str[start]) continue;
            swap(str[i], str[start]);
            getPermutation(res, str, start+1);
            swap(str[i], str[start]);
        }
    }
};

int main() {
    Solution s;
    string str;
    while (cin >> str) {
        vector<string> res = s.Permutation(str);
        for (auto s: res) {
            cout << s << endl;
        }
    }
    return 0;
}
