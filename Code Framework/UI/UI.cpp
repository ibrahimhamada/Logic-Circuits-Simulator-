#include "UI.h"
#include "../CMUgraphicsLib/CMUgraphics.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Logic Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}


int UI::getGateWidth() const
{
	return GATE_Width;
}

int UI::getGateHeight() const
{
	return GATE_Height;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	/*xClicked = x;
	yClicked = y;*/

	if (AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Horizontal Toolbar
		if (y >= 0 && y < ToolBarHeight && x >= 0 && x < width)
		{
			//Check whick Menu item was clicked
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_INV1: return ADD_INV;
			//case ITM_BUFF1: return ADD_BUFF1
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_LED: return ADD_LED;
			case ITM_CLOSEDSWITCH: return ADD_Closed_Switch;
			case ITM_OPENSWITCH: return ADD_Open_Switch;
			case ITM_EDIT: return EDIT_Label;
			case ITM_CONNECT: return ADD_CONNECTION;
			case ITM_DELETE: return DEL;
			case ITM_MOVE: return MOVE;
			case ITM_EXIT: return EXIT;


			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}


		//[2] If user clicks on the Left Vertical Toolbar
		if (y > GATE_Height && y < (6 * ToolBarHeight) && x > 0 && x < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			int ClickedItemOrder = (y / ToolBarHeight);
			//Divide y coord of the point clicked by the ToolBar Height (80)  (int division)
			//if division result is 1 ==> first item in the right vertical menu is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case 1: return SAVE;
			case 2: return LOAD;
			case 3: return COPY;
			case 4: return CUT;
			case 5: return PASTE;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
		}
	}

		//[3] If user clicks on the Right Vertical Toolbar

		if (y > ToolBarHeight && y < 6 * ToolBarHeight && x >= width - ToolItemWidth && x < width)
		{
			//Check whick Menu item was clicked
			int ClickedItemOrder = (y / ToolBarHeight);
			//Divide y coord of the point clicked by the ToolBar Height (80)  (int division)
			//if division result is 1 ==> first item in the right vertical menu is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case 1: return CMODULE;
			case 2: return UNDO;
			case 3: return REDO;
			case 4: return SIM_MODE;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
		}
	}

		//[4] User clicks on the drawing area
		if (y > ToolBarHeight && y < height - StatusBarHeight && x > ToolItemWidth && x < width - ToolItemWidth)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}

		//[5] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (x <= 80 && x > 0 && y <= 80 && y > 0)
			return DSN_MODE;
		else
			return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(ToolItemWidth, ToolBarHeight, width-ToolBarHeight, height - StatusBarHeight);
	
	
}

void UI::ClearArea(int x1,int y1,int x2,int y2,string oldlbl) const
{
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(x1, y1, x2, y2,FILLED);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar()
{	
	ClearStatusBar();
	AppMode = DESIGN;	//Design Mode

						//You can draw the tool bar icons in any way you want.

						//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_INV1] = "images\\Menu\\Menu_NOT.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_CLOSEDSWITCH] = "images\\Menu\\Menu_CLOSEDSWITCH.jpg";
	MenuItemImages[ITM_OPENSWITCH] = "images\\Menu\\Menu_OPENSWITCH.jpg";

	MenuItemImages[ITM_EDIT] = "images\\Menu\\Menu_EDIT.jpg";
	MenuItemImages[ITM_CONNECT] = "images\\Menu\\Menu_CONNECT.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\Menu_DELETE.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\Menu_MOVE.jpg";

	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\Menu_PASTE.jpg";
	MenuItemImages[ITM_CMODULE] = "images\\Menu\\Menu_CircuitModule.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_UNDO.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_REDO.jpg";

	MenuItemImages[ITM_SIM] = "images\\Menu\\Menu_SIM11.jpg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++) {
		if (i < 15)
			pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
		else if ((i >= 15) && (i < 20))
			pWind->DrawImage(MenuItemImages[i], 0, (i - 14) * ToolItemWidth, ToolItemWidth, ToolBarHeight);
		else
			pWind->DrawImage(MenuItemImages[i], width - ToolItemWidth, (i - 19)*ToolItemWidth, ToolItemWidth, ToolBarHeight);
	}
	//Draw a line under the toolbar
	pWind->SetPen(RED, 5);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	pWind->DrawLine(ToolBarHeight, ToolBarHeight, ToolBarHeight, height - StatusBarHeight);
	pWind->DrawLine(width - ToolItemWidth, ToolBarHeight, width - ToolItemWidth, height - StatusBarHeight);

	// design area (ToolItemWidth, ToolBarHeight, width- ToolItemWidth, height- StatusBarHeight)

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	ClearStatusBar();
	AppMode = SIMULATION;	//Simulation Mode

	pWind->DrawRectangle(0, 0, 1200, 80);
	pWind->DrawRectangle(0, 0, 80, 650-50);
	pWind->DrawRectangle(1200-80, 80, 1200, 650-50);

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Sim_to_Design.jpg";
	pWind->DrawImage(MenuItemImages[0], 0, 0, 80, 80);
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	pWind->DrawLine(ToolBarHeight, ToolBarHeight, ToolBarHeight, height);

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawAND2(const GraphicsInfo &r_GfxInfo, bool selected,string lbl) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	//ClearArea(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y + GATE_Height, r_GfxInfo.PointsList[0].x + GATE_Width, r_GfxInfo.PointsList[0].y + GATE_Height + 10);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED,ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y+GATE_Height, lbl);
}

void UI::DrawOR2(const GraphicsInfo &r_GfxInfo, bool selected, string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x , r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}

void UI::DrawNAND2(const GraphicsInfo &r_GfxInfo, bool selected,string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}

void UI::DrawNOR2(const GraphicsInfo &r_GfxInfo, bool selected,string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}

void UI::DrawXOR2(const GraphicsInfo &r_GfxInfo, bool selected,string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}


void UI::DrawXNOR2(const GraphicsInfo &r_GfxInfo, bool selected,string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x , r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}

void UI::DrawINV1(const GraphicsInfo &r_GfxInfo, bool selected,string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_INV1_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_INV1.jpg";

	//Draw Inverter at Gfx_Info (1st corner)
	//Set the Image Width & Height by Inverter Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x , r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}

void UI::DrawBUFF1(const GraphicsInfo &r_GfxInfo, bool selected, string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_BUFF1_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_BUFF1.jpg";

	//Draw Buffer at Gfx_Info (1st corner)
	//Set the Image Width & Height by Buffer Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawClosedSwitch(const GraphicsInfo &r_GfxInfo, bool selected, string lbl) const
{
	string GateImage;
	/*if (AppMode == SIMULATION)
	{
		if (selected) //use image in the highlighted case
			GateImage = "Images\\Gates\\Open_SWITCH.jpg";
		else
			GateImage = "Images\\Gates\\Closed_SWITCH.jpg";
	}*/
	if (AppMode == DESIGN)
		if (selected) //use image in the highlighted case
			GateImage = "Images\\Gates\\Closed_SWITCH_Hi.jpg";
		else
			GateImage = "Images\\Gates\\Closed_SWITCH.jpg";
	//Draw Switch at Gfx_Info (1st corner)
	//Set the Image Width & Height by Switch Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x , r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}

void UI::DrawOpenSwitch(const GraphicsInfo &r_GfxInfo, bool selected, string lbl) const
{
	string GateImage;
	if (AppMode == DESIGN)
	{
		if (selected) //use image in the highlighted case
			GateImage = "Images\\Gates\\Open_SWITCH_Hi.jpg";
		else
			GateImage = "Images\\Gates\\Open_SWITCH.jpg";
	}
	/*else 
	{
		if (selected) //use image in the highlighted case
			GateImage = "Images\\Gates\\Closed_SWITCH.jpg";
		else
			GateImage = "Images\\Gates\\Open_SWITCH.jpg";
	}*/
	//Draw Switch at Gfx_Info (1st corner)
	//Set the Image Width & Height by Switch Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x , r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}
void UI::DrawCircuitModule(const GraphicsInfo & r_GfxInfo, bool selected, string lbl) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_CircuitModule_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_CircuitModule.jpg";

	//Draw LED at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}
void UI::DrawLED(const GraphicsInfo &r_GfxInfo, bool selected, string lbl, STATUS stat) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates\\LED_Hi.jpg";
	else if (stat == HIGH)
		GateImage = "Images\\Gates\\LED_HIGH.jpg";
	else if (stat == LOW)
		GateImage = "Images\\Gates\\LED_LOW.jpg";
	else
		GateImage = "Images\\Gates\\LED.jpg";
	//Draw LED at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(10, ITALICIZED, ROMAN);
	pWind->DrawString(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y + GATE_Height, lbl);
}
//TODO: Add similar functions to draw all components


void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected,string lbl) const
{
	if (selected)	//use image in the highlighted case
		pWind->SetPen(GREEN);
	else
		pWind->SetPen(BLACK);
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);

	/*if (r_GfxInfo.PointsList[0].x < r_GfxInfo.PointsList[1].x && r_GfxInfo.PointsList[0].y > r_GfxInfo.PointsList[1].y)
	{
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}
	else if (r_GfxInfo.PointsList[0].x > r_GfxInfo.PointsList[1].x && r_GfxInfo.PointsList[0].y > r_GfxInfo.PointsList[1].y)
	{
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y - 25);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y - 25, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y - 25);
		pWind->DrawLine(r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y - 25, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}
	else if (r_GfxInfo.PointsList[0].x > r_GfxInfo.PointsList[1].x && r_GfxInfo.PointsList[0].y < r_GfxInfo.PointsList[1].y)
	{
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y + 25);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y + 25, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y + 25);
		pWind->DrawLine(r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y + 25, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}
	else if (r_GfxInfo.PointsList[0].x < r_GfxInfo.PointsList[1].x && r_GfxInfo.PointsList[0].y < r_GfxInfo.PointsList[1].y)
	{
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[1].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}*/
	//TODO: Add code to draw connection
}


UI::~UI()
{
	delete pWind;
}