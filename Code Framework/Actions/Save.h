#ifndef _SAVE_
#define _SAVE_

#include "Action.h"

class Save : public Action
{
	int compCount;

public:
	Save(ApplicationManager *pApp,int);
	virtual ~Save(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif