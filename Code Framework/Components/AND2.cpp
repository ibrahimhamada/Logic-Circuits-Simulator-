#include "AND2.h"

AND2::AND2(GraphicsInfo *r_pGfxInfo, int r_FanOut):Gate(r_pGfxInfo,2, r_FanOut)
{

}


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	bool out = 1;

	for (int i = 0; i < m_Inputs; i++) {
		out = out && (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::HIGH : STATUS::LOW);
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawAND2(*m_pGfxInfo,selected,getLabel());
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
