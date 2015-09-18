
//
//  EnemyObject.cpp
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#include "EnemyObject.h"
#include "BulletObject.h"

USING_NS_CC;

EnemyObject::EnemyObject()
:m_MaxLife(1)
,m_Life(1)
,m_State(EnemyState::WAIT)
{
    this->setHitLength(64.0f);

}
EnemyObject::~EnemyObject()
{
    
}
EnemyObject* EnemyObject::create(int charaId)
{
    EnemyObject * ret = nullptr;
    ret = new EnemyObject();
    if(ret && ret->init(charaId))
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        delete ret;
        ret = nullptr;
    }
    return ret;
}
bool EnemyObject::init(int charaId)
{
    if(!HitObject::init())
    {
        return false;
    }
    this->m_mainSprite = nullptr;
    switch (charaId) {
        default:
        case 0:
            m_mainSprite = Sprite::create("game/enemy.png");
            break;
    }

    
    this->addChild(this->m_mainSprite);
    this->setContentSize(this->m_mainSprite->getContentSize());
    this->setAnchorPoint(Vec2::ONE * 0.5f);
    
    this->m_mainSprite->setPosition(this->getContentSize()/2.0f);
    return true;
}

/**
 * 行動の更新
 */
void EnemyObject::updateAction(float dt)
{
    //ダメージ反映処理
    if(this->getState() == EnemyState::WAIT)
    {
        for(auto work : this->getHitObjectList() )
        {
            BulletObject * bullet = dynamic_cast<BulletObject*>(work);
            if(bullet)
            {
                this->setLife(this->getLife() - bullet->getAttack());
            }
        }
        //死亡判定
        if(this->getLife() < 0)
        {
            this->setState(EnemyState::DEAD);
        }
    }
    this->getHitObjectList().clear();
    
    
    //死亡アニメーション
    if(this->getState() == EnemyState::DEAD)
    {
        if(this->m_mainSprite->getScale() > 2.0f)
        {
            this->setState(EnemyState::SOUL);
        }
        else
        {
            float rate = this->m_mainSprite->getScale() + 1.0f * dt;
            this->m_mainSprite->setScale(rate);
        }
    }
}
/**
 * ダメージを受け入れるか
 */
bool EnemyObject::isUnlockOfDamage()
{
    if(this->getState() == EnemyState::WAIT)return true;
    return false;
}

