#include "OpenSwitch.h"

OpenSwitch::OpenSwitch(GraphicsInfo *r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 0, r_FanOut)
{
}


void OpenSwitch::Operate()
{
	m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws the Switch
void OpenSwitch::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawOpenSwitch(*m_pGfxInfo,selected,getLabel());
}

//returns status of outputpin
int OpenSwitch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OpenSwitch::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OpenSwitch::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
