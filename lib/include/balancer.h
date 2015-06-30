/*******************************************************************************
 * File         :   balancer.h
 * Author       :   AppRealKit
 * Version      :   1.0.1
 ******************************************************************************/
#ifndef BALANCER_H
#define	BALANCER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <pthread.h>
#include "constant.h"

namespace AppRealKit {
	namespace Realtime {

        /**
         * Balancer handler
         */
        class Balancer {
            /*******************************************************************
             * Property public
             ******************************************************************/
        public:
            /**
             * Async callback function
             */
            typedef void (*AsyncCallbackFunc)(const std::string &sMessage, int iCode);

            /*******************************************************************
             * Property private
             ******************************************************************/
        private:

            /**
             * Debug information
             */
            bool bDebug;

            /**
             * Current Instance
             */
            static Balancer *singletonInstance;

            /**
             * Singleton control
             */
            static pthread_once_t singletonControl;

            /**
             * APP ID
             */
            std::string appID;

            /**
             * APP Secret
             */
            std::string appSecret;

            /**
             * ServerKits Host
             */
            std::string sHost;

            /**
             * ServerKits Port
             */
            int iPort;

            /**
             * Ready connection
             */
            bool isReady;

            /*******************************************************************
             * Description  :   Singleton initialize
             ******************************************************************/
            static void singletonInitialize();

            /**
             * Open callback after opened the socket
             */
            AsyncCallbackFunc openedCallback;

            /**
             * Sent callback after sent the message to server
             */
            AsyncCallbackFunc sentCallback;

            /**
             * Received callback to handle the notification messages
             */
            AsyncCallbackFunc receivedCallback;

            /**
             * Close callback after closed the connection
             */
            AsyncCallbackFunc closedCallback;

            /*******************************************************************
             * Description  :   Constructor with arguments
             ******************************************************************/
            Balancer();

            /*******************************************************************
             * Description  :   Destructor function without parameter
             ******************************************************************/
            ~Balancer();

            /*******************************************************************
             * Property public
             ******************************************************************/
        public:

            /*******************************************************************
             * Description  :   Get current instance
             ******************************************************************/
            static Balancer* getInstance();

            /*******************************************************************
             * Description  :   Destroy current instance
             ******************************************************************/
            static void release();

            /*******************************************************************
             * Description  :   Get sever HOST
             ******************************************************************/
            std::string getHost();

            /*******************************************************************
             * Description  :   Get sever PORT
             ******************************************************************/
            int getPort();

            /*******************************************************************
             * Description  :   Handle verbose
             ******************************************************************/
            bool isVerbose();

            /*******************************************************************
             * Description  :   Set debug flag
             ******************************************************************/
            void setVerbose(bool bDebug_);

            /*******************************************************************
             * Description  :   Set ready status
             ******************************************************************/
            void setReady(bool isRead_);

            /*******************************************************************
             * Description  :   Set APP ID and APP secret
             ******************************************************************/
            void setProductID(std::string appID_, std::string appSecret_);

            /*******************************************************************
             * Description  :   Connection to TCP server
             ******************************************************************/
            void connect(std::string pullHost_, int pullPort_);

            /*******************************************************************
             * Description  :   Check connection status
             ******************************************************************/
            bool isConnected();

            /*******************************************************************
             * Description  :   Close connection
             ******************************************************************/
            void close();

            /*******************************************************************
             * Description  :   Set opened callback
             ******************************************************************/
            void onKitOpen(AsyncCallbackFunc callbackFunc);

            /*******************************************************************
             * Description  :   Get opened callback
             ******************************************************************/
            AsyncCallbackFunc getOpenedCallback();

            /*******************************************************************
             * Description  :   Set sent callback
             ******************************************************************/
            void onKitSent(AsyncCallbackFunc callbackFunc);

            /*******************************************************************
             * Description  :   Get sent callback
             ******************************************************************/
            AsyncCallbackFunc getSentCallback();

            /*******************************************************************
             * Description  :   Set received callback
             ******************************************************************/
            void onKitMessage(AsyncCallbackFunc callbackFunc);

            /*******************************************************************
             * Description  :   Get received callback
             ******************************************************************/
            AsyncCallbackFunc getReceviedCallback();

            /*******************************************************************
             * Description  :   Set closed callback
             ******************************************************************/
            void onKitClose(AsyncCallbackFunc callbackFunc);

            /*******************************************************************
             * Description  :   Get closed callback
             ******************************************************************/
            AsyncCallbackFunc getClosedCallback();

            /*******************************************************************
             * Description  :   AUTHENTICATE calling API
             ******************************************************************/
            bool authenticate(const std::string &loginID, AsyncCallbackFunc callbackFunc);

            /*******************************************************************
             * Description  :   CREATE_ROOM calling API
             ******************************************************************/
            bool createRoom(const std::string &creatorUserID, const std::map<std::string, std::string> &properties, const int &iCapacity, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   JOIN_ROOM calling API
             ******************************************************************/
            bool joinRoom(const std::string &userID, const std::string &roomID, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   LEAVE_ROOM calling API
             ******************************************************************/
            bool leaveRoom(const std::string &userID, const std::string &roomID, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   GET_ROOM calling API
             ******************************************************************/
            bool getRoom(const std::string &roomID, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   GET_LIST_ROOM_OF_USER calling API
             ******************************************************************/
            bool getListRoom(const std::string &userID, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   GET_USER calling API
             ******************************************************************/
            bool getUser(const std::string &userID, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   UPDATE_POINT calling API
             ******************************************************************/
            bool updatePoint(const std::string &userID, const std::map<std::string, int> &pointlist, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   GET_LIST_USER calling API
             ******************************************************************/
            bool getListUser(const std::vector<std::string> &arrUserID, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   GET_LEADER_BOARD calling API
             ******************************************************************/
            bool getLeaderBoard(const std::string &orderBy, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   NOTIFY_IN_ROOM calling API
             ******************************************************************/
            bool notifyInRoom(const std::string &roomID, int code, const std::string &reason, bool ignoreAlertMeFlg, AsyncCallbackFunc callbackFunc);
            
            /*******************************************************************
             * Description  :   NOTIFY_USER_LIST calling API
             ******************************************************************/
            bool notifyListUser(const std::vector<std::string> &arrUserID, int code, const std::string &reason, bool ignoreAlertMeFlg, AsyncCallbackFunc callbackFunc);
        };
    }
}

#endif	/* BALANCER_H */

