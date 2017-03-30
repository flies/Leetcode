//***************************************************************************
//按位与
//https://leetcode.com/problems/bitwise-and-of-numbers-range/#/description
//ans&(ans-1)<ans
//***************************************************************************
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(n==0){return 0;}
        int ans=n;
        while(ans>m){
            ans=ans&(ans-1);
        }
    return ans;
    }
};
