/*

18870. 좌표 압축

[문제]
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다.
이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표 Xj의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

[입력]
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

[출력]
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

[제한]
- 1 ≤ N ≤ 1,000,000
- -10^9 ≤ Xi ≤ 10^9

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> points;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        points.push_back(tmp);
    }

    vector<int> sorted = points;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    map<int, int> indexing;
    int idx = 0;
    for (int i = 0; i < sorted.size(); ++i)
        indexing[sorted[i]] = i;

    for (int i = 0; i < points.size(); ++i)
        cout << indexing[points[i]] << " ";

    return 0;
}