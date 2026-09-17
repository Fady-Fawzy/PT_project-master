#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLACK;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);

	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_START] = "images\\Start.jpg";
	MenuItemImages[ITM_END] = "images\\End.jpg";
	MenuItemImages[ITM_DECLARE] = "images\\Declare.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Val.jpg";
	MenuItemImages[ITM_VAR_ASSIGN] = "images\\Var.jpg";
	MenuItemImages[ITM_OP_ASSIGN] = "images\\Op.jpg";
	MenuItemImages[ITM_COND] = "images\\Condition.jpg";
	MenuItemImages[ITM_READ] = "images\\Read.jpg";
	MenuItemImages[ITM_WRITE] = "images\\Write.jpg";
	MenuItemImages[ITM_CONNECT] = "images\\Connect.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Select.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Edit.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Load.jpg";
	MenuItemImages[ITM_SIM] = "images\\Mode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	string MenuItemImages[SIM_ITM_CNT];
	MenuItemImages[ITM_VALIDATE] = "images\\validate.jpg";
	MenuItemImages[ITM_RUN] = "images\\Run.jpg";
	MenuItemImages[ITM_DSN] = "images\\Mode.jpg";
	MenuItemImages[ITM_EXIT_SIM] = "images\\Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/25, Left.y + height/4, Text);
}

//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawDeclareStat(.....), DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
void Output::DrawDeclareStat(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 25, Left.y + height / 4, Text);
}
void Output::DrawParallelogram(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	int x[4] = { Left.x, Left.x + width, Left.x - 40 + width, Left.x - 40};
	int y[4] = { Left.y, Left.y, Left.y + height, Left.y + height };
	pWind->DrawPolygon(x, y, 4);
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}
void Output::DrawStart(Point Center, int width, int height, bool Selected)
{
	if (Selected)  // Highlight if selected
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	// Draw filled ellipse using your DrawEllipse function
	pWind->DrawEllipse(Center.x - width / 2, Center.y - height / 2,
		Center.x + width / 2, Center.y + height / 2, FILLED);

	// Draw the text roughly centered
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - width / 8, Center.y - height / 4, "Start");
}
void Output::DrawEnd(Point Center, int width, int height, bool Selected)
{
	// Set pen color and thickness
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);  // highlight if selected
	else
		pWind->SetPen(UI.DrawColor, 3);        // normal end statement color

	// Draw filled ellipse using your window::DrawEllipse function
	pWind->DrawEllipse(Center.x - width / 2, Center.y - height / 2,
		Center.x + width / 2, Center.y + height / 2, FILLED);

	// Draw the text roughly centered
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - width / 8, Center.y - height / 4, "End");
}

void Output::DrawConditionalStat(Point Left, int width, int height, string Text, bool Selected)
{
	// Set pen color and thickness
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);  // highlight if selected
	else
		pWind->SetPen(UI.DrawColor, 3);        // normal end statement color
	int x[4] = { Left.x + width / 2, Left.x + width, Left.x + width / 2, Left.x };
	int y[4] = { Left.y, Left.y + height / 2, Left.y + height, Left.y + height / 2 };
	pWind->DrawPolygon(x, y, 4);
	// Draw the text roughly centered
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2, Left.y + height / 2, Text);
}

	
//TODO: Add DrawConnector function
void Output::DrawConnector(Point Start, Point End, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color
	int s = 8;
	if (Start.y == End.y && Start.x < End.x) //right arrow
	{
		pWind->DrawLine(Start.x, Start.y, End.x, End.y, FRAME);
		pWind->DrawLine(End.x, End.y, End.x - s, End.y - s, FRAME);
		pWind->DrawLine(End.x, End.y, End.x - s, End.y + s, FRAME);
	}
	else if (Start.y == End.y && Start.x > End.x) //left arrow
	{
		pWind->DrawLine(Start.x, Start.y, End.x, End.y, FRAME);
		pWind->DrawLine(End.x, End.y, End.x + s, End.y - s, FRAME);
		pWind->DrawLine(End.x, End.y, End.x + s, End.y + s, FRAME);
	}
	else if (Start.x == End.x && Start.y < End.y) //down arrow
	{
		pWind->DrawLine(Start.x, Start.y, End.x, End.y, FRAME);
		pWind->DrawLine(End.x, End.y, End.x + s, End.y - s, FRAME);
		pWind->DrawLine(End.x, End.y, End.x - s, End.y - s, FRAME);
	}
	else if (Start.x < End.x && Start.y < End.y) //right down arrow
	{
		pWind->DrawLine(Start.x, Start.y, End.x, Start.y, FRAME);
		pWind->DrawLine(End.x, Start.y, End.x, End.y, FRAME);
		pWind->DrawLine(End.x, End.y, End.x + s, End.y - s, FRAME);
		pWind->DrawLine(End.x, End.y, End.x - s, End.y - s, FRAME);
	}
	else if (Start.x > End.x && Start.y < End.y) //left down arrow
	{
		pWind->DrawLine(Start.x, Start.y, End.x, Start.y, FRAME);
		pWind->DrawLine(End.x, Start.y, End.x, End.y, FRAME);
		pWind->DrawLine(End.x, End.y, End.x + s, End.y - s, FRAME);
		pWind->DrawLine(End.x, End.y, End.x - s, End.y - s, FRAME);
	}
	else if (Start.y > End.y) //loop arrow
	{
		pWind->DrawLine(Start.x, Start.y, Start.x - 50, Start.y, FRAME);
		pWind->DrawLine(Start.x - 50, Start.y, Start.x - 50, End.y, FRAME);
		pWind->DrawLine(Start.x - 50, End.y, End.x, End.y, FRAME);
		pWind->DrawLine(End.x, End.y, End.x - s, End.y - s, FRAME);
		pWind->DrawLine(End.x, End.y, End.x - s, End.y + s, FRAME);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
