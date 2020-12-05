#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void improved_bubblesort(int a[], int n)
{
    int i, j;
    bool isExchanged = false;
    for (i = 1; i < n; ++i)
    {
        for (j = n - 1; j >= i; --j)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                isExchanged = true;
            }
        }

        if (!isExchanged)
            return;
    }
}
int main()
{
    int a[100];
    for (int i = 0; i < 100; ++i)
        a[i] = (i + 13) - (a[i] % 3) * i;
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    cout << endl;
    improved_bubblesort(a, 10);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}