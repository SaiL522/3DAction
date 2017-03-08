#include "TGameObject.h"

//コンストラクタ
TGameObject::TGameObject() :
	m_tag(GameTag::NONE),
	m_pos(GSvector2(0.f, 0.f)),
	m_r(0.f)
{

}

//開始
void TGameObject::start()
{
}

//更新
void TGameObject::update(float _deltaTime)
{
}

//描画
void TGameObject::draw(const Renderer & _renderer)
{
}

//衝突判定
void TGameObject::collision(const IGameObject & _other)
{
}

//オブジェクトの位置
GSvector2 TGameObject::Pos() const
{
	return m_pos;
}

//オブジェクトの半径
float TGameObject::R() const
{
	return m_r;
}

GameTag TGameObject::Tag() const
{
	return m_tag;
}
