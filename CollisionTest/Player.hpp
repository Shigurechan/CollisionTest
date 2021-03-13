#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Actor.hpp"
#include "Collision.hpp"

class Entry;

class Player : public Actor , public Box_Collision
{
public:

	Player(Entry *e);	//�R���X�g���N�^
	~Player();			//�f�X�g���N�^

	void Update();		//�X�V
	void Draw();		//�`��

	//Box_Collision mCol;
private:
	glm::ivec2 mSize;




};

#endif
