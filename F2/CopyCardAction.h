#pragma once
#include "Action.h"
#include"Grid.h"
#include"Card.h"
#include"CardOne.h"
class CopyCardAction :
	public Action
{
public:
	CopyCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~CopyCardAction();
};

