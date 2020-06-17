#ifndef _Edit_H
#define _Edit_H

#include "Action.h"


class Edit : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	Edit(ApplicationManager *pApp);
	virtual ~Edit(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
