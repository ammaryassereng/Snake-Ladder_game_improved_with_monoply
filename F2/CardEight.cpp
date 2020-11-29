#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 8;
	for (int i = 0;i < 4;i++)
	{
		AbleToMove[i] = true;
	}
}

CardEight::~CardEight()
{

}

void CardEight::ReadCardParameters(Grid* pGrid)
{

}
	
void CardEight::Convert(int index)
{
	if (AbleToMove[index] == false)
	{
		AbleToMove[index] = true;
	}
	else
	{
		AbleToMove[index] = false;
	}
}

bool CardEight::GetStatues(int index)
{
	return AbleToMove[index];
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int index = pPlayer->GetPlayerNumber();
	AbleToMove[index] = false;
}

Card* CardEight::CopyParameters(CellPosition position)
{
	Card* pCard = new CardEight(position);
	pCard->SetCardNumber(cardNumber);
	//((CardOne*)pCard)->walletAmount = walletAmount;
	return pCard;
}

void CardEight::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}
