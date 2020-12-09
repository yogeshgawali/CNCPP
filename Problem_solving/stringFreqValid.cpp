#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    long freq[26], i, len, add=0, count;
    string y="YES", n="NO";
    len=s.length();
    for(i=0; i<26; i++)
        freq[i]=0;
    for(i=0; i<len; i++)
        freq[(int)(s[i]-'a')]++;
    for(i=0; i<len; i++)
        cout<<freq[i]<<" ";
    cout<<endl;
    for(i=0; i<26; i++)
    {
        add+=freq[i];
        if(freq[i])
            count++;
    }
    cout<<"add = "<<add<<endl;
    cout<<"count = "<<count<<endl;

    if(add%count==0)
        return y;
    else if(add%count==1)
        return y;
    else
        return n;
}

int main()
{
    string s;
    cin>>s;

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
