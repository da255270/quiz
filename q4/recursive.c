/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}


int maxSubArray(int A[], int n)
{
    int max = A[0];
    int currentMax = A[0];

    for (int i = 1; i < n; i++) {
        currentMax = max(A[i], currentMax + A[i]);
        max = max(max, currentMax);
    }
    return max;
}

int main()
{
    struct timespec start, end;
    double cpu_time;

    int array[9] = { -2,1,-3,4,-1,2,1,-5,4 };
    int max;

    clock_gettime(CLOCK_REALTIME, &start);
    max = maxSubArray(array,9);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printf("ans = %d execution time = %lf nsec\n", max, cpu_time);

    return 0;
}
