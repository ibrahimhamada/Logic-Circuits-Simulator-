#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

GraphicsInfo* Component::getCompGraphInfo() const
{
	return m_pGfxInfo;
}

void Component::setGraphInfo(GraphicsInfo *gf)
{
	m_pGfxInfo = gf;
}

string Component::getLabel() const
{
	return m_Label;
}

bool Component::IsDeleted() const
{
	return mDeleted;
}

Component::Component()
{}

Component::~Component()
{}

string Component::getCompType() const
{
	return CompType;
}

int Component::getCompID() const
{
	return CompID;
}



void Component::setLabel(string label)
{
	m_Label = label;
}

void Component::setCompType(string type)
{
	CompType = type;
}

void Component::setCompID(int id)
{
	CompID = id;
}

OutputPin * Component::getOutputPin(int n)
{
	return nullptr;
}

InputPin* Component::getDestPin()
{
	return nullptr;
}

int Component::getDstPinNo()
{
	return 0;
}

int Component::getSrcPinNo(Component *pCmp, OutputPin* oPin)
{
	return 0;
}

InputPin * Component::getInputPin(int No)
{
	return nullptr;
}

int Component::getInPinsNo()
{
	return 0;
}

int Component::getOutPinNo(OutputPin * oPin)
{
	return 0;
}
