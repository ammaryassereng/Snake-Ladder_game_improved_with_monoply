#include "EditCardAction.h"
#include "Input.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Output.h"
#include "UI_Info.h"
#include "DEFS.h"
#include"Card.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

EditCardAction::EditCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void EditCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();

	pGrid->GetOutput()->PrintMessage("click on the source to edit");		//instruct the player to click on the cell
	editedCardPositon = pGrid->GetInput()->GetCellClicked();
	pCard = pGrid->GetCopyOfCardInCell(editedCardPositon);
	if (pCard == NULL)
	{
		pGrid->PrintErrorMessage("The cell selected doesn't have a card");
	}
	CardNum = pCard->GetCardNumber();
	if (CardNum >= 3 && CardNum <= 8)
	{
		pGrid->PrintErrorMessage("The cell selected have a card that can't be edited");
		pCard = NULL;
	}
	pGrid->GetOutput()->ClearStatusBar();
}

void EditCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pCard != NULL)
	{
		if (dynamic_cast<CardTen*>(pCard))
		{
			((CardTen*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardEleven*>(pCard))
		{
			((CardEleven*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardTwelve*>(pCard))
		{
			((CardTwelve*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardThirteen*>(pCard))
		{
			((CardThirteen*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardFourteen*>(pCard))
		{
			((CardFourteen*)pCard)->EditParametersInCard10(pGrid);
		}
		else
		{
			pCard->ReadCardParameters(pGrid);
		}
	}
}

EditCardAction::~EditCardAction()
{
}

