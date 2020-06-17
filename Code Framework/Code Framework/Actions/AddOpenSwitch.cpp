#include "AddOpenSwitch.h"
#include "..\ApplicationManager.h"

AddOpenSwitch::AddOpenSwitch(ApplicationManager *pApp) :Action(pApp)
{
}

AddOpenSwitch::~AddOpenSwitch(void)
{
}

void AddOpenSwitch::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Switch: Click to add the Open Switch");

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
	OpenSwitch *pA = new OpenSwitch(pGInfo, SWITCH_FANOUT);
	pA->setCompType("OPN_SWTCH");
	pA->setLabel("OPN_SWTCH");
	pManager->AddComponent(pA);
}

void AddOpenSwitch::Undo()
{}

void AddOpenSwitch::Redo()
{}

