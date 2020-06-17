#include "Cut.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"


Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	pManager->clearcopylist();
	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->selected)
		{
			pManager->CopyComp(i);
			pManager->clearcompitem(i);
		}
	pUI->ClearDrawingArea();
}

void Cut::Undo()
{
}

void Cut::Redo()
{
}
