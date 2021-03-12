#ifndef ___GAME_SCENE_HPP_
#define ___GAME_SCENE_HPP_

#include "Scene_base.hpp"

#include <iostream>
#include <vector>


//前方宣言
class Player;
class Enemy;
class Entry;

enum class Scene_Type;

/*####################################################
* メインゲーム　シーン
*
* 説明
* メインのゲーム画面
######################################################*/
class Game_Scene : public Scene_base
{
public:
	Game_Scene(Scene_Type t,Entry* e);	//コンストラクタ
	~Game_Scene();						//デストラクタ

	void Update();	//更新
	void Draw();	//描画

	//オブジェクト　関係
	std::shared_ptr<Player> player;
	std::shared_ptr<Enemy> enemy;




private:

	
	






	bool flag;	//ショップかどうかのフラグ
	Entry* Owner;	//Entry クラス

};

#endif
