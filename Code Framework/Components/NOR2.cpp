#include "NOR2.h"

NOR2::NOR2(GraphicsInfo *r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}


void NOR2::Operate()
{
	bool out = 0;

	for (int i = 0; i < m_Inputs; i++) {
		out = out || (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::LOW : STATUS::HIGH);
}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(UI* pUI)
{
	//Call output class NOR pass gate drawing info to it.
	pUI->DrawNOR2(*m_pGfxInfo,selected,getLabel());
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
