#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x,y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
};

// 纯暴力，复杂度过高！！
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0) return 0;
        if (points.size() == 1) return 1;
        vector<pair<Point, Point>> lines;
        makeAllLines(points, lines);
        return getMaxPoints(points, lines);
    }
    int getMaxPoints(vector<Point>& points, vector<pair<Point, Point>>& lines) {
        int res = 0;
        for (int i = 0; i < lines.size(); ++i) {
            pair<Point, Point> ln = lines[i];
            Point a = ln.first, b = ln.second;
            int cnt = 0;
            for (int j = 0; j < points.size(); ++j) {
                Point p = points[j];
                if ((p.x == a.x && p.y == a.y)||(p.x == b.x && p.y == b.y)) {
                    cnt++;
                    continue;
                }
                if (a.x == b.x) {
                    if (p.x == a.x) cnt++;
                } else {
                    long long temp1 = (b.y - a.y), temp2 = (p.x - a.x);
                    long long temp3 = (b.x - a.x), temp4 = (p.y - a.y);
                    if (temp1*temp2 == temp3*temp4) cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
    void makeAllLines(vector<Point>& points, vector<pair<Point, Point>>& lines) {
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                Point a = points[i], b = points[j];
                lines.push_back(make_pair(a,b));
            }
        }
    }
};

// 上述方案的优化，在遍历点的时候就可以将他们的斜率计算出来，两条直线，如果过同一个点，并且两条直线的斜率一致，那么说明这两条直线重合
class Solution2 {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int dup = 1;
            Point a = points[i], b;
            for (int j = i+1; j < points.size(); ++j) {
                b = points[j];
                if (a.x == b.x && a.y == b.y) {
                    dup++;
                    continue;
                }
                int dy = b.y - a.y;
                int dx = b.x - a.x;
                int gcd = getGCD(dy, dx);
                m[make_pair(dy/gcd, dx/gcd)]++;
            }
            res = max(res, dup);
            for (map<pair<int, int>, int>::iterator it = m.begin(); it!=m.end(); ++it) {
                res = max(res, (it->second)+dup);
            }
        }
        return res;
    }
    int getGCD(int a, int b) {
        if (b == 0) return a;
        return getGCD(b, a%b);
    }
};

int main() {
    Solution2 s;
    vector<Point> points;
    int n;
    while (cin >> n) {
        points.clear();
        int x, y;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            points.push_back(Point(x,y));
        }
        cout << s.maxPoints(points) << endl;
    }
    return 0;
}
/**
3
1 1
2 2
3 3
3

6
1 1
3 2
5 3
4 1
2 3
1 4
4

3
0 0
1 65536
65536 0
2

3
0 0
1 3
3 0
2
*/
