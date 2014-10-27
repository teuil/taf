#include "cell.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    Cell myCell;
    //float* afMinCoords;
    myCell.divide();
    for (int i = 0; i < myCell.getChildrenNbr(); i++)
    {
        printf("%f\n",myCell.getChildAt(i)->getMin());
    	cout<<"----------------------------------"<<endl;
    }
    return 0;
}
