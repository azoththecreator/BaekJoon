/*

1461. 도서관

[문제]
세준이는 도서관에서 일한다.
도서관의 개방시간이 끝나서 세준이는 사람들이 마구 놓은 책을 다시 가져다 놓아야 한다.
세준이는 현재 0에 있고, 사람들이 마구 놓은 책도 전부 0에 있다.
각 책들의 원래 위치가 주어질 때, 책을 모두 제자리에 놔둘 때 드는 최소 걸음 수를 계산하는 프로그램을 작성하시오.
세준이는 한 걸음에 좌표 1칸씩 가며, 책의 원래 위치는 정수 좌표이다.
책을 모두 제자리에 놔둔 후에는 다시 0으로 돌아올 필요는 없다.
그리고 세준이는 한 번에 최대 M권의 책을 들 수 있다.

[입력]
첫째 줄에 책의 개수 N과, 세준이가 한 번에 들 수 있는 책의 개수 M이 주어진다.
둘째 줄에는 책의 위치가 주어진다.
N과 M은 50보다 작거나 같은 자연수이다.
책의 위치는 0이 아니며, 절댓값은 10,000보다 작거나 같은 정수이다.

[출력]
첫째 줄에 정답을 출력한다.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> pos;
vector<int> neg;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;

        if (tmp > 0)
            pos.push_back(tmp);
        else
            neg.push_back(tmp);
    }

    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());

    int dist = 0;
    for (int i = 0; i < pos.size(); i += m)
        dist += pos[i] * 2;
    for (int i = 0; i < neg.size(); i += m)
        dist += abs(neg[i] * 2);

    if (pos.size() == 0)
        dist -= abs(neg[0]);
    else if (neg.size() == 0)
        dist -= pos[0];
    else
        dist -= (pos[0] > abs(neg[0]) ? pos[0] : abs(neg[0]));

    cout << dist;

    return 0;
}