#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_INV,			//Add 1-input Inverter gate
	//ADD_BUFF,
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_LED,			//Add LED
	ADD_Closed_Switch,	//Add Closed Switch
	ADD_Open_Switch,	//Add Open Switch

	EDIT_Label,			//Edit Label of a Component, a Connection
	ADD_CONNECTION,		//Add Wire Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection
	EXIT,		//Exit the application

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file
	COPY,
	CUT,
	PASTE,
	CMODULE,
	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

				//ADD_Label,			//Add Label to a Component, a Connection

				//Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT		//Select a Component, a Connection
};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	NCON	//not connected
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,	//Default fan out of 2-input AND gate
	OR2_FANOUT = 5,
	NAND2_FANOUT = 5,
	NOR2_FANOUT = 5,
	XOR2_FANOUT = 5,
	XNOR2_FANOUT = 5,
	INV1_FANOUT = 5,
	BUFF1_FANOUT = 5,
	LED_FANOUT = 5,
	SWITCH_FANOUT =5
};


#ifndef NULL
#define NULL 0
#endif

#endif