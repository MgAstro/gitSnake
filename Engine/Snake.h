#pragma once

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(int& pattern);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& bdr) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& bdr) const;
	bool OverlappingBody(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr int nSegmentsMax = 1063;	//Board dimensions: 28 x 38 = 1064 --> -1 so goal is able to spawn.
	int pattern = 0;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};