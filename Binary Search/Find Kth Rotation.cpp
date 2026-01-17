class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low = 0, high = arr.size() - 1;
        int mini = INT_MAX;
        int index = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[low] <= arr[high]){
                if(arr[low] < mini){
                    index = low;
                    mini = arr[low];
                }
                return index;
            }
            // if left half sorted then pick min and now go on searching on right half so low = mid + 1
            if(arr[low] <= arr[mid]){
                if(arr[low] < mini){
                    index = low;
                    mini = arr[low];
                }
                low = mid + 1;
            }
            // if right half is sorted then pick min and now go on searching on left side
            else{
                if(arr[mid] < mini){
                    index = mid;
                    mini = arr[mid];
                }
                high = mid -1;
            }
        }

        return index;
        
    }
};

