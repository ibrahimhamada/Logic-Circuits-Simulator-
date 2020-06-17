#include "Save.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"
#include <fstream>
Save::Save(ApplicationManager *pApp,int comp):Action(pApp)
{
	compCount = comp;
}

Save::~Save(void)
{
}

void Save::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	int cCN = 0, cCMP = 0;
	ofstream file;
	pUI->ClearStatusBar();
	pUI->PrintMsg("Enter your file name: ");
	file.open(pUI->GetSrting());
	if (!file)
		pUI->PrintMsg("Error");
	else
	{
		Component *item;
		Connection *cn;
		for (int i = 0; i < compCount; i++)
		{
			item = pManager->getcomplist(i);
			if (item->getCompType() == "Connection")
				cCN++;
			else
				cCMP++;
		}
		file << cCMP << endl;
		Point* p = new Point;
		for (int i = 0; i < compCount; i++)
		{
			item = pManager->getcomplist(i);
			if (item->getCompType() != "Connection")
			{
				p = item->getCompGraphInfo()->getPointList();
				file << item->getCompType() << " " << item->getCompID() << " " << item->getLabel() << " " << p[0].x << " " << p[0].y << endl;
			}
		}
		file << "Connections" << endl << cCN << endl;
		for (int i = 0; i < compCount; i++)
		{
			item = pManager->getcomplist(i);
			if (item->getCompType() == "Connection")
			{
				if (item->getOutputPin()->getComponent()->getCompType() != "CircuitModule#17")
					file << item->getOutputPin()->getComponent()->getCompID() << " " << item->getDestPin()->getComponent()->getCompID() << " " << item->getDstPinNo() << endl;
				else
					file << item->getOutputPin()->getComponent()->getCompID() << " " << item->getDestPin()->getComponent()->getCompID() << " " << item->getDstPinNo() << " " << item->getSrcPinNo(item->getOutputPin()->getComponent(), item->getOutputPin()) << endl;
			}
		}
		//delete p;
		pUI->PrintMsg("Save Complete!");
	}
	file.close();
}

void Save::Undo()
{
}

void Save::Redo()
{
}
