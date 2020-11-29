#include "CardFive.h"

CardFive::CardFive(const CellPosition P)
	:Card(P)
{
	cardNumber = 5;
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
}

CardFive::~CardFive()
{

}

Card* CardFive::CopyParameters(CellPosition position)
{
	Card* pCard = new CardFive(position);
	pCard->SetCardNumber(cardNumber);
	//((CardOne*)pCard)->walletAmount = walletAmount;
	return pCard;
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	CellPosition Position = position;
	Position.AddCellNum(pPlayer->GetJustRolledDiceNumber());
	pGrid->UpdatePlayerCell(pPlayer, Position);
	Card* pCard2 = pGrid->GetCopyOfCardInCell(Position);
	if (pCard2)
	{
		pCard2->Apply(pGrid, pPlayer);
	}
}

void CardFive::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}


