#ifndef _ADD_CircuitModule_H
#define _ADD_CircuitModule_H

#include "Action.h"
#include "..\Components\CircuitModule.h"

class AddCircuitModule : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddCircuitModule(ApplicationManager* pApp);
	virtual ~AddCircuitModule(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif