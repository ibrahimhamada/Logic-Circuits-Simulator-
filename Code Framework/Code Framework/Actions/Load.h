#ifndef _LOAD_
#define _LOAD_

#include "Action.h"

class Load : public Action
{

public:
	Load(ApplicationManager *pApp);
	virtual ~Load(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif