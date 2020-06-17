#include "AddCircuitModule.h"
#include "..\ApplicationManager.h"

AddCircuitModule::AddCircuitModule(ApplicationManager* pApp) :Action(pApp)
{
}

AddCircuitModule::~AddCircuitModule(void)
{
}

void AddCircuitModule::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	//Print Action Message
	pUI->PrintMsg("CircuitModule #17: Click to add the module");

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

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;

	CircuitModule* pA = new CircuitModule(pGInfo);
	pA->setCompType("CircuitModule#17");
	pA->setLabel("CircuitModule#17");
	pManager->AddComponent(pA);
}

void AddCircuitModule::Undo()
{}

void AddCircuitModule::Redo()
{}

