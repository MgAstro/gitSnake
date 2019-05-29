#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);							//Class constructor. In this case the embedded class Graphics is being initialized inside it.
	void DrawCell(const Location& coord, Color c);
	void DrawLimits();
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	static constexpr int cellDim = 20;				//Cells are 20 x 20 pixels.
	static constexpr int width = 38;				//Amount of cells long.
	static constexpr int height = 28;				//Amount of cells tall.
	static constexpr int wallThick = 8;			//Wall thickness in pixels.
	static constexpr int pathing = 1;				//1 pixel thick.
	Location loc;
	Color wallColor;
	Graphics& gfx;									//So we don't have to pass that on every member function, we create a local copy(Cache).
};