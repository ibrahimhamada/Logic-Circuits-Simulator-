#ifndef _ADD_BUFF_GATE_H
#define _ADD_BUFF_GATE_H

#include "Action.h"
#include "..\Components\BUFF1.h"

class AddBUFFgate1 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddBUFFgate1(ApplicationManager *pApp);
	virtual ~AddBUFFgate1(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif