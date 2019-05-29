#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetBoardWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetBoardHeight() - 1);

	Location newLoc;
	while (true)
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
		if ( !snake.OverlappingBody(newLoc) )
		{
			break;
		}
	}

	loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const
{
	return loc;
}