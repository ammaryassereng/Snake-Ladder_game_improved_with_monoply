#include "CardSeven.h"
#include"RollDiceAction.h"
#include "ApplicationManager.h"

CardSeven::CardSeven(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 7;
}

CardSeven::~CardSeven()
{

}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	
	
}

Card* CardSeven::CopyParameters(CellPosition position)
{
	Card* pCard = new CardSeven(position);
	pCard->SetCardNumber(cardNumber);
	//((CardOne*)pCard)->walletAmount = walletAmount;
	return pCard;
}

void CardSeven::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}
