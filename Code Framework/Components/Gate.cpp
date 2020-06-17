#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut):Component(pGfxInfo), m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	m_OutputPin.setComponent(this);
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

OutputPin * Gate::getOutputPin(int n)
{
	return &m_OutputPin;
}

InputPin * Gate::getInputPin(int No)
{
	return &m_InputPins[No];
}

int Gate::getInPinsNo()
{
	return m_Inputs;
}
