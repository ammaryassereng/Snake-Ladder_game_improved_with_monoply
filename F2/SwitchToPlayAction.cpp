#include "SwitchToPlayAction.h"
#include"Grid.h"
#include"Output.h"
#include"Input.h"
SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToPlayAction::ReadActionParameters()
{

}

void SwitchToPlayAction::Execute()
{
	Output* pOut = pManager->GetGrid()->GetOutput();
	pOut->CreatePlayModeToolBar();
}

SwitchToPlayAction::~SwitchToPlayAction()
{

}