#include "../Headers/engine_functions.h"
#include "../Headers/SpriteAnimation.h"

Scene LoadScene(){
    //Create Scene
    Scene sc;

    //Create "slime prefab"
    auto slimePrefab = std::make_unique<GameObject>();
    slimePrefab->name = "Slime";
    slimePrefab->size = { 64, 64 };

    //Add a texture to the Player Game Object
    SDL_Surface* surfaceForSlime = SDL_LoadBMP("Assets/smile.bmp");
    if (surfaceForSlime) {
        SDL_Surface* formattedSurface = SDL_ConvertSurface(surfaceForSlime, SDL_PIXELFORMAT_RGBA32);
        
        unsigned int id;
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
    
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, formattedSurface->w, formattedSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, formattedSurface->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);
    
        slimePrefab->textureID = id;
        SDL_DestroySurface(formattedSurface);
        SDL_DestroySurface(surfaceForSlime);
    } else {
        SDL_Log("BMP Load Failed: %s", SDL_GetError());
    }

    //Setup slime animations
    slimePrefab->totalFramesInSheet = 4;
    slimePrefab->animator = std::make_unique<AnimationController>();
    SpriteAnimation bounce = { "Bounce", 0, 4, 0.1f, true };
    slimePrefab->animator->addClip(bounce);

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

    //Add slime prefab to the scene (this is a temporary solution until we remake the file structure for the game)
    sc.prefabs->addPrefab("Slime", std::move(slimePrefab));

    return sc;
}