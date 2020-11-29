#include "InputDiceAction.h"
#include "Grid.h"
#include "Player.h"
InputDiceAction::InputDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}
void InputDiceAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pGrid->GetEndGame() == true)
	{
		pGrid->PrintErrorMessage("Game ended");
		return;
	}
	pOut->PrintMessage("Please enter a dice value between 1-6");
	DiceNum = pIn->GetInteger(pOut);
	if (DiceNum < 0 || DiceNum>6)
	{
		pGrid->PrintErrorMessage("Invalid dice number");
		return;
	}
}
void InputDiceAction::Execute()
{
	ReadActionParameters();
	if (DiceNum < 0 || DiceNum>6)
	{
		return;
	}
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	CurrentPlayer->Move(pGrid, DiceNum);
	pGrid->AdvanceCurrentPlayer();
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

InputDiceAction::~InputDiceAction()
{
}
