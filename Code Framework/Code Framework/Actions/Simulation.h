#pragma once
#pragma once
#include "..\Actions\Action.h"
#include "..\UI\UI.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Components\LED.h"
#include "..\Components\ClosedSwitch.h"
#include "..\Components\Gate.h"
#include "..\Components\Connection.h"
#include "..\Components\Component.h"
#include <string>
#include <set>
using namespace std;

class Simulation : public Action
{
public:
	Simulation(ApplicationManager* pAppMan);

	int CalcOutput(Component* pCmp);

	virtual void Execute();

	virtual void Undo();

	virtual void Redo();

	virtual ~Simulation();
private:
	set<Component*> visited, circuit;
	bool stop;
	Component* pComp = NULL;
};
