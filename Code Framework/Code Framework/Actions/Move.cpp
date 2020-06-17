#include "Move.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include <string>


Move::Move(ApplicationManager* pApp) :Action(pApp)
{
}

Move::~Move(void)
{
}

void Move::Execute()
{
	int x1, y1, c = 0;
	GraphicsInfo * pGInfo = new GraphicsInfo(2);
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMsg("Click on your desired place!");

	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->selected && pManager->getcomplist(i)->getCompType() != "Connection")
		{
			pUI->GetPointClicked(x1, y1);
			//limits
			pGInfo->PointsList[0].x = x1 - pUI->getGateWidth() / 2;
			pGInfo->PointsList[0].y = y1 - pUI->getGateHeight() / 2;
			pGInfo->PointsList[1].x = x1 + pUI->getGateWidth() / 2;
			pGInfo->PointsList[1].y = y1 + pUI->getGateHeight() / 2;
			pManager->getcomplist(i)->setGraphInfo(pGInfo);
			pManager->getcomplist(i)->selected = false;
			for (int j = 0; j < pManager->getcompcount(); j++)
			{
				GraphicsInfo * gfx = new GraphicsInfo(2);
				if (pManager->getcomplist(j)->getCompType() == "Connection")
					if (pManager->getcomplist(j)->getCompType() != "CircuitModule#17")
						if (pManager->getcomplist(i) == pManager->getcomplist(j)->getOutputPin()->getComponent())
						{
							gfx->PointsList[0].x = pGInfo->PointsList[0].x + pUI->getGateWidth();
							gfx->PointsList[0].y = pGInfo->PointsList[0].y + pUI->getGateHeight()/2;
							gfx->PointsList[1].x = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[1].x;
							gfx->PointsList[1].y = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[1].y;
							pManager->getcomplist(j)->setGraphInfo(gfx);
						}
						else if (pManager->getcomplist(i) == pManager->getcomplist(j)->getDestPin()->getComponent())
						{
							if (pManager->getcomplist(i)->getInPinsNo() == 2)
							{
								if (pManager->getcomplist(j)->getDstPinNo() == 1)
								{
									gfx->PointsList[1].x = pGInfo->PointsList[0].x;
									gfx->PointsList[1].y = pGInfo->PointsList[0].y + pUI->getGateHeight() / 4;
									gfx->PointsList[0].x = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[0].x;
									gfx->PointsList[0].y = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[0].y;
									pManager->getcomplist(j)->setGraphInfo(gfx);
								}
								else if (pManager->getcomplist(j)->getDstPinNo() == 2)
								{
									gfx->PointsList[1].x = pGInfo->PointsList[0].x;
									gfx->PointsList[1].y = pGInfo->PointsList[0].y + pUI->getGateHeight() * 3 / 4;
									gfx->PointsList[0].x = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[0].x;
									gfx->PointsList[0].y = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[0].y;
									pManager->getcomplist(j)->setGraphInfo(gfx);
								}
							}
							else
							{
								gfx->PointsList[1].x = pGInfo->PointsList[0].x;
								gfx->PointsList[1].y = pGInfo->PointsList[0].y + pUI->getGateHeight() / 2;
								gfx->PointsList[0].x = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[0].x;
								gfx->PointsList[0].y = pManager->getcomplist(j)->getCompGraphInfo()->PointsList[0].y;
								pManager->getcomplist(j)->setGraphInfo(gfx);
							}
						}
			}
			c++;
			break;
		}
	if (c == 0)
	{
		pUI->PrintMsg("No Component has been selected");
	}
	pUI->ClearDrawingArea();

}

void Move::Undo()
{
}

void Move::Redo()
{
}
