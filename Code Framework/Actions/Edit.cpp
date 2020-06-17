#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "..\Components\Component.h"
#include "Edit.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>

Edit::Edit(ApplicationManager *pApp) :Action(pApp)
{
}

Edit::~Edit(void)
{
}

void Edit::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	int count;
	pUI->ClearStatusBar();
	int selectedCount = 0;
	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->selected)
			selectedCount++;
	if (selectedCount == 1)
	{
		for (int i = 0; i <= pManager->getcompcount(); i++)
			if (pManager->getcomplist(i)->selected)
			{
				pUI->PrintMsg("Write your new label: ");
				count = (pManager->getcomplist(i)->getLabel()).length();
				pUI->ClearArea(pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x, pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight(), pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + count*7, pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() + 20, pManager->getcomplist(i)->getLabel());
				pManager->setlbl(pUI->GetSrting(),i);
				pUI->ClearStatusBar();
				break;
			}
	}
	else
		pUI->PrintMsg("Error: Select only one editable component");

}

void Edit::Undo()
{
}

void Edit::Redo()
{
}