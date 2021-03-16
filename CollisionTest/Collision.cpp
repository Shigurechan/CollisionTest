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
glm::vec2 Collision::getVector()
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


//���x���擾
glm::vec2 Collision::getSpeed()
{
	return *Speed;
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
void Collision::setVector(glm::vec2 *vec)
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



//���x��ݒ�
void Collision::setSpeed(glm::vec2 *spp)
{
	Speed = spp;
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

//�␳�ʂ��̂𓾂�
glm::vec2 BoxCollision::getFixValue(glm::vec2 player_min, glm::vec2 player_max, glm::vec2 block_min, glm::vec2 block_max)
{
	//X���̕␳��
	float xA = player_max.x - block_min.x;
	float xB = block_max.x - player_min.x;
	float x;
	float y;

	if (xA < xB)
	{
		x = xA;
	}
	else
	{
		x = xB;
	}

	//Y���̕␳��
	float yA = player_max.y - block_min.y;
	float yB = block_max.y - player_min.y;

	if (yA < yB)
	{
		y = yA;
	}
	else
	{
		y = yB;
	}

	glm::vec2 pos;
	pos.x = x;
	pos.y = y;


	return pos;
}
//��������
void BoxCollision::Intersect(BoxCollision& col)
{

//	printf("%f\n",getVector().y);


	if ((col.getMax().x > box.mMin->x && box.mMax->x > col.getMin().x)
		&& (col.getMax().y > box.mMin->y && box.mMax->y > col.getMin().y))
	{
		setCol(true);				//�����蔻���ݒ�
		setColTag(col.getMyTag());	//�^�O���擾
		col.setColTag(getMyTag());	//�^�O��ݒ�

		glm::ivec2 size = getMax() - getMin();	//�T�C�Y

		glm::vec2 fix = getFixValue(getMin(), getMax(), col.getMin(), col.getMax());	//�߂肱�ݗ�
		printf("X: %.2f\n", fix.x);
		printf("y: %.2f\n", fix.y);

		if (getVector().x > 0 && getVector().y == 0)
		{
			glm::vec2 p;
			p.x = col.getMin().x - size.x;
			p.y = getMin().y;

			setMinValue(p);
		}else if (getVector().x < 0 && getVector().y == 0)
		{
			glm::vec2 p;
			p.x = col.getMax().x;
			p.y = getMin().y;

			setMinValue(p);

		}
		else if (getVector().y < 0 && getVector().x == 0)
		{
			glm::vec2 p;
			p.y = col.getMax().y;
			p.x = getMin().x;

			setMinValue(p);
		}
		else if (getVector().y > 0 && getVector().x == 0)
		{
			printf("������\n");
			glm::vec2 p;
			p.y = col.getMin().y - size.y;
			p.x = getMin().x;

			setMinValue(p);
		}	
		else if (getVector().x > 0 && getVector().y < 0)
		{
			
		
			if ((fix.x < fix.y))
			{

				printf("��������\n");
				glm::vec2 p;
				p.x = col.getMin().x - size.x;
				p.y = getMin().y;
				
				setMinValue(p);

			}
			else {
				printf("������������\n");

				glm::vec2 p;
				p.x = getMin().x;
				p.y = col.getMax().y;

				setMinValue(p);

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
glm::vec2 BoxCollision::getMax()
{
	return *box.mMax;
}

//�ŏ��l���擾
glm::vec2 BoxCollision::getMin()
{
	return *box.mMin;
}




// #################################### �ݒ�@�֌W

//�ő�l��ݒ�
void BoxCollision::setMax(glm::vec2 *max)
{
	box.mMax = max;
}

//�ŏ��l��ݒ�
void BoxCollision::setMin(glm::vec2 *min)
{
	box.mMin = min;
}

//�ő�l�̒l��ݒ�
void BoxCollision::setMaxValue(glm::vec2& max)
{
	*box.mMax = max;
}

//�ŏ��l�̒l��ݒ�
void BoxCollision::setMinValue(glm::vec2& min)
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
CircleCollision::CircleCollision()
{

}

//�f�X�g���N�^
CircleCollision::~CircleCollision()
{

}

//��������
void CircleCollision::Intersect(CircleCollision& col)
{
	//printf("������%d\n",col.getRadius());
	//printf("������%d\n",getRadius());

	float c = sqrt((col.getCenter().x - getCenter().x) * (col.getCenter().x - getCenter().x) +
			(col.getCenter().y - getCenter().y) * (col.getCenter().y - getCenter().y));

	//printf("C:%d\n",c);
	if ( c <= (col.getRadius() + getRadius()) )
	{
//		printf("true\n");

		//�^�O�Ɠ����蔻��
		setCol(true);				//�����蔻���ݒ�
		setColTag(col.getMyTag());	//�^�O���擾
		col.setColTag(getMyTag());	//�^�O��ݒ�

		if (getTriggerType() == false)
		{
			float len = sqrt((col.getCenter().x - getCenter().x) * (col.getCenter().x - getCenter().x) +
				(col.getCenter().y - getCenter().y) * (col.getCenter().y - getCenter().y));
			//printf("len %d\n",len);

			float m = (col.getRadius() + getRadius()) - len;	//�߂荞�ݗ�

//			printf("������ %d\n", getRadius());
//			printf("�������� %d\n", col.getRadius());

//			printf("m %f\n",m);
			
			glm::vec2 vec = getVector();
			vec = vec * -1.0f;	//�x�N�g���𔽓]
			printf("vec : %.2f , %.2f \n", vec.x, vec.y);

			vec = glm::normalize(vec);
			vec.x = vec.x * m;
			vec.y = vec.y * m;
//			printf("vec : %.2f , %.2f \n", vec.x, vec.y);


			
			glm::vec2 p = getCenter() += (vec);
			//printf("p : %d , %d \n",p.x,p.y);
			setCenterValue(p);



		}
	}
	else
	{
		//�������Ă��Ȃ�
	//	printf("false\n");

		//�^�O�Ɠ����蔻��
		setCol(false);					//�����蔻���ݒ�
		setColTag(Tag::Invalid);		//�^�O���擾
		col.setColTag(Tag::Invalid);	//�^�O��ݒ�
	}
}


// #################################### �擾�@�֌W

//���a�擾
float CircleCollision::getRadius()
{
	return *sp.mRadius;
}

//�ʒu�擾
glm::vec2 CircleCollision::getCenter()
{
	return *sp.mCenter;
}

/// #################################### �ݒ�@�֌W

//���a�@�ݒ�@�|�C���^
void CircleCollision::setRadius(float *r)
{
	sp.mRadius = r;
}

//�ʒu�@�ݒ�@�|�C���^
void CircleCollision::setCenter(glm::vec2 *pos)
{
	sp.mCenter = pos;
}

//���a �l��ݒ�
void CircleCollision::setRadiusValue(float r)
{
	*sp.mRadius = r;
}

//�ʒu�@�l��ݒ�
void CircleCollision::setCenterValue(glm::vec2 pos)
{
	*sp.mCenter = pos;
}




 