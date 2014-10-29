#include "cell.h"
#include <vector>

class Octree: public Cell
{
	public:
		Octree();
		Octree(std::vector<Cell*>);
		void divide();
		Octree fragment();
};

Octree::Octree()
{
    for (int i = 0; i < m_iSubCellsNbr; ++i)
    {
        Cell* newCell = new Cell;
        m_vChildren.push_back(newCell);
    }
}

Octree::Octree(std::vector<Cell*> cells)
{
	for(std::vector<Cell*>::iterator it = cells.begin(); it != cells.end(); ++it)
	{
		std::vector<Cell*> *children;
		children = *(*it)->getChildren();
    	m_vChildren.insert(m_vChildren.end(), children->begin(), children->end());
	}
}

void Octree::divide(){}

Octree Octree::fragment()
{
	for(std::vector<Cell*>::iterator it = cells.begin(); it != cells.end(); ++it)
	{
		*it->divide();
	}
	return Octree(m_vChildren);
}