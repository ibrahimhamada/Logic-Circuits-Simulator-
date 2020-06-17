#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include <set>

class Select : public Action
{


public:
	Select(ApplicationManager* pAppMan);

	//virtual bool ReadActionParameters();

	virtual void Execute();

	virtual void Undo();

	virtual void Redo();

	virtual ~Select();
private:
	int mS_X, mE_X;
	int mS_Y, mE_Y;
	set<Component*> selComps;
};

