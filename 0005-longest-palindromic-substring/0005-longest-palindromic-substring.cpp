class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        
        for (int center = 0; center < s.size(); center++) {
            // Odd-length palindrome: center is a single character
            int len1 = expandAroundCenter(s, center, center);
            // Even-length palindrome: center is between center and center+1
            int len2 = expandAroundCenter(s, center, center + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                // Calculate starting index of this palindrome
                start = center - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    // Returns the length of the palindrome expanding from left/right
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // When loop ends, left and right have gone one step too far
        return right - left - 1;
    }
};