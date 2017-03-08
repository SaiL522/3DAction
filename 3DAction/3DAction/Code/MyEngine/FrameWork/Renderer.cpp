#include "Renderer.h"
#include "Manager\ContentManager.h"
#include "..\Def\GameDef.h"
#include "Sprite.h"
#include <algorithm>
#include <math.h>

Renderer::Renderer(ContentManager* _content) :
	m_content(_content),
	m_sprite(std::make_unique<Sprite>())
{
	m_content->contentRoot("./res/");
}

void Renderer::loadTexture(GSuint _id, std::string _path)
{
	m_content->loadTexture(_id, _path);
}

void Renderer::unloadContent()
{
	m_content->unloadContent(); 
}

void Renderer::drawSprite2D(
	GSuint _id, 
	const GSvector2 & _position, 
	const GSrect & _rect, 
	const GSvector2 & _center, 
	const GSvector2 & _scale, 
	const GSfloat _rotation, 
	const GScolor & _color
) const
{
	m_sprite->DrawSprite2D(
		_id,
		_position,
		_rect,
		_center,
		_scale,
		_rotation,
		_color
	);
}

void Renderer::drawTexture(
	GSuint _id, 
	const GSvector2 & _position, 
	const GSvector2 & _center, 
	const GSvector2 & _scale, 
	const GSfloat _rotation, 
	const GScolor & _color
) const
{
	gsBindTexture(_id);
	GLsizei s_texWidth;
	GLsizei s_texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &s_texWidth);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &s_texHeight);
	m_sprite->DrawSprite2D(
		_id,
		_position,
		GSrect(0.f, 0.f, s_texWidth, s_texHeight),
		_center,
		_scale,
		_rotation,
		_color
	);
}

void Renderer::drawText(
	const std::string & _text, 
	const GSvector2 & _position, 
	GSuint _fontSize, 
	const GScolor & _color
) const
{
	gsFontParameter(GS_FONT_NORMAL, _fontSize, "ÉÅÉCÉäÉI");
	glColor4f(_color.r, _color.g, _color.b, _color.a);
	gsTextPos(_position.x, _position.y);
	gsDrawText(_text.c_str());
	glColor4f(1.f, 1.f, 1.f, 1.f);
}
