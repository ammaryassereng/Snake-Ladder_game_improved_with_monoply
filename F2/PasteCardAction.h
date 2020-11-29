#pragma once
#include "Action.h"
#include"Grid.h"
#include"Card.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
class PasteCardAction :
	public Action
{
public:
	PasteCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~PasteCardAction();
};

