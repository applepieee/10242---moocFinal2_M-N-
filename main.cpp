#include <iostream>
#include "lab7.h"
#include "QBlock.h"
using namespace std;
int main()
{
I_Block i, *ip = &i;
 K_Block s, *sp = &s;
 q_Block k, *kp = &k;
 i.paint();
 ip->paint();
 s.paint();
 sp->paint();
k.paint();
 kp->paint();
 return 0;
 }
