class Solution {
public:
    bool isPathCrossing(string path) {
        std::unordered_set<std::string> value_pairs;
        value_pairs.insert("0,0");
        
        int x = 0, y = 0;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == 'N') {
                y += 1;
            } else if (path[i] == 'S') {
                y -= 1;
            } else if (path[i] == 'W') {
                x -= 1;
            } else {
                x += 1;
            }

            std::string current_pair = std::to_string(x) + "," + std::to_string(y);
            if (value_pairs.find(current_pair) != value_pairs.end()) {
                return true;
            }

            value_pairs.insert(current_pair);
        }

        return false;
    }
};




