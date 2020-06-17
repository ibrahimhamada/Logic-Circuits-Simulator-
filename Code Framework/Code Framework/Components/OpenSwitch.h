#ifndef _OPEN_SWITCH_H
#define _OPEN_SWITCH_H

/*
Class OpenSwitch
-----------
represent the Open Switch
*/

#include "Gate.h"

class OpenSwitch :public Gate
{
public:
	OpenSwitch(GraphicsInfo *r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the Switch
	virtual void Draw(UI*);	//Draws the Switch

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif