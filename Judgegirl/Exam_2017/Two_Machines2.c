//Two_Machines2.c
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
        int K, a, b;
        int A_last = 0, B_last = 0; // the ready time for the last task.
        int a_last = 0, b_last = 0; // the time the last task takes on machines.
        /*
        A_n = max(A_n-1 + a_n-1, K_n); // the ready time of machine A for the n task.
        B_n = max(B_n-1 + b_n-1, A_n + a_n); //  the ready time of machine B for the n task.
        */
        while (scanf("%d%d%d", &K, &a, &b) != EOF) {
                int A = (A_last + a_last > K) ? A_last + a_last : K;
                int B = (B_last + b_last > A + a) ? B_last + b_last : A + a;
                int total = B + b;
                printf("%d\n", total);
                A_last = A;
                B_last = B;
                a_last = a;
                b_last = b;
        }
        return 0;
}