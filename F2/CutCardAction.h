#pragma once
#include "Action.h"
#include"Grid.h"
#include"Card.h"
#include"CardOne.h"
class CutCardAction :
	public Action
{
public:
	CutCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~CutCardAction();
};

