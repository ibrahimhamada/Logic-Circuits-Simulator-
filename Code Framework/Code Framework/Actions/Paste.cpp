#include "Paste.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include <string>


Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	int j = pManager->getcompcount(),x,y;
	GraphicsInfo * pGInfo = new GraphicsInfo(2);
	pManager->PasteCopyList();
	for (int i = j; i < pManager->getcompcount(); i++)
	{
			pUI->PrintMsg("Click for Paste a Component");
			pUI->GetPointClicked(x, y);
			pGInfo->PointsList[0].x = x - pUI->getGateWidth() / 2;
			pGInfo->PointsList[0].y = y - pUI->getGateHeight() / 2;
			pGInfo->PointsList[1].x = x + pUI->getGateWidth() / 2;
			pGInfo->PointsList[1].y = y + pUI->getGateHeight() / 2;
			pManager->setGraphicsInfo(pGInfo, i);
	}
	pManager->clearcopylist();
}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
