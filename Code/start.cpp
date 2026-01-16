#include "../Headers/engine_functions.h"
#include "../Headers/SpriteAnimation.h"

Scene LoadScene(){
    //Create Scene
    Scene sc;

    //Create Player Game Object
    auto player = std::make_unique<GameObject>();
    player->id = 1;
    player->name = "Player";
    player->position = { 100, 100, 0 };
    player->size = { 64, 64 };

    player->totalFramesInSheet = 4;

    player->animator = std::make_unique<AnimationController>();

    SpriteAnimation idle = { "Idle", 0, 1, 0.5f, true };
    SpriteAnimation walk = { "Walk", 0, 4, 0.15f, true };

    player->animator->addClip(idle);
    player->animator->addClip(walk);
    
    player->animator->play("Idle");

    //Add a texture to the Player Game Object
    SDL_Surface* surface = SDL_LoadBMP("Assets/smile.bmp");
    if (surface) {
        SDL_Surface* formattedSurface = SDL_ConvertSurface(surface, SDL_PIXELFORMAT_RGBA32);
        
        unsigned int id;
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
    
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, formattedSurface->w, formattedSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, formattedSurface->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);
    
        player->textureID = id;
        SDL_DestroySurface(formattedSurface);
        SDL_DestroySurface(surface);
    } else {
        SDL_Log("BMP Load Failed: %s", SDL_GetError());
    }

    //Add the Player Game Object to the Scene
    sc.gameObjects.push_back(std::move(player)); 
    return sc;
}