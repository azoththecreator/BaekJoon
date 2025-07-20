/*

1991. 트리 순회

[문제]
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

    - 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
    - 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
    - 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)

가 된다.

[입력]
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다.
둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다.
자식 노드가 없는 경우에는 .으로 표현한다.

[출력]
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다.
각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

*/

#include <iostream>

using namespace std;

struct leaf
{
    char value;
    int idx_left;
    int idx_right;
};

leaf tree[27];

void preorder(int curr)
{
    if (curr == 0)
        return;

    cout << tree[curr].value;
    preorder(tree[curr].idx_left);
    preorder(tree[curr].idx_right);
}

void inorder(int curr)
{
    if (curr == 0)
        return;

    inorder(tree[curr].idx_left);
    cout << tree[curr].value;
    inorder(tree[curr].idx_right);
}

void postorder(int curr)
{
    if (curr == 0)
        return;

    postorder(tree[curr].idx_left);
    postorder(tree[curr].idx_right);
    cout << tree[curr].value;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        leaf node;
        node.value = parent;
        node.idx_left = (left == '.') ? 0 : (left - 'A' + 1);
        node.idx_right = (right == '.') ? 0 : (right - 'A' + 1);

        tree[parent - 'A' + 1] = node;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
    cout << '\n';

    return 0;
}