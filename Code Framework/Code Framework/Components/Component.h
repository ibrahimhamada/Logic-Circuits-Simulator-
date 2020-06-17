#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "OutputPin.h"
#include "InputPin.h"
//Base class for classes Gate, Switch, and LED.
class Component
{
	string m_Label;
	string CompType;
	int CompID = 0;
protected:
	GraphicsInfo *m_pGfxInfo;
	bool mDeleted;
	//The parameters required to draw a component
public:
	Component(GraphicsInfo *r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	bool selected = false;
	GraphicsInfo* getCompGraphInfo() const;
	void setGraphInfo(GraphicsInfo*);
	string getLabel() const;
	string getCompType() const;
	int getCompID() const;
	void setLabel(string);
	void setCompType(string);
	void setCompID(int);

	virtual OutputPin* getOutputPin(int n = 0);
	virtual InputPin* getDestPin();
	virtual int getDstPinNo();
	virtual int getSrcPinNo(Component *pCmp, OutputPin* oPin);
	virtual InputPin* getInputPin(int No);
	virtual int getInPinsNo();
	virtual int getOutPinNo(OutputPin * oPin);


	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	
	bool IsDeleted() const;

	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
