#pragma once
#include "Gate.h"
#include "Connection.h"
#include "InputPin.h"
#include "OutputPin.h"

class CircuitModule: public Component
{
	InputPin m_InputPins[5];
	OutputPin m_OutPin0,m_Outpin1;
	Component *m_Gates[14];
	Connection m_Connections[30];
	int GatesNo = 14, ConnectNo = 30;
public:
	CircuitModule(GraphicsInfo* pGfxInfo);
	void setInputPin(InputPin *InPin, int n);
	int getInPinsNo();
	OutputPin* getOutputPin(int n);
	InputPin* getInputPin(int No);
	int getOutPinNo(OutputPin * oPin);
	virtual void Operate();	
	virtual void Draw(UI*);	
	virtual int GetOutPinStatus();
	virtual int GetOutPinStatus(int n);	
	virtual int GetInputPinStatus(int n);	

	virtual void setInputPinStatus(int n, STATUS s);	
	~CircuitModule();
};

