#include "bullet.h"

Bullet::Bullet(SDL_Renderer* renderer, float x, float y) {

	active = false;

	speed = 800.0;

	SDL_Surface* surface = IMG_Load("./Assets/bullet.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == NULL)
	{
		printf("Unable to load Image %s! SDL_image Error: %s\n",
			"./Assets/bullet.png", IMG_GetError());
	}

	SDL_FreeSurface(surface);

	int w, h;

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	posRect.w = w;
	posRect.h = h;

	posRect.x = x - (posRect.w / 2);
	posRect.y = y;

	pos_x = x;
	pos_y = y;

	xDir = 1;
	yDir = 0;

}

void Bullet::Reset()
{
	active = false;

	posRect.x = -1000;
	posRect.y = -1000;

	pos_x = posRect.x;
	pos_y = posRect.y;

}

void Bullet::Update(float deltatTime)
{
	if (active) {
		pos_x += (speed * xDir) * deltatTime;

		posRect.x = (int)(pos_x + 0.5f);

		if (posRect.x > (1024 - posRect.w))
		{
			posRect.y = -1000;
			pos_y = posRect.y;
			active = false;
		}
	}

}

void Bullet::Draw(SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer, texture, NULL, &posRect);

}

Bullet::~Bullet()
{
	//SDL_DestroyTexture(texture);
}