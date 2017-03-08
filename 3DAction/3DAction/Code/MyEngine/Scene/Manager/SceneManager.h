#pragma once

#include <map>
#include <memory>
#include <string>
#include "..\ID\SceneID.h"

class IScene;
class Renderer;

/**
@class
@brief �V�[���}�l�[�W���[
@author �L�y�E��
@date 2017/01/29
*/
class SceneManager
{
private:
public:
	/**
	@fn
	@brief �R���X�g���N�^
	*/
	SceneManager();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~SceneManager() = default;
	/**
	@fn
	@brief �J�n
	*/
	void start();
	/**
	@fn
	@brief �X�V
	@param[_deltaTime] ���t���[���̎���
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
	@brief �V�[���̒ǉ�
	*/
	void addScene(SceneID _id, std::unique_ptr<IScene>* _scene);
	/**
	@fn
	@brief�V�[����؂�ւ���
	@param[_id] �؂�ւ������V�[���h�c
	*/
	void changeScene(SceneID _id);
private:
	//�V�[���؂�ւ�
	void change();
private:
	//�^���ȗ�
	using ScenePtr = std::unique_ptr<IScene>;
	using SceneContainer = std::map<SceneID, ScenePtr>;
private:
	//�V�[���p�R���e�i
	SceneContainer m_scenes;
	//���݂̃V�[��
	SceneID m_currentScene;
};