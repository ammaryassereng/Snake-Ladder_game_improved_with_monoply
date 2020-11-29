#include "CardTwelve.h"
CardTwelve::CardTwelve(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 12;
	owned = false;
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	Added = false;
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int CellNumOfAnyCard10;
	for (int i = 1; i <= 99;i++)
	{
		CellPosition a(i);
		Card* C0 = pGrid->GetCopyOfCardInCell(a);
		if (C0)
		{
			CardTwelve* C1 = dynamic_cast<CardTwelve*>(C0);
			if (C1)
			{
				Added = true;
				CellNumOfAnyCard10 = i;
				break;
			}
		}
	}
	if (Added == false)
	{
		pOut->PrintMessage("Please enter the buying price");
		CardPrice = pIn->GetInteger(pOut);
		pOut->PrintMessage("Please enter the card fees");
		fees = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}
	else
	{
		CellPosition a(CellNumOfAnyCard10);
		CardTwelve* C = dynamic_cast<CardTwelve*>(pGrid->GetCopyOfCardInCell(a));
		CardPrice = C->CardPrice;
		fees = C->fees;
	}
}

CardTwelve::~CardTwelve()
{

}

Card* CardTwelve::CopyParameters(CellPosition position)
{
	Card* pCard = new CardTwelve(position);
	pCard->SetCardNumber(cardNumber);
	((CardTwelve*)pCard)->CardPrice = CardPrice;
	((CardTwelve*)pCard)->fees = fees;
	((CardTwelve*)pCard)->Added = true;
	return pCard;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (owned == false)
	{
		pOut->PrintMessage("Press y then enter if you want to buy this cell");
		string d = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
		if (d == "y" || d == "Y")
		{
			int wallet = pPlayer->GetWallet();
			wallet = wallet - CardPrice;
			if (wallet < 0)
				return;
			else
			{
				pPlayer->SetWallet(wallet);
				owned = true;
				Owner = pPlayer;
				for (int i = 1;i <= 99;i++)
				{
					CellPosition pos3(i);
					Card* C0 = pGrid->GetCopyOfCardInCell(pos3);
					if (C0)
					{
						CardTwelve* C1 = dynamic_cast<CardTwelve*>(C0);
						if (C1)
						{
							C1->owned = true;
							C1->Owner = Owner;
						}
					}
				}
			}
		}
	}
	else
	{
		if (pPlayer->GetPlayerNumber() != Owner->GetPlayerNumber())
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - fees);
			Owner->SetWallet(Owner->GetWallet() + fees);
		}
	}
}

void CardTwelve::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << " " << CardPrice << " " << fees << endl;
	}
}

void CardTwelve::SpecialSave(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}

CardTwelve::CardTwelve(Grid* pGrid, const CellPosition& pos, int Price, int f)
	:Card(pos)
{
	cardNumber = 10;
	Added = true;
	CardPrice = Price;
	fees = f;
}

void CardTwelve::EditParametersInCard10(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the Card Price");
	int newPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter the Card fees");
	int newfees = pIn->GetInteger(pOut);
	CardPrice = newPrice;
	fees = newfees;
	pOut->ClearStatusBar();
	for (int i = 1; i <= 99;i++)
	{
		CellPosition a(i);
		Card* C0 = pGrid->GetCopyOfCardInCell(a);
		if (C0)
		{
			CardTwelve* C1 = dynamic_cast<CardTwelve*>(C0);
			if (C1)
			{
				C1->CardPrice = CardPrice;
				C1->fees = fees;
			}
		}
	}

}

void CardTwelve::ReStartCard()
{
	owned = false;
	Owner = NULL;
}

