/* ------------------------------------------------------------------|
一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：

'A' -> 1
'B' -> 2
...
'Z' -> 26
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：

"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。

题目数据保证答案肯定是一个 32 位 的整数。

 

示例 1：

输入：s = "12"
输出：2
解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2：

输入：s = "226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
示例 3：

输入：s = "0"
输出：0
解释：没有字符映射到以 0 开头的数字。
含有 0 的有效映射是 'J' -> "10" 和 'T'-> "20" 。
由于没有字符，因此没有有效的方法对此进行解码，因为所有数字都需要映射。
示例 4：

输入：s = "06"
输出：0
解释："06" 不能映射到 "F" ，因为字符串含有前导 0（"6" 和 "06" 在映射中并不等价）。
 

提示：

1 <= s.length <= 100
s 只包含数字，并且可能包含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	动态规划法
*   dp[i] = dp[i-1](s[i] != '0') + dp[i-2](s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6 MB, 在所有 C++ 提交中击败了79.46%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int n;
int numDecodings(string s) {
    n = s.size();
    vector<int> dp(n, 0);
    if (s[0] == '0') {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != '0') {
            if (i == 0) {
                dp[0] = 1;
            }
            else {
                dp[i] += dp[i - 1];
            }
        }
        if (i > 0) {
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                if (i == 1) {
                    dp[1] += 1;
                }
                else {
                    dp[i] += dp[i - 2];
                }
            }
        }
    }
    return dp[n - 1];

    //int pre = 1;
    //int curr = 1;
    //for (int i = 1; i < n; ++i) {
    //    int tmp = curr;
    //    if (s[i] == '0') {
    //        if (s[i - 1] <= '2' && s[i - 1] != '0') {
    //            curr = pre;
    //        }
    //        else {
    //            return 0;
    //        }
    //    }
    //    else {
    //        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
    //            curr += pre;
    //        }
    //    }
    //    pre = tmp;
    //}
    //return curr;
}