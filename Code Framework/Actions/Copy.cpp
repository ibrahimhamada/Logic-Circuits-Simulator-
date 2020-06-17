#include "Copy.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include <string>


Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	pManager->clearcopylist();
	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->selected)
			pManager->CopyComp(i);
}

void Copy::Undo()
{
}

void Copy::Redo()
{
}
