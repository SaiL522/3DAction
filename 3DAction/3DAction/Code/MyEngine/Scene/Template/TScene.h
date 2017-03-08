#pragma once

#include "..\Interface\IScene.h"

/**
@class
@brief �e���v���[�g�V�[���N���X
@author �L�y�E��
@date 2017/03/08
*/
class TScene :
	public IScene
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
	@author �L�y�E��
	@date 2017/03/08
	*/
	TScene();
	//�J�n
	virtual void start() override;
	//�X�V
	virtual void update(float _deltaTime) override;
	//�`��
	virtual void draw(const Renderer & _renderer) override;
	//�I��
	virtual void end() override;
	//�I���������H
	virtual bool isEnd() override;
	//���̃V�[��
	virtual SceneID next() override;
private:
	bool m_isEnd;
};