#include <iostream>
#include <algorithm>

using namespace std;

class binarySet
{
private:
    long *A;
    long *B;
    long *C;
    int n, m;
    long length;
    long maximum;

public:
    binarySet(int n, int m)
    {
        A = new long[n];
        B = new long[m];
        this->n = n;
        this->m = m;
        length = 0;
        maximum = -100000;
        C = new long[n + m];
    }

    void difference();
    void displayDifference();
    void setA();
    void setB();

    ~binarySet()
    {
        delete[] A, B, C;
    }
};

void binarySet ::setA()
{
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        maximum = max(maximum, A[i]);
    }
}

void binarySet ::setB()
{
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        maximum = max(maximum, B[i]);
    }
}

void binarySet ::difference()
{
    maximum++;
    long hash[maximum] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[A[i]] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        if (hash[B[i]] == 1)
            hash[B[i]] = 2;
    }
    for (int i = 0; i < maximum; i++)
    {
        if (hash[i] == 1)
            C[length++] = i;
    }
}

void binarySet ::displayDifference()
{
    for (int i = 0; i < length; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        binarySet bSet(n, m);

        bSet.setA();
        bSet.setB();

        bSet.difference();
        bSet.displayDifference();
    }
}