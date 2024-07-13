#include <bits/stdc++.h>
using namespace std;
void buble_sort(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}
void selection_sort(float a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            float temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}
void insert_sort(float a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        float temp = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > temp)
        {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = temp;
    }
}
int main()
{
    float a[] = {1, 4, 2, 5, 12, 4, 2, 34, 32, 54, 18};
    // int n=11;

    // selection_sort(a, n);
    // for (auto x : a)
    // {
    //     cout<<x<<" ";
    // }
    int size = sizeof(a) / sizeof(int);
    cout << size;

    return 0;
}
