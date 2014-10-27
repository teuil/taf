#include <stdio.h>
#include <cell.h>
using namespace std;
int main()
{
    Cell myCell;
    //float* afMinCoords;
    float* afMinCoords = myCell.getMin();
    for (int i = 0; i < 3; i++)
        printf("coords %f \n", afMinCoords[i]);
    return 0;
}
