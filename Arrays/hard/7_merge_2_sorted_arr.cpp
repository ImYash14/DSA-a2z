#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void brute(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    vector<int> arr3(m + n);
    int x = 0;
    int y = 0;
    int index = 0;
    // step1
    while (x < m && y < n)
    {
        if (arr1[x] < arr2[y])
        {
            arr3[index] = arr1[x];
            x++;
            index++;
        }
        else
        {
            arr3[index] = arr2[y];
            y++;
            index++;
        }
    }
    while (x < m)
    {
        arr3[index] = arr1[x];
        x++;
        index++;
    }
    while (y < n)
    {
        arr3[index] = arr2[y];
        y++;
        index++;
    }

    // step2
    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
            arr1[i] = arr3[i];
        else
            arr2[i - m] = arr3[i];
    }
}

void optimal1(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int x = m - 1;
    int y = 0;
    while (x >= 0 && y < n)
    {
        if (arr1[x] > arr2[y])
        {
            swap(arr1[x], arr2[y]);
            x--;
            y++;
        }
        else
            break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void optimal2(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int len = m + n;
    int gap = (len / 2) + (len % 2); // for seal value
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
           int val1, val2;

            // Determine values at left and right positions
            if (left < m) val1 = arr1[left];
            else val1 = arr2[left - m];

            if (right < m) val2 = arr1[right];
            else val2 = arr2[right - m];

            if (val1 > val2) {
                //if we are in arr1
                if (left < m && right < m)
                    swap(arr1[left], arr1[right]);
                //if we are in arr1 and arr2
                else if (left < m && right >= m)
                    swap(arr1[left], arr2[right - m]);
                //if we are in arr2
                //if (left >= m)
                else
                    swap(arr2[left - m], arr2[right - m]);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        else
        {
            gap = (gap / 2) + (gap % 2);
        }
    }
}

int main()
{
    int m;
    cout << "enter the size of arr1: ";
    cin >> m;
    vector<int> arr1(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    int n;
    cout << "enter the size of arr2: ";
    cin >> n;
    vector<int> arr2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    // brute(arr1,arr2,m,n);
    // optimal1(arr1, arr2, m, n);
    optimal2(arr1, arr2, m, n);

    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
            cout << arr1[i] << " ";
        else
            cout << arr2[i - m] << " ";
    }

    return 0;
}