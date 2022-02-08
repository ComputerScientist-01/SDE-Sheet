class Solution {
public:
    int addDigits(int num) {
        // we use the property of 9
        if(num == 0) return 0;
        if(num % 9 == 0 ) return 9;
        return (num%9);
    }
};