#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx),
	loc({1, 1}),
	wallColor({127, 0, 127})
{}

void Board::DrawCell(const Location& coord, Color c)
{
	gfx.DrawRectDim(cellDim * (loc.x + coord.x) + pathing, cellDim * (loc.y + coord.y) + pathing, cellDim - 2 * pathing, cellDim - 2 * pathing, c);
}

void Board::DrawLimits()
{
	gfx.DrawRectDim(cellDim * loc.x - wallThick - pathing, cellDim * loc.y - wallThick - pathing, wallThick, 2 * (wallThick + pathing) + cellDim * height, wallColor);
	gfx.DrawRectDim(cellDim * loc.x - wallThick - pathing, cellDim * loc.y - wallThick - pathing, 2 * (wallThick + pathing) + cellDim * width, wallThick, wallColor);
	gfx.DrawRectDim(cellDim * loc.x - wallThick - pathing, cellDim * (loc.y + height) + pathing, 2 * (wallThick + pathing) + cellDim * width, wallThick, wallColor);
	gfx.DrawRectDim(cellDim * (loc.x + width) + pathing, cellDim * loc.y - wallThick - pathing, wallThick, 2 * (wallThick + pathing) + cellDim * height, wallColor);
}

int Board::GetBoardWidth() const
{
	return width;
}

int Board::GetBoardHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}
