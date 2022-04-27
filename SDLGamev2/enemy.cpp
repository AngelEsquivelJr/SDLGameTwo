#include "enemy.h"

Enemy::Enemy(SDL_Renderer* renderer) {

	SDL_Surface* surface = IMG_Load("./Assets/Enemy.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	int w, h;

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	posRect.w = w;

	posRect.h = h;

	Reset();

	xDir = -1;
	yDir = 0;

}

void Enemy::Reset()
{
	speed = rand() % (5) + 1;
	speed *= 100;

	posRect.y = rand() % (768 - posRect.h) + 1;

	posRect.x = 1024 - posRect.w;

	pos_x = posRect.x;
	pos_y = posRect.y;

}

void Enemy::Update(float deltatTime)
{
	pos_x += (speed * xDir) * deltatTime;

	posRect.x = (int)(pos_x + 0.5f);

	if (posRect.x < 0)
	{
		Reset();
	}

}

void Enemy::Draw(SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer, texture, NULL, &posRect);

}

Enemy::~Enemy()
{
	//SDL_DestroyTexture(texture);
}