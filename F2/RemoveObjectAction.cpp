#include "RemoveObjectAction.h"
#include"Grid.h"

RemoveObjectAction::RemoveObjectAction(ApplicationManager* pApp) :Action(pApp)
{
}

void RemoveObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Click on the object you want to delete");
	pos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

RemoveObjectAction::~RemoveObjectAction()
{
}

void RemoveObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	GameObject* Obj = pGrid->GetObjectFromCell(pos);
	if (Obj)
	{
		pGrid->RemoveObjectFromCell(pos);
	}
	else
	{
		pGrid->PrintErrorMessage("Cell has no Object to remove");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
}




