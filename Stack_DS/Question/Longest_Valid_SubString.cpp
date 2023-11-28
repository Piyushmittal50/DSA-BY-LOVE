#include <iostream>
#include <stack>
using namespace std;
int validParenthess(string input)
{
  stack<int> s;
  s.push(-1);
  int maxi = 0;
  for (int i = 0; i < input.length(); i++)
  {
    char ch = input[i];

    if (ch == '(')
    {
      s.push(i);
    }
    else
    {
      s.pop();
      if (s.empty())
      {
        s.push(i);
      }
      else
      {
        int len = i - s.top();
        maxi = max(len, maxi);
      }
    }
  }
  return maxi;
}
int main()
{

  string input = ")()()(";
  int length = validParenthess(input);
  cout << "Length is : " << length << endl;
}