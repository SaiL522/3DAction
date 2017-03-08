#pragma once

#include <gslib.h>
#include <string>
#include <memory>

class ContentManager;
class Sprite;

/**
@class
@brief ÉåÉìÉ_ÉâÅ[
@author óLïyóEîø
@date 2017/02/06
*/
class Renderer
{
public:
	Renderer(ContentManager* _content);
	~Renderer() = default;
	void loadTexture(GSuint _id, std::string _path);
	void unloadContent();
	void drawSprite2D(
		GSuint _id,
		const GSvector2& _position,
		const GSrect& _rect,
		const GSvector2& _center = GSvector2(0.f, 0.f),
		const GSvector2& _scale = GSvector2(1.f, 1.f),
		const GSfloat _rotation = 0.f,
		const GScolor& _color = GScolor(1.f, 1.f, 1.f, 1.f)
	) const;
	void drawTexture(
		GSuint _id,
		const GSvector2& _position,
		const GSvector2& _center = GSvector2(0.f, 0.f),
		const GSvector2& _scale = GSvector2(1.f, 1.f),
		const GSfloat _rotation = 0.f,
		const GScolor& _color = GScolor(1.f, 1.f, 1.f, 1.f)
	) const;
	void drawText(
		const std::string& _text,
		const GSvector2& _position,
		GSuint _fontSize = 32,
		const GScolor& _color = GScolor(1.f, 1.f, 1.f, 1.f)
	) const;
private:
	using SpritePtr = std::shared_ptr<Sprite>;
private:
	ContentManager* m_content;
	SpritePtr m_sprite;
};