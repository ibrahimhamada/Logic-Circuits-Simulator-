#ifndef _DEL_
#define _DEL_

#include "Action.h"

class Delete : public Action
{

public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif