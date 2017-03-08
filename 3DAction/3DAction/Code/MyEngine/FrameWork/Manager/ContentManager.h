#pragma once

#include <gslib.h>
#include <string>

/**
@class
@brief コンテンツ管理者
@author 有冨勇帆
@date 2017/02/06
*/
class ContentManager
{
public:
	/**
	@fn
	@brief コンストラクタ
	*/
	ContentManager();
	/**
	@fn
	@brief デストラクタ
	*/
	~ContentManager() = default;
	/**
	@fn
	@brief コンテンツまでのルートを指定
	@param[_path] コンテンツが格納されているフォルダを指定
	*/
	void contentRoot(const std::string _path);
	/**
	@fn
	@brief テクスチャの読み込み
	@param[_id] 登録するID
	@param[_path] 登録する画像
	*/
	void loadTexture(const GSuint _id, const std::string _path);
	/**
	@fn
	@brief コンテンツの解放*/
	void unloadContent();
private:
	//コピー禁止
	ContentManager(const ContentManager& _other) = delete;
	void operator=(const ContentManager& _other) = delete;
private:
	std::string m_rootPath;
};