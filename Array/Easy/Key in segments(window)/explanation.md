- Variables <br/>
    1. array = {1,2,3,1,5,6,1,8,9,1} <br/>
    2. n = 10 <br/>
    3. key = 1 <br/>
    4. segment size = 3 <br/>
    =>**Segments** :
        ```
        {1,2,3}
        {1,5,6}
        {1,8,9}
     
        {1}
        ```
        Last Segment **INCOMPLETE** b/c <br/>
        n % seg_size  <br/> 
        **10 % 3 != 0** <br/>

- Loop while (*i < n*) 
    1. i = 0 <br />
    Segment : {1,2,3} <br />
    **PERFORM LINEAR SEARCH** for key<br />
    if found : continue<br />
    else : return **false**
    2. i = 3<br/>
    Segment : {1,5,6} <br />
    **PERFORM LINEAR SEARCH** for key<br />
    if found : continue<br />
    else : return **false**
    3. i = 6 <br />
    Segment : {1,8,9} <br />
    **PERFORM LINEAR SEARCH** for key<br />
    if found : continue<br />
    else : return **false**
    4. i = 9 <br />
    Segment : {1} <br />
    i + seg_size > n <br />
    **9 + 3 = 12 > 10** <br />
    **break**

- Last segment **may** remain unchecked if **i + seg_size > n** <br/>
        **i = n - seg_size**<br/>
        i = 9 <br />
        Segment : {1} <br />
        **PERFORM LINEAR SEARCH** for key<br />
         if found : continue<br />

- if (i == n) => the last seg did not contain key b/c if it did it would **break before i = n** <br/> 
    return **false**

- else : return **true**