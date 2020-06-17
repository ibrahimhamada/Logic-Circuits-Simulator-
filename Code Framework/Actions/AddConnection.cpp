#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include <cmath>
AddConnection::AddConnection(ApplicationManager *pApp) :Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	/*int selectedCount = 0;
	int *x = new int[2];
	int *y = new int[2];
	for (int i = 0; i < pManager->getcompcount(); i++)
		if (pManager->getcomplist(i)->selected)
			selectedCount++;
	if (selectedCount == 2)
	{//Calculate the rectangle Corners
		int gateWidth = pUI->getGateWidth();
		int gateHeight = pUI->getGateHeight();
		for (int i = 0; i < pManager->getcompcount(); i++)
			if (pManager->getcomplist(i)->selected)
			{
				x[i] = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x;
				y[i] = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y;
			}
*/
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection
	Component* DstComp,*ConnectionInPin;
	int InPinNo, c=0,n=0,q=0,PinNo;
	pUI->PrintMsg("Click on Two Components to Connect");
	pUI->GetPointClicked(x1, y1);
	pUI->GetPointClicked(x2, y2);
	for (int i = 0; i < pManager->getcompcount(); i++)
	{
		if (x2 > x1 + pUI->getGateWidth())
		{
			if ((x1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
				n++;
			else if ((x2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
				n++;
		}
		else if (x1 > x2 + pUI->getGateWidth())
		{
			if ((x2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
				n++;
			else if ((x1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
				n++;
		}
	}
	if (n == 2)
	{
		if (x2 > x1 + pUI->getGateWidth())
		{
			for (int i = 0; i < pManager->getcompcount(); i++)
			{
				if ((x1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
					//					if (x2 > x1)
				{
					if (pManager->getcomplist(i)->getCompType() != "LED")
					{
						if (pManager->getcomplist(i)->getCompType() != "CircuitModule#17")
						{
							pGInfo->PointsList[0].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
							pGInfo->PointsList[0].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
							opin = pManager->getcomplist(i)->getOutputPin();
						}
						else
						{
							if (y2 < y1)
							{
								pGInfo->PointsList[0].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
								pGInfo->PointsList[0].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 3;
								opin = pManager->getcomplist(i)->getOutputPin(1);
							}
							else
							{
								pGInfo->PointsList[0].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
								pGInfo->PointsList[0].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 3*2;
								opin = pManager->getcomplist(i)->getOutputPin(2);
							}
						}
					}
					else
					{
						q++;
						break;
					}
				}
				/*					else
				{
				pGInfo->PointsList[1].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
				pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
				}*/
				else if ((x2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
				{
					pGInfo->PointsList[1].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x;
					pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
					DstComp = pManager->getcomplist(i);
					for (int i = 0; i < pManager->getcompcount(); i++)
						if (pManager->getcomplist(i)->getCompType() == "Connection")
							if (pManager->getcomplist(i)->getDestPin()->getComponent() == DstComp)
							{
								ConnectionInPin = pManager->getcomplist(i);
								c++;
							}
					if (DstComp->getInPinsNo() == 2)
						if (c == 1)
						{
							InPinNo = ConnectionInPin->getDstPinNo();
							if (InPinNo == 1)
							{
								ipin = DstComp->getInputPin(1);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2 + 12.5;
								PinNo = 2;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 2);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
								pA->setCompType("Connection");
								pA->setLabel("Connection");
								pManager->AddComponent(pA);
								}
								else
								pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
							else
							{
								ipin = DstComp->getInputPin(0);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
								PinNo = 1;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 1);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
								pA->setCompType("Connection");
								pA->setLabel("Connection");
								pManager->AddComponent(pA);
								}
								else
								pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
						}
						else if (c == 2)
						{
							ipin = NULL;
							/*pUI->PrintMsg("Error: The Connection is invalid!");*/
						}
						else
						{
							if (pGInfo->PointsList[0].y - pGInfo->PointsList[1].y > 0)
							{
								ipin = DstComp->getInputPin(1);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2 + 12.5;
								PinNo = 2;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 2);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
								pA->setCompType("Connection");
								pA->setLabel("Connection");
								pManager->AddComponent(pA);
								}
								else
								pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
							else
							{
								ipin = DstComp->getInputPin(0);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
								PinNo = 1;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 1);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
								pA->setCompType("Connection");
								pA->setLabel("Connection");
								pManager->AddComponent(pA);
								}
								else
								pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
						}
					else if (DstComp->getInPinsNo() == 1)
						if (c == 1)
						{
							ipin = NULL;
							/*pUI->PrintMsg("Error: The Connection is invalid!");*/
						}
						else
						{
							ipin = DstComp->getInputPin(0);
							PinNo = 1;
							/*Connection *pA = new Connection(pGInfo, opin, ipin, 1);
							//pA->setSrcComponent(SrcComp);
							pUI->ClearStatusBar();
							if (opin->ConnectTo(pA))
							{
							pA->setCompType("Connection");
							pA->setLabel("Connection");
							pManager->AddComponent(pA);
							}
							else
							pUI->PrintMsg("Error: The Connection is invalid!");*/

						}
					else if (DstComp->getInPinsNo() == 5)
					{
						if (c == 5)
							ipin = NULL;
						else if (c == 0)
						{
							ipin = DstComp->getInputPin(1);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 8;
							PinNo = 1;
						}
						else if (c == 1)
						{
							ipin = DstComp->getInputPin(2);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
							PinNo = 2;
						}
						else if (c == 2)
						{
							ipin = DstComp->getInputPin(3);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() *3/8;
							PinNo = 3;
						}
						else if (c == 3)
						{
							ipin = DstComp->getInputPin(4);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
							PinNo = 4;
						}
						else if (c == 4)
						{
							ipin = DstComp->getInputPin(5);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() *5/8;
							PinNo = 5;
						}
					}
					/*else
					pUI->PrintMsg("Error: The Connection is invalid!");*/
				}
			}
			if (q == 1)
				pUI->PrintMsg("Error: The Connection is invalid!");
			else
				if (DstComp->getInPinsNo() == 2)
					if (c == 2)
					{
						pUI->PrintMsg("Error: The Connection is invalid!");
					}
					else
					{
						Connection *pA = new Connection(pGInfo, opin, ipin, PinNo);
						//pA->setSrcComponent(SrcComp);
						pUI->ClearStatusBar();
						if (opin->ConnectTo(pA))
						{
							pA->setCompType("Connection");
							pA->setLabel("Connection");
							pManager->AddComponent(pA);
						}
						else
							pUI->PrintMsg("Error: The Connection is invalid!");
					}
				else if (DstComp->getInPinsNo() == 1)
					if (c == 1)
					{
						pUI->PrintMsg("Error: The Connection is invalid!");
					}
					else
					{
						Connection *pA = new Connection(pGInfo, opin, ipin, PinNo);
						//pA->setSrcComponent(SrcComp);
						pUI->ClearStatusBar();
						if (opin->ConnectTo(pA))
						{
							pA->setCompType("Connection");
							pA->setLabel("Connection");
							pManager->AddComponent(pA);
						}
						else
							pUI->PrintMsg("Error: The Connection is invalid!");
					}
				else if (DstComp->getInPinsNo() == 5)
				{
					if (c == 5)
						pUI->PrintMsg("Error: The Connection is invalid!");
					else
					{
						Connection *pA = new Connection(pGInfo, opin, ipin, PinNo);
						//pA->setSrcComponent(SrcComp);
						pUI->ClearStatusBar();
						if (opin->ConnectTo(pA))
						{
							pA->setCompType("Connection");
							pA->setLabel("Connection");
							pManager->AddComponent(pA);
						}
						else
							pUI->PrintMsg("Error: The Connection is invalid!");
					}
				}
				else
					pUI->PrintMsg("Error: The Connection is invalid!");
		}
		else if (x1 > x2 + pUI->getGateWidth())
		{
			for (int i = 0; i < pManager->getcompcount(); i++)
			{
				if ((x2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y2 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y2 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
					//					if (x2 > x1)
				{
					if (pManager->getcomplist(i)->getCompType() != "LED")
					{
						if (pManager->getcomplist(i)->getCompType() != "CircuitModule#17")
						{
							pGInfo->PointsList[0].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
							pGInfo->PointsList[0].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
							opin = pManager->getcomplist(i)->getOutputPin();
						}
						else
						{
							if (y2 < y1)
							{
								pGInfo->PointsList[0].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
								pGInfo->PointsList[0].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 3*2;
								opin = pManager->getcomplist(i)->getOutputPin(2);
							}
							else
							{
								pGInfo->PointsList[0].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
								pGInfo->PointsList[0].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() /3;
								opin = pManager->getcomplist(i)->getOutputPin(1);
							}
						}
					}
					else
					{
						q++;
						break;
					}
				}
				/*					else
				{
				pGInfo->PointsList[1].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth();
				pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
				}*/
				else if ((x1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x && x1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x + pUI->getGateWidth()) && (y1 >= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y && y1 <= pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight()))
				{
					pGInfo->PointsList[1].x = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].x;
					pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
					DstComp = pManager->getcomplist(i);
					for (int i = 0; i < pManager->getcompcount(); i++)
						if (pManager->getcomplist(i)->getCompType() == "Connection")
							if (pManager->getcomplist(i)->getDestPin()->getComponent() == DstComp)
							{
								ConnectionInPin = pManager->getcomplist(i);
								c++;
							}
					if (DstComp->getInPinsNo() == 2)
						if (c == 1)
						{
							InPinNo = ConnectionInPin->getDstPinNo();
							if (InPinNo == 1)
							{
								ipin = DstComp->getInputPin(1);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2 + 12.5;
								PinNo = 2;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 2);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
									pA->setCompType("Connection");
									pA->setLabel("Connection");
									pManager->AddComponent(pA);
								}
								else
									pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
							else
							{
								ipin = DstComp->getInputPin(0);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
								PinNo = 1;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 1);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
									pA->setCompType("Connection");
									pA->setLabel("Connection");
									pManager->AddComponent(pA);
								}
								else
									pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
						}
					else if (c == 2)
					{
						ipin = NULL;
						//pUI->PrintMsg("Error: The Connection is invalid!");
					}
						else
						{
							if (pGInfo->PointsList[0].y - pGInfo->PointsList[1].y > 0)
							{
								ipin = DstComp->getInputPin(1);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2 + 12.5;
								PinNo = 2;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 2);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
									pA->setCompType("Connection");
									pA->setLabel("Connection");
									pManager->AddComponent(pA);
								}
								else
									pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
							else
							{
								ipin = DstComp->getInputPin(0);
								pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
								PinNo = 1;
								/*Connection *pA = new Connection(pGInfo, opin, ipin, 1);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
									pA->setCompType("Connection");
									pA->setLabel("Connection");
									pManager->AddComponent(pA);
								}
								else
									pUI->PrintMsg("Error: The Connection is invalid!");*/
							}
						}
					else if (DstComp->getInPinsNo() == 1)
						if (c == 1)
						{
							ipin = NULL;
							/*pUI->PrintMsg("Error: The Connection is invalid!");*/
						}
						else
						{
							ipin = DstComp->getInputPin(0);
							PinNo = 1;
							/*	Connection *pA = new Connection(pGInfo, opin, ipin, 1);
								//pA->setSrcComponent(SrcComp);
								pUI->ClearStatusBar();
								if (opin->ConnectTo(pA))
								{
									pA->setCompType("Connection");
									pA->setLabel("Connection");
									pManager->AddComponent(pA);
								}
								else
									pUI->PrintMsg("Error: The Connection is invalid!");*/
						}
					else if (DstComp->getInPinsNo() == 5)
					{
						if (c == 5)
							ipin = NULL;
						else if (c == 0)
						{
							ipin = DstComp->getInputPin(1);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 8;
							PinNo = 1;
						}
						else if (c == 1)
						{
							ipin = DstComp->getInputPin(2);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 4;
							PinNo = 2;
						}
						else if (c == 2)
						{
							ipin = DstComp->getInputPin(3);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() *3/8;
							PinNo = 3;
						}
						else if (c == 3)
						{
							ipin = DstComp->getInputPin(4);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() / 2;
							PinNo = 4;
						}
						else if (c == 4)
						{
							ipin = DstComp->getInputPin(5);
							pGInfo->PointsList[1].y = pManager->getcomplist(i)->getCompGraphInfo()->PointsList[0].y + pUI->getGateHeight() * 5 / 8;
							PinNo = 5;
						}
					}
					/*else
						pUI->PrintMsg("Error: The Connection is invalid!");*/
				}
			}
			if (q == 1)
				pUI->PrintMsg("Error: The Connection is invalid!");
			else
				if (DstComp->getInPinsNo() == 2)
					if (c == 2)
					{
						pUI->PrintMsg("Error: The Connection is invalid!");
					}
					else
					{
						Connection *pA = new Connection(pGInfo, opin, ipin, PinNo);
						//pA->setSrcComponent(SrcComp);
						pUI->ClearStatusBar();
						if (opin->ConnectTo(pA))
						{
							pA->setCompType("Connection");
							pA->setLabel("Connection");
							pManager->AddComponent(pA);
						}
						else
							pUI->PrintMsg("Error: The Connection is invalid!");
					}
				else if (DstComp->getInPinsNo() == 1)
					if (c == 1)
					{
						pUI->PrintMsg("Error: The Connection is invalid!");
					}
					else
					{
						Connection *pA = new Connection(pGInfo, opin, ipin, PinNo);
						//pA->setSrcComponent(SrcComp);
						pUI->ClearStatusBar();
						if (opin->ConnectTo(pA))
						{
							pA->setCompType("Connection");
							pA->setLabel("Connection");
							pManager->AddComponent(pA);
						}
						else
							pUI->PrintMsg("Error: The Connection is invalid!");
					}
				else if (DstComp->getInPinsNo() == 5)
				{
					if (c == 5)
						pUI->PrintMsg("Error: The Connection is invalid!");
					else
					{
						Connection *pA = new Connection(pGInfo, opin, ipin, PinNo);
						//pA->setSrcComponent(SrcComp);
						pUI->ClearStatusBar();
						if (opin->ConnectTo(pA))
						{
							pA->setCompType("Connection");
							pA->setLabel("Connection");
							pManager->AddComponent(pA);
						}
						else
							pUI->PrintMsg("Error: The Connection is invalid!");
					}
				}
				else
					pUI->PrintMsg("Error: The Connection is invalid!");
		}
		else
			pUI->PrintMsg("Error: The Connection is invalid!");
	}
	else
		pUI->PrintMsg("Error: The Connection is invalid!");

		/*}
		else
			pUI->PrintMsg("Invalid to have such connection!");
				*/
		/*if (x[0] < x[1] + gateWidth)
		{
			pGInfo->PointsList[0].x = x[0] + gateWidth;
			pGInfo->PointsList[0].y = y[0] + gateHeight / 2;
			pGInfo->PointsList[1].x = x[1];
			pGInfo->PointsList[1].y = y[1] + gateHeight / 2;
			Connection *pA = new Connection(pGInfo, opin, ipin);
			selectedCount = 0;
			delete x;
			delete y;
			pManager->AddComponent(pA);
		}
		else if (x[1] < x[0] + gateWidth)
		{
			pGInfo->PointsList[0].x = x[1] + gateWidth;
			pGInfo->PointsList[0].y = y[1] + gateHeight / 2;
			pGInfo->PointsList[1].x = x[0];
			pGInfo->PointsList[1].y = y[0] + gateHeight / 2;
			Connection *pA = new Connection(pGInfo, opin, ipin);
			selectedCount = 0;
			delete x;
			delete y;
			pA->setCompType("Connection");
			pA->setLabel("Connection");
			pManager->AddComponent(pA);
		}
		else
		{
			pUI->PrintMsg("Error: Cannot Draw 2 gates at the same vertical position!");
		}
	}
	else
	{
		pUI->PrintMsg("Error: Select only 2 components!");
	}*/
}

void AddConnection::Undo()
{
	//Add your code
}

void AddConnection::Redo()
{
	//Add your code
}

