class Solution {
public:
    int flag=0;
    vector<vector<int>> Prime(0,vector<int>(1))
    bool isPrimeNumber(int a){
        if(a<=2){
            return true;
        }
        for (int i=2;i<a;i++){
            if(a%i==0) return true;
        }
        return false;
    }
    bool isSameExist(vector<int> A,vector<int> B){}
    void mergeAB(vector<int> A,vector<int> B){}
    int largestComponentSize(vector<int>& A) {
        if (A.size()<=1) return A.size();
        for(auto it=A.begin();it<A.end();it++){
            if(isPrimeNumber(*it)){
                flag++;
                Prime.resize(flag);
                Prime[flag].push_back(*it);
                *it=-1;
            }
        }
        for(int i=0;i<flag;i++){
            for(auto it=A.begin();it<A.end();it++){
                if(*it%Prime[i][0]==0){
                    Prime[i].push_back(*it)
                    *it=-1;
                }
            }
        }
        for(int i=0;i<flag-1;i++){
            for(int j=i+1;j<flag;j++){
                if(isSameExist(Prime[i],Prime[j]) mergeAB(Prime[i],Prime[j]);
            }
        }
        int max;
        for(int k=0;k<Prime.size();k++){
            max=max>Prime[k].size()?max:Prime[k].size();
        }
        return max;
    }
};
