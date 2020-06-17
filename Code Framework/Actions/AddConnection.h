#ifndef _ADD_CONNECTION_GATE_H
#define _ADD_CONNECTION_GATE_H

#include "Action.h"
#include "..\Components\Connection.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"
class AddConnection : public Action
{
private:
	//Parameters for the line of connection
	int x1, y1, x2, y2;	//Two points of the connection line
	OutputPin *opin = new OutputPin(2);
	InputPin *ipin = new InputPin();

public:
	AddConnection(ApplicationManager *pApp);
	virtual ~AddConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif