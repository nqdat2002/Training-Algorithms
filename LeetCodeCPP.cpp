/*
    author: datnq02
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;

// Test 1, Problem 1: Reverse Integer
// AC FULL TEST
class Solution {
public:
    long long reverse(long long x) {
        int y = abs(x);
        long long res = 0, maxR = pow(2, 31) - 1;
        while(y > 0){
            int i = y % 10;
            res = res * 10 + i;
            y /= 10;
        }
        if(res > maxR) return 0;
        if(x < 0) res *= -1;
        return res;
    }
};


// Test 1, Problem 2: Roman to Integer
// AC FULL TEST
class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res = mp[s[s.size() - 1]];
        for (int i = s.length() - 2; i >= 0; --i) {
            if (mp[s[i]] < mp[s[i + 1]])
                res -= mp[s[i]];
            else
                res += mp[s[i]];
        }
        return res;
    }
};


// Test 1, Problem 3: Employees Earning More Than Their Managers
// AC FULL TEST
SELECT e.name AS Employee
FROM Employee e
JOIN Employee m ON e.managerId = m.id
WHERE e.salary > m.salary;


// Test 2, Problem 1: Reverse Words in a String
// AC FULL TEST
class Solution {
public:
    string reverseWords(string s) {
        string tmp = "", res = "";
        stringstream ss(s);
        stack<string> st;
        while(ss >> tmp){
            st.push(tmp);
        }
        while(!st.empty()){
            string a = st.top();
            st.pop();
            if (st.size())
                res += a + " ";
            else res += a;
        }
        return res;
    }
};


// Test 2, Problem 2: Merge Two Sorted Lists
// AC FULL TEST
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode res; 
        ListNode* a = &res;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                a->next = list1;
                list1 = list1->next;
            } else {
                a->next = list2;
                list2 = list2->next;
            }
            a = a->next;
        }
        a->next = list1 ? list1 : list2;

        return res.next;

    }
};


// Test 2, Problem 3: Restore IP Addresses
// AC FULL TEST
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, path;
        Try(s, 0, path, res);
        return res;
    }

    void Try(const string& s, int i, vector<string>& path, vector<string>& res) {
        if (path.size() == 4 && i == s.size()) {
            string tmp = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
            res.push_back(tmp);
            return;
        }
        for (int j = 1; j < 4; ++j) {
            if (i + j > s.size()) break;
            string seg = s.substr(i, j);
            if (isValidIp(seg)) {
                path.push_back(seg);
                Try(s, i + j, path, res);
                path.pop_back(); 
            }
        }
    }

    bool isValidIp(const string& x) {
        if (x.size() > 1 && x[0] == '0') return false;
        int num = stoi(x);
        return num >= 0 && num <= 255;
    }
};


// Test 3, Problem 1: Longest Palindromic Substring
// AC FULL TEST
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        int st = 0, maxIndex = 1;
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (dp[i + 1][j - 1] || j - i <= 2) {
                        dp[i][j] = true;
                        if (j - i + 1 > maxIndex) {
                            maxIndex = j - i + 1;
                            st = i;
                        }
                    }
                }
            }
        }
        return s.substr(st, maxIndex);
    }
};


// Test 3, Problem 2: Edit Distance
// AC FULL TEST
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size(), mx = 505;
        vector<vector<int>> dp(505, vector<int>(505, 0));
        for (int i = 0; i < mx; i++)
            dp[0][i] = i;
        for (int i = 0; i < mx; i++)
            dp[i][0] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[n][m];
    }
};


// Test 3, Problem 3: Maximal Rectangle
// NOT AC FULL TEST
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> a(m, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    a[j] += 1;
                }
            }
            res = max(res, maxArea(a));
        }
        return res;
    }
    int maxArea(vector<int>& x) {
        stack<int> st;
        x.push_back(0);
        int res = 0;
        for (int i = 0; i < x.size(); ++i) {
            while (!st.empty() && x[i] < x[st.top()]) {
                int h = x[st.top()];
                st.pop();
                int l = st.empty() ? -1 : st.top();
                int r = i - l - 1;
                res = max(res, h * r);
            }
            st.push(i);
        }
        return res;
    }
};