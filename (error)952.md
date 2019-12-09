# 952.largestComponentSize按公因数计算最大组件大小
1. version 1
```c++
//没考虑无素数情况
class Solution {
public:
    int flag=0;
    vector<vector<int>> Prime;
    vector<int> v;
    bool isPrimeNumber(int a){
        if(a<=2){
            return true;
        }
        for (int i=2;i<a;i++){
            if(a%i==0) return false;
        }
        return true;
    }
    //Find
    bool isSameExist(vector<int> A,vector<int> B){
        if(A.size()==1||B.size()==1) return false;
        for (auto it=B.begin();it<B.end();it++){
            if(find(A.begin(),A.end(),*it)!=A.end()){
                return true;
            }
        }
        return false;
    }
    //Merge
    void mergeAB(vector<int>& A,vector<int>& B){
        A.insert(A.end(),B.begin(),B.end());
        sort(A.begin(),A.end());
        auto iter = unique(A.begin(), A.end());
        A.erase(iter,A.end());
        B.erase(B.begin()+1,B.end());
        return ;
    }
    int largestComponentSize(vector<int>& A) {
        if (A.size()<=1) return A.size();
        for(auto it=A.begin();it<A.end();it++){
            v.clear();
            if(isPrimeNumber(*it)){
                flag++;
                v.push_back(*it);
                Prime.push_back(v);
                *it=-1;
            }
        }
        for(int i=0;i<flag;i++){
            for(auto it=A.begin();it<A.end();it++){
                if(*it%Prime[i][0]==0){
                    Prime[i].push_back(*it);
                }
            }
        }
        for(int i=0;i<flag-1;i++){
            for(int j=i+1;j<flag;j++){
                if(isSameExist(Prime[i],Prime[j])) mergeAB(Prime[i],Prime[j]);
            }
        }
        int max;
        for(int k=0;k<Prime.size();k++){
            max=max>Prime[k].size()?max:Prime[k].size();
        }
        return max;
    }
};
```
2. version 2
上一个问题解决了，60/100 输入错误
输入
> [2,7,522,526,535,26,944,35,519,45,48,567,266,68,74,591,81,86,602,93,610,621,111,114,629,641,131,651,142,659,669,161,674,163,180,187,190,194,195,206,207,218,737,229,240,757,770,260,778,270,272,785,274,290,291,292,296,810,816,314,829,833,841,349,880,369,147,897,387,390,905,405,406,407,414,416,417,425,938,429,432,926,959,960,449,963,966,929,457,463,981,985,79,487,1000,494,508]

输出
> 83

答案
> 84

代码
```c++
class Solution {
public:
   vector<int> prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359 };
//Find
    bool isSameExist(vector<int> A, vector<int> B) {
        if (A.size() <= 1 || B.size() <= 1) return false;
        for (auto it = B.begin(); it < B.end(); it++) {
            if (find(A.begin(), A.end(), *it) != A.end()) {
                return true;
            }
        }
        return false;
    }
//Merge
    void mergeAB(vector<int>& A, vector<int>& B) {
        A.insert(A.end(), B.begin(), B.end());
        sort(A.begin(), A.end());
        auto iter = unique(A.begin(), A.end());
        A.erase(iter, A.end());
        B=A;
        return;
    }
    int largestComponentSize(vector<int>& A) {
        map<int, vector<int>> primeNumber;
        if (A.size() <= 1) return A.size();
        int max = *max_element(A.begin(), A.end());
        int max_p = 0;
        for (auto it = A.begin(); it < A.end(); it++) {
            for (int p = 0; p<72; p++) {
                if (prime[p] > max/2) break;
                if (*it % prime[p] == 0) {
                    primeNumber[p].push_back(*it);
                    max_p = p > max_p ? p : max_p;
                }
            }
        }
        for (int i = 0; i < max_p; i++) {
            for (int j = i + 1; j <= max_p; j++) {
                if (isSameExist(primeNumber[i], primeNumber[j])) mergeAB(primeNumber[i], primeNumber[j]);
            }
        }
        int length=0;
        for (int k = 0; k <= max_p; k++) {
            length = length > primeNumber[k].size() ? length : primeNumber[k].size();
        }
        return length;
    }
};
```
