#include <iostream.h>
#include <conio.h>
main()
{
    int a[10]={42,34,90,87,75,35,29,54,37,44};
    int value,i;
    cout<<"Enter Value to search ";
    cin>>value;
    for(i=0;i<=9;i++)
    {
        if(value==a[i])
            break
    }
    if(i==10)
        cout<<"Value Not Present ";
    else
        cout<<"Value present at "<<i
} 