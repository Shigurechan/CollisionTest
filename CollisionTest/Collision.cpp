#include "Collision.hpp"
#include "Entry.hpp"


/*####################################################
* �����蔻��̊��N���X
######################################################*/

//�R���X�g���N�^
Collision::Collision()
{
	col_TagType = Tag::Invalid;	//�擾�@�^�O
	my_TagType = Tag::Invalid;	//���g�@�^�O

	IsTrigger = false;		//�g���K�[�^�C�v
	isCol = false;			//�����������ǂ����H
	Vector = nullptr;		//����
}

// #################################### �擾�@�֌W

//�g���K�[�^�C�v���擾
bool Collision::getTriggerType()
{
	return IsTrigger;
}

//�擾�����^�C�v���擾
Tag Collision::getTag()
{
	return col_TagType;
}

//�������擾
glm::ivec2 Collision::getVector()
{
	return *Vector;
}

//�^�C�v���擾
Tag Collision::getMyTag()
{
	return my_TagType;
}

//�����������ǂ����H
bool Collision::getCol()
{
	return isCol;
}

// #################################### �ݒ�@�֌W

//�g���K�[�^�C�v��ݒ�
void Collision::setTriggerType(bool tri)
{
	IsTrigger = tri;
}

//�^�O�^�C�v��ݒ�
void Collision::setTag(Tag type)
{	
	my_TagType = type;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Collision::setVector(glm::ivec2 *vec)
{
	Vector = vec;
}

//�����蔻��̃^�O��ݒ�
void Collision::setColTag(Tag type)
{
	col_TagType = type;
}

//�����蔻��̃^�O��ݒ�
void Collision::setCol(bool b)
{
	isCol = b;
}


//�f�X�g���N�^
Collision::~Collision()
{

}


/*##############################################################################################################################################*/

/*####################################################
* ��`�̓����蔻��
######################################################*/

//�R���X�g���N�^
BoxCollision::BoxCollision()
{
	box.mMax = nullptr;	//AABB������
	box.mMin = nullptr;	//AABB������
}



void BoxCollision::Intersect(BoxCollision& col)
{
	if ((col.getMax().x > box.mMin->x && box.mMax->x > col.getMin().x)
		&& (col.getMax().y > box.mMin->y && box.mMax->y > col.getMin().y))
	{
		
		setCol(true);				//�����蔻���ݒ�
		setColTag(col.getMyTag());	//�^�O���擾
		col.setColTag(getMyTag());	//�^�O��ݒ�

		if (getTriggerType() == false)
		{

			//�߂荞�ݗʂ��C��
			if (getVector() == VECTOR_RIGHT)
			{
				glm::ivec2 b = *box.mMax - *box.mMin;
				box.mMin->x = (col.getMin().x - b.x);

			}
			else if (getVector() == VECTOR_LEFT)
			{
			
				box.mMin->x = (col.getMax().x);

			}
			else if (getVector() == VECTOR_UP)
			{
				//printf("������\n");
				glm::ivec2 b = *box.mMax - *box.mMin;
				box.mMin->y = (col.getMin().y + b.y + 1);

			}
			else if (getVector() == VECTOR_DOWN)
			{
				//printf("111\n");

				glm::ivec2 b = *box.mMax - *box.mMin;

				box.mMin->y = (col.getMin().y - b.y);

			}
			else if (getVector() == VECTOR_NONE)
			{
				//�x�N�g�����ݒ肳��Ă��Ȃ��Ƃ�
				
				if (col.getVector() == VECTOR_RIGHT)
				{		
					glm::ivec2 b = col.getMax() - col.getMin();
					glm::ivec2 t = col.getMin();
					t.x = box.mMin->x - b.x;
					col.setMinValue(t);
				}
				else if (col.getVector() == VECTOR_LEFT)
				{	
					glm::ivec2 t = col.getMin();
					t.x = box.mMax->x;
					col.setMinValue(t);
				}
				else if (col.getVector() == VECTOR_UP)
				{
					glm::ivec2 b = col.getMax() - col.getMin();
					glm::ivec2 t = col.getMin();
					t.y = box.mMax->y;
					col.setMinValue(t);

				}
				else if (col.getVector() == VECTOR_DOWN)
				{
					glm::ivec2 b = col.getMax() - col.getMin();
					glm::ivec2 t = col.getMin();
					t.y = box.mMin->y - b.y;
					col.setMinValue(t);

				}	
			}
		}
	}
	else
	{
		//�������Ă��Ȃ�
		
		setCol(false);
		setColTag(Tag::Invalid);
		col.setColTag(Tag::Invalid);
	}
}


// #################################### �擾�@�֌W

//�ő�l���擾
glm::ivec2 BoxCollision::getMax()
{
	return *box.mMax;
}

//�ŏ��l���擾
glm::ivec2 BoxCollision::getMin()
{
	return *box.mMin;
}




// #################################### �ݒ�@�֌W

//�ő�l��ݒ�
void BoxCollision::setMax(glm::ivec2 *max)
{
	box.mMax = max;
}

//�ŏ��l��ݒ�
void BoxCollision::setMin(glm::ivec2 *min)
{
	box.mMin = min;
}

//�ő�l�̒l��ݒ�
void BoxCollision::setMaxValue(glm::ivec2& max)
{
	*box.mMax = max;
}

//�ŏ��l�̒l��ݒ�
void BoxCollision::setMinValue(glm::ivec2& min)
{
	*box.mMin = min;

}



//�f�X�g���N�^
BoxCollision::~BoxCollision()
{

}



/*##############################################################################################################################################*/

/*####################################################
*�@���̓����蔻��
######################################################*/


//�R���X�g���N�^
SphereCollision::SphereCollision() 
{

}

//�f�X�g���N�^
SphereCollision::~SphereCollision()
{

}

//��������
void SphereCollision::Intersect(SphereCollision& col)
{
	if ( false )
	{

		setCol(true);				//�����蔻���ݒ�
		setColTag(col.getMyTag());	//�^�O���擾
		col.setColTag(getMyTag());	//�^�O��ݒ�

		if (getTriggerType() == false)
		{

		}
	}
	else
	{
		//�������Ă��Ȃ�

		setCol(false);
		setColTag(Tag::Invalid);
		col.setColTag(Tag::Invalid);
	}
}


// #################################### �擾�@�֌W

//���a�擾
int SphereCollision::getRadius()
{
	return *sp.mRadius;
}

//�ʒu�擾
glm::ivec2 SphereCollision::getCenter()
{
	return *sp.mCenter;
}

/// #################################### �ݒ�@�֌W

//���a�@�ݒ�@�|�C���^
void SphereCollision::setRadius(int *r)
{
	sp.mRadius = r;
}

//�ʒu�@�ݒ�@�|�C���^
void SphereCollision::setCenter(glm::ivec2 *pos)
{
	sp.mCenter = pos;
}


