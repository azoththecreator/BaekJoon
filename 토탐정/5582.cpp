/*

5582. 공통 부분 문자열

[문제]
두 문자열이 주어졌을 때, 두 문자열에 모두 포함된 가장 긴 공통 부분 문자열을 찾는 프로그램을 작성하시오.

어떤 문자열 s의 부분 문자열 t란, s에 t가 연속으로 나타나는 것을 말한다.
예를 들어, 문자열 ABRACADABRA의 부분 문자열은 ABRA, RAC, D, ACADABRA, ABRACADABRA, 빈 문자열 등이다.
하지만, ABRC, RAA, BA, K는 부분 문자열이 아니다.

두 문자열 ABRACADABRA와 ECADADABRBCRDARA의 공통 부분 문자열은 CA, CADA, ADABR, 빈 문자열 등이 있다.
이 중에서 가장 긴 공통 부분 문자열은 ADABR이며, 길이는 5이다.
또, 두 문자열이 UPWJCIRUCAXIIRGL와 SBQNYBSBZDFNEV인 경우에는 가장 긴 공통 부분 문자열은 빈 문자열이다.

[입력]
첫째 줄과 둘째 줄에 문자열이 주어진다.
문자열은 대문자로 구성되어 있으며, 길이는 1 이상 4000 이하이다.

[출력]
첫째 줄에 두 문자열에 모두 포함 된 부분 문자열 중 가장 긴 것의 길이를 출력한다.

*/

#include <iostream>
#include <string>

using namespace std;

int dp[4001][4001];

int main()
{
    string a, b;
    cin >> a >> b;

    int max_length = 0;
    for (int i = 1; i <= a.length(); ++i)
    {
        for (int j = 1; j <= b.length(); ++j)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;

            max_length = max(max_length, dp[i][j]);
        }
    }

    cout << max_length;

    return 0;
}