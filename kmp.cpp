void kmp(string s,vector<int>&kmp){
    int n = s.length();
    kmp.resize(n+1); //kmp[i] stores the kmp value of string at index i-1
    int i = 0,j=-1;kmp[0]=-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]) j=kmp[j];
        j++;i++;
        kmp[i]=j;
    }
}