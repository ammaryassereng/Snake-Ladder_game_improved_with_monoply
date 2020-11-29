#include "CardFour.h"

#include "Snake.h"
CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

void CardFour::ReadCardParameters(Grid* pGrid)
{

}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Snake* pSnake = pGrid->GetNextSnake(position);
	if (pSnake == NULL)
	{
		return;
	}
	else
	{
		//int CellsToMove = pSnake->GetPosition().GetCellNum() - position.GetCellNum();
		//pPlayer->Move(pGrid, CellsToMove);
		pGrid->UpdatePlayerCell(pPlayer, pSnake->GetPosition());
		pSnake->Apply(pGrid, pPlayer);
	}
}

Card* CardFour::CopyParameters(CellPosition position)
{
	Card* pCard = new CardFour(position);
	pCard->SetCardNumber(cardNumber);
	//((CardOne*)pCard)->walletAmount = walletAmount;
	return pCard;
}

CardFour::~CardFour()
{

}


void CardFour::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}