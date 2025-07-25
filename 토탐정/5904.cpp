/*

5904. Moo 게임

[문제]
Moo는 술자리에서 즐겁게 할 수 있는 게임이다.
이 게임은 Moo수열을 각 사람이 하나씩 순서대로 외치면 되는 게임이다.

Moo 수열은 길이가 무한대이며, 다음과 같이 생겼다.

    - m o o m o o o m o o m o o o o m o o m o o o m o o m o o o o o

Moo 수열은 다음과 같은 방법으로 재귀적으로 만들 수 있다.
먼저, S(0)을 길이가 3인 수열 "m o o"이라고 하자.
1보다 크거나 같은 모든 k에 대해서, S(k)는 S(k-1)과 o가 k+2개인 수열 "m o ... o" 와 S(k-1)을 합쳐서 만들 수 있다.

    - S(0) = "m o o"
    - S(1) = "m o o m o o o m o o"
    - S(2) = "m o o m o o o m o o m o o o o m o o m o o o m o o"

위와 같은 식으로 만들면, 길이가 무한대인 문자열을 만들 수 있으며, 그 수열을 Moo 수열이라고 한다.

N이 주어졌을 때, Moo 수열의 N번째 글자를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N (1 ≤ N ≤ 10^9)이 주어진다.

[출력]
N번째 글자를 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> total_length;

char moo(int n, int level)
{
    if (n == 1)
        return 'm';

    if (level == 0)
        return 'o';

    if (n <= total_length[level - 1])
        return moo(n, level - 1);
    else if (n <= total_length[level - 1] + level + 3)
    {
        if (n == total_length[level - 1] + 1)
            return 'm';
        else
            return 'o';
    }
    else
        return moo(n - (total_length[level - 1] + level + 3), level - 1);
}

int main()
{
    int n;
    cin >> n;

    int level = 0;
    int length = 0;
    while (length < n)
    {
        length = length * 2 + level + 3;
        total_length.push_back(length);
        ++level;
    }
    --level;

    cout << moo(n, level);

    return 0;
}