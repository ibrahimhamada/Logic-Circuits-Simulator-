#ifndef _COPY_
#define _COPY_

#include "Action.h"

class Copy : public Action
{

public:
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif