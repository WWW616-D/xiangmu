#include "gogogo++.h"

using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

static bool cmpX(const Point& a, const Point& b) { return a.x < b.x; }
static bool cmpY(const Point& a, const Point& b) { return a.y < b.y; }

static double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// 归并排序辅助数组（用于优化版）
static vector<Point> tmp;

// 优化版：分治同时维护按y排序的序列
double closestPair(vector<Point>& pts, int l, int r) {
    if (l >= r) return DBL_MAX;
    if (l + 1 == r) return dist(pts[l], pts[r]);

    int mid = (l + r) >> 1;
    double midX = pts[mid].x;

    // 递归计算左右
    double d = min(closestPair(pts, l, mid), closestPair(pts, mid + 1, r));

    // 归并：按y排序（替代每层sort）
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (pts[i].y < pts[j].y) tmp[k++] = pts[i++];
        else tmp[k++] = pts[j++];
    }
    while (i <= mid) tmp[k++] = pts[i++];
    while (j <= r) tmp[k++] = pts[j++];
    for (i = l; i <= r; ++i) pts[i] = tmp[i];

    // 提取条带：横坐标差 < d
    vector<Point> strip; 
    for (i = l; i <= r; ++i) {
        if (fabs(pts[i].x - midX) < d) {
            strip.push_back(pts[i]);
        }
    }

    // 条带已经是按y有序的了
    for (i = 0; i < (int)strip.size(); ++i) {
        for (j = i + 1; j < (int)strip.size(); ++j) {
            if (strip[j].y - strip[i].y >= d) break;
            double tmpd = dist(strip[i], strip[j]);
            if (tmpd < d) d = tmpd;
        }
    }
    return d;
}

double minDistance(vector<Point>& pts) {
    sort(pts.begin(), pts.end(), cmpX);
    tmp.resize(pts.size());
    return closestPair(pts, 0, pts.size() - 1);
}

int main_minpoint() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    double ans = minDistance(pts);
    cout << fixed << setprecision(4) << ans << '\n';

    return 0;
}