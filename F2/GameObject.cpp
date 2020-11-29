#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}

void GameObject::Save(ofstream& OutFile, int type)
{
	int cellnum = position.GetCellNum();
	OutFile << cellnum ;
}