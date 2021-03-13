#ifndef ___COLLISION_HPP_
#define ___COLLISION_HPP_

#include "glm/glm.hpp"

//タグ
typedef enum class Tag
{
	Player,
	Enemy,
	Wall,
	Item,
	None,		//未設定


	Invalid,	//交差してない
}Tag;


//プリミティブ型

typedef struct LineSegment
{
	glm::ivec2 mStart;
	glm::ivec2 mEnd;


}LineSegment;

typedef struct AABB
{
	glm::ivec2 *mMax;
	glm::ivec2 *mMin;

}AABB;

typedef struct Sphere
{
	glm::ivec2 *mCenter;	
	int *mRadius;		
}Sphere;

/*####################################################
* 当たり判定の基底クラス
######################################################*/

/*当たり判定の基底クラス
* 
* 機能一覧
* トリガータイプ
* タグ
* 当たったかどうか？
* 
* 
*/
class Collision
{
public:
	Collision();	//コンストラクタ
	~Collision();	//デストラクタ
	
	//機能
	
	

	//設定　関係
	void setCol(bool b);				//当たったかどうか？
	void setColTag(Tag type);			//取得したタイプ設定
	void setVector(glm::ivec2* vec);	//方向設定
	void setTriggerType(bool tri);			//トリガータイプを設定
	void setTag(Tag type);				//タグを設定

	//取得　関係
	Tag getMyTag();				//タイプを取得
	bool getTriggerType();			//トリガータイプを取得
	glm::ivec2 getVector();		//方向を取得
	bool getCol();				//当たったかどうか？
	Tag getTag();				//取得したタイプを取得


private:
	bool IsTrigger;		//トリガータイプかどうか？
	Tag my_TagType;		//自身タグ
	Tag col_TagType;	//取得タグ
	glm::ivec2 *Vector;	//方向
	bool isCol;			//当たったかどうか？
};


/*####################################################
* 矩形の当たり判定
######################################################*/

class BoxCollision : public Collision
{
public:
	BoxCollision();		//コンストラクタ
	~BoxCollision();	//デストラクタ

	void Intersect(BoxCollision &col);


	//取得　関係
	glm::ivec2 getMax();
	glm::ivec2 getMin();


	//設定　関係
	void setMax(glm::ivec2 *max);
	void setMin(glm::ivec2 *min);

	void setMaxValue(glm::ivec2 &max);
	void setMinValue(glm::ivec2 &min);

private:
	AABB box;
};





/*####################################################
* 球の当たり判定
######################################################*/

class SphereCollision : public Collision
{
public:
	SphereCollision();		//コンストラクタ
	~SphereCollision();		//デストラクタ

	void Intersect(SphereCollision& col);


	//取得　関係
	int getRadius();		//半径
	glm::ivec2 getCenter();	//位置

	//設定　関係
	void setRadius(int *r);		//半径
	void setCenter(glm::ivec2 *pos);	//位置

private:
	Sphere sp;
};




#endif