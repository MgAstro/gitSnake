#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l( segments[0].GetLocation() );
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody(pattern);
		++nSegments;
	}
}

void Snake::Draw(Board& bdr) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(bdr);
	}
}

bool Snake::OverlappingBody(const Location& target) const
{
	for (int i = 0; i < nSegments; ++i)			//-->	//i starts at 0 although it wouldn't be needed cuz next head position
	{													//will never be the same as the one before.
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	//Same as if we did:
	//loc.x = in_loc.x;
	//loc.y = in_loc.y;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(int& pattern)
{
	const unsigned char val = 100 + 25 * pattern;
	c = {0, val, 0};
	pattern = ++pattern % 5;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	//loc.x += delta_loc.x;
	//loc.y += delta_loc.y;
	//That's an option but we can also create an Add function for the Location struct:
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& bdr) const
{
	bdr.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}