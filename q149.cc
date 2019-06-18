#include<iostream>
#include<vector>
#include<algorithm>
#include<initializer_list>
using namespace std;

struct Point{
    int x;
    int y;
    Point(int a = 0, int b = 0):x(a),y(b){}
};

bool issame(Point a, Point b)
{
    return a.x == b.x && a.y == b.y;
}

bool judge(Point a, Point b, Point c)
{
    if(issame(a, b) || issame(b, c)  || issame(c, a))
        return true;
    if(a.x == b.x && a.x == c.x)
        return true;
    if(a.x != b.x && a.x != c.x && (((long long)a.y - b.y)*((long long)a.x - c.x) == ((long long)a.y - c.y) * ((long long)a.x - b.x)))
        return true;
    return false;
}

int maxPoints(vector<Point>& points) {
        int res = 0;
        int n = points.size();
        if(n <= 2)
            return n;
        for(int i = 0; i < n -1; i++)
        {
            int ans = 1;
            for(int j = i + 1; j < n; j++)
            {
                if(issame(points[i],points[j]))
                {
                    ans += 1;
                }
                else
                {
                    ans = 2;
                    for(int k = 0; k < n; k++)
                    {
                        if(k == i || k == j)
                            continue;
                        if(judge(points[k], points[i], points[j]))
                            ans += 1;
                    }
                }
                    
                res = max(res, ans);
            }
        }
        return res;
    }

int  main()
{
    //Point a(0, 0), b(1, 65536), c(65536, 0);
    
    vector<Point> p{Point(0,9),Point(138,429),Point(115,359),Point(115,359),Point(-30,-102),Point(230,709),Point(-150,-686),Point(-135,-613),Point(-60,-248),Point(-161,-481),Point(207,639),Point(23,79),Point(-230,-691),Point(-115,-341),Point(92,289),Point(60,336),Point(-105,-467),Point(135,701),Point(-90,-394),Point(-184,-551),Point(150,774)};
    vector<Point> p1{Point(0, 0), Point(1, 1), Point(0, 0)};
    cout << maxPoints(p1) << endl;
    return 0;
}