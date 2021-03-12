#include "Entry.hpp"

//�R���X�g���N�^
Entry::Entry()
{
	//printf("SCRREN_WIDTH : %d\n", SCREEN_WIDTH);
	//printf("SCRREN_HEIGHT : %d\n",SCREEN_HEIGHT);

	InputKey = std::make_shared<Input>();
	game = std::make_shared<Game_Scene>(Scene_Type::Game,this);
	type = Scene_Type::Game;
}


int Entry::GetRand(int start,int end) {
	std::random_device rnd;								// �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());								//  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
	std::uniform_int_distribution<> Rand(start,end);    // [start,end] �͈͂̈�l����

	return Rand(mt);
}

//�X�v���C�g�����[�h
int Entry::LoadSprite(const char* FileName)
{
	int a = LoadGraph(FileName);

	if (a == -1)
	{
		printf("�t�@�C�������݂��܂���B%s \n",FileName);
		return -1;
	}
	else {
		return a;
	}
}





//�v�Z
void Entry::Update()
{

	InputKey->Update();
	switch (type)
	{
		//���C���Q�[��
	case Scene_Type::Game:
	{
		game->Update();
		type = game->getSceneType();
	}
	};
}

//�`��
void Entry::Draw()
{
	switch (type)
	{
		//���C���Q�[��
	case Scene_Type::Game:
		{
			game->Draw();
			type = game->getSceneType();
		}




	};
}

//�f�X�g���N�^
Entry::~Entry()
{
	
}

