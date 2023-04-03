//The brute force approach of this question is->

int sum=0;

for(int i=0;i<n;i++){
sum=0;

for(int j=i;j<n;j++){
sum+=arr[j];

if(sum==0){

return true;

}

}

return false;

}

//The efficient approach of this question is->

set<int>s;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum == 0){
                return true;
            }
            if(s.find(sum)!=s.end()){
                return true;
            }
            s.insert(sum);
        }
        return false;
