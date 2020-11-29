#include "CardSix.h"

CardSix::CardSix(const CellPosition P)
	:Card(P)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
}

CardSix::~CardSix()
{

}

Card* CardSix::CopyParameters(CellPosition position)
{
	Card* pCard = new CardSix(position);
	pCard->SetCardNumber(cardNumber);
	//((CardOne*)pCard)->walletAmount = walletAmount;
	return pCard;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Cell* pCell = pPlayer->GetCell();
	//CellPosition pos = pCell->GetCellPosition();
	CellPosition Position = position;
	if (pPlayer->GetStepCount()==1)
		Position.AddCellNum(-(pPlayer->GetJustRolledDiceNumber())+1);
	else
		Position.AddCellNum(-(pPlayer->GetJustRolledDiceNumber()));
	pGrid->UpdatePlayerCell(pPlayer, Position);
	Card* pCard2 = pGrid->GetCopyOfCardInCell(Position);
	if (pCard2)
	{
		pCard2->Apply(pGrid, pPlayer);
	}
}

void CardSix::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}