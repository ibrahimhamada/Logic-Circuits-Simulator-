#include "INV1.h"

INV1::INV1(GraphicsInfo *r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 1, r_FanOut)
{
}


void INV1::Operate()
{
	//caclulate the output status as the Inverting of one input pin

	m_OutputPin.setStatus(m_InputPins[0].getStatus() == STATUS::LOW ? STATUS::HIGH : STATUS::LOW);
}


// Function Draw
// Draws 1-input Inverter gate
void INV1::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawINV1(*m_pGfxInfo,selected,getLabel());
}

//returns status of outputpin
int INV1::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV1::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV1::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
