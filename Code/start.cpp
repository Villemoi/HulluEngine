#include "../Headers/engine_functions.h"

Scene LoadScene(){
    Scene sc;
    auto player = std::make_unique<GameObject>();
    player->id = 1;
    player->name = "Player";
    player->position = { 100, 100, 0 }; // Added 0 for the 'z' you added earlier
    player->size = { 64, 64 };

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

    sc.gameObjects.push_back(std::move(player));
    return sc;
}