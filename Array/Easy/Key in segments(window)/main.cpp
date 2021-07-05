#include <iostream>

using namespace std;

bool find_key_segment(int arr[], int n, int key, int segment_size)
{
    bool found;
    int i;
    for (i = 0; i < n; i += segment_size)
    {
        // Print current segment : NOT Required_______________________________________________________________________
        for (int j = 0; j < segment_size && j < n; j++)
        {
            if (i + j >= n)
                break;

            cout << arr[j + i] << " ";
        }
        cout << endl;

        // LAST Segment is out of range_______________________________________________________________________
        if (i + segment_size >= n)
            break;

        // Reset every iteration i.e every new segment
        found = false;

        // Linear Search in current segment_______________________________________________________________________
        // OR for (int j = 0; j < segment_size && j < n; j++)
        for (int j = i; j < (i + segment_size) && j < n; j++)
        {
            //                  V [i + j]
            found = (key == arr[j]) ? true : false;
            // No need to search further if found
            if (found)
                break;
        }

        // If not found in ANY one of the segments_______________________________________________________________________
        if (!found)
            return false;
    }

    // ONLY search if key was found in the previous segment_______________________________________________________________________

    // Check Last Segment_______________________________________________________________________

    found = false;
    for (int i = n - segment_size; i < n; i++)
    {
        found = (key == arr[i]) ? true : false;
        // No need to search further if found
        if (found)
            break;
    }

    // If found loop would break before i reached n
    if (i == n)
        return false;
    else
        return true;
}

int main()
{

    int arr[] = {1, 2, 3, 1, 5, 6, 1, 8, 9, 1};
    int n = 10;
    // Should be present in every segment
    int key = 1;

    int segment_size = 3;
    // Segments are =>
    // {1,2,3}
    // {1,5,6}
    // {1,8,9}
    // {1}

    printf(find_key_segment(arr, n, key, segment_size) ? "Key Found in every segment" : "Key missing in a few or all of the segments");

    return 0;
}
