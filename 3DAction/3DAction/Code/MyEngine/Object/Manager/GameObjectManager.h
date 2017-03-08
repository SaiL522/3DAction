#pragma once

#include <memory>
#include <list>

class IGameObject;
class Renderer;

/**
@class
@brief �Q�[���I�u�W�F�N�g�}�l�[�W���[
@author �L�y�E��
@date 2017/03/07
*/
class GameObjectManager
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
	*/
	GameObjectManager();
	/**
	@fn
	@brief �J�n
	*/
	void start();
	/**
	@fn
	@brief �X�V
	@param[_deltaTime] �P�t���[�����̎���
	*/
	void update(float _deltaTime);
	/**
	@fn
	@brief �`��
	@param[_renderer] �`��N���X
	*/
	void draw(const Renderer& _renderer);
	/**
	@fn
	@brief �I��
	*/
	void end();
	/**
	@fn
	@brief �I�u�W�F�N�g�̒ǉ�
	@param[_objct] �ǉ�����I�u�W�F�N�g
	*/
	void add(std::unique_ptr<IGameObject>* _object);
private:
	//�Փ˔���
	void collision();
	//�I�u�W�F�N�g��ǉ�
	void addObject();
private:
	//�^���ȗ�
	using Obj_Ptr = std::unique_ptr<IGameObject>;
	using Obj_List = std::list<Obj_Ptr>;
private:
	Obj_List m_objs;
	Obj_List m_newObjs;
};