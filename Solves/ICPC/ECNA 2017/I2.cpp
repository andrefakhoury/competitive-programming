#include <iostream>
using namespace std;

const int MAXSIZE =8;

const char LEAF = 'L';
const int PARENCOST = 1;
const int INVCOST = 2;
const int IMPOSSIBLE = 1000000;

int original[MAXSIZE];

struct node
{
    int val;
    char op;
    node *left, *right;
};

void printTree(node *tree)
{
    if (tree->op == LEAF)
        cout << tree->val;
    else {
        cout << '(';
        printTree(tree->left);
        cout << ')' << tree->op << '(';
        printTree(tree->right);
        cout << ')';
    }
}

int countParens(node *tree)
{
    if (tree->op == LEAF)
        return 0;
    else {
        int count = countParens(tree->left) + countParens(tree->right);
        if (tree->op == '-' && tree->right->op == '-')
            count++;
        else if (tree->op == '*' || tree->op == '/') {
            if (tree->left->op == '+' || tree->left->op == '-')
                count++;
            if (tree->right->op == '+' || tree->right->op == '-')
                count++;
            if (tree->op == '/' && tree->right->op == '/')
                count++;
        }
        return count;
    }
}

int numParens(node tree)
{
    int count = countParens(&tree);
//    printTree(&tree);
//    cout << ' ' << count << endl;
    return count;
}

int find24(node tlist[], int numTerms)
{
//cout << "here, numTerms = " << numTerms << endl;
    if (numTerms == 1) {
        if (tlist[0].val == 24)
            return numParens(tlist[0]);
        else
            return IMPOSSIBLE;
    }
    else {
        int cost = IMPOSSIBLE;
        for(int i=1; i<numTerms; i++) {
            node newList[numTerms-1];
            for(int j=0; j<i-1; j++)
                newList[j] = tlist[j];
            for(int j=i; j<numTerms-1; j++)
                newList[j] = tlist[j+1];
            newList[i-1].left = tlist+(i-1);
            newList[i-1].right = tlist+i;
            newList[i-1].op = '+';
            newList[i-1].val = tlist[i-1].val+tlist[i].val;
            int val = find24(newList, numTerms-1);
            if (val < cost)
                cost = val;
            newList[i-1].op = '-';
            newList[i-1].val = tlist[i-1].val-tlist[i].val;
            val = find24(newList, numTerms-1);
            if (val < cost)
                cost = val;
            newList[i-1].op = '*';
            newList[i-1].val = tlist[i-1].val*tlist[i].val;
            val = find24(newList, numTerms-1);
            if (val < cost)
                cost = val;
            if (tlist[i].val != 0 && tlist[i-1].val%tlist[i].val == 0) {
                newList[i-1].op = '/';
                newList[i-1].val = tlist[i-1].val/tlist[i].val;
                val = find24(newList, numTerms-1);
                if (val < cost)
                    cost = val;
            }
        }
        return cost;
    }
}

int numInversions(int list[], int n)
{
    int count = 0;
    int buildList[n];
    for(int i=0; i<n; i++)
        buildList[i] = original[i];
    for(int i=0; i<n-1; i++) {
        int j=i;
        while (buildList[j] != list[i])
            j++;
        count += j-i;
        int tmp = buildList[j];
        for(int k=j-1; k >= i; k--)
            buildList[k+1] = buildList[k];
        buildList[i] = tmp;
    }
    return count;
}

int permute(int list[], int index, int n)
{
    if (index == n) {
        int numInv = numInversions(list, n);
//for(int i=0; i<n; i++)
//cout << list[i] << ' ';
//cout << numInv << endl;
        node tlist[n];
        for(int i=0; i<n; i++) {
            tlist[i].val = list[i];
            tlist[i].op = LEAF;
            tlist[i].left = tlist[i].right = 0;
        }
        return find24(tlist, n)*PARENCOST + numInv*INVCOST;
    }
    int cost = permute(list, index+1, n);
    for(int i=index+1; i<n; i++) {
        int tmp = list[i];
        list[i] = list[index];
        list[index] = tmp;
        int val = permute(list, index+1, n);
        if (val < cost)
            cost = val;
        tmp = list[i];
        list[i] = list[index];
        list[index] = tmp;
    }
    return cost;
}

int permute(int list[], int len)
{
    return permute(list, 0, len);
}

int main()
{
    int list[MAXSIZE];
    int n;

/**/
//    cin >> n;
    n = 4;
    for(int i=0; i<n; i++)
        cin >> list[i];
    for(int i=0; i<n; i++)
        original[i] = list[i];
    int ans = permute(list, n);
    if (ans >= IMPOSSIBLE)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}
