/*

1748. 수 이어 쓰기 1

[문제]
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

    - 1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수는 몇 자리 수일까?
이 수의 자릿수를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N(1 ≤ N ≤ 100,000,000)이 주어진다.

[출력]
첫째 줄에 새로운 수의 자릿수를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 1;
    int digits = 0;
    int tens = 10;
    for (; tens <= n; tens *= 10)
    {
        digits += (tens - tens / 10) * cnt;
        ++cnt;
    }
    cout << digits + (n - tens / 10 + 1) * cnt;
    
    return 0;
}