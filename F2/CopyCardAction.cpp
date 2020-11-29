#include "CopyCardAction.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{
}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Press on the desired card to copy");
	CellPosition pos = pIn->GetCellClicked();
	Card* pCard = pGrid->GetCopyOfCardInCell(pos);
	if (pCard)
	{
		pGrid->SetClipboard(pCard);
		pOut->PrintMessage("Copied successfully");
	}
	else
	{
		pGrid->PrintErrorMessage("The pressed Cell has no card");
	}
}



