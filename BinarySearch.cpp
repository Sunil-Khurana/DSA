#include <iostream.h>
#include <conio.h>
main()
{
    int a[10]={12,23,34,45,56,67,78,89,90.98};
    int value,beg,end,mid;
    cout<<"Enter Value to search ";
    cin>>value;
    beg=0; end=9;

    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(value==a[mid])
            break
        if(value>a[mid])
            beg=mid+1;
        else
            end=mid-1;
    }
    if(beg>end)
        cout<<"Value Not Present ";
    else
        cout<<"Value present at "<<mid;
} 