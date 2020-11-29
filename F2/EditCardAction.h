#pragma once
#include "Input.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Action.h"
#include "Output.h"

class EditCardAction : public Action
{
private:
	int CardNum;
	CellPosition editedCardPositon;
	Card* pCard;


public:
	EditCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~EditCardAction();
};

