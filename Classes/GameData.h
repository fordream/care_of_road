//
//  GameData.h
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#ifndef __care_of_road__GameData__
#define __care_of_road__GameData__

#include "cocos2d.h"

class GameData
{
    
    //移動量
    CC_SYNTHESIZE(float, m_GroundHeightMove, GroundHeightMove);
    //Gameスコア
    CC_SYNTHESIZE(int, m_GameScore, GameScore);
    //ポイント
    CC_SYNTHESIZE(int, m_GamePoint, GamePoint);
    
    //最大パワー
    CC_SYNTHESIZE(int, m_MaxPower, MaxPower);
    //チャージパワー
    CC_SYNTHESIZE(int, m_ChargePower, ChargePower);
    //チャージ速度
    CC_SYNTHESIZE(float, m_ChargeTime, ChargeTime);
    //連射ディレイ
    CC_SYNTHESIZE(float, m_ShotCycle, ShotCycle);
    //弾の大きさ
    CC_SYNTHESIZE(float, m_ShotSize, ShotSize);
    //プレイヤーのHP
    CC_SYNTHESIZE(int, m_PlayerHp, PlayerHp);
    
public:
    static GameData * getInstance();
    
    /**
     * スコアの取得
     */
    int getHighScore();
    /**
     * スコアの設定
     */
    void setHighScore(int val);
    
    /**
     * 基本値の読み込み
     */
    void loadSettingData();
    
    /**
     * 基本値の保存
     */
    void saveSettingData();
    
};

#endif /* defined(__care_of_road__GameData__) */
