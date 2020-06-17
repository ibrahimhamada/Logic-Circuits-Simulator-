#include "Select.h"

Select::Select(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/*bool Select::ReadActionParameters()
{
	UI* Out = pManager->GetOutput();
	UI* In = pManager->GetInput();
	

	pIn->GetLastPointClicked(mSt_X, mSt_Y);
	mE_X = mS_X;
	mE_Y = mS_Y;

	
	if (pOut->GetComponentAtPin(mS_X, mS_Y) == NULL) {
		int x = mSt_X, wan_X = x;
		int y = mStartY, wan_Y = y;

		int minX = 0;
		int maxX = UI.Width;
		int minY = UI.ToolBarHeight + UI.GateBarHeight;
		int maxY = UI.Height - UI.StatusBarHeight;

		image wind;
		pOut->StoreImage(wind, minX, minY, maxX, maxY - minY);

		while (pIn->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN) {
			if (x < minX || x > maxX) x = wan_X;
			if (y < minY || y > maxY) y = wan_Y;

			if (x != prvX || y != prvY) {
				pOut->DrawImage(wind, minX, minY, maxX, maxY - minY);
				pOut->DrawSelectionRectangle(mS_X, mS_Y, x, y);
				wan_X = x;
				wan_Y = y;
			}

			pOut->UpdateScreen();
		}

		if (x < minX || x > maxX) x = prvX;
		if (y < minY || y > maxY) y = prvY;

		mEndX = x, mEndY = y;

		if (mStartX > mEndX) swap(mStartX, mEndX);
		if (mStartY > mEndY) swap(mStartY, mEndY);

		pOut->DrawImage(wind, minX, minY, maxX, maxY - minY);
		pOut->UpdateScreen();
	}

	for (int x = mStartX; x <= mEndX; x += UI.PinOffset) {
		for (int y = mStartY; y <= mEndY; y += UI.PinOffset) {
			Component* pComp = pOut->GetComponentAtPin(x, y);

			if (pComp != NULL) {
				mSelectedComps.insert(pComp);
			}
		}
	}

	return true;
}*/

void Select::Execute() {

	UI* pUI = pManager->GetUI();
	int x /*= pUI->xClicked*/, y /*= pUI -> yClicked*/, selCompPointX, selCompPointY,x2,y2;
	double m;
	pUI->GetPointClicked(x,y);
	Component *selComp;
	for (int i = 0; i < pManager->getcompcount(); i++)
	{
		selComp = pManager->getcomplist(i);
		selCompPointX = selComp->getCompGraphInfo()->PointsList[0].x;
		selCompPointY = selComp->getCompGraphInfo()->PointsList[0].y;
		if (selComp->getCompType() == "Connection")
		{
			x2 = selComp->getCompGraphInfo()->PointsList[1].x;
			y2 = selComp->getCompGraphInfo()->PointsList[1].y;
			m = (double)(y2 - selCompPointY) / (double)(x2 - selCompPointX);
			if ((x >= selCompPointX && x <= x2) && ((y >= selCompPointY && y <= y2) || (y <= selCompPointY && y >= y2)) && ((y - (int)((double)m*x + (y2 - (double)m*x2))) >= -5 && (y - (int)((double)m*x + (y2 - (double)m*x2)) <= 5)))
				if (selComp->selected == false)
					selComp->selected = true;
				else
					selComp->selected = false;
		}
		else
			if ((x >= selCompPointX && x <= selCompPointX + pUI->getGateWidth()) && (y >= selCompPointY && y <= selCompPointY + pUI->getGateHeight()))
				if (selComp->selected == false)
					selComp->selected = true;
				else
					selComp->selected = false;
	}

	/*int selectedCount = pManager->CountSelectedComponents();

	if (selectedCount > 0)
		pOut->PrintMsg(to_string(selectedCount) + " Selected Component(s)");
	else
		pOut->ClearStatusBar();*/

		
}

void Select::Undo() {
	return;
}

void Select::Redo() {
	return;
}

/* Destructor */
Select::~Select() {

}