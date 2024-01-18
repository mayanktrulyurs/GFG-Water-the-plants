//Approach (Greedy sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        
        vector<pair<int,int>>v;
        
        for (int i=0;i<n;i++){
            
            if (gallery[i]==-1){
                continue;
            }
            int left=max(0,i-gallery[i]);
            int right=min(n-1,i+gallery[i]);
            
            v.push_back({left,right});
        }
        sort(v.begin(),v.end());
        
        int target=0, idx=0, cnt=0;
        
        while (target<n){
            
            int maxRightEnd=-1;
            
            while (idx<v.size()){
                if (v[idx].first<=target){
                    
                    maxRightEnd=max(maxRightEnd,v[idx].second);
                    idx++;
                }
                else{
                    break;
                }
            }
            
            if (maxRightEnd<target){
                return -1;
            }
            
            cnt++;
            target=maxRightEnd+1;
        }
        return cnt;
    }
};
