class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int index, int parts, string current) {
        // We already have 4 parts
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back();  // Remove last '.'
                ans.push_back(current);
            }
            return;
        }

        // Try segments of length 1, 2, or 3
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {

            string segment = s.substr(index, len);

            // Leading zero is not allowed
            if (segment.size() > 1 && segment[0] == '0')
                break;

            int value = stoi(segment);

            // IP part cannot exceed 255
            if (value > 255)
                break;

            backtrack(
                s,
                index + len,
                parts + 1,
                current + segment + "."
            );
        }
    }

    vector<string> restoreIpAddresses(string s) {
        // Valid IPv4 needs between 4 and 12 digits
        if (s.size() < 4 || s.size() > 12)
            return {};

        backtrack(s, 0, 0, "");

        return ans;
    }
};