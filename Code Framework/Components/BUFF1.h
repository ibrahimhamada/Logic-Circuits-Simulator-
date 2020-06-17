#ifndef _BUFF1_H
#define _BUFF1_H

/*
Class BUFF1
-----------
represent the 1-input Buffer gate
*/

#include "Gate.h"

class BUFF1 :public Gate
{
public:
	BUFF1(GraphicsInfo *r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the Buffer gate
	virtual void Draw(UI*);	//Draws 1-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif