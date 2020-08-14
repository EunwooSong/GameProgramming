#pragma once
#include "Sprite.h"
class Particle :
	public Sprite
{
private:
	ParticleType type;
	bool isMove;
	float moveSpeed;
	float targetAngle;
	float fadeSpeed;
	bool isFadeIn;

public:
	Particle(string p, ParticleType type, bool isFadeIn = false);
	Particle(Texture * p, ParticleType type, bool isFadeIn = false);
	~Particle();

	void Update(float dt);
};

