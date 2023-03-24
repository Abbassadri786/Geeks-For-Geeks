string modify (string s)
        {
            //code here.
            int l=0;
            int h = s.length()-1;
            
            while(l < h){
                if((s[l] == 'a'|| s[l] == 'e' || s[l] == 'i' ||s[l] == 'o' || s[l] == 'u') && (s[h] == 'a'|| s[h] == 'e' || s[h] == 'i' ||s[h] == 'o' || s[h] == 'u')){
                    swap(s[l],s[h]);
                    l++,h--;
                }
                else if(!(s[l] == 'a'|| s[l] == 'e' || s[l] == 'i' ||s[l] == 'o' || s[l] == 'u')){
                    l++;
                }
                else{
                    h--;
                }
            }
            return s;
        }
