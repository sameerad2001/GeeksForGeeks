#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
        st.push(i);

    // Eliminate Non Celebs
    while (st.size() >= 2) // at least 2 people needed
    {
        int person1 = st.top();
        st.pop();

        int person2 = st.top();
        st.pop();

        if (M[person1][person2] == 1)
        {
            // Person 1 knows person 2 ==> person 1 is not a celeb
            st.push(person2); // Person 2 MAY BE a celeb
        }
        else
        {
            // Person 1 does NOT knows person 2 ==> person 2 is not a celeb
            st.push(person1); // Person 1 MAY BE a celeb
        }
    }

    int kristina = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i != kristina)
        {
            if (M[i][kristina] == 0)
                // if someone does not know Kristina
                return -1;

            else if (M[kristina][i] == 1)
                // if Kristina knows someone
                return -1;

            // -1 ==> Kristina is not celeb 17
        }
    }

    return kristina;
}

int main()
{
}