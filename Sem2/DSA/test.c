#include <stdio.h>
#define max 10000009
#define int long long int
int a[max], given[max];
int stack[max];
int t = -1, b = -1;
void init_q()
{
    t = b = -1;
}
int isempty()
{
    if (t == -1)
        return 1;
    return 0;
}
void insert_t(int a)
{
    if (t == -1)
        t = b = 0;
    else if (t == 0)
        t = max - 1;
    else
        t--;
    stack[t] = a;
}
void insert_b(int a) //insert at b b++
{
    if (t == -1) //if empty
        t = b = 0;
    else if (b == max - 1)
        b = 0;
    else
        b++;
    stack[b] = a;
}
void delete_t() //delete from t t++
{
    if (t == b)
        t = b = -1;
    else if (t == max - 1)
        t = 0;
    else
        t++;
}
void delete_b() // b --
{
    if (t == b)
        t = b = -1;
    else if (b == 0)
        b = max - 1;
    else
        b--;
}
int peek_t()
{
    return stack[t];
}
int peek_b()
{
    return stack[b];
}
signed main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &given[i]);
    int sum = 0;
    if (n == 1)
    {
        printf("%lld\n", given[0]);
        return 0;
    }
    else if (k >= n - 1)
    {
        printf("%lld\n", given[0] + given[n - 1]);
        return 0;
    }
    else
    {
        init_q();
        for (int i = 0; i < n; i++)
        {
            a[i] = (isempty() ? given[i] : a[peek_b()] + given[i]);
            while (!isempty() && peek_b() < i - k + 1)
                delete_b();

            while (!isempty() && a[i] <= a[peek_t()])
                delete_t();
            insert_t(i);
        }
        printf("%lld\n", a[n - 1]);
    }
}