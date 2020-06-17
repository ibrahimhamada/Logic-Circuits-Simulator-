#include "Delete.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include <string>


Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	int c = 0;
	pUI->ClearStatusBar();
	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->selected)
		{
			c++;
			if (pManager->getcomplist(i)->getCompType() != "Connection")
				for (int j = 0; j < pManager->getcompcount(); j++)
					if (pManager->getcomplist(j)->getCompType() == "Connection")
						if (pManager->getcomplist(j)->getDestPin()->getComponent() == pManager->getcomplist(i) || pManager->getcomplist(j)->getOutputPin()->getComponent() == pManager->getcomplist(i))
						{
							pManager->clearcompitem(j);
							j--;
						}
			pManager->clearcompitem(i);
			i--;
		}
	if (c != 0)
		pUI->ClearDrawingArea();
	else
		pUI->PrintMsg("Please Select a Component first!");
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}
