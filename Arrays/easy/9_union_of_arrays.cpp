#include <iostream>
#include <vector>
#include <set>
using namespace std;

void brute(vector<int> arr1, vector<int> arr2, int n1, int n2)
{
    // step1
    set<int> st;
    for (int i = 0; i < n1; i++)
    {
        st.insert(arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        st.insert(arr2[i]);
    }

    // step2
    int i = 0;
    vector<int> un(st.size());
    for (auto it : st)
    {
        un[i++] = it;
    }

    for (int i = 0; i < st.size(); i++)
    {
        cout << un[i] << " ";
    }
}

void optimal(vector<int> arr1, vector<int> arr2, int n1, int n2)
{
    int i = 0;
    int j = 0;

    vector<int> un;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (un.size() == 0 || un.back() != arr1[i])
            {
                un.push_back(arr1[i]);
            }
            i++;
        }
        
        else
        {
            if (un.size() == 0 || un.back() != arr2[j])
            {
                un.push_back(arr2[j]);
            }
            j++;
        }
        
    }

    while (i < n1)
    {
        if (un.size() == 0 || un.back() != arr1[i])
        {
            un.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2)
    {
        if (un.size() == 0 || un.back() != arr2[j])
        {
            un.push_back(arr2[j]);
        }
        j++;
    }

    for (int i = 0; i < un.size(); i++)
    {
        cout<<un[i];
    }
    
}

int main()
{
    int n1;
    cout << "enter the size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cout << "enter the size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr2[i];
    }

    optimal(arr1, arr2, n1, n2);

    return 0;
}