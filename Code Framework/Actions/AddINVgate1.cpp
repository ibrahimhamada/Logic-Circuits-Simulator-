#include "AddINVgate1.h"
#include "..\ApplicationManager.h"

AddINVgate1::AddINVgate1(ApplicationManager *pApp) :Action(pApp)
{
}

AddINVgate1::~AddINVgate1(void)
{
}

void AddINVgate1::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("1-Input Inverter Gate: Click to add the gate");

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

	GraphicsInfo * pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	INV1 *pA = new INV1(pGInfo, INV1_FANOUT);
	pA->setCompType("NOT");
	pA->setLabel("NOT");
	pManager->AddComponent(pA);
}

void AddINVgate1::Undo()
{}

void AddINVgate1::Redo()
{}

