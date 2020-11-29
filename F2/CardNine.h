#pragma once
#include "Card.h"
class CardNine :
	public Card
{
	CellPosition pos2;
public:
	CardNine(const CellPosition pos);
	void Setpos2(CellPosition Position);
	virtual void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid,Player* pPlayer);
	virtual ~CardNine();
	Card* CopyParameters(CellPosition position);
	virtual void Save(ofstream& OutFile, int type);
};

