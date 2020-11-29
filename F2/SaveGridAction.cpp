#include "SaveGridAction.h"
#include "Output.h"
#include"Grid.h"
#include<fstream>
using namespace std;

SaveGridAction::SaveGridAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter the file name: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	FileName = FileName + ".txt";
	int laddersnum = pGrid->CountLadders();
	int SnakesNum = pGrid->CountSnakes();
	int CardNum = pGrid->CountCards();
	ofstream outFile(FileName,ios::out);
	outFile << laddersnum << endl;
	pGrid->SaveAll(outFile, 0);
	outFile << SnakesNum << endl;
	pGrid->SaveAll(outFile, 1);
	outFile << CardNum << endl;
	pGrid->SaveAll(outFile, 2);
	outFile.close();
}

