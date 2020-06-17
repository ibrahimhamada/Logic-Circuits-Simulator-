#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddConnection.h"
#include "Actions\AddINVgate1.h"
#include "Actions\AddBUFFgate1.h"
#include "Actions\AddLED.h"
#include "Actions\AddOpenSwitch.h"
#include "Actions\AddClosedSwitch.h"
#include "Actions\AddCircuitModule.h"
#include "Actions\Exit.h"
#include "UI\UI.h"
#include "Actions\Save.h"
#include "Actions\Load.h"
#include "Actions\Select.h"
#include "Actions\Edit.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include "Actions\Delete.h"
#include "Actions\Move.h"
#include "Actions\Simulation.h"
#include "Actions\Design.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	CopyCompCount = 0;
	for (int i = 0; i < MaxCompCount; i++)
	{
		CompList[i] = NULL;
		CopyCompList[i] = NULL;
	}
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp,int i)
{
	if (i == 0)
	{
		pComp->setCompID(CompCount + 1);
		CompList[CompCount++] = pComp;
	}
	else
	{
		pComp->setCompID(i);
		CompList[i - 1] = pComp;
		CompCount++;
	}
	//cout << (CompList[0]->getCompGraphInfo())->getPointList()[0].x << " --- " << (CompList[0]->getCompGraphInfo())->getPointList()[0].y << endl;
		
	//CompList[CompCount]->setCompID(CompCount);
	//cout << (CompList[0]->getCompGraphInfo())->getPointList()[0].x << " --- " << (CompList[0]->getCompGraphInfo())->getPointList()[0].y << endl;
}
void ApplicationManager::setlbl(string lbl, int i)
{
	CompList[i]->setLabel(lbl);
}
Component *ApplicationManager::getcomplist(int i) const
{
	return CompList[i];
}

void ApplicationManager::clearcomplist()
{
	for (int i = 0; i<CompCount; i++)
		CompList[i] = NULL;
	CompCount = 0;
}
void ApplicationManager::clearcopylist()
{
	for (int i = 0; i<CopyCompCount; i++)
		CopyCompList[i] = NULL;
	CopyCompCount = 0;
}
void ApplicationManager::PasteCopyList()
{
	for (int i = 0; i < CopyCompCount; i++)
		AddComponent(CopyCompList[i]);
}
void ApplicationManager::clearcompitem(int x)
{
	for (int i = x; i < CompCount; i++)
		CompList[i] = CompList[i + 1];
	CompCount--;
	
}
int ApplicationManager::getcompcount() const
{
	return CompCount;
}
void ApplicationManager::CopyComp(int x)
{
	CompList[x]->selected = false;
	CopyCompList[CopyCompCount] = CompList[x];
	CopyCompCount++;
}
void ApplicationManager::setGraphicsInfo(GraphicsInfo* gfx, int index)
{
	CompList[index]->setGraphInfo(gfx);
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case SAVE:
			pAct = new Save(this,CompCount);
			break;
		case LOAD:
			pAct = new Load(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case CMODULE:
			pAct = new AddCircuitModule(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;

		/*case ADD_Buff:
			pAct = new AddBUFFgate1(this);
			break;*/

		case ADD_INV:
			pAct = new AddINVgate1(this);
			break;

		case ADD_Closed_Switch:
			pAct = new AddClosedSwitch(this);
			break;

		case ADD_Open_Switch:
			pAct = new AddOpenSwitch(this);
			break;

		case ADD_LED:
			pAct = new AddLED(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
			pAct = new AddConnection(this);
			break;
	
		case EXIT:
			///TODO: create ExitAction here
			pAct = new Exit(this);
			break;

		case EDIT_Label:
			pAct = new Edit(this);
			break;
		case COPY:
			//TODO: Create Copy Action here
			pAct = new Copy(this);
			break;
		case DEL:
			///TODO: create Delete Action here
			pAct = new Delete(this);
			break;

		case MOVE:
			//TODO: Create Move Action here
			pAct = new Move(this);
			break;

		case CUT:
			//TODO: Create Cut Action here
			pAct = new Cut(this);
			break;
		case PASTE:
			//TODO: Create Paste Action here
			pAct = new Paste(this);
			break;
		case SIM_MODE:
			pAct = new Simulation(this);
			break;
		case DSN_MODE:
		{
			pAct = new Design(this);
			break;
		}
/*
		case UNDO:
			//TODO: Create AddConection Action here
			//pAct = new AddConnection();
			break;
		case REDO:
			//TODO: Create AddConection Action here
			//pAct = new AddConnection();
			break;*/
		
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

void ApplicationManager::SetSelectionOfComponents(bool s)
{
	for (int i = 0; i < CompCount; i++) 
	{
		CompList[i]->selected = s;
	}

}

vector<LED*> ApplicationManager::GetLeds() {
	vector<LED*> x;

	for (int i = 0; i < CompCount; i++) {
		LED* p = dynamic_cast<LED*>(CompList[i]);

		if (p != NULL && !p->IsDeleted()) {
			x.push_back(p);
		}
	}

	return x;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}