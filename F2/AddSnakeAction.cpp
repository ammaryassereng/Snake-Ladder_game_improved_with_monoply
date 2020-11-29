#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include"Ladder.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (endPos.HCell() != startPos.HCell())
	{
		pGrid->PrintErrorMessage("end cell and start cell are not in the same column");
	}
	if (endPos.VCell() <= startPos.VCell())
	{
		pGrid->PrintErrorMessage("end cell must be below start cell");
	}
	if (pGrid->GetLadderFromPosition(endPos) != NULL)
	{
		pGrid->PrintErrorMessage("End position can't be the start of a ladder");
	}


	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}

void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager


	// Add the card object to the GameObject of its Cell:
	if (startPos.HCell() != endPos.HCell())
	{
		return;
	}
	if (endPos.VCell() <= startPos.VCell())
	{
		return;
	}
	if (pGrid->IsOverLapping(pSnake))
	{
		return;
	}
	if (startPos.VCell() == endPos.VCell())
	{
		return;
	}
	if (pGrid->GetLadderFromPosition(endPos) != NULL)
	{
		return;
	}
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}

