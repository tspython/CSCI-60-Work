#include <iostream>
using namespace std;
int main ()
{
int a(1), b(3);
int *pa(&a), *pb(&b);
cout << *pa << ", " << *pb << endl;
pa = pb;
cout << *pa << ", " << *pb << endl;
int *pc = new int[2];
*pc = a+*pa;
*(pc+1) = b+*pb;
cout << pc[0] << ", " << pc[1] << endl;
b = 0;
int *pd = new int[2];
pd[a] = *pc + b;
pd[b] = *pc + a;
cout << *pd << ", " << *(pd+1) << endl;
cout << pd[a] << ", " << pd[b] << endl;
return 0;
}
