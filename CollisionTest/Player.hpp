#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Actor.hpp"
#include "Collision.hpp"

class Entry;

class Player : public Actor 
{
public:

	Player(Entry *e);	//�R���X�g���N�^
	~Player();			//�f�X�g���N�^

	void Update();		//�X�V
	void Draw();		//�`��

	BoxCollision mCol;
private:
	glm::ivec2 mSize;
	glm::ivec2 Max;



};

#endif
