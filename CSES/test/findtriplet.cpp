 
int findTriplets(int a[], int n, int sum)
{
    int i;
 
    sort(a, a + n);
 
  int ctr=0;
 for (i = 0; i < n - 2; i++)
    {
        if (i == 0 || a[i] > a[i - 1])
        {
            int start = i + 1;
 
            int end = n - 1;
 
            int target = sum - a[i];
 
            while (start < end)
            {
                
                if (start > i + 1
                    && a[start] == a[start - 1])
                {
                    start++;
                    continue;
                }
 
               
                if (end < n - 1
                    && a[end] == a[end + 1])
                {
                    end--;
                    continue;
                }
 
                
                if (target == a[start] + a[end])
                {
                    ctr++;
                }
               
                else if (target > (a[start] + a[end]))
                {
                    start++;
                }
                
                else {
                    end--;
                }
            }
        }
    }
 
 return ctr;
}