#include <iostream>

using namespace std;

int main()
{
   int len,c1=0,c2=0;
   scanf("%d",&len);
   
   char S[len];
   scanf("%s",S);
   
   for(int i=0; i<len; i++)
   {
       if(S[i]=='R')
       {
           c1++;
       }
       if(S[i]=='G')
       {
           c2++;
       }
   }
   if(c1>c2)
   {
       printf("%d",c2);
   }
   else{
       printf("%d",c1);
   }
   
   return 0;
}
