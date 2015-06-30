#include "HelloWorldScene.h"

USING_NS_CC;
using namespace std;

std::string loginID = "1234";
std::string memberID = "5678";

static void receiveMessageCallback(const std::string &sMessage, int iCode) {
    std::cout << "receiveMessage Message:" << sMessage << " and Code:" << iCode << std::endl;
}

static void createRoomCallback(const std::string &sMessage, int iCode) {
    std::cout << "createRoom Message:" << sMessage << " and Code:" << iCode << std::endl;
}

static void authenticateCallback(const std::string &sMessage, int iCode) {
    std::cout << "authenticateCallback Message:" << sMessage << " and Code:" << iCode << std::endl;
    
    //Create ROOM ID
    std::map<std::string, std::string> arrProperties;
    arrProperties["name"] = "ROOM_TEST\n+++\n";
    arrProperties["description"] = "ROOM_DESCRIPTION\n+++\n";
    int iCapacity = 0;
    
    //Create a room without receive the response message    
    AppRealKit::Realtime::Balancer::getInstance()->createRoom(loginID, arrProperties, iCapacity, createRoomCallback);
}

static void openedCallback(const std::string &sMessage, int iCode) {
    std::cout << "Message:" << sMessage << " and Code:" << iCode << std::endl;
    
    //Call authenticate
    AppRealKit::Realtime::Balancer::getInstance()->authenticate(loginID, authenticateCallback);
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
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

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    //---------------------------------
    std::string appID_="080693ab-7123-4aee-b560-9f6a8a332a43";
    std::string appSecret_="VORAI5D6yz";
    std::string hostIP_="192.168.10.102";
    int iPort_=7777;
    bool bDebug = true;
    
    //Get balancer instance
    oBalancer = AppRealKit::Realtime::Balancer::getInstance();
    
    //Set verbose flag
    oBalancer->setVerbose(bDebug);
    
    //Set product ID
    oBalancer->setProductID(appID_, appSecret_);
    
    //Set all callback here
    oBalancer->onKitOpen(openedCallback);
    oBalancer->onKitMessage(receiveMessageCallback);
    
    //Connect to server
    oBalancer->connect(hostIP_, iPort_);
    //---------------------------------
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
