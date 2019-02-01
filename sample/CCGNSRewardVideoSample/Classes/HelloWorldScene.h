#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <iostream>
#include "cocos-ext.h"
#include "CCGNSRewardVideoAd.h"

class HelloWorld : public cocos2d::Scene, CCGNSRewardVideoAdDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    //Sample label, edit, button for load and show video ad
    cocos2d::Label *label;
    cocos2d::Label *logLabel[20];
    std::string loglist[20];
    int logCnt = 20;
    cocos2d::extension::EditBox* zoneid_edit;
    void push_Load_Button(Ref *pSender);
    void push_Show_Button(Ref *pSender);
    void addLog(const std::string str);
    
    // CCGNSRewardVideoAdDelegate callback
    virtual void rewardVideoAdDidReceiveAd();
    virtual void didFailToLoadWithError(const char* errorMsg);
    virtual void rewardVideoAdDidStartPlaying();
    virtual void rewardVideoAdDidClose();
    virtual void didRewardUserWithReward(const char* rewardType, double rewardAmount);
};

#endif // __HELLOWORLD_SCENE_H__
