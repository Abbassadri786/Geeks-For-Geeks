void sort012(int a[], int n)
    {
        int k=0,c1=0,c2=0,c3=0;
        
        for(int i=0; i<n; i++){
            if(a[i]==0){c1++;}
            else if(a[i]==1){c2++;}
            else {c3++;}
        }
        
        for(int i=0; i<c1; i++)a[k++]=0;
        for(int i=0; i<c2; i++)a[k++]=1;
        for(int i=0; i<c3; i++)a[k++]=2;
    }
