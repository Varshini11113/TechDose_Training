class Solution {
public:
    string removeStars(string s) {
        string t;

        for (auto letter : s) {
            if (letter == '*') {
                if (t.size() > 0) {
                    t.pop_back();
                }
            } else {
                t += letter;
            }
        }

        return t;
    }
};