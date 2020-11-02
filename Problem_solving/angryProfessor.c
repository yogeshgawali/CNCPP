char* angryProfessor(int k, int a_count, int* a) {
    static char str_yes[] = "YES";
    static char str_no[] = "NO";
    int late=a_count, i;
    for(i=0; i<a_count; i++)
    {
        if(a[i]>0)
            late--;
    }
    if(late>=k)
        return str_no;
    else {
    return str_yes;
    }
}


/*
inpur:
2
4 3
-1 -3 4 2
4 2
0 -1 2 1

Output:
YES
NO
*/
