```
int bsgs(matrix a,matrix b,int p)
{
    int m=ceil(sqrt(p));
    matrix t=b;
    for (int i=0;i<=m;i++)
    {
        hash.insert(t,i);
        t=t*a;
    }
    matrix s=quickpow(a,m,p);
    t=s;
    for (int i=1;i<=m;i++)
    {
        int v=hash.get(t);
        if (v!=-1)
            return i*m-v;
        t=t*s;
    }
    return -1;
}
```