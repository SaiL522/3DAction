#include "TScene.h"

//�R���X�g���N�^
TScene::TScene() :
	m_isEnd(false)
{
}

//�J�n
void TScene::start()
{
}

//�X�V
void TScene::update(float _deltaTime)
{
}

//�`��
void TScene::draw(const Renderer & _renderer)
{
}

//�I��
void TScene::end()
{
}

//�I���������H
bool TScene::isEnd()
{
	return false;
}

//���̃V�[��
SceneID TScene::next()
{
	return SceneID();
}
