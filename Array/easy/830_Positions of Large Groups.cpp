#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S){
        vector<vector<int>> ans;
        int len = S.size();
        int p1 = 0, p2 = 0, cnt = 0;
        char flag = S[0];
        for (int i = 0; i < len; ++i) {
            if (S[i] == flag) {
                p2 = i;
                cnt++;
                if (i == len-1 && cnt >= 3) {
                    vector<int> out;
                    out.push_back(p1);
                    out.push_back(p2);
                    ans.push_back(out);
                }
            } else {
                if (cnt >= 3) {
                    vector<int> out;
                    out.push_back(p1);
                    out.push_back(p2);
                    ans.push_back(out);
                }
                flag = S[i];
                p1 = i;
                p2 = i;
                cnt = 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    string in;
    cin >> in;
    vector<vector<int>> out = s.largeGroupPositions(in);
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i][0] << " " << out[i][1] << endl;
    }
    return 0;
}
