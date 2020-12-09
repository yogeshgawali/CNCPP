#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int i=1, count=0;

    while(s[i]!='\0')
    {
        if(s[i]==s[i-1])
            count++;
        i++;
    }
    return count;
}

int main()
{
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        cin>>s;

        int result = alternatingCharacters(s);

        cout << result << "\n";
    }

    return 0;
}

/*
5
AAAA
3
BBBBB
4
ABABABAB
0
BABABA
0
AAABBB
4
*/
