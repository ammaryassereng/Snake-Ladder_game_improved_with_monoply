#include "PasteCardAction.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

PasteCardAction::~PasteCardAction()
{

}

void PasteCardAction::ReadActionParameters()
{
}

void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Card* pCard = pGrid->GetClipboard();
	if (pCard)
	{
		pOut->PrintMessage("Press on the desired cell to have a copy of the copied card");
		CellPosition pos = pIn->GetCellClicked();
		int CardNum = pCard->GetCardNumber();
		bool added;
		Card* pn = NULL;
		switch (CardNum)
		{
		case 1:
			pn = ((CardOne*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 2:
			pn = ((CardTwo*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 3:
			pn = ((CardThree*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 4:
			pn = ((CardFour*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 5:
			pn = ((CardFive*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 6:
			pn = ((CardSix*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 7:
			pn = ((CardSeven*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 8:
			pn = ((CardEight*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 9:
			pn = ((CardNine*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 10:
			pn = ((CardTen*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 11:
			pn = ((CardEleven*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 12:
			pn = ((CardTwelve*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 13:
			pn = ((CardThirteen*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		case 14:
			pn = ((CardFourteen*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(pn);
			break;
		}
		
	if (added == false)
		{
			pGrid->PrintErrorMessage("the Desired cell to copy the card already has an object");
		}

	}
	else
	{
		pGrid->PrintErrorMessage("There is no copied card to be pasted");
	}
	pOut->ClearStatusBar();
}