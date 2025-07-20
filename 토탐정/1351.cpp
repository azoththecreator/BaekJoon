/*

1351. 무한 수열

[문제]
무한 수열 A는 다음과 같다.

    - A0 = 1
    - Ai = A⌊i/P⌋ + A⌊i/Q⌋ (i ≥ 1)

N, P와 Q가 주어질 때, AN을 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 3개의 정수 N, P, Q가 주어진다.

[출력]
첫째 줄에 AN을 출력한다.

[제한]
- 0 ≤ N ≤ 1012
- 2 ≤ P, Q ≤ 109

*/

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> um;

long long solve(long long i, int p, int q)
{
    if (i == 0)
        return 1;

    if (um[i])
        return um[i];

    long long tmp;
    tmp = solve(i / p, p, q) + solve(i / q, p, q);
    um[i] = tmp;
    return tmp;
}

int main()
{
    long long n;
    int p, q;

    cin >> n >> p >> q;

    cout << solve(n, p, q);

    return 0;
}