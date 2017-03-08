#include "ContentManager.h"
#include <gslib.h>

//�R���X�g���N�^
ContentManager::ContentManager() :
	m_rootPath("")
{
}

//�R���e���c�܂ł̃��[�g���w��
void ContentManager::contentRoot(const std::string _path)
{
	m_rootPath = _path;
}

//�摜�̓ǂݍ���
void ContentManager::loadTexture(const GSuint _id, const std::string _path)
{
	std::string path = m_rootPath + _path;
	if (!gsLoadTexture(_id, path.c_str())) {
		path = path + "�̓ǂݍ��݂Ɏ��s";
		MessageBox((HWND)_glutGetHWND(), path.c_str(), "�e�N�X�`���̓ǂݍ��݂Ɏ��s", MB_OK);
	}
}

//�R���e���c�̉��
void ContentManager::unloadContent()
{
	gsFinishGraphics();
}
