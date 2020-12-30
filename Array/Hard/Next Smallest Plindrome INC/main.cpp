#include <iostream>
#include <vector>

using namespace std;

vector<int> generateNextPalindrome(int num[], int n)
{
    vector<int> res;

    int arr[n];
    int nineCounter = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = num[i];

        if (num[i] == 9)
            nineCounter++;
    }

    if (nineCounter == n)
    {
        int temp[n + 1];
        // 999 => 1001
        temp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            temp[i] = 0;
        }

        temp[n - 1] = 1;

        res.insert(res.end(), &temp[0], &temp[n]);
        return res;
    }

    int arr[n];
    bool leftSmaller = false;
    int mid = n / 2;

    //start i and j as pointers to the pair of middle elements
    int i, j;
    i = mid - 1;
    j = mid % 2 == 0 ? mid : mid + 1;

    //i and j to the left and right side
    // 4 5 6 4 6 7 8
    //   ^       ^
    //   i       j
    //ignore middle palindrome
    while (i >= 0 && arr[i] == arr[j])
    {
        i--;
        j++;
    }

    //Check if Mirroring Left side is suffiicient
    //Left side < Right => Not Sufficient
    if (i < 0 || arr[i] < arr[j])
        leftSmaller = true;

    //Mirror the Elements
    while (i <= 0)
    {
        arr[j++] = arr[i--];
    }

    //If Mirroring was not sufficient
    //Increment middle pair and propagate carry
    if (leftSmaller)
    {
        int carry = 1;
        i = mid - 1;

        // Odd number of Elements
        if (n % 2 != 0)
        {
            arr[mid] += carry;
            carry = arr[mid] / 10;
            arr[mid] %= 10;
            j = mid + 1;
        }
        else

        {
            j = mid;
        }

        while (i >= 0)
        {
            //Increment with Carry
            arr[i] += carry;
            carry = arr[i] / 10;
            num[i] %= 10;

            //Copy the modified value to the mirror
            arr[j++] = arr[i--];
        }
    }

    res.insert(res.end(), &arr[0], &arr[n]);

    return res;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    delete[] arr;
}
