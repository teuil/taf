#include <string>
#include <vector>

class Cell
{
    const static int m_iSubCellsNbr = 8;
    float m_afCoordsMin[3];
    float m_afCoordsMax[3];
    Cell* m_aChildren[m_iSubCellsNbr];

    public:
        Cell();
        int getChildrenNbr();
        Cell* getChildAt(int);
        float* getMin();
        void divide();
        ~Cell();

};

Cell::Cell()
{
    for (int i=0;i<m_iSubCellsNbr;i++)
        m_aChildren[i] = NULL;
    m_afCoordsMin[0] = 0;
    m_afCoordsMin[1] = 0;
    m_afCoordsMin[2] = 0;

    m_afCoordsMax[0] = 1;
    m_afCoordsMax[1] = 1;
    m_afCoordsMax[2] = 1;
}

int Cell::getChildrenNbr()
{
    return m_iSubCellsNbr;
}

Cell* Cell::getChildAt(int index)
{
    return m_aChildren[index];
}

float* Cell::getMin()
{
    return m_afCoordsMin;
}

void Cell::divide()
{
    for (int i = 0; i < m_iSubCellsNbr; i++)
    {
        Cell newCell;
        Cell* pNewCell = new Cell(newCell);
        m_aChildren[i] = pNewCell;
    }
}


Cell::~Cell()
{
    for (int i=0;i<m_iSubCellsNbr;i++)
        delete(m_aChildren[i]);
    delete(m_aChildren);
}