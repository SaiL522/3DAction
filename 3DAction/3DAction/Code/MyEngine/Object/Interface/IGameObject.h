#pragma once

#include <gslib.h>
#include "../ID/GameTag.h"

class Renderer;

/**
@interface
@brief �Q�[���I�u�W�F�N�g�C���^�[�t�F�C�X
@author �L�y�E��
@date 2017/03/07
*/
class IGameObject
{
public:
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	virtual ~IGameObject() = default;
	/**
	@fn
	@brief �J�n
	*/
	virtual void start() = 0;
	/**
	@fn
	@brief �X�V
	*/
	virtual void update(float _deltaTime) = 0;
	/**
	@fn
	@brief �`��
	*/
	virtual void draw(const Renderer& _renderer) = 0;
	/**
	@fn
	@brief �Փ˔���
	*/
	virtual void collision(const IGameObject& _other) = 0;
	/**
	@fn
	@brief �I�u�W�F�N�g�̈ʒu��Ԃ�
	@return �I�u�W�F�N�g�̈ʒu
	*/
	virtual GSvector2 Pos() const = 0;
	/**
	@fn
	@brief �I�u�W�F�N�g�̔��a��Ԃ�
	@return �I�u�W�F�N�g�̔��a
	*/
	virtual float R() const = 0;
	/**
	@fn
	@brief �I�u�W�F�N�g�̃^�O��Ԃ�
	@return �I�u�W�F�N�g�̃^�O
	*/
	virtual GameTag Tag() const = 0;
};