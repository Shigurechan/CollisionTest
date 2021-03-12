#ifndef ___GAME_SCENE_HPP_
#define ___GAME_SCENE_HPP_

#include "Scene_base.hpp"

#include <iostream>
#include <vector>


//�O���錾
class Player;
class Enemy;
class Entry;

enum class Scene_Type;

/*####################################################
* ���C���Q�[���@�V�[��
*
* ����
* ���C���̃Q�[�����
######################################################*/
class Game_Scene : public Scene_base
{
public:
	Game_Scene(Scene_Type t,Entry* e);	//�R���X�g���N�^
	~Game_Scene();						//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

	//�I�u�W�F�N�g�@�֌W
	std::shared_ptr<Player> player;
	std::shared_ptr<Enemy> enemy;




private:

	
	






	bool flag;	//�V���b�v���ǂ����̃t���O
	Entry* Owner;	//Entry �N���X

};

#endif
