#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
	texture = std::make_unique<sf::Texture>();
	state = std::make_unique<sf::RenderStates>();

	vertices = sf::VertexArray(sf::PrimitiveType::TriangleFan, 4u);
}

void SpriteRenderer::Configure()
{
	Renderer::AddDrawable(owner->GetComponent<SpriteRenderer>());
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	state->transform = transform->GetSF();
	target.draw(vertices, *state);
}

void SpriteRenderer::SetTexture(std::unique_ptr<sf::Texture> tx)
{
	texture = std::move(tx);
	state->texture = texture.get();

	sf::Vector2u dim = texture->getSize();

	vertices[0].position = sf::Vector2f(0.0f, 0.0f);
	vertices[1].position = sf::Vector2f((float)dim.x, 0.0f);
	vertices[2].position = sf::Vector2f((float)dim.x, (float)dim.y);
	vertices[3].position = sf::Vector2f(0.0f, (float)dim.y);

	vertices[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	vertices[1].texCoords = sf::Vector2f((float)dim.x, 0.0f);
	vertices[2].texCoords = sf::Vector2f((float)dim.x, (float)dim.y);
	vertices[3].texCoords = sf::Vector2f(0.0f, (float)dim.y);
}
