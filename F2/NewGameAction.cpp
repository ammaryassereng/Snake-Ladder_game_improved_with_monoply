#include "NewGameAction.h"


NewGameAction::NewGameAction(ApplicationManager* pApp) :Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
}

NewGameAction::~NewGameAction()
{
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	for (int i = 0; i < 4;i++)
	{
		Player* p = pGrid->GetCurrentPlayer();
		p->SetWallet(100);
		CellPosition a(1);
		pGrid->UpdatePlayerCell(p, a);
		p->SetStepCount(0);
		p->SetTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	Player* p = pGrid->GetCurrentPlayer();
	int PlayerNum = p->GetPlayerNumber();
	while (PlayerNum != 0)
	{
		pGrid->AdvanceCurrentPlayer();
		p = pGrid->GetCurrentPlayer();
		PlayerNum = p->GetPlayerNumber();
	}
	for (int i = 1;i <= 99;i++)
	{
		CellPosition pos(i);
		Card* pCard = pGrid->GetCopyOfCardInCell(pos);
		if (pCard)
		{
			if (dynamic_cast<CardTen*>(pCard))
			{
				CardTen* pCard2 = dynamic_cast<CardTen*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardEleven*>(pCard))
			{
				CardEleven* pCard2 = dynamic_cast<CardEleven*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardTwelve*>(pCard))
			{
				CardTwelve* pCard2 = dynamic_cast<CardTwelve*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardThirteen*>(pCard))
			{
				CardThirteen* pCard2 = dynamic_cast<CardThirteen*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardFourteen*>(pCard))
			{
				CardFourteen* pCard2 = dynamic_cast<CardFourteen*>(pCard);
				pCard2->ReStartCard();
			}
		}
	}
	pGrid->SetEndGame(false);
}
