string transform(string s)
{
    // code here
    s[0] = s[0] -'a' + 'A';
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            s[i +1] = s[i+1] - 'a' + 'A';
        }
        else{
            continue;
        }
    }
    return s;
}
