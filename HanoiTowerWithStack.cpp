/*
经典的汉诺塔问题，本题使用C++STL的栈结构，使用栈来模拟递归函数的调用
*/
#include <iostream>
#include <stack>
using namespace std;
struct Problem
{
    int n;
    char src, mid, dst;
    Problem(){}
    Problem(int n, char s, char m, char d) : n(n), src(s), mid(m), dst(d) {}
};
int main()
{
     int n;
     cin >> n;
     stack<Problem> stk;
     Problem curPrb;
     stk.push(Problem(n, 'A', 'B', 'C'));
     while (!stk.empty()) {
         curPrb = stk.top();
         stk.pop();
         if (curPrb.n == 1)
             cout << curPrb.src << "->" << curPrb.dst << endl;
         else {
             stk.push(Problem(curPrb.n-1, curPrb.mid, curPrb.src, curPrb.dst));
             cout << curPrb.src << "->" << curPrb.dst << endl;
             stk.push(Problem(curPrb.n-1, curPrb.src, curPrb.dst, curPrb.mid));
         }
     }
 }
