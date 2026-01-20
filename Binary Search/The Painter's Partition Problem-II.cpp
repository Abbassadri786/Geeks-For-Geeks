// this question similar to Split Array larget Sum, Capacity to ship packages withtin D days, Book Allocation problem
// where High = arraySum and low = MaxElement, and solve helper function for contigous sub array
class Solution {
  public:
    bool isPossible(vector<int>& a, int mid, int k)
    {
        int csum=0;
        int painters=1;
        for(int i=0;i<a.size();i++)
        {
            if(csum+a[i]<=mid)
            {
                csum=csum+a[i];
            }
            else{
                csum=a[i];
                painters++;
                if(painters>k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int minTime(vector<int>& a, int k) {
        int n=a.size();
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        int res=0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPossible(a,mid,k))
            {
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
        
    }
};
