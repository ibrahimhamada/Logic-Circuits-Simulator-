#include "OR2.h"

OR2::OR2(GraphicsInfo *r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void OR2::Operate()
{
	bool out = 0;

	for (int i = 0; i < m_Inputs; i++) {
		out = out || (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::HIGH : STATUS::LOW);
}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawOR2(*m_pGfxInfo,selected,getLabel());
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
