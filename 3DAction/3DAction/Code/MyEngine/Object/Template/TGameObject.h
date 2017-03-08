#pragma once

#include "..\Interface\IGameObject.h"

/**
@class
@brief �e���v���[�g�Q�[���I�u�W�F�N�g�N���X
@author �L�y�E��
@date 2017/03/07
*/
class TGameObject :
	public IGameObject
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
	*/
	TGameObject();
	//�J�n
	virtual void start() override;
	//�X�V
	virtual void update(float _deltaTime) override;
	//�`��
	virtual void draw(const Renderer & _renderer) override;
	//�Փ˔���
	virtual void collision(const IGameObject & _other) override;
	//�I�u�W�F�N�g�̈ʒu
	virtual GSvector2 Pos() const override;
	//�I�u�W�F�N�g�̔��a
	virtual float R() const override;
	// IGameObject ����Čp������܂���
	virtual GameTag Tag() const override;
protected:
	GameTag m_tag; //�I�u�W�F�N�g�̃^�O
	GSvector2 m_pos; //�I�u�W�F�N�g�̈ʒu
	float m_r; //�I�u�W�F�N�g�̔��a
};