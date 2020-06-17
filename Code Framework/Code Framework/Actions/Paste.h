#ifndef _PASTE_
#define _PASTE_

#include "Action.h"

class Paste : public Action
{

public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif