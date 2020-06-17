#include "Exit.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "..\Components\Component.h"

Exit::Exit(ApplicationManager *pApp) :Action(pApp)
{
}

Exit::~Exit(void)
{
}

void Exit::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearDrawingArea();
	
}

void Exit::Undo()
{
}

void Exit::Redo()
{
}
