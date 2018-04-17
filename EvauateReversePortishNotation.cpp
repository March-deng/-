/*
描述
逆波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的逆波兰表示法为+ 2 3。逆波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 + 3) * 4的逆波兰表示法为* + 2 3 4。本题求解逆波兰表达式的值，其中运算符包括+ - * /四个。
输入
输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
输出
输出为一行，表达式的值。
可直接用printf("%f\n", v)输出表达式的值v。
*/
/*本题用堆栈解决，避免了递归解法*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int str2int(string s) // string转int
    {
        int result = 0;
        int base = 1;
        int t = 1; // 正负号

        if (s[0] == '-')
            t = -1;

        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                result += base * (s[i] - '0');
                base *= 10;
            }
        }

        return result * t;
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<int> k;

        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int Num2 = k.top(); // 第一个取出的是右操作数
                k.pop();
                int Num1 = k.top(); // 左操作数
                k.pop();

                if (tokens[i] == "+"){
                    k.push(Num1 + Num2);
                }
                else if (tokens[i] == "-"){
                    k.push(Num1 - Num2);
                }
                else if (tokens[i] == "*"){
                    k.push(Num1 * Num2);
                }
                else if (tokens[i] == "/"){
                    k.push(Num1 / Num2);
                }
            }
            else
                k.push(str2int(tokens[i]));
        }
        return k.top(); // 最后栈剩下一个元素，就是结果
    }
};
