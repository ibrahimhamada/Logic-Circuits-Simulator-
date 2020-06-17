#pragma once
#include "Component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection :	public Component
{
	Component*	SrcCmpnt = NULL;	//Connection source component
	Component*	DstCmpnt = NULL;	//Connection Destination component
	int		DstPinNo;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(GraphicsInfo *r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin,int no);
	Connection();
	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(UI* );	//for each component to Draw itself

	
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getOutputPin(int n = 0);
	InputPin* getDestPin();
	int getDstPinNo();
	int getSrcPinNo(Component *pCmp,OutputPin* oPin);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};
