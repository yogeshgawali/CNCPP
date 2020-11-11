#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int i, x, y, k;
    x = strlen(a);
    y = strlen(b);
    k = (x=y)?y:((x<y)?y:x);
    for(i=0;i<k;i++)
    {
        if(a[i] < b[i])
            return 0;
        else if(a[i] > b[i])
            return 1;
    }
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int i, x, y, k;
    x = strlen(a);
    y = strlen(b);
    k = (x=y)?y:((x<y)?y:x);
    for(i=0;i<k;i++)
    {
        if(a[i] < b[i])
            return 1;
        else if(a[i] > b[i])
            return 0;
    }
}

int diffChars(const char* s)
{
    int i, j=0, cnt=0, l = strlen(s);
    int ar[26];
    for(i=0; i<26; i++)
        ar[i]=0;
    for(i=0; i<l; i++)
    {
        j = s[i] - 97;
        if(!ar[j])
            ar[j]=1;
    }
    for(i=0; i<26; i++)
        cnt += ar[i];
    return cnt;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int x = diffChars(a);
    int y = diffChars(b);
    if(x<y)
        return 0;
    else if(x > y)
        return 1;
    else
        return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int x = strlen(a);
    int y = strlen(b);
    if(x<y)
        return 0;
    else if(x>y)
        return 1;
    else
        return lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i,j;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(cmp_func(arr[i],arr[j]))
            {
                char *tmp;
                tmp = arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}



int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    printf("\n");
    string_sort(arr, n, lexicographic_sort);
    printf("lexicographic sort:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    printf("lexicographic reverse sort:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    printf("sort_by_length:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    printf("sort_by_number_of_distinct_characters:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}

/*
Sample Input 0

4
wkue
qoi
sbv
fekls


Sample Output 0

fekls
qoi
sbv
wkue

wkue
sbv
qoi
fekls

qoi
sbv
wkue
fekls

qoi
sbv
wkue
fekls
*/

/*
sample input 1

44
katwgrwmww
fczzelkko
ggoxik
glsrml
uflg
jiil
h
ttdhikpxjy
mewevksl
xynakykv
t
boskwc
v
agzedecnwp
vpk
zihxocmr
e
oj
mw
sw
vaolydf
spsuzbrp
dg
jk
sp
pvqnhnpxan
ikuze
zhh
mmx
whuqyshvku
z
baydki
jmo
vwxhk
qgdlxdf
brzfqih
jkcrkogzw
xvjh
bquo
attb
ugfdnxm
cfkqllo
kkyu
bkyq

sample output 1

agzedecnwp
attb
baydki
bkyq
boskwc
bquo
brzfqih
cfkqllo
dg
e
fczzelkko
ggoxik
glsrml
h
ikuze
jiil
jk
jkcrkogzw
jmo
katwgrwmww
kkyu
mewevksl
mmx
mw
oj
pvqnhnpxan
qgdlxdf
sp
spsuzbrp
sw
t
ttdhikpxjy
uflg
ugfdnxm
v
vaolydf
vpk
vwxhk
whuqyshvku
xvjh
xynakykv
z
zhh
zihxocmr

zihxocmr
zhh
z
xynakykv
xvjh
whuqyshvku
vwxhk
vpk
vaolydf
v
ugfdnxm
uflg
ttdhikpxjy
t
sw
spsuzbrp
sp
qgdlxdf
pvqnhnpxan
oj
mw
mmx
mewevksl
kkyu
katwgrwmww
jmo
jkcrkogzw
jk
jiil
ikuze
h
glsrml
ggoxik
fczzelkko
e
dg
cfkqllo
brzfqih
bquo
boskwc
bkyq
baydki
attb
agzedecnwp

e
h
t
v
z
dg
jk
mw
oj
sp
sw
jmo
mmx
vpk
zhh
attb
bkyq
bquo
jiil
kkyu
uflg
xvjh
ikuze
vwxhk
baydki
boskwc
ggoxik
glsrml
brzfqih
cfkqllo
qgdlxdf
ugfdnxm
vaolydf
mewevksl
spsuzbrp
xynakykv
zihxocmr
fczzelkko
jkcrkogzw
agzedecnwp
katwgrwmww
pvqnhnpxan
ttdhikpxjy
whuqyshvku

e
h
t
v
z
dg
jk
mmx
mw
oj
sp
sw
zhh
attb
jiil
jmo
kkyu
vpk
bkyq
bquo
uflg
xvjh
ggoxik
glsrml
ikuze
vwxhk
baydki
boskwc
cfkqllo
qgdlxdf
spsuzbrp
xynakykv
brzfqih
fczzelkko
katwgrwmww
mewevksl
pvqnhnpxan
ugfdnxm
vaolydf
jkcrkogzw
whuqyshvku
zihxocmr
agzedecnwp
ttdhikpxjy

*/


/*

Description:

To sort a given array of strings into lexicographically increasing order or
into an order in which the string with the lowest length appears first,
a sorting function with a flag indicating the type of comparison strategy
can be written. The disadvantage with doing so is having to rewrite the function
for every new comparison strategy.
A better implementation would be to write a sorting function that accepts a pointer
to the function that compares each pair of strings. Doing this will mean only passing
a pointer to the sorting function with every new comparison strategy.

Given an array of strings, you need to implement a  function which sorts the strindg
according to a comparison function, i.e, you need to implement the function:

void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b)){

}

The arguments passed to this function are:

an array of strings :
length of string array:
pointer to the string comparison function:
You also need to implement the following four string comparison functions:

 to sort the strings in lexicographically non-decreasing order.

 to sort the strings in lexicographically non-increasing order.

 to sort the strings in non-decreasing order of the number of distinct characters present in them. If two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first.

 to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first.


Input Format

You just need to complete the function string\sort and implement the four string comparison functions.

Constraints

 No. of Strings
 Total Length of all the strings
You have to write your own sorting function and you cannot use the inbuilt  function
The strings consists of lower-case English Alphabets only.
Output Format

The locked code-stub will check the logic of your code. The output consists of the strings sorted according to the four comparsion functions in the order mentioned in the problem statement.
*/
