#include "CircuitModule.h"
#include "AND2.h"
#include "XOR2.h"
#include "NAND2.h"
#include "NOR2.h"
#include "XNOR2.h"
#include "OR2.h"
CircuitModule::CircuitModule(GraphicsInfo* pGfxInfo):Component(pGfxInfo),m_OutPin0(5),m_Outpin1(5)
{
	for (int i = 0; i<5;i++)
		m_InputPins[i].setComponent(this);

	m_OutPin0.setComponent(this);
	m_Outpin1.setComponent(this);
	OR2 *OR0 = new OR2(pGfxInfo, 2);
	AND2 *AND1 = new AND2(pGfxInfo,2),*AND5 = new AND2(pGfxInfo,2),*AND7 = new AND2(pGfxInfo,2),*AND13 = new AND2(pGfxInfo,2);
	XOR2 *Xor2 = new XOR2(pGfxInfo, 2), *XOR8 = new XOR2(pGfxInfo, 2), *XOR10 = new XOR2(pGfxInfo, 2);
	NAND2 *NAND3 = new NAND2(pGfxInfo, 2), *NAND6 = new NAND2(pGfxInfo,2);
	NOR2 *NOR4 = new NOR2(pGfxInfo, 2),*NOR11 = new NOR2(pGfxInfo,2),*NOR12 = new NOR2(pGfxInfo,2);
	XNOR2 *XNOR9 = new XNOR2(pGfxInfo, 2);
	m_Gates[0] = OR0;
	m_Gates[1] = AND1;
	m_Gates[2] = Xor2;
	m_Gates[3] = NAND3;
	m_Gates[4] = NOR4;
	m_Gates[5] = AND5;
	m_Gates[6] = NAND6;
	m_Gates[7] = AND7;
	m_Gates[8] = XOR8;
	m_Gates[9] = XNOR9;
	m_Gates[10] =XOR10;
	m_Gates[11] =NOR11;
	m_Gates[12] =NOR12;
	m_Gates[13] =AND13;
	OutputPin *opin = new OutputPin(2);
	InputPin *ipin = new InputPin();
	opin->setComponent(this);
	opin->setStatus(m_InputPins[0].getStatus());
	ipin->setComponent(Xor2);
	Connection c0(pGfxInfo, opin, ipin, 1);
	m_Connections[0] = c0;
	opin->setComponent(this);
	opin->setStatus(m_InputPins[1].getStatus());
	ipin->setComponent(Xor2);
	Connection c1(pGfxInfo, opin, ipin, 2);
	m_Connections[1] = c1;
	opin->setComponent(this);
	opin->setStatus(m_InputPins[1].getStatus());
	ipin->setComponent(NAND3);
	Connection c2(pGfxInfo, opin, ipin, 1);
	m_Connections[2] = c2;
	opin->setComponent(this);
	opin->setStatus(m_InputPins[3].getStatus());
	ipin->setComponent(NAND3);
	Connection c3(pGfxInfo, opin, ipin, 2);
	m_Connections[3] = c3;
	opin->setComponent(this);
	opin->setStatus(m_InputPins[2].getStatus());
	ipin->setComponent(NAND6);
	Connection c4(pGfxInfo, opin, ipin, 1);
	m_Connections[4] = c4;
	opin->setComponent(this);
	opin->setStatus(m_InputPins[4].getStatus());
	ipin->setComponent(NAND6);
	Connection c5(pGfxInfo, opin, ipin, 2);
	m_Connections[5] = c5;
	opin->setComponent(this);
	opin->setStatus(m_InputPins[2].getStatus());
	ipin->setComponent(OR0);
	Connection c6(pGfxInfo, opin, ipin, 1);
	m_Connections[6] = c6;
	opin->setComponent(this);
	opin->setStatus(m_InputPins[4].getStatus());
	ipin->setComponent(OR0);
	Connection c7(pGfxInfo, opin, ipin, 2);
	m_Connections[7] = c7;
	opin->setComponent(OR0);
	ipin->setComponent(AND1);
	Connection c8(pGfxInfo, opin, ipin, 1);
	m_Connections[8] = c8;
	opin->setComponent(Xor2);
	ipin->setComponent(AND1);
	Connection c9(pGfxInfo, opin, ipin, 2);
	m_Connections[9] = c9;
	opin->setComponent(NAND3);
	ipin->setComponent(NOR4);
	Connection c10(pGfxInfo, opin, ipin, 1);
	m_Connections[10] = c10;
	opin->setComponent(NAND6);
	ipin->setComponent(NOR4);
	Connection c11(pGfxInfo, opin, ipin, 2);
	m_Connections[11] = c11;
	opin->setComponent(AND1);
	ipin->setComponent(AND5);
	Connection c12(pGfxInfo, opin, ipin, 1);
	m_Connections[12] = c12;
	opin->setComponent(NOR4);
	ipin->setComponent(AND5);
	Connection c13(pGfxInfo, opin, ipin, 2);
	m_Connections[13] = c13;
	opin->setComponent(AND5);
	ipin->setComponent(this);
	Connection c14(pGfxInfo, opin, ipin, 1);
	m_Connections[14] = c14;
	opin->setComponent(this);
	ipin->setComponent(XOR10);
	Connection c15(pGfxInfo, opin, ipin, 1);
	m_Connections[15] = c15;
	opin->setComponent(this);
	ipin->setComponent(XOR10);
	Connection c16(pGfxInfo, opin, ipin, 2);
	m_Connections[16] = c16;
	opin->setComponent(this);
	ipin->setComponent(NOR11);
	Connection c17(pGfxInfo, opin, ipin, 1);
	m_Connections[17] = c17;
	opin->setComponent(this);
	ipin->setComponent(NOR11);
	Connection c18(pGfxInfo, opin, ipin, 2);
	m_Connections[18] = c18;
	opin->setComponent(this);
	ipin->setComponent(AND13);
	Connection c19(pGfxInfo, opin, ipin, 1);
	m_Connections[19] = c19;
	opin->setComponent(this);
	ipin->setComponent(AND13);
	Connection c20(pGfxInfo, opin, ipin, 2);
	m_Connections[20] = c20;
	opin->setComponent(this);
	ipin->setComponent(AND7);
	Connection c21(pGfxInfo, opin, ipin, 1);
	m_Connections[21] = c21;
	opin->setComponent(this);
	ipin->setComponent(AND7);
	Connection c22(pGfxInfo, opin, ipin, 2);
	m_Connections[22] = c22;
	opin->setComponent(XOR10);
	ipin->setComponent(XOR8);
	Connection c23(pGfxInfo, opin, ipin, 2);
	m_Connections[23] = c23;
	opin->setComponent(NOR11);
	ipin->setComponent(NOR12);
	Connection c24(pGfxInfo, opin, ipin, 1);
	m_Connections[24] = c24;
	opin->setComponent(AND13);
	ipin->setComponent(NOR12);
	Connection c25(pGfxInfo, opin, ipin, 2);
	m_Connections[25] = c25;
	opin->setComponent(AND7);
	ipin->setComponent(XOR8);
	Connection c26(pGfxInfo, opin, ipin, 1);
	m_Connections[26] = c26;
	opin->setComponent(XOR8);
	ipin->setComponent(XNOR9);
	Connection c27(pGfxInfo, opin, ipin, 1);
	m_Connections[27] = c27;
	opin->setComponent(NOR12);
	ipin->setComponent(XNOR9);
	Connection c28(pGfxInfo, opin, ipin, 2);
	m_Connections[28] = c28;
	opin->setComponent(XNOR9);
	ipin->setComponent(this);
	Connection c29(pGfxInfo, opin, ipin, 1);
	m_Connections[29] = c29;
}

void CircuitModule::setInputPin(InputPin * InPin, int n)
{
	m_InputPins[n - 1] = *InPin;
}

int CircuitModule::getInPinsNo()
{
	return 5;
}

OutputPin * CircuitModule::getOutputPin(int n)
{
	if (n == 1)
		return &m_OutPin0;
	else if (n == 2)
		return &m_Outpin1;
}

InputPin * CircuitModule::getInputPin(int No)
{
	return &m_InputPins[No-1];
}

int CircuitModule::getOutPinNo(OutputPin * oPin)
{
	if (oPin == &m_OutPin0)
		return 1;
	else if (oPin == &m_Outpin1)
		return 2;
}

void CircuitModule::Operate()
{
	m_Connections[0].setInputPinStatus(1, m_InputPins[0].getStatus());
	m_Connections[1].setInputPinStatus(1, m_InputPins[1].getStatus());
	m_Connections[2].setInputPinStatus(1, m_InputPins[1].getStatus());
	m_Connections[3].setInputPinStatus(1, m_InputPins[3].getStatus());
	m_Connections[4].setInputPinStatus(1, m_InputPins[2].getStatus());
	m_Connections[5].setInputPinStatus(1, m_InputPins[4].getStatus());
	m_Connections[6].setInputPinStatus(1, m_InputPins[2].getStatus());
	m_Connections[7].setInputPinStatus(1, m_InputPins[4].getStatus());
	m_Connections[15].setInputPinStatus(1, m_InputPins[0].getStatus());
	m_Connections[16].setInputPinStatus(1, m_InputPins[2].getStatus());
	m_Connections[17].setInputPinStatus(1, m_InputPins[1].getStatus());
	m_Connections[18].setInputPinStatus(1, m_InputPins[2].getStatus());
	m_Connections[19].setInputPinStatus(1, m_InputPins[2].getStatus());
	m_Connections[20].setInputPinStatus(1, m_InputPins[4].getStatus());
	m_Connections[21].setInputPinStatus(1, m_InputPins[3].getStatus());
	m_Connections[22].setInputPinStatus(1, m_InputPins[4].getStatus());
	
	for (int i = 0, j = 15; i < 8 && j < 23; i++, j++)
	{
		m_Connections[i].Operate();
		m_Connections[j].Operate();
	}

	m_Gates[0]->Operate();
	m_Gates[2]->Operate();
	m_Gates[3]->Operate();
	m_Gates[6]->Operate();
	m_Gates[7]->Operate();
	m_Gates[10]->Operate();
	m_Gates[11]->Operate();
	m_Gates[13]->Operate();

	for (int i = 8, j = 23; i < 13 && j < 27; i++, j++)
	{
		m_Connections[i].Operate();
		m_Connections[j].Operate();
	}
	
	m_Gates[1]->Operate();
	m_Gates[4]->Operate();
	m_Gates[8]->Operate();
	m_Gates[12]->Operate();

	for (int i = 12, j = 27; i < 14 && j < 29; i++, j++)
	{
		m_Connections[i].Operate();
		m_Connections[j].Operate();
	}
	
	m_Gates[5]->Operate();
	m_Gates[9]->Operate();

	m_Connections[14].Operate();
	m_Connections[29].Operate();

	m_OutPin0.setStatus((STATUS)m_Connections[14].GetOutPinStatus());
	m_Outpin1.setStatus((STATUS)m_Connections[29].GetOutPinStatus());
}

void CircuitModule::Draw(UI *pUI)
{
	pUI->DrawCircuitModule(*m_pGfxInfo, selected, getLabel());
}

int CircuitModule::GetOutPinStatus()
{
	return 0;
}

int CircuitModule::GetOutPinStatus(int n)
{
	if (n == 1)
		return m_OutPin0.getStatus();
	else if (n == 2)
		return m_Outpin1.getStatus();
}

int CircuitModule::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void CircuitModule::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

CircuitModule::~CircuitModule()
{
}