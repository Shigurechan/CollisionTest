#include "Game_Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

//コンストラクタ
Game_Scene::Game_Scene(Scene_Type t,Entry *e) : Scene_base(t,e)
{
	Owner = e;	//Entry クラス


	//オブジェクト　関係
	player = std::make_shared<Player>(Owner);
	enemy = std::make_shared<Enemy>(Owner);
	
}

//更新
void Game_Scene::Update()
{
	player->Update();
	enemy->Update();
	
	//enemy->mCol.Intersect(player->mCol);
	//player->mCol.Intersect(enemy->mCol);

}

//描画
void Game_Scene::Draw()
{
	player->Draw();
	enemy->Draw();

}

//デストラクタ
Game_Scene::~Game_Scene()
{

}
