#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == nullptr || length <= 0) return ;
        int strLen = 0, blank = 0;
        while (str[strLen] != '\0') {
            if (str[strLen] == ' ') {
                blank++;
            }
            strLen++;
        }
        int first = strLen, second = strLen + blank*2;
        while (first >= 0 && first < second) {
            if (str[first] == ' ') {
                str[second--] = '0';
                str[second--] = '2';
                str[second--] = '%';
            } else {
                str[second--] = str[first];
            }
            first--;
        }
        return ;
	}
};
