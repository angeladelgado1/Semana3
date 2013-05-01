#include "Player.h"
#include "Enemy.h"

Player::Player(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "player/1.png" );
    this->images[1] = IMG_Load( "player/2.png" );
    this->images[2] = IMG_Load( "player/3.png" );
    this->images[3] = IMG_Load( "player/4.png" );
    this->images[4] = IMG_Load( "assets/jump.png" );
    this->images[5] = IMG_Load( "assets/perder01.png" );
    this->images[6] = IMG_Load( "assets/perder02.png" );
    this->images[7] = IMG_Load( "assets/perder03.png" );
    this->images[8] = IMG_Load( "assets/perder04.png" );
    this->images[9] = IMG_Load( "assets/perder05.png" );

    this->x = 200;
    this->y = 0;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    this->murio = false;
}

Player::~Player()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
    SDL_FreeSurface( images[5] );
    SDL_FreeSurface( images[6] );
    SDL_FreeSurface( images[7] );
    SDL_FreeSurface( images[8] );
    SDL_FreeSurface( images[9] );

}

void Player::logic()
{
    y+=velocity;
    velocity+=acceleration;
    if(y>=500-images[current_frame]->w/2)
    {
        y=500-images[current_frame]->w/2;
        velocity=0;
    }
}

void Player::jump()
{
    current_frame = 4;
    velocity=-30;
}

void Player::perder()
{
    this->current_frame = 5;
}


void Player::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    if (current_frame >= 5)// && current_frame < 10)
        this->current_frame++;
    else if ( (current_frame == 4 && this->velocity<0)
            ||(current_frame == 4 && this->y<372)){
        this->current_frame--;
        //this->velocity++;
    }
    else if(current_frame>=3){
        current_frame=0;
        murio = false;
    }


   current_frame++;
   if (current_frame >=10 && this->x > 60){
        current_frame =3;
        murio = true;
   }


}
