#include "octree.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    Octree myOctree1;
    Octree myOctree2 = *myOctree1.fragment();
    Octree myOctree3 = *myOctree2.fragment();
    myOctree2.clear();
    return 0;
}
