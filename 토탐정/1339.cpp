/*

1339. 단어 수학

[문제]
민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다.
이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다.
같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 두 수의 합은 99437이 되어서 최대가 될 것이다.

N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.

[입력]
첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다.
둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다.
단어는 알파벳 대문자로만 이루어져있다.
모든 단어에 포함되어 있는 알파벳은 최대 10개이고, 수의 최대 길이는 8이다.
서로 다른 문자는 서로 다른 숫자를 나타낸다.

[출력]
첫째 줄에 주어진 단어의 합의 최댓값을 출력한다.

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string words[10];
int alphabet[26];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];

        int pow = 1;
        for (int j = words[i].length() - 1; j >= 0; --j)
        {
            alphabet[words[i][j] - 'A'] += pow;
            pow *= 10;
        }
    }

    for (int i = 9; i >= 0; --i)
    {
        int biggest = -1;
        int idx;
        for (int j = 0; j < 26; ++j)
        {
            if (biggest < alphabet[j])
            {
                biggest = alphabet[j];
                idx = j;
            }
        }

        for (int j = 0; j < n; ++j)
            replace(words[j].begin(), words[j].end(), 'A' + idx, i + '0');

        alphabet[idx] = -1;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += stoi(words[i]);

    cout << sum;

    return 0;
}