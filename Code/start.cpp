#include "../Classes/scene.h"

Scene LoadScene(SDL_Renderer* renderer){
    Scene sc;

    // Create a new GameObject
    GameObject player;
    player.id = 1;
    player.name = "Player";
    player.transform = { 100, 100, 64, 64 }; // Positioned at 100,100

    // Load the texture for this specific object
    SDL_Surface* surface = SDL_LoadBMP("./Assets/smile.bmp");
    if (surface) {
        player.texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_DestroySurface(surface);
    }

    // Add the object to the scene
    sc.gameObjects.push_back(player);

    return sc;
}