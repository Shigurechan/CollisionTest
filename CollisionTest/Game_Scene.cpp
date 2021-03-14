#include "Game_Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

//�R���X�g���N�^
Game_Scene::Game_Scene(Scene_Type t,Entry *e) : Scene_base(t,e)
{
	Owner = e;	//Entry �N���X


	//�I�u�W�F�N�g�@�֌W
	player = std::make_shared<Player>(Owner);
	enemy = std::make_shared<Enemy>(Owner);
	
}

//�X�V
void Game_Scene::Update()
{
	player->Update();
	enemy->Update();
	
	player->mCol.Intersect(enemy->mCol);


}

//�`��
void Game_Scene::Draw()
{
	player->Draw();
	enemy->Draw();

}

//�f�X�g���N�^
Game_Scene::~Game_Scene()
{

}
