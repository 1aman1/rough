#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> result;
        std::string current;
        current.reserve(2 * n);

        backtrack(n, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(int n,
                   int open,
                   int close,
                   std::string &current,
                   std::vector<std::string> &result)
    {
        if (current.size() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        if (open < n)
        {
            current.push_back('(');
            backtrack(n, open + 1, close, current, result);
            current.pop_back();
        }

        if (close < open)
        {
            current.push_back(')');
            backtrack(n, open, close + 1, current, result);
            current.pop_back();
        }
    }
};

int main()
{
    Solution solution;

    for (const auto &s : solution.generateParenthesis(3))
        std::cout << s << '\n';
}