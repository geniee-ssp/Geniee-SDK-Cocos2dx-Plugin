/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;
using namespace ui;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
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

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    //label
    label = Label::createWithTTF("GNSAdSDK NativeAd", "fonts/Marker Felt.ttf", 12);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height * 2));
    this->addChild(label, 1);
    
    //zoneid edit box
    cocos2d::Size editBoxSize = cocos2d::Size(visibleSize.width, 20);
    zoneid_edit = EditBox::create(editBoxSize, Scale9Sprite::create("editbox.png"));
    zoneid_edit->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.85f + origin.y));
    zoneid_edit->setFontColor(Color3B::RED);
    zoneid_edit->setPlaceHolder("zoneid");
    zoneid_edit->setReturnType(EditBox::KeyboardReturnType::DONE);
    zoneid_edit->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
    addChild(zoneid_edit);
    
    //load Ad button
    auto loadButton = MenuItemImage::create("load_normal.png", "load_selected.png",
                                            CC_CALLBACK_1(HelloWorld::push_Load_Button, this));
    loadButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.78f + origin.y));
    auto menu_load = Menu::create(loadButton, NULL);
    menu_load->setPosition(cocos2d::Point::ZERO);
    this->addChild(menu_load, 1);
    
    //clear log button
    auto clearLogButton = MenuItemImage::create("button_clear_log_selected.png", "button_clear_log_disabled.png",
                                            CC_CALLBACK_1(HelloWorld::clearLog, this));
    clearLogButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.7f + origin.y));
    auto menu_clear_log = Menu::create(clearLogButton, NULL);
    menu_clear_log->setPosition(cocos2d::Point::ZERO);
    this->addChild(menu_clear_log, 1);

    // Logs scrollView
    scrollView = ScrollView::create();
    scrollView->setDirection(ScrollView::Direction::VERTICAL);
    cocos2d::Size scrollViewSize = cocos2d::Size(visibleSize.width, visibleSize.height*2/3);
    scrollView->setContentSize(scrollViewSize);
    scrollView->setTouchEnabled(true);
    scrollView->setBounceEnabled(true);
    scrollView->setAnchorPoint(Vec2(0, 0));
    scrollView->setPosition(Vec2(origin.x, origin.y));

    this->addChild(scrollView);

    debugLog = Label::createWithSystemFont("SetSystemFont Alpha Test Alpha is 0.2", "arial", 4);

    debugLog->setDimensions(visibleSize.width, 0);
    debugLog->setPosition(Vec2(scrollView->getPosition().x - 90, scrollView->getPosition().y + debugLog->getContentSize().height));

    scrollView->addChild(debugLog);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::sendNativeAdRequest()
{
    zoneIds = zoneid_edit->getText();

    if (strcmp(zoneIds, "") == 0) {
        
        addLog("Zone id is empty");
        return;
    }
    
    addLog("=======================================");
    addLog("zoneId = " + StringUtils::toString(zoneIds));
    addLog("NativeAd start load...");
    
    nativeAdRequest = new GNSAdSDK::CCGNSNativeAdRequest();
    nativeAdRequest->setDelegate(this);
    nativeAdRequest->initialize(zoneIds);
    
    if (strstr(zoneIds, ",") != NULL) {
        nativeAdRequest->multiLoadAds(); // When there are two or more zoneid
    } else {
        nativeAdRequest->loadAds(); // When there is one zoneid
    }
}

void HelloWorld::push_Load_Button(Ref *pSender)
{
    sendNativeAdRequest();
}

void HelloWorld::clearLog(Ref *pSender)
{
    this->debugLog->setString("");
}

void HelloWorld::onNativeAdsLoaded(std::vector<GNSAdSDK::CCGNSNativeAd *> nativeAds)
{
    
    addLog("Succesfully loaded native ads, zone id = " + StringUtils::toString(zoneIds));

    for (GNSAdSDK::CCGNSNativeAd* _nativeAd : nativeAds) {
        
        addLog("********************************");
        addLog("NativeAd zoneID=" + (_nativeAd->zoneID != NULL && _nativeAd->zoneID[0] != '\0' ? StringUtils::toString(_nativeAd->zoneID) : "NULL"));
        addLog("NativeAd advertiser=" + (_nativeAd->advertiser != NULL && _nativeAd->advertiser[0] != '\0' ? StringUtils::toString(_nativeAd->advertiser) : "NULL"));
        addLog("NativeAd title=" + (_nativeAd->title != NULL && _nativeAd->title[0] != '\0' ? StringUtils::toString(_nativeAd->title) : "NULL"));
        addLog("NativeAd description=" + (_nativeAd->description != NULL && _nativeAd->description[0] != '\0' ? StringUtils::toString(_nativeAd->description) : "NULL"));
        addLog("NativeAd cta=" + (_nativeAd->cta != NULL && _nativeAd->cta[0] != '\0' ? StringUtils::toString(_nativeAd->cta) : "NULL"));
        addLog("NativeAd icon_aspectRatio=" + StringUtils::toString(_nativeAd->icon_aspectRatio));
        addLog("NativeAd icon_url=" + (_nativeAd->icon_url != NULL && _nativeAd->icon_url[0] != '\0' ? StringUtils::toString(_nativeAd->icon_url) : "NULL"));
        addLog("NativeAd icon_height=" + StringUtils::toString(_nativeAd->icon_height));
        addLog("NativeAd icon_width=" + StringUtils::toString(_nativeAd->icon_width));
        addLog("NativeAd screenshots_aspectRatio=" + StringUtils::toString(_nativeAd->screenshots_aspectRatio));
        addLog("NativeAd screenshots_url=" + (_nativeAd->screenshots_url != NULL && _nativeAd->screenshots_url[0] != '\0' ? StringUtils::toString(_nativeAd->screenshots_url) : "NULL"));
        addLog("NativeAd screenshots_height=" + StringUtils::toString(_nativeAd->screenshots_height));
        addLog("NativeAd screenshots_width=" + StringUtils::toString(_nativeAd->screenshots_width));
        addLog("NativeAd app_appName=" + (_nativeAd->app_appName != NULL && _nativeAd->app_appName[0] != '\0' ? StringUtils::toString(_nativeAd->app_appName) : "NULL"));
        addLog("NativeAd app_appid=" + (_nativeAd->app_appid != NULL && _nativeAd->app_appid[0] != '\0' ? StringUtils::toString(_nativeAd->app_appid) : "NULL"));
        addLog("NativeAd app_rating=" + StringUtils::toString(_nativeAd->app_rating));
        addLog("NativeAd storeURL=" + (_nativeAd->app_storeURL != NULL && _nativeAd->app_storeURL[0] != '\0' ? StringUtils::toString(_nativeAd->app_storeURL) : "NULL"));
        addLog("NativeAd targetAge=" + (_nativeAd->app_targetAge != NULL && _nativeAd->app_targetAge[0] != '\0' ? StringUtils::toString(_nativeAd->app_targetAge) : "NULL"));
        addLog("NativeAd optout_text=" + (_nativeAd->optout_text != NULL && _nativeAd->optout_text[0] != '\0' ? StringUtils::toString(_nativeAd->optout_text) : "NULL"));
        addLog("NativeAd optout_image_url=" + (_nativeAd->optout_image_url != NULL && _nativeAd->optout_image_url[0] != '\0' ? StringUtils::toString(_nativeAd->optout_image_url) : "NULL"));
        addLog("NativeAd optout_url=" + (_nativeAd->optout_url != NULL && _nativeAd->optout_url[0] != '\0' ? StringUtils::toString(_nativeAd->optout_url) : "NULL"));
        addLog("********************************");
        
        // Execute when displaying advertisement
        _nativeAd->onTrackingImpression();
        // Execute when clicking ad
        _nativeAd->onTrackingClick();
    }

    addLog("=======================================");
}

void HelloWorld::onNativeAdsFailedToLoad()
{
    printf("HelloWorld::onNativeAdsFailedToLoad\n");
    addLog("Failed to load native ad with zone id = " + StringUtils::toString(zoneIds));
    addLog("=======================================");
}

bool HelloWorld::onShouldStartInternalBrowserWithClick(const char *landingURL)
{
    printf("HelloWorld::onShouldStartInternalBrowserWithClick\n");
    addLog("onShouldStartInternalBrowserWithClick landingURL = " + StringUtils::toString(landingURL));
    addLog("=======================================");
    return false;
}

void HelloWorld::addLog(const std::string logAdded) {

    debugLog->setString(debugLog->getString() + "\n" + logAdded);

    debugLog->setPosition(Vec2(scrollView->getPosition().x - 30, scrollView->getPosition().y + 20));
    debugLog->setAnchorPoint(Vec2(0.5, 0.5));

    log("%s", logAdded.c_str());
}

