// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        string exp;
        for (char c : s)
        {
            if (c != ' ')
            {
                exp += c;
            }
        }

        stack<int> countStack;

        int current = 0;
        int sign = 1;
        string currentNum;

        int i = 0;
        while (i < exp.length())
        {
            char currentChar = exp[i];
            if (currentChar == '-')
            {
                int num = stoi(currentNum.length() > 0 ? currentNum : "0");
                current += sign * num;
                sign = -1;
                currentNum = "";
            }
            else if (currentChar == '+')
            {
                int num = stoi(currentNum.length() > 0 ? currentNum : "0");
                current += sign * num;
                // cout << current << " current" << endl;
                sign = 1;
                currentNum = "";
            }
            else if (currentChar == '(')
            {
                // int num = stoi(currentNum.length() > 0 ? currentNum : "0");
                // current += sign * num;
                countStack.push(current);
                // cout << current << " current" << endl;

                current = 0;
            }
            else if (currentChar == ')')
            {
                int top = countStack.top();
                countStack.pop();
                int total = top + (current * sign);
                current = total;
            }
            else
            {
                currentNum += currentChar;
            }

            i++;
        }
        current += sign * stoi(currentNum.length() > 0 ? currentNum : "0");
        cout << current << " current" << endl;
        return 0;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73};
    // string s = "()";
    int result = obj.calculate("1-(1+2)");
    cout << result << endl;
    return 0;
}