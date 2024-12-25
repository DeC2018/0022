#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        dfs(n, n, "", ans);
        return ans;
    }

private:
    void dfs(int l, int r, std::string&& path, std::vector<std::string>& ans) {
        if (l == 0 && r == 0) {
            ans.push_back(path);
            return;
        }

        if (l > 0) {
            path.push_back('(');
            dfs(l - 1, r, std::move(path), ans);
            path.pop_back();
        }
        if (l < r) {
            path.push_back(')');
            dfs(l, r - 1, std::move(path), ans);
            path.pop_back();
        }
    }
};

int main() {
    int n = 3;
    Solution solution;
    std::vector<std::string> result = solution.generateParenthesis(n);

    std::cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}