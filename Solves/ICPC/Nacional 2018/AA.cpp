
int tree[MAXN];
int lazy[MAXN];

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {
    if (lazy[si] != 0) {
        tree[si] += (se-ss+1)*lazy[si]; 
        if (ss != se) { 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        }
        lazy[si] = 0; 
    } 

    if (ss>se || ss>ue || se<us) 
        return ; 
  
    if (ss>=us && se<=ue) 
    { 
        // Add the difference to current node 
        tree[si] += (se-ss+1)*diff; 
  
        // same logic for checking leaf node or not 
        if (ss != se) 
        { 
            // This is where we store values in lazy nodes, 
            // rather than updating the segment tree itelf 
            // Since we don't need these updated values now 
            // we postpone updates by storing values in lazy[] 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
  
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
  
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 
  
void updateRange(int n, int us, int ue, int diff) { 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
  
int getSumUtil(int ss, int se, int qs, int qe, int si) { 
    if (lazy[si] != 0) { 
        tree[si] += (se-ss+1)*lazy[si]; 
  
        if (ss != se) { 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 

        lazy[si] = 0; 
    } 
  
    if (ss>se || ss>qe || se<qs) 
        return 0; 

    if (ss>=qs && se<=qe) 
        return tree[si]; 

    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 
  
int getSum(int n, int qs, int qe) {
    return getSumUtil(0, n-1, qs, qe, 0); 
}
 
  
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {1, 3, 5, 7, 9, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // Build segment tree from given array 
    constructST(arr, n); 
  
    // Print sum of values in array from index 1 to 3 
    printf("Sum of values in given range = %d\n", 
           getSum(n, 1, 3)); 
  
    // Add 10 to all nodes at indexes from 1 to 5. 
    updateRange(n, 1, 5, 10); 
  
    // Find sum after the value is updated 
    printf("Updated sum of values in given range = %d\n", 
            getSum( n, 1, 3)); 
  
    return 0; 
} 
