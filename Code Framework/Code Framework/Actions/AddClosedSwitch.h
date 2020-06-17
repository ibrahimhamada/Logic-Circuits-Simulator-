#ifndef _ADD_CLOSED_SWITCH_H
#define _ADD_CLOSED_SWITCH_H

#include "Action.h"
#include "..\Components\ClosedSwitch.h"

class AddClosedSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddClosedSwitch(ApplicationManager *pApp);
	virtual ~AddClosedSwitch(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif