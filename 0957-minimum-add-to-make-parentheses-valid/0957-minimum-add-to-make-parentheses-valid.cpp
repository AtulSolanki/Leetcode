class Solution {
public:
    int minAddToMakeValid(string S) {
        int stack_size = 0;
        int miss_match = 0;
        for (char c : S) {
            if (c == '(') {
                stack_size++; // stack push 
            }
            else if (c == ')' && stack_size > 0) {
                stack_size--; // stack pop
            } else {
                miss_match++;
            }
        }
        return stack_size + miss_match;
    }
};