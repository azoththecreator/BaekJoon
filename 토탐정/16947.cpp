/*

16947. 레벨 햄버거

[문제]
상근날드에서 오랜만에 새로운 햄버거를 출시했다. 바로 레벨-L 버거이다. 레벨-L 버거는 다음과 같이 만든다.

    - 레벨-0 버거는 패티만으로 이루어져 있다.
    - 레벨-L 버거는 햄버거번, 레벨-(L-1) 버거, 패티, 레벨-(L-1)버거, 햄버거번으로 이루어져 있다. (L ≥ 1)
    - 예를 들어, 레벨-1 버거는 'BPPPB', 레벨-2 버거는 'BBPPPBPBPPPBB'와 같이 생겼다. (B는 햄버거번, P는 패티)

상도가 상근날드에 방문해서 레벨-N 버거를 시켰다.
상도가 햄버거의 아래 X장을 먹었을 때, 먹은 패티는 몇 장일까?
한 장은 햄버거번 또는 패티 한 장이다.

[입력]
첫째 줄에 N과 X가 주어진다.

[출력]
첫째 줄에 상도가 먹은 패티의 수를 출력한다.

[제한]
- 1 ≤ N ≤ 50
- 1 ≤ X ≤ 레벨-N 버거에 있는 레이어의 수

*/

#include <iostream>
#include <vector>

using namespace std;

vector<long long> total_layers;
vector<long long> total_patties;

long long count_patties(int level, long long x)
{
    if (level == 0)
    {
        if (x == 0)
            return 0;
        else
            return 1;
    }

    if (x == 0)
        return 0;
    else if (x <= 1 + total_layers[level - 1])
        return count_patties(level - 1, x - 1);
    else if (x == 1 + total_layers[level - 1] + 1)
        return total_patties[level - 1] + 1;
    else if (x <= 1 + (total_layers[level - 1] * 2) + 1)
        return total_patties[level - 1] + 1 + count_patties(level - 1, x - (1 + total_layers[level - 1] + 1));
    else
        return total_patties[level];
}

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    total_layers.push_back(1);
    total_patties.push_back(1);
    for (int i = 1; i <= n; ++i)
    {
        total_layers.push_back(total_layers[i - 1] * 2 + 3);
        total_patties.push_back(total_patties[i - 1] * 2 + 1);
    }

    cout << count_patties(n, x);

    return 0;
}