#include "Snake.h"
#include"Card.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	if (startCellPos.HCell() != endCellPos.HCell())
	{
		return;
	}
	if (startCellPos.VCell() >= endCellPos.VCell())
	{
		return;
	}
	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a snake. Click to continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pOut->ClearStatusBar();
	Card* pCard = pGrid->GetCopyOfCardInCell(endCellPos);
	if (pCard)
		pCard->Apply(pGrid, pPlayer);
}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile, int type)
{
	if (type == 1)
	{
		GameObject::Save(OutFile, type);
		int n = endCellPos.GetCellNum();
		OutFile << " " << n << endl;
	}
}

Snake::~Snake()
{
}
