#pragma once
#include "Card.h"
#include"Player.h"
class CardTen :
	public Card
{
	bool Added;
	bool owned;
	Player* Owner;
	int CardPrice;
	int fees;
public:
	CardTen(Grid* pGrid,const CellPosition& pos, int Price, int f);
	CardTen(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual Card* CopyParameters(CellPosition position);
	virtual void Save(ofstream& OutFile, int type);
	void SpecialSave(ofstream& OutFile, int type);
	void EditParametersInCard10(Grid* pGrid);
	void ReStartCard();
	~CardTen();
};

