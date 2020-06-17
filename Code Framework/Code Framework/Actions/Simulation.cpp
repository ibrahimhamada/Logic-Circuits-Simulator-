#include "Simulation.h"
#include "AddConnection.h"
#include "..\Components\Connection.h" 
#include "..\ApplicationManager.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include <iostream>
using namespace std;

Simulation::Simulation(ApplicationManager* pAppMan) : Action(pAppMan) {
	stop = false;
}

int Simulation::CalcOutput(Component* pCmp) 
{
	Component* cn;
	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->getCompType() == "Connection")
			if (pManager->getcomplist(i)->getDestPin() == pCmp->getInputPin(0))
				cn = pManager->getcomplist(i);
			else if (pManager->getcomplist(i)->getDestPin() == pCmp->getInputPin(1))
				cn = pManager->getcomplist(i);
	if (pCmp->getCompType() == "CLD_SWTCH")
	{
		pCmp->Operate();
		cn->Operate();
		return 1;
	}
	if (pCmp->getCompType() == "OPN_SWTCH")
	{
		pCmp->Operate();
		cn->Operate();
		return 0;
	}
	if (pCmp->getCompType() != "LED")
		pCmp->Operate();

	//cn->Operate();
	return CalcOutput(cn->getOutputPin()->getComponent());
}

void Simulation::Execute() 
{

	int f = 0;
	UI* pUI = pManager->GetUI();
	for (int i = 0; f == 0 && i < pManager->getcompcount(); i++) 
	{
		if ((pManager->getcomplist(i)->getCompType() != "CLD_SWTCH") && (pManager->getcomplist(i)->getCompType() != "OPN_SWTCH") && (pManager->getcomplist(i)->getCompType() != "Connection")) 
		{
			if (pManager->getcomplist(i)->getInPinsNo() == 1) 
			{
				for (int j = 0; j < pManager->getcompcount(); j++)
				{
					if (pManager->getcomplist(j)->getCompType() == "Connection")
					{
						if (pManager->getcomplist(j)->getDestPin() == pManager->getcomplist(i)->getInputPin(0))
						{
							f = 0;
							break;
						}
						else
							f++;
					}
					else
						f++;
				}
			}
			if (pManager->getcomplist(i)->getInPinsNo() == 2) 
			{
				for (int j = 0; j < pManager->getcompcount(); j++) 
				{
					if (pManager->getcomplist(j)->getCompType() == "Connection")
					{
						if (pManager->getcomplist(j)->getDestPin() == pManager->getcomplist(i)->getInputPin(0))
						{
							f = 0;
							break;
						}
						else
							f++;
					}
					else
						f++;
				}

				for (int k = 0; k < pManager->getcompcount(); k++) 
				{
					if (pManager->getcomplist(k)->getCompType() == "Connection")
					{
						if (pManager->getcomplist(k)->getDestPin() == pManager->getcomplist(i)->getInputPin(1))
						{
							f = 0;
							break;
						}
						else
							f++;
					}
					else
						f++;
				}
			}
		}
		else if ((pManager->getcomplist(i)->getCompType() == "CLD_SWTCH") || (pManager->getcomplist(i)->getCompType() == "OPN_SWTCH"))
		{
			for (int j = 0; j < pManager->getcompcount(); j++) 
			{
				if (pManager->getcomplist(j)->getCompType() == "Connection") 
				{
					if (pManager->getcomplist(j)->getOutputPin() == pManager->getcomplist(i)->getOutputPin()) 
					{
						f = 0;
						break;
					}
					else
						f++;
				}
				else
					f++;
			}
		}
	}


	if (f == 0) 
	{
		pUI->CreateSimulationToolBar();
		pUI->PrintMsg("Simulation Mode is On");
		pManager->SetSelectionOfComponents(false);
	}
	else 
	{
		pUI->ClearStatusBar();
		pUI->PrintMsg("Circuit is not valid. Cannot start simulation. ");
	}
	
	int count = pManager->getcompcount();
	/*int *stats = new int[count];
	vector<LED*>pLeds = pManager->GetLeds();
	int n = pLeds.size();*/

	for (int i = 0; i < count; i++)
	{
		//stats[i]=pLeds[i]->GetOutPinStatus();
		//visited.clear();
		if (pManager->getcomplist(i)->getCompType() == "CLD_SWTCH" || pManager->getcomplist(i)->getCompType() == "OPN_SWTCH")
		{
			pManager->getcomplist(i)->Operate();
			for (int j = 0; j < count ; j++)
				if (pManager->getcomplist(j)->getCompType() == "Connection")
					if (pManager->getcomplist(j)->getOutputPin()->getComponent() == pManager->getcomplist(i))
						pManager->getcomplist(j)->Operate();
			cout << pManager->getcomplist(i)->getCompType() << " id: " << pManager->getcomplist(i)->getCompID() << " is operated" << endl;
		}
	}
	for (int i = 0; i < count; i++)
	{
		//stats[i]=pLeds[i]->GetOutPinStatus();
		//visited.clear();
		if (pManager->getcomplist(i)->getCompType() != "CLD_SWTCH" && pManager->getcomplist(i)->getCompType() != "OPN_SWTCH" && pManager->getcomplist(i)->getCompType() != "LED")
		{
			if (pManager->getcomplist(i)->getInPinsNo() == 1)
			{
				if (pManager->getcomplist(i)->GetInputPinStatus(1) != 2)
				{
					pManager->getcomplist(i)->Operate();
					for (int j = 0; j < count; j++)
						if (pManager->getcomplist(j)->getCompType() == "Connection")
							if (pManager->getcomplist(j)->getOutputPin()->getComponent() == pManager->getcomplist(i))
								pManager->getcomplist(j)->Operate();
				}
			}
			else if (pManager->getcomplist(i)->getInPinsNo() == 2)
			{
				if (pManager->getcomplist(i)->GetInputPinStatus(1) != 2 && pManager->getcomplist(i)->GetInputPinStatus(2) != 2)
				{
					pManager->getcomplist(i)->Operate();
					for (int j = 0; j < count; j++)
						if (pManager->getcomplist(j)->getCompType() == "Connection")
							if (pManager->getcomplist(j)->getOutputPin()->getComponent() == pManager->getcomplist(i))
								pManager->getcomplist(j)->Operate();
				}
			}
			else if (pManager->getcomplist(i)->getInPinsNo() == 5)
			{
				if (pManager->getcomplist(i)->GetInputPinStatus(1) != 2 && pManager->getcomplist(i)->GetInputPinStatus(2) != 2 && pManager->getcomplist(i)->GetInputPinStatus(3) != 2 && pManager->getcomplist(i)->GetInputPinStatus(4) != 2 && pManager->getcomplist(i)->GetInputPinStatus(5) != 2)
				{
					pManager->getcomplist(i)->Operate();
					for (int j = 0; j < count; j++)
						if (pManager->getcomplist(j)->getCompType() == "Connection")
							if (pManager->getcomplist(j)->getOutputPin()->getComponent() == pManager->getcomplist(i))
								pManager->getcomplist(j)->Operate();
				}
			}
			cout << "Comp id: " << pManager->getcomplist(i)->getCompID() << " is operated" << endl;
		}
	}
	for (int i = 0; i < count; i++)
		if (pManager->getcomplist(i)->getCompType() == "LED")
		{
			pManager->getcomplist(i)->Operate();
			cout << "LED id: " << pManager->getcomplist(i)->getCompID() << " is operated" << endl;
		}

/*	int x, y;
	pUI->GetPointClicked(x, y);
	if (x <= 80 && y <= 80)
	{
	pUI->CreateDesignToolBar();
	pUI->ClearStatusBar();
	}
	/*if (stop || (circuit.size() < count) || (count == 0))
	{
	ActionType act = ActionType::DSN_MODE;
	pManager->ExecuteAction(act);
	pUI->PrintMsg("Circuit is not valid!");
	}

	int n = visited.size();
	if (pComp != NULL)
	{
	circuit.insert(pComp);
	visited.insert(pComp);
	}


	if (n == visited.size())
	{
	stop = true;
	}
	int out;

	if (pComp != NULL) {
	if (dynamic_cast<ClosedSwitch*>(pComp)) {
	visited.erase(pComp);
	out= pComp->GetOutPinStatus();
	}
	else if (dynamic_cast<LED*>(pComp)) {
	if (((LED*)pComp)->GetInputPin(0)->MAX()) {
	//out to be assigend
	}
	else {
	out = -1;
	stop = true;
	}
	if (out > -1)
	((LED*)pComp)->setInputPinStatus(0, out ? STATUS::HIGH : STATUS::LOW);
	}
	visited.erase(pComp);
	((Gate*)pComp)->Operate();
	out = ((Gate*)pComp)->GetOutPinStatus();

	}*/
}


void Simulation::Undo() {
}

void Simulation::Redo() {
}

Simulation::~Simulation() {

}