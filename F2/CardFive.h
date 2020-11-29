#pragma once
#include "Card.h"
class CardFive :
	public Card
{
public:
	CardFive(const CellPosition P);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual ~CardFive();
	virtual Card* CopyParameters(CellPosition position);
	void Apply(Grid* pGrid, Player* pPlager);
	virtual void Save(ofstream& OutFile, int type);
};

