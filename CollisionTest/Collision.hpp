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

//線
typedef struct LineSegment
{
	glm::vec2 mStart;	
	glm::vec2 mEnd;		


}LineSegment;

//AABB
typedef struct AABB
{
	glm::vec2* mMin;	//最小値
	glm::vec2* mMax;	//最大値

}AABB;

//円
typedef struct Circle
{
	glm::vec2* mCenter;	//中心点
	float* mRadius;		//半径
}Circle;

//線分
typedef struct Segment {
	glm::vec2* mStart;	//始点
	glm::vec2* mEnd;	//終点
}Segment;



/*####################################################
* 当たり判定の基底クラス
######################################################*/
class Collision
{
public:
	Collision();	//コンストラクタ
	~Collision();	//デストラクタ
	
	//機能
	
	

	//設定　関係
	void setCol(bool b);				//当たったかどうか？
	void setColTag(Tag type);			//取得したタイプ設定
	void setVector(glm::vec2* vec);		//方向設定
	void setTriggerType(bool tri);		//トリガータイプを設定
	void setTag(Tag type);				//タグを設定
	void setSpeed(glm::vec2 *spp);		//速度を設定

	//取得　関係
	Tag getMyTag();				//タイプを取得
	bool getTriggerType();		//トリガータイプを取得
	glm::vec2 getVector();		//方向を取得
	bool getCol();				//当たったかどうか？
	Tag getTag();				//取得したタイプを取得
	glm::vec2 getSpeed();		//速度を取得

private:
	bool IsTrigger;		//トリガータイプかどうか？
	Tag my_TagType;		//自身タグ
	Tag col_TagType;	//取得タグ
	glm::vec2 *Vector;	//方向
	bool isCol;			//当たったかどうか？
	glm::vec2 *Speed;	//速度
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
	glm::vec2 getMax();
	glm::vec2 getMin();


	//設定　関係
	void setMax(glm::vec2 *max);
	void setMin(glm::vec2 *min);

	void setMaxValue(glm::vec2 &max);
	void setMinValue(glm::vec2 &min);

private:
	AABB box;
};





/*####################################################
* 球の当たり判定
######################################################*/

class CircleCollision : public Collision
{
public:
	CircleCollision();		//コンストラクタ
	~CircleCollision();		//デストラクタ

	void Intersect(CircleCollision& col);


	//取得　関係
	float getRadius();		//半径
	glm::vec2 getCenter();	//位置

	//設定　関係
	void setRadius(float *r);		//半径
	void setCenter(glm::vec2 *pos);	//位置

	void setRadiusValue(float r);		//半径
	void setCenterValue(glm::vec2 pos);	//位置


private:
	Circle sp;
};




/*####################################################
* 線分の当たり判定
######################################################*/


/*めりこみ修正不可
*/
class SegmentCollision : public Collision
{
public:
	SegmentCollision();		//コンストラクタ
	~SegmentCollision();	//デストラクタ

	void Intersect(SegmentCollision& col);	//交差判定


	
	//取得　関係
	glm::vec2 getStart();	//始点
	glm::vec2 getEnd();		//終点


	//設定　関係
	void setStart(glm::vec2 *pos);	//始点
	void setEnd(glm::vec2 *pos);	//終点





private:
	bool SegmentCol(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec2 d);		//線分と線分の当たり判定
	glm::ivec2 InterPos(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec2 d);	//交点座標
	Segment seg;
};



#endif