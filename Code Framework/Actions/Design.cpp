#include "Design.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include <string>


Design::Design(ApplicationManager* pApp) :Action(pApp)
{
}

Design::~Design(void)
{
}

void Design::Execute()
{
	//Get a Pointer to the user Interfaces
	for (int i = 0; i < pManager->getcompcount() ; i++)
		if (pManager->getcomplist(i)->getCompType() == "Connection")
		{
			pManager->getcomplist(i)->getOutputPin()->setStatus(NCON);
			pManager->getcomplist(i)->Operate();
		}

	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->getCompType() == "LED")
			pManager->getcomplist(i)->Operate();

	UI* pUI = pManager->GetUI();
	pUI->CreateDesignToolBar();
	pUI->ClearStatusBar();
}

void Design::Undo()
{
}

void Design::Redo()
{
}

