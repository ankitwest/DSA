#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug1(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define debug3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl


void pre(int &a,int* &ptr) //Pass by reference  
{                           //taking only the address of values
    a=a+5;
    // int b=55;
    // ptr=&b;
      debug1(a);
     debug2(ptr,*ptr);
}

void pree(int* cptr,int** ptr) //storing in pointers
{
    *cptr=*cptr+10;
    debug3(*cptr,ptr,*ptr);
}

int main(){
    int a=5;
    int* ptr=&a;
    int* ptr2;
    ptr2=&a;
    int** ptrptr=&ptr2;

    debug1(a);
    debug2(ptr,*ptr);
    debug2(ptr2,*ptr2);
    debug3(ptrptr,*ptrptr,**ptrptr);ln;

    pre(a,ptr);   //passing the values
    ln;

////

    int c=100;
    int* ptr3=&c;
    pree(&c,&ptr3);   //passing the address

    return 0;

}