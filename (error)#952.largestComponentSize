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
