﻿/* ------------------------------------------------------------------|
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

题目数据保证答案肯定是一个 32 位的整数。

 

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
示例 4：

输入：s = "1"
输出：1
示例 5：

输入：s = "2"
输出：1
 

提示：

1 <= s.length <= 100
s 只包含数字，并且可能包含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	动态规划法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.4 MB, 在所有 C++ 提交中击败了26.63%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

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

int numDecodings(string s) {
    if (s[0] == '0') {
        return 0;
    }
    int pre = 1;
    int curr = 1;
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') {
                curr = pre;
            }
            else {
                return 0;
            }
        }
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
            curr += pre;
        }
        pre = tmp;
    }
    return curr;

}