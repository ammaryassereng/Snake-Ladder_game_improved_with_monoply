#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	
}

void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Press on the desired card to Cut");
	CellPosition pos = pIn->GetCellClicked();
	Card* pCard = pGrid->GetCopyOfCardInCell(pos);
	if (pCard)
	{
		pGrid->SetClipboard(pCard);
		pGrid->RemoveObjectFromCell(pCard->GetPosition());
		pOut->PrintMessage("Cut successfully");
	}
	else
	{
		pGrid->PrintErrorMessage("The pressed Cell has no card");
	}
}
