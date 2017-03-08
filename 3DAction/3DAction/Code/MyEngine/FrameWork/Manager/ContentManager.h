#pragma once

#include <gslib.h>
#include <string>

/**
@class
@brief �R���e���c�Ǘ���
@author �L�y�E��
@date 2017/02/06
*/
class ContentManager
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
	*/
	ContentManager();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~ContentManager() = default;
	/**
	@fn
	@brief �R���e���c�܂ł̃��[�g���w��
	@param[_path] �R���e���c���i�[����Ă���t�H���_���w��
	*/
	void contentRoot(const std::string _path);
	/**
	@fn
	@brief �e�N�X�`���̓ǂݍ���
	@param[_id] �o�^����ID
	@param[_path] �o�^����摜
	*/
	void loadTexture(const GSuint _id, const std::string _path);
	/**
	@fn
	@brief �R���e���c�̉��*/
	void unloadContent();
private:
	//�R�s�[�֎~
	ContentManager(const ContentManager& _other) = delete;
	void operator=(const ContentManager& _other) = delete;
private:
	std::string m_rootPath;
};