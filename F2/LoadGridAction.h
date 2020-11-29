#pragma once
#include "Action.h"
#include<fstream>
#include<string>
class LoadGridAction :
	public Action
{
	string FileName;
public:

	LoadGridAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)

	virtual ~LoadGridAction();  // Virtual Destructor

};

