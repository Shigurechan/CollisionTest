#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Actor.hpp"
#include "Collision.hpp"

class Entry;

class Player : public Actor 
{
public:

	Player(Entry *e);	//コンストラクタ
	~Player();			//デストラクタ

	void Update();		//更新
	void Draw();		//描画

//	BoxCollision mCol;
	CircleCollision mCol;
private:
	glm::ivec2 mSize;
	glm::ivec2 colPos;
	int r;


};

#endif
