/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
char smallest_character(char str[], char c,int i)
{
    if(str[i]=='\0')
       return str[0];
    if(str[i]>c)
       return str[i];
    smallest_character(str,c,++i);
}
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
int main()
{
    struct timespec start, end;
    double cpu_time;
    char str[]="cdefjmnpsv";
    char c;
    printf("The sorted character array is %s \n",str);
    printf("Enter the search character : ");
    scanf("%c",&c);
    //c = getche();
    clock_gettime(CLOCK_REALTIME, &start);
    assert(printf("%c\n",smallest_character(str, c,0)));
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printf("\nexecution time of iterative : %lf sec\n", cpu_time);
    fflush(stdin);
    

    return 0;
}
