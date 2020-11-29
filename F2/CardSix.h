#pragma once
#include "Card.h"
class CardSix :
	public Card
{
public:
	CardSix(const CellPosition P);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual ~CardSix();
	virtual Card* CopyParameters(CellPosition position);
	void Apply(Grid* pGrid, Player* pPlager);
	virtual void Save(ofstream& OutFile, int type);
};

