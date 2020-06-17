#ifndef _EXIT_
#define _EXIT_

#include "Action.h"

class Exit : public Action
{

public:
	Exit(ApplicationManager *pApp);
	virtual ~Exit(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif