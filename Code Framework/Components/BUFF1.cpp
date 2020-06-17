#include "BUFF1.h"

BUFF1::BUFF1(GraphicsInfo *r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 1, r_FanOut)
{
}


void BUFF1::Operate()
{
	//caclulate the output status as the Buffering of one input pin
	m_OutputPin.setStatus(m_InputPins[0].getStatus());
}


// Function Draw
// Draws 1-input Buffer gate
void BUFF1::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawBUFF1(*m_pGfxInfo,selected,getLabel());
}

//returns status of outputpin
int BUFF1::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF1::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF1::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
