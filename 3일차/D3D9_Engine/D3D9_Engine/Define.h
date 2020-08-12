#pragma once
#include "stdafx.h"
#include <map>
#include <list>
#include <vector>

//Debug Setting
#if defined(DEBUG) | defined(_DEBUG)
#define DEBUG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

using Vec2 = D3DXVECTOR2;

class Rect : public RECT {
public:
	Rect() {
		left = 0;
		right = 0;
		top = 0;
		bottom = 0;
	}

	Rect(int l, int b, int r, int t) {
		left = l;
		right = r;
		top = t;
		bottom = b;
	}

	Rect(Vec2 lb, Vec2 rt) {
		left = lb.x;
		bottom = lb.y;
		right = rt.x;
		top = rt.y;
	}

	bool Intersects(Rect r) {
		Rect intersect;
		return IntersectRect(&intersect, this, &r);
	}

	bool Contain(Vec2 p) {
		return left < p.x&& p.x < right&& top < p.y&& p.y < bottom;
	}

	Rect offset(Vec2 p) {
		Rect r = *this;
		r.left += p.x;
		r.right += p.x;
		r.top += p.y;
		r.bottom += p.y;
	
		return r;
	}
};