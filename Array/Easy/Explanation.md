# Array : Easy
## 1. Count the number of zeros
Given an array of size N consisting of only 0's and 1's. The array is <b>sorted</b> in such a manner that all the 1's are placed first and then they are followed by all the 0's. Find the count of all the 0's.

```
N = 12
Arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
Output: 3
```

```cpp
int countZeroes(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            return (n - i);
        }
        i++;
    }
    return 0;
}
```

Returns : <b> Size - (The count of 1's) </b>
<hr>

## 2. Rope Cutting
You are given N ropes. A cut operation is performed on ropes such that all of them are reduced by the length of the smallest rope. Display the number of ropes left after every cut operation until the length of each rope is zero.
```
Ropes[] = { 5, 1, 1, 2, 3, 5 }
Output : 4 3 2

Explanation : In first operation the minimum ropes is 1 so we reduce length 1 from all of them after reducing we left with 4 ropes and we do same for rest.
```

Efficient solution: works in O(nlog(n)). First we have to <b>sort</b> all Ropes in <b>increasing</b> order of there length. after that we have follow the step.
```
CuttingLength = Ropes[0]

Now Traverse a loop from left to right [1...n]
 
  During traverse we check that 
  is current ropes length is greater than zero or not 
 IF ( Ropes[i] - CuttingLength > 0 ) 
 ... IF Yes then all ropes to it's right side also greater than 0
 ... Print number of ropes remains (n - i)
 ... update Cutting Length by current rope length
 ... CuttingLength = Ropes[i]          
Do the same process for the rest.
```

```c++

```