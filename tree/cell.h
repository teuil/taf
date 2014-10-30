#include <vector>

class Cell
{
    private:
        const static int m_cubeRoot = 2;
    protected:
        int m_iCellNbr;
        float m_afCoordsMin[3];
        float m_afCoordsMax[3];
        std::vector<Cell*> m_vChildren;
        void _divide();
        void _clear();

    public:
        Cell();
        std::vector<Cell*>* getChildren();
        float* getMin();
        void setCoordsMin(float*);
        void setCoordsMax(float*);
        void fragment();
        void clear();
};

Cell::Cell()
{
    m_iCellNbr = 0;
    m_afCoordsMin[0] = 0;
    m_afCoordsMin[1] = 0;
    m_afCoordsMin[2] = 0;

    m_afCoordsMax[0] = 1;
    m_afCoordsMax[1] = 1;
    m_afCoordsMax[2] = 1;
}

std::vector<Cell*>* Cell::getChildren()
{
    return &m_vChildren;
}

float* Cell::getMin()
{
    return m_afCoordsMin;
}

void Cell::setCoordsMin(float* coordsMin)
{
    m_afCoordsMin[0] = coordsMin[0];
    m_afCoordsMin[1] = coordsMin[1];
    m_afCoordsMin[2] = coordsMin[2];
}

void Cell::setCoordsMax(float* coordsMax)
{
    m_afCoordsMax[0] = coordsMax[0];
    m_afCoordsMax[1] = coordsMax[1];
    m_afCoordsMax[2] = coordsMax[2];
}

void Cell::_divide()
{
    if (m_vChildren.empty())
    {
        float cellMinX = m_afCoordsMin[0];
        float cellMinY = m_afCoordsMin[1];
        float cellMinZ = m_afCoordsMin[2];

        float cellMaxX = m_afCoordsMax[0];
        float cellMaxY = m_afCoordsMax[1];
        float cellMaxZ = m_afCoordsMax[2];

        float subCellWidth  = (cellMaxX - cellMinX) / m_cubeRoot;
        float subCellHeight = (cellMaxY - cellMinY) / m_cubeRoot;
        float subCellDepth  = (cellMaxZ - cellMinZ) / m_cubeRoot;

        m_iCellNbr = 0;
        for (float subCellMinX=cellMinX; subCellMinX<cellMaxX; subCellMinX+=subCellWidth)
        {
            for (float subCellMinY=cellMinY; subCellMinY<cellMaxY; subCellMinY+=subCellHeight)
            {
                for (float subCellMinZ=cellMinZ; subCellMinZ<cellMaxZ; subCellMinZ+=subCellDepth)
                {
                    float subCellCoordsMin[3];
                    subCellCoordsMin[0] = subCellMinX;
                    subCellCoordsMin[1] = subCellMinY;
                    subCellCoordsMin[2] = subCellMinZ;
                    float subCellCoordsMax[3];
                    subCellCoordsMax[0] = subCellMinX + subCellWidth;
                    subCellCoordsMax[1] = subCellMinY + subCellHeight;
                    subCellCoordsMax[2] = subCellMinZ + subCellDepth;

                    Cell* newCell = new Cell;
                    newCell->setCoordsMin(subCellCoordsMin);
                    newCell->setCoordsMax(subCellCoordsMax);
                    m_vChildren.push_back(newCell);
                    m_iCellNbr += 1;
                }
            }
        }
    }
    else
    {
        for(std::vector<Cell*>::iterator it = m_vChildren.begin(); it != m_vChildren.end(); ++it)
            (*it)->_divide();
    }
}

void Cell::fragment()
{
    /*Here, a specific factor can determine wether the cell can be divided or not*/
    _divide();
}

void Cell::_clear()
{
    while(m_vChildren.size())
    {
        Cell *child = m_vChildren.back();
        m_vChildren.pop_back();
        child->_clear();
        delete child;
    }
    m_iCellNbr = 0;
}
