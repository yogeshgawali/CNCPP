#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int freqA[26], freqB[26], i;
    for(i=0 ; i< 26 ; i++)
        freqA[i] = freqB[i] = 0;
    for(i = 0 ; i< a.length() ; i++)
        freqA[(int)(a[i] - 'a')]++;
    for(i = 0 ; i< b.length() ; i++)
        freqB[(int)(b[i] - 'a')]++;
    int outp = 0;
    for(i=0 ; i< 26 ; i++)
    {
        outp = outp + abs(freqA[i] - freqB[i]);//freqA[i] + freqB[i] - 2*min(freqA[i],freqB[i]);
    }
    return outp;
}

int main()
{
    string a;
    cin>>a;

    string b;
    cin>>b;

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}
