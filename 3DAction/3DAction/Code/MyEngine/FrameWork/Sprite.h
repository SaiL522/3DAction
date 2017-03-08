#pragma once

#include <gslib.h>

/**
@class
@brief スプライトクラス
@author 有冨勇帆
@date 2017/02/07
*/
class Sprite
{
public:
	Sprite();
	~Sprite();
	void DrawSprite2D(
		GSuint _id,
		const GSvector2& _position,
		const GSrect& _rect,
		const GSvector2& _center = GSvector2(0.f, 0.f),
		const GSvector2& _scale = GSvector2(1.f, 1.f),
		const GSfloat _rotation = 0.f,
		const GScolor& _color = GScolor(1.f, 1.f, 1.f, 1.f)
	);
};
