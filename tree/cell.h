#ifndef CELL_H
#define CELL_H
#include <string>

class Cell
{
    float m_afCoordsMin[3];
    float m_afCoordsMax[3];
    public:
        Cell();
        float* getMin();
        float* getMax();
};

Cell::Cell()
{
    m_afCoordsMin[0] = 0;
    m_afCoordsMin[1] = 0;
    m_afCoordsMin[2] = 0;

    m_afCoordsMax[0] = 1;
    m_afCoordsMax[1] = 1;
    m_afCoordsMax[2] = 1;
}

float* Cell::getMin()
{
    return m_afCoordsMin;
}
#endif // CELL_H
