#include "Load.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "..\Components\Component.h"
#include <fstream>
#include <string>
#include "..\Components\AND2.h"
#include "..\Components\OR2.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\XOR2.h"
#include "..\Components\XNOR2.h"
#include "..\Components\INV1.h"
#include "..\Components\LED.h"
#include "..\Components\ClosedSwitch.h"
#include "..\Components\OpenSwitch.h"
#include "..\Components\OutputPin.h"
#include "..\Components\InputPin.h"
#include "..\Components\Connection.h"
#include "..\Components\CircuitModule.h"
Load::Load(ApplicationManager *pApp) :Action(pApp)
{
}

Load::~Load(void)
{
}

void Load::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearDrawingArea();
	ifstream file;
	pUI->ClearStatusBar();
	pUI->PrintMsg("Enter your file name: ");
	file.open(pUI->GetSrting());
	if (!file)
		pUI->PrintMsg("Error");
	else
	{
		pManager->clearcomplist();
		int compCount, SrcID, DstID, InNo,cnCount, inPins, OutNo;
		string type, lbl;
		int id, x, y;
		
		OutputPin *opin = new OutputPin(2);
		InputPin *ipin = new InputPin;
		file >> compCount;
		for (int i = 0; i < compCount; i++)
		{
			GraphicsInfo *gf = new GraphicsInfo(2);
			file >> type >> id >> lbl >> x >> y;
			gf->PointsList[0].x = x;
			gf->PointsList[0].y = y;
			gf->PointsList[1].x = x + pUI->getGateWidth();
			gf->PointsList[1].y = y + pUI->getGateHeight();
			//pManager->setcomplist(i,lbl,type,id,gf);
			if (type == "AND")
			{
				AND2 *pA = new AND2(gf, AND2_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA,id);
			}
			else if (type == "OR")
			{
				OR2 *pA = new OR2(gf, OR2_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA,id);
			}
			else if (type == "NAND")
			{
				NAND2 *pA = new NAND2(gf, NAND2_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "NOR")
			{
				NOR2 *pA = new NOR2(gf, NOR2_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "XOR")
			{
				XOR2 *pA = new XOR2(gf, XOR2_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "XNOR")
			{
				XNOR2 *pA = new XNOR2(gf, XNOR2_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "NOT")
			{
				INV1 *pA = new INV1(gf, INV1_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "CLD_SWTCH")
			{
				ClosedSwitch *pA = new ClosedSwitch(gf, SWITCH_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "OPN_SWTCH")
			{
				OpenSwitch *pA = new OpenSwitch(gf, SWITCH_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "LED")
			{
				LED *pA = new LED(gf, LED_FANOUT);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA, id);
			}
			else if (type == "CircuitModule#17")
			{
				CircuitModule* pA = new CircuitModule(gf);
				pA->setCompType(type);
				pA->setLabel(lbl);
				pManager->AddComponent(pA,id);
			}
		}
		file >> type >> cnCount;
		for (int i = 0; i < cnCount; i++)
		{
			GraphicsInfo *gfx = new GraphicsInfo(2);
		//	if (pManager->getcomplist(i)->getCompType() != "CircuitModule#17")
				file >> SrcID >> DstID >> InNo;
	/*		else
				file >> SrcID >> DstID >> InNo >> OutNo;*/
			for (int i = 0; i < cnCount+compCount; i++)
			{
				if (pManager->getcomplist(i) == NULL)
					continue;
				if (SrcID == pManager->getcomplist(i)->getCompID())
				{
					if (pManager->getcomplist(i)->getCompType() != "CircuitModule#17")
						opin = pManager->getcomplist(i)->getOutputPin();
					else
					{
						file >> OutNo;
						opin = pManager->getcomplist(i)->getOutputPin(OutNo);
					}
				}
				if (DstID == pManager->getcomplist(i)->getCompID())
				{
					if (pManager->getcomplist(i)->getCompType() != "CircuitModule#17")
					{
						ipin = pManager->getcomplist(i)->getInputPin(InNo - 1);
						inPins = pManager->getcomplist(i)->getInPinsNo();
					}
					else
					{
						ipin = pManager->getcomplist(i)->getInputPin(InNo);
						inPins = pManager->getcomplist(i)->getInPinsNo();
					}
				}
			}
			gfx->PointsList[0].x = opin->getComponent()->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
			gfx->PointsList[0].y = opin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()/2;
			if (inPins == 2)
				if (InNo == 2)
				{
					gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
					gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2 + 12.5;
				}
				else
				{
					gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
					gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
				}
			else if (inPins == 5)
			{
				if (InNo == 1)
				{
					gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
					gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 8;
				}
				else if (InNo == 2)
				{
					gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
					gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
				}
				else if (InNo == 3)
				{
					gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
					gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() *3/ 8;
				}
				else if (InNo == 4)
				{
					gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
					gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() /2;
				}
				else if (InNo == 5)
				{
					gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
					gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() *5/8;
				}
			}
			else
			{
				gfx->PointsList[1].x = ipin->getComponent()->getCompGraphInfo()->PointsList[0].x;
				gfx->PointsList[1].y = ipin->getComponent()->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
			}
			Connection *pA = new Connection(gfx, opin, ipin, InNo);
			pA->setCompType("Connection");
			pA->setLabel("Connection");
			for (int i = 0; i < cnCount+compCount; i++)
				if (pManager->getcomplist(i) == NULL)
				{
					pManager->AddComponent(pA, i + 1);
					break;
				}
		}
		pUI->ClearStatusBar();
		//pUI->PrintMsg("Load Complete");
	}
}

void Load::Undo()
{
}

void Load::Redo()
{
}
