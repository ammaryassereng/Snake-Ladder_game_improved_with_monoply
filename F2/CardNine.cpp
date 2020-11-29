#include "CardNine.h"
#include"Input.h"
#include"Output.h"
#include"GameObject.h"
#include"Cell.h"
#include"Ladder.h"
#include"Snake.h"

CardNine::CardNine(const CellPosition pos)
	:Card(pos)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Please Select the Cell that you want the player to move to");
	pos2 = pIn->GetCellClicked();
	//int x, y;
	//pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pGrid->UpdatePlayerCell(pPlayer, pos2);
	if (pGrid->GetCopyOfCardInCell(pos2))
	{
		pGrid->GetCopyOfCardInCell(pos2)->Apply(pGrid, pPlayer);
	}
	if (pGrid->GetLadderFromPosition(pos2))
	{
		pGrid->GetLadderFromPosition(pos2)->Apply(pGrid, pPlayer);
	}
	if (pGrid->GetSnakeFromPosition(pos2))
	{
		pGrid->GetSnakeFromPosition(pos2)->Apply(pGrid, pPlayer);
	}
}

void CardNine::Setpos2(CellPosition Position)
{
	pos2 = Position;
}

CardNine::~CardNine()
{

}

Card* CardNine::CopyParameters(CellPosition position)
{
	Card* pCard = new CardNine(position);
	pCard->SetCardNumber(cardNumber);
	((CardNine*)pCard)->Setpos2(pos2);
	return pCard;
}

void CardNine::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << " " << pos2.GetCellNum() << endl;
	}
}


