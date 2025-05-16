/*

17103. 골드바흐 파티션

[문제]
    - 골드바흐의 추측: 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다.

짝수 N을 두 소수의 합으로 나타내는 표현을 골드바흐 파티션이라고 한다.
짝수 N이 주어졌을 때, 골드바흐 파티션의 개수를 구해보자.
두 소수의 순서만 다른 것은 같은 파티션이다.

[입력]
첫째 줄에 테스트 케이스의 개수 T (1 ≤ T ≤ 100)가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고, 정수 N은 짝수이고, 2 < N ≤ 1,000,000을 만족한다.

[출력]
각각의 테스트 케이스마다 골드바흐 파티션의 수를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    bool primes[1000001];

    for (int i = 2; i <= 1000000; ++i)
        primes[i] = true;

    for (int i = 2; i * i <= 1000000; ++i)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
                primes[j] = false;
        }
    }

    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        int cnt = 0;
        for (int j = 2; j < n / 2 + 1; ++j)
        {
            if (primes[j] && primes[n - j])
                ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}