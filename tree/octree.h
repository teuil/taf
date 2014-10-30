#include "cell.h"
#include <vector>
#include <stdio.h>

class Octree: public Cell
{
	private:
		Octree *m_nextOctree;
	public:
		Octree();
		Octree(std::vector<Cell*>);
		Octree* fragment();
		void clear();
};

Octree::Octree()
{
	m_nextOctree = NULL;
	_divide();
}

Octree::Octree(std::vector<Cell*> cells)
{
	for(std::vector<Cell*>::iterator it = cells.begin(); it != cells.end(); ++it)
	{
		std::vector<Cell*> *children;
		children = (*it)->getChildren();
    	m_vChildren.insert(m_vChildren.end(), children->begin(), children->end());
	}
	m_iCellNbr = m_vChildren.size();
}

Octree* Octree::fragment()
{
	for(std::vector<Cell*>::iterator it = m_vChildren.begin(); it != m_vChildren.end(); ++it)
	{
		(*it)->fragment();
	}
	m_nextOctree = new Octree(m_vChildren);
	return m_nextOctree;
}

void Octree::clear()
{
    if(m_nextOctree!=NULL)
        m_nextOctree->clear();
	_clear();
	printf("all clear! %d\n", m_iCellNbr);
}
