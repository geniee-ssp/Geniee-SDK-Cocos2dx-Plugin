#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace cocos2d::extension;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    for (int i = 0; i < logCnt; i++) {
        logLabel[i] = Label::createWithTTF("GNSAdSDK RewardVideoAd", "fonts/arial.ttf", 4);
        logLabel[i]->setPosition(Vec2(origin.x + visibleSize.width / 2,
                        origin.y + (int)(visibleSize.height * (0.65f - i * 0.03f)) - logLabel[i]->getContentSize().height));
        logLabel[i]->setWidth((int)(visibleSize.width * 0.95f));
        this->addChild(logLabel[i]);
    }
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2 ,
                                origin.y + closeItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //label
    label = Label::createWithTTF("GNSAdSDK RewardVideoAd", "fonts/Marker Felt.ttf", 12);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height * 0.95f - label->getContentSize().height));
    this->addChild(label, 1);
    
    //zoneid edit box
    Size editBoxSize = Size(visibleSize.width * 0.7f, 20.0f);
    zoneid_edit = EditBox::create(editBoxSize, Scale9Sprite::create("editbox.png"));
    zoneid_edit->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.85f + origin.y));
    zoneid_edit->setFontColor(Color3B::RED);
    zoneid_edit->setPlaceHolder("zoneid");
    zoneid_edit->setMaxLength(15);
    zoneid_edit->setReturnType(EditBox::KeyboardReturnType::DONE);
    zoneid_edit->setInputMode(ui::EditBox::InputMode::NUMERIC);
    addChild(zoneid_edit);
    
    //load Ad button
    auto loadButton = MenuItemImage::create("button_load_normal.png", "button_load_selected.png",
                                            CC_CALLBACK_1(HelloWorld::push_Load_Button, this));
    loadButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.78f + origin.y));
    auto menu_load = Menu::create(loadButton, NULL);
    menu_load->setPosition(Point::ZERO);
    this->addChild(menu_load, 1);
    
    //show Ad button
    auto showButton = MenuItemImage::create("button_show_normal.png", "button_show_selected.png",
                                            CC_CALLBACK_1(HelloWorld::push_Show_Button, this));
    showButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.71f + origin.y));
    auto menu_show = Menu::create(showButton, NULL);
    menu_show->setPosition(Point::ZERO);
    this->addChild(menu_show, 1);

    addLog("init load");
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::push_Load_Button(Ref *pSender)
{
    addLog("zoneId=" + StringUtils::toString(zoneid_edit->getText()));
    addLog("VideoAd start load...");
    GNSAdSDK::CCGNSRewardVideoAd::initialize(zoneid_edit->getText());
    GNSAdSDK::CCGNSRewardVideoAd::setDelegate(this);
    GNSAdSDK::CCGNSRewardVideoAd::loadRequest();
}

void HelloWorld::push_Show_Button(Ref *pSender)
{
    addLog("show button");
    if (GNSAdSDK::CCGNSRewardVideoAd::canShow()) {
        addLog("VideoAd start show");
        GNSAdSDK::CCGNSRewardVideoAd::show();
    }
}

void HelloWorld::rewardVideoAdDidReceiveAd() {
    addLog("VideoAd load success. You can show");
}

void HelloWorld::didFailToLoadWithError(const char* errorMsg) {
    addLog("didFailToLoadWithError=" + std::string(errorMsg));
}

void HelloWorld::rewardVideoAdDidStartPlaying() {
    addLog("VideoAd showing...");
}

void HelloWorld::rewardVideoAdDidClose() {
    addLog("VideoAd close");
}

void HelloWorld::didRewardUserWithReward(const char* rewardType, double rewardAmount) {
    addLog("VideoAd rewarded to user");
    addLog("rewardAmount=" + StringUtils::toString(rewardAmount));
    addLog("rewardType=" +  std::string(rewardType));
}
void HelloWorld::addLog(const std::string str) {
    log("%s", str.c_str());
    for (int i = logCnt - 2; i >= 0; i--) {
        loglist[i + 1] = loglist[i];
    }
    loglist[0] = str;
    for (int i = logCnt - 1; i >= 0; i--) {
        logLabel[i]->setString(loglist[i]);
    }
}
