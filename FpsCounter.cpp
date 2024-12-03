#include "FpsCounter.h"

FpsCounter::FpsCounter(std::string UID)
	: GameObject(UID)
{
}

void FpsCounter::Start() 
{
    GetComponent<Transform>()->SetLocalPosition(400.0f, 300.0f);
    textRenderer = AddComponent<TextRenderer>();
    
    textRenderer->SetFont(AssetLoader::GetFont("roboto.ttf"));
    (*textRenderer)("SEX");

    Renderer::AddDrawable(textRenderer);
}

void FpsCounter::Update()
{
	(*textRenderer)("FPS: " + std::to_string((int)Time::FPS()));
}
