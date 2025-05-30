/*

25305. 커트라인

[문제]
2022 연세대학교 미래캠퍼스 슬기로운 코딩생활에 N명의 학생들이 응시했다.

이들 중 점수가 가장 높은 k명은 상을 받을 것이다.
이 때, 상을 받는 커트라인이 몇 점인지 구하라.

커트라인이란 상을 받는 사람들 중 점수가 가장 가장 낮은 사람의 점수를 말한다.

[입력]
첫째 줄에는 응시자의 수 N과 상을 받는 사람의 수 k가 공백을 사이에 두고 주어진다.

둘째 줄에는 각 학생의 점수 x가 공백을 사이에 두고 주어진다.

[출력]
상을 받는 커트라인을 출력하라.

[제한]
- 1 ≤ N ≤ 1000
- 1 ≤ k ≤ N
- 0 ≤ x ≤ 10000

*/

#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int students[n];
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        
        bool max_check = false;
        for (int j = 0; j < i; ++j)
        {
            if (students[j] < tmp)
            {
                max_check = true;
                for (int l = i - 1; l >= j; --l)
                    students[l + 1] = students[l];

                students[j] = tmp;
                break;
            }
        }
        if (!max_check)
            students[i] = tmp;
    }

    cout << students[k - 1];

    return 0;
}