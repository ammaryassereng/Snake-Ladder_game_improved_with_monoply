#include "CardThree.h"
#include "Ladder.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

void CardThree::ReadCardParameters(Grid* pGrid)
{

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Ladder* pLadder = pGrid->GetNextLadder(position);
	if (pLadder == NULL)
	{
		return;
	}
	else
	{
		//int CellsToMove = pLadder->GetPosition().GetCellNum() - position.GetCellNum();
		//pPlayer->Move(pGrid, CellsToMove);
		pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
		pLadder->Apply(pGrid, pPlayer);
	}
}

Card* CardThree::CopyParameters(CellPosition position)
{
	Card* pCard = new CardThree(position);
	pCard->SetCardNumber(cardNumber);
	return pCard;
}

void CardThree::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}

CardThree::~CardThree()
{

}
