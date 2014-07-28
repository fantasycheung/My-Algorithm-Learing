/* The classic 8 Queen Problem as follows:
 * Try to put the 8 queens in the chess board
 * and prevent each of them to attack each other.
 * Figure out how many ways are there.
 *
 * Analysis:
 * 1. It's easy to find out that every column and every row
 *    can only have only one queen or it will attack the one
 *    on the same row or column.
 * 2. The BackTracting algorithm is very useful here. The primary goal
 *    of this algorithm is to try out every possible way in an efficient
 *    way such as if we check row by row, if the next row doesn't work
 *    we go back to the previous row and check on.
 * 3. We can think the way of queen put on the chess board like a vector:
 *    X_{n} = {x_{1},x_{2},\dots,x_{8}},and x_{i} = 1 to 8,x_{i} = k mean that the
 *    queen has been put on the k-th position on row i.
 * 4. The time cost is O(n!).
 *
 * Author: Falcon
 * Date  : 2014-07-28
 */
#include <iostream>
#include <math.h>
#define N 8
int x[N],sums = 0;
void show(){
    int i;
    printf("(");
    for (i = 0; i < N; i++) {
        printf(" %d ", x[i]);
    }
    printf(")\n");
    sums++;
}
bool isPlace(int k){
    /*  the function isPlace is to check whether or not queen can be put on k-ith column. */
    int i;
    for (i = 0; i < k; i++) {
        if (x[i] == x[k] || abs(x[i] - x[k]) == (k - i)) {
            /* watch out the way to check on the diagram path. */
            return false;
        }
    }
    return true;
}

void Queen(int n){
    int i;
    for (i = 1; i <= N; i++) {
        x[n] = i;
        if (isPlace(n)) {
            if (n==(N-1)) {
                show();
            }
            else {
                Queen(n+1);
            }
        }
    }
}
int main(int argc, char const* argv[])
{
    Queen(0);
    printf("There are %d ways to put 8 queens on the chess board. \n", sums);
    return 0;
}
