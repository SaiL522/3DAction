#pragma once

#include "..\ID\SceneID.h"

class Renderer;

/**
@class
@brief �V�[���}�l�[�W���[
@author �L�y�E��
@date 2017/01/29
*/
class IScene
{
public:
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	virtual ~IScene() = default;
	/**
	@fn
	@brief �J�n
	*/
	virtual void start() = 0;
	/**
	@fn
	@brief �X�V
	@param _deltaTime
	*/
	virtual void update(float _deltaTime) = 0;
	/**
	@fn
	@brief �`��
	*/
	virtual void draw(const Renderer& _renderer) = 0;
	/**
	@fn
	@brief �I��
	*/
	virtual void end() = 0;
	/**
	@fn
	@brief �I���������H
	@return �I���������H
	*/
	virtual bool isEnd() = 0;
	/**
	@fn
	@brief ���̃V�[��
	*/
	virtual SceneID next() = 0;
};