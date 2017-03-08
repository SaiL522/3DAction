#include "TGameObject.h"

//�R���X�g���N�^
TGameObject::TGameObject() :
	m_tag(GameTag::NONE),
	m_pos(GSvector2(0.f, 0.f)),
	m_r(0.f)
{

}

//�J�n
void TGameObject::start()
{
}

//�X�V
void TGameObject::update(float _deltaTime)
{
}

//�`��
void TGameObject::draw(const Renderer & _renderer)
{
}

//�Փ˔���
void TGameObject::collision(const IGameObject & _other)
{
}

//�I�u�W�F�N�g�̈ʒu
GSvector2 TGameObject::Pos() const
{
	return m_pos;
}

//�I�u�W�F�N�g�̔��a
float TGameObject::R() const
{
	return m_r;
}

GameTag TGameObject::Tag() const
{
	return m_tag;
}
