#include "LoadGridAction.h"
#include"Grid.h"
#include<fstream>
#include"CellPosition.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"
using namespace std;

LoadGridAction::LoadGridAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

LoadGridAction::~LoadGridAction()
{
}

void LoadGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter the file name: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void LoadGridAction::Execute()
{
	int c10 = 0, c11 = 0, c12 = 0, c13 = 0, c14 = 0;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->RemoveAll();
	ReadActionParameters();
	ifstream Input(FileName + ".txt");
	int n;
	Input >> n;
	for (int i = 0;i < n;i++)
	{
		int start, end;
		Input >> start >> end;
		CellPosition a(start);
		CellPosition b(end);
		Ladder* pLadder = new Ladder(a, b);
		pGrid->AddObjectToCell(pLadder);
	}
	Input >> n;
	for (int i = 0;i < n;i++)
	{
		int start, end;
		Input >> start >> end;
		CellPosition a(start);
		CellPosition b(end);
		Snake* pSnake = new Snake(a, b);
		pGrid->AddObjectToCell(pSnake);
	}
	Input >> n;
	for (int i = 0;i < n;i++)
	{
		int par;
		int CardNum, posNumber;
		Input >> CardNum >> posNumber;
		Card* pCard;
		CellPosition cardPosition(posNumber);
		switch (CardNum)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			Input >> par;
			((CardOne*)pCard)->SetWallet(par);
			pGrid->AddObjectToCell(pCard);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			Input >> par;
			((CardTwo*)pCard)->SetWallet(par);
			pGrid->AddObjectToCell(pCard);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			pGrid->AddObjectToCell(pCard);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			pGrid->AddObjectToCell(pCard);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			pGrid->AddObjectToCell(pCard);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			pGrid->AddObjectToCell(pCard);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			pGrid->AddObjectToCell(pCard);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			pGrid->AddObjectToCell(pCard);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			Input >> par;
			{
				CellPosition a(par);
				((CardNine*)pCard)->Setpos2(a);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 10:
			if (c10 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardTen(pGrid,cardPosition, par1, par2);
				c10++;
			}
			else
			{
				pCard = new CardTen(cardPosition);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 11:
			if (c11 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardEleven(pGrid, cardPosition, par1, par2);
				c11++;
			}
			else
			{
				pCard = new CardEleven(cardPosition);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 12:
			if (c12 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardTwelve(pGrid, cardPosition, par1, par2);
				c12++;
			}
			else
			{
				pCard = new CardTwelve(cardPosition);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 13:
			if (c13 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardThirteen(pGrid, cardPosition, par1, par2);
				c13++;
			}
			else
			{
				pCard = new CardThirteen(cardPosition);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 14:
			if (c14 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardFourteen(pGrid, cardPosition, par1, par2);
				c14++;
			}
			else
			{
				pCard = new CardFourteen(cardPosition);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		}
	}
}
