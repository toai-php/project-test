#pragma once
#include "Object.h"
#include "define.h"

class Bullet :
	public Object
{
private:
	int m_NumberOfBullet;
	int m_isChange;
	float m_AttackDame;
	float m_AttackSpeed;
	float m_SpeedOfBulletX;
	float m_SpeedOfBulletY;
	float m_MaxOfLength;
	float m_CurrentLength;
	b2Body* m_target;
public:
	Bullet(int ID) : Object(ID) {}

	void InitA(float attackDame, float attackSpeed, float speedOfBulletX, float speedOfBulletY, float maxOfLength);
	void ResetBullet();
	void SetCurrLength(float curr);
	void ReverseV();
	void SetTarget(b2Body* target);
	bool IsEmptyBullet();
	bool IsOverLength();
	void SetIsChange();

	bool IsChange();
	float GetAttackDame();
	float GetAttackSpeed();
	float GetCurrLength();
	int GetNumberOfBullet() { return m_NumberOfBullet; }

	Vector2 GetSpeedOfBullet();
	b2Body* GetTarget();
	float GetMaxOfLength();
	void Update(float deltaTime);
	void SetBodyObject(float positionX, float positionY, b2World* world, bool isPlayer = true, bool notBoss = true);
};

