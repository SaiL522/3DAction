#include "ContentManager.h"
#include <gslib.h>

//コンストラクタ
ContentManager::ContentManager() :
	m_rootPath("")
{
}

//コンテンツまでのルートを指定
void ContentManager::contentRoot(const std::string _path)
{
	m_rootPath = _path;
}

//画像の読み込み
void ContentManager::loadTexture(const GSuint _id, const std::string _path)
{
	std::string path = m_rootPath + _path;
	if (!gsLoadTexture(_id, path.c_str())) {
		path = path + "の読み込みに失敗";
		MessageBox((HWND)_glutGetHWND(), path.c_str(), "テクスチャの読み込みに失敗", MB_OK);
	}
}

//コンテンツの解放
void ContentManager::unloadContent()
{
	gsFinishGraphics();
}
