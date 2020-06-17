#ifndef _MOVE_
#define _MOVE_

#include "Action.h"

class Move : public Action
{

public:
	Move(ApplicationManager* pApp);
	virtual ~Move(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif