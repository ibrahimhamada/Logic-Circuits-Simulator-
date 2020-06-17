#include "ClosedSwitch.h"

ClosedSwitch::ClosedSwitch(GraphicsInfo *r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 0, r_FanOut)
{
}


void ClosedSwitch::Operate()
{
	//caclulate the output status as the Switching of the two terminals

	//Add you code here
	m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws the Switch
void ClosedSwitch::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawClosedSwitch(*m_pGfxInfo,selected,getLabel());
}

//returns status of outputpin
int ClosedSwitch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int ClosedSwitch::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void ClosedSwitch::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
