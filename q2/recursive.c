/* FIXME: Implement! */
#include <stdio.h>
#include <assert.h>
char smallest_character(char str[], char c,int i)
{
    if(str[i]=='\0')
       return str[0];
    if(str[i]>c)
       return str[i];
    smallest_character(str,c,++i);
}

int main()
{
    char str[]="cdefjmnpsv";
    char c;
    printf("The sorted character array is %s \n",str);
    printf("Enter the search character : ");
    scanf("%c",&c);
    //c = getche();
    
    fflush(stdin);
    assert(printf("%c\n",smallest_character(str, c,0)));

    return 0;
}
