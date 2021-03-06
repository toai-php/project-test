#pragma once
#include "Object.h"
#include "Bullet.h"

class Enemy :
	public Object
{
private:
	float m_HP;
	float m_speedx;
	float m_speedy;
	float m_attackDame;
	float m_left;
	float m_right;
	int m_bulletID;
	Bullet* m_bullet;
	Vector2 transPosBox;
public:
	float m_time;
	int cnt;
	int m_direction;
	Enemy(int ID) : Object(ID) {
		m_direction = 1;
		cnt = 0;
	}
	~Enemy();
	void SetHP(float hp);
	void SetBulletID(int bulletID);
	int GetBulletID();
	float GetHP();
	void SetSpeed(float speedx, float speedy);
	Vector2 GetSpeed();
	bool isDie();
	bool isAttack();

	void UpdateAttack(float deltaTime);
	void Update(float deltaTime);
	void SetLimit(float left, float right);
	void SetBullet(Bullet* bullet);
	void SetBodyObject(b2World* world);
	void UpdateAnimation(float deltaTime);
	void setTransBox(float b1, float b2);
	Vector2 getTransBox() {
		return transPosBox;
	}

	Bullet* GetBullet();
};