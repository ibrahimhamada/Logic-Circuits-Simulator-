#include "LED.h"

LED::LED(GraphicsInfo *r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 1, r_FanOut)
{
	m_OutputPin = NULL;
}


void LED::Operate()
{
	m_OutputPin.setStatus(m_InputPins[0].getStatus());
}


// Function Draw
// Draws LED
void LED::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawLED(*m_pGfxInfo,selected,getLabel(),m_OutputPin.getStatus());
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
