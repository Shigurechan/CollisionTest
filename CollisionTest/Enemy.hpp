#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Actor.hpp"
#include "Collision.hpp"

class Actor;
class Entry;


class Enemy : public Actor
{
public:

	Enemy(Entry* e);	//�R���X�g���N�^
	~Enemy();			//�f�X�g���N�^

	void Update();		//�X�V
	void Draw();		//�`��

	BoxCollision mCol;
//	CircleCollision mCol;
private:
	glm::vec2 mSize;
	int r;
	glm::vec2 Max;
	glm::vec2 colPos;



};

#endif
