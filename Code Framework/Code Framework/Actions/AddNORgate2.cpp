#include "AddNORgate2.h"
#include "..\ApplicationManager.h"

AddNORgate2::AddNORgate2(ApplicationManager *pApp) :Action(pApp)
{
}

AddNORgate2::~AddNORgate2(void)
{
}

void AddNORgate2::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input NOR Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);
	while (Cx < 80 || Cx > 1120 || Cy < 80 || Cy > 600) {
		//Print Error Message
		pUI->PrintMsg("You can't draw here. Please Click in the Design Area!");
		pUI->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo * pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the NOR2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	NOR2 *pA = new NOR2(pGInfo, NOR2_FANOUT);
	pA->setCompType("NOR");
	pA->setLabel("NOR");
	pManager->AddComponent(pA);
}

void AddNORgate2::Undo()
{}

void AddNORgate2::Redo()
{}

