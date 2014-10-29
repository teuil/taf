#include <string>
#include <vector>

class Cell
{
    protected:
        const static int m_iSubCellsNbr = 8;
        float m_afCoordsMin[3];
        float m_afCoordsMax[3];
        std::vector<Cell*> m_vChildren;

    public:
        Cell();
        std::vector<Cell*> getChildren();
        float* getMin();
        void divide();
        void clear();
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

std::vector<Cell*> Cell::getChildren()
{
    return m_vChildren;
}

float* Cell::getMin()
{
    return m_afCoordsMin;
}

void Cell::divide()
{
    if (m_vChildren.empty())
    {
        for (int i = 0; i < m_iSubCellsNbr; ++i)
        {
            Cell* newCell = new Cell;
            m_vChildren.push_back(newCell);
        }
    }
    else
    {
        for (int i=0;i<m_iSubCellsNbr;i++)
            m_vChildren.at(i)->divide();
    }
}
void Cell::clear()
{
    while(m_vChildren.size())
    {
        Cell *child = m_vChildren.back();
        m_vChildren.back();
        child->clear();
        delete child;
    }
}
