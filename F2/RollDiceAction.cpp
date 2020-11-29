#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include "Card.h"
#include"CardSeven.h"
#include"CardEight.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame() == true)
	{
		return;
	}
		// -- If not ended, do the following --:

		// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid
	Player* p = pGrid->GetCurrentPlayer();
	Card* pCard = p->GetCell()->HasCard();
	if (pCard)
	{
		CardEight* pCard2 = dynamic_cast<CardEight*>(pCard);
		if (pCard2)
		{
			//pCard2->Apply(pGrid, p);
			if (pCard2->GetStatues(p->GetPlayerNumber()) == false)
			{
				pCard2->Convert(p->GetPlayerNumber());
				p->Move(pGrid, 0);
				return;
			}
		}
	}
	// 4- Move the currentPlayer using function Move of class player
	p->Move(pGrid, diceNumber);
	// 5- Advance the current player number of pGrid
	pCard = p->GetCell()->HasCard();
	if (pCard)
	{
		CardSeven* pCard2 = dynamic_cast<CardSeven*>(pCard);
		if (pCard2)
		{
			//pCard2->Apply(pGrid,p);
			return;
		}
	}
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	
}

RollDiceAction::~RollDiceAction()
{
}
