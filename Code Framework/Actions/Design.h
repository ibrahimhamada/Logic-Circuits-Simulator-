#ifndef _DESIGN_
#define _DESIGN_

#include "Action.h"

class Design : public Action
{

public:
	Design(ApplicationManager* pApp);
	virtual ~Design(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif