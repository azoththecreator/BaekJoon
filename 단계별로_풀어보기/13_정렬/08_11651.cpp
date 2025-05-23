/*

11651. 좌표 정렬하기 2

[문제]
2차원 평면 위의 점 N개가 주어진다.
좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

[입력]
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000)
좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

[출력]
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if (a[1] != b[1])
        return a[1] < b[1];
    return a[0] < b[0];
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int> > points;
    for (int i = 0; i < n; ++i)
    {
        vector<int> tmp(2);
        cin >> tmp[0] >> tmp[1];
        points.push_back(tmp);
    }

    sort(points.begin(), points.end(), compare);

    for (int i = 0; i < n; ++i)
        cout << points[i][0] << " " << points[i][1] << '\n';

    return 0;
}