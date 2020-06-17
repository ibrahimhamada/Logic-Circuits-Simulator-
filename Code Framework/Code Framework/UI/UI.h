#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point
{
	int x,y;
};


//A structure to contain drawing parameters for each component
//Each component stores its drawing points in this struct 
//For example, a Gate can store points of the rectangluar area it occupies
//				The Connection 
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}
Point *getPointList()
	{
		return this->PointsList;
	}

void setGraphicsInfo()
{
}

};


class UI
{
	

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		//If you want to change the menu items order, change the order here
		//TODO: Add more items names here

		ITM_AND2,	   	  //AND gate item in menu
		ITM_OR2,   	      //OR gate item in menu
		ITM_XOR2,		  //XOR gate item in menu
		ITM_INV1,		  //NOT gate item in menu
		//ITM_BUFF1,
		ITM_NAND2,		  //NAND gate item in menu
		ITM_NOR2,		  //NOR gate item in menu
		ITM_XNOR2,		  //XNOR gate item in menu
		ITM_LED,		  //LED item in menu
		ITM_CLOSEDSWITCH, //SWITCH item in menu
		ITM_OPENSWITCH,	  //SWITCH item in menu

		ITM_EDIT,		//EDIT item
		ITM_CONNECT,    //CONNECT item
		ITM_DELETE,		//DELETE item
		ITM_MOVE,		//REDO item
		ITM_EXIT,		//Exit item

		ITM_SAVE,		//SAVE item
		ITM_LOAD,		//LOAD item
		ITM_COPY,		//COPY item
		ITM_CUT,		//CUT item
		ITM_PASTE,		//PASTE item

		ITM_CMODULE,
		ITM_UNDO,		//UNDO item
		ITM_REDO,		//REDO item 

		ITM_SIM,
						//Simulate menu item
		//Bonus
		ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum	
	};
	//////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	/* PHASE 2
	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
	//Note: Items are ordered here as they appear in menu

	//TODO:Add more items names here

	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,	//Truth table menu item


	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

	};

	*/
	////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////



	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1200, height = 650,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 80;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	GATE_Width = 50,		//Gate Image default width
						GATE_Height = 50;		//Gate Image default height

	window *pWind;
	
public:
	//int xClicked, yClicked;
	UI();
	int getGateWidth() const;
	int getGateHeight() const;	
	// Input Functions  ---------------------------
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	
	// Output Functions  ---------------------------

	void ChangeTitle(string Title) const;

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearArea(int, int, int, int,string) const;

		
	// Draws 2-input AND gate
	void DrawAND2(const GraphicsInfo &r_GfxInfo, bool selected = false,string lbl = "AND GATE") const;
	void DrawOR2(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "OR GATE") const;
	void DrawNAND2(const GraphicsInfo &r_GfxInfo, bool selected = false,string lbl = "NAND GATE") const;
	void DrawNOR2(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "NOR GATE") const;
	void DrawXOR2(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "XOR GATE") const;
	void DrawXNOR2(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "XNOR GATE") const;
	void DrawINV1(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "NOT GATE") const;
	void DrawBUFF1(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "BUFF GATE") const;
	void DrawClosedSwitch(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "CLOSED SWITCH") const;
	void DrawOpenSwitch(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "OPEN SWITCH") const;
	void DrawCircuitModule(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "Module 17") const;
	void DrawLED(const GraphicsInfo &r_GfxInfo, bool selected = false, string lbl = "LED",STATUS stat = NCON) const;
	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	void DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected = false,string lbl = "Connection") const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar

	~UI();
};

#endif