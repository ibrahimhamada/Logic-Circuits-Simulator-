#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components\LED.h"
#include <vector>
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount,CopyCompCount;		//Actual number of Components
	Component* CompList[MaxCompCount],*CopyCompList[MaxCompCount];	//List of all Components (Array of pointers)
	UI* pUI; //pointer to the UI
	Component** mCompList;
public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	void SetSelectionOfComponents(bool s);
	vector<LED*> GetLeds();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp, int i = 0);
	void setlbl(string,int);
	Component *getcomplist(int) const;
	void clearcomplist();
	void clearcopylist();
	void PasteCopyList();
	void clearcompitem(int);
	int getcompcount() const;
	void CopyComp(int);
	void setGraphicsInfo(GraphicsInfo*, int);

	//destructor
	~ApplicationManager();
};

#endif