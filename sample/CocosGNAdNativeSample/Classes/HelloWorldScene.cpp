#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace ui;

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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //label
    label = Label::createWithTTF("GNSAdSDK NativeAd", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height * 2));
    this->addChild(label, 1);
    
    //zoneid edit box
    zoneid_edit = EditBox::create(Size(visibleSize.width/3, 30), Scale9Sprite::create("editbox.png"));
    zoneid_edit->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    zoneid_edit->setFontColor(Color3B::RED);
    zoneid_edit->setPlaceHolder("zoneid");
    zoneid_edit->setMaxLength(15);
    zoneid_edit->setReturnType(EditBox::KeyboardReturnType::DONE);
    zoneid_edit->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
    addChild(zoneid_edit);
    
    //load Ad button
    auto loadButton = MenuItemImage::create("load_normal.png", "load_selected.png",
                                            CC_CALLBACK_1(HelloWorld::push_Load_Button, this));
    loadButton->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/3 + origin.y));
    auto menu_load = Menu::create(loadButton, NULL);
    menu_load->setPosition(Point::ZERO);
    this->addChild(menu_load, 1);
    
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
    if (strcmp(zoneid_edit->getText(), "") == 0) {
        return;
    }
    label->setString("NativeAd start load...");
    GNSAdSDK::CCGNNativeAdRequest::initialize(zoneid_edit->getText());
    GNSAdSDK::CCGNNativeAdRequest::setDelegate(this);
    GNSAdSDK::CCGNNativeAdRequest::loadAds();
}

void HelloWorld::onNativeAdsLoaded(std::vector<GNSAdSDK::CCGNNativeAd*> nativeAds) {
    for (GNSAdSDK::CCGNNativeAd* _nativeAd : nativeAds) {
        log("NativeAd zoneID=%s", _nativeAd->zoneID);
        log("NativeAd advertiser=%s", _nativeAd->advertiser);
        log("NativeAd title=%s", _nativeAd->title);
        log("NativeAd description=%s", _nativeAd->description);
        log("NativeAd cta=%s", _nativeAd->cta);
        log("NativeAd icon_aspectRatio=%f", _nativeAd->icon_aspectRatio);
        log("NativeAd icon_url=%s", _nativeAd->icon_url);
        log("NativeAd icon_height=%d", _nativeAd->icon_height);
        log("NativeAd icon_width=%d", _nativeAd->icon_width);
        log("NativeAd screenshots_aspectRatio=%f", _nativeAd->screenshots_aspectRatio);
        log("NativeAd screenshots_url=%s", _nativeAd->screenshots_url);
        log("NativeAd screenshots_height=%d", _nativeAd->screenshots_height);
        log("NativeAd screenshots_width=%d", _nativeAd->screenshots_width);
        log("NativeAd app_appName=%s", _nativeAd->app_appName);
        log("NativeAd app_appid=%s", _nativeAd->app_appid);
        log("NativeAd app_rating=%f", _nativeAd->app_rating);
        log("NativeAd storeURL=%s", _nativeAd->app_storeURL);
        log("NativeAd targetAge=%s", _nativeAd->app_targetAge);
        // 広告を表示したとき実行
        _nativeAd->onTrackingImpression();
        // 広告をクリックしたとき実行
        _nativeAd->onTrackingClick();
    }
    label->setString("NativeAd load success.");
}

void HelloWorld::onNativeAdsFailedToLoad() {
    label->setString("NativeAd load fatal.");
}

bool HelloWorld::onShouldStartInternalBrowserWithClick(const char* landingURL) {
    log("NativeAd click=%s", landingURL);
    label->setString("NativeAd should start internal browser with click");
    return false;
}

