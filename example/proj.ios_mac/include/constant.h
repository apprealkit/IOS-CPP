/*******************************************************************************
 * File         :   constant.h
 * Author       :   AppRealKit
 * Version      :   1.0.0
 ******************************************************************************/
#ifndef CONSTANT_H
#define	CONSTANT_H
#include <iostream>
#include <stdio.h>

#ifndef REQUEST_CALLBACK_TYPE_KEY
#define REQUEST_CALLBACK_TYPE_KEY "cbtp"
#endif

#ifndef REQUEST_CALLBACK_METHOD_KEY
#define REQUEST_CALLBACK_METHOD_KEY "cb"
#endif

#ifndef REQUEST_CALLBACK_ID_KEY
#define REQUEST_CALLBACK_ID_KEY "cbid"
#endif

#ifndef REQUEST_DATA_KEY
#define REQUEST_DATA_KEY "obj"
#endif

#ifndef REQUEST_DATA_APP_ID_KEY
#define REQUEST_DATA_APP_ID_KEY "appid"
#endif

#ifndef REQUEST_DATA_APP_SECRET_KEY
#define REQUEST_DATA_APP_SECRET_KEY "appsecret"
#endif

#ifndef REQUEST_DATA_ID_KEY
#define REQUEST_DATA_ID_KEY "id"
#endif

#ifndef REQUEST_DATA_USER_ID_KEY
#define REQUEST_DATA_USER_ID_KEY "uid"
#endif

#ifndef REQUEST_CALLBACK_ID_DEFAULT_VALUE
#define REQUEST_CALLBACK_ID_DEFAULT_VALUE ""
#endif

#ifndef REQUEST_DATA_EXTRAS_KEY
#define REQUEST_DATA_EXTRAS_KEY "extras"
#endif

#ifndef REQUEST_DATA_ROOM_ID_KEY
#define REQUEST_DATA_ROOM_ID_KEY "rid"
#endif

#ifndef REQUEST_DATA_LIST_ID_KEY
#define REQUEST_DATA_LIST_ID_KEY "ids"
#endif

#ifndef REQUEST_DATA_ORDER_BY_KEY
#define REQUEST_DATA_ORDER_BY_KEY "orderby"
#endif

#ifndef REQUEST_DATA_IGNORE_ME_KEY
#define REQUEST_DATA_IGNORE_ME_KEY "ignore_me"
#endif

#ifndef RESPONSE_CODE_KEY
#define RESPONSE_CODE_KEY "code"
#endif

#ifndef RESPONSE_MESSAGE_KEY
#define RESPONSE_MESSAGE_KEY "msg"
#endif

#ifndef REQUEST_DATA_STAMINA_KEY
#define REQUEST_DATA_STAMINA_KEY "stamina"
#endif

#ifndef REQUEST_DATA_EXP_KEY
#define REQUEST_DATA_EXP_KEY "exp"
#endif

#ifndef REQUEST_DATA_LEVEL_KEY
#define REQUEST_DATA_LEVEL_KEY "level"
#endif

#ifndef REQUEST_DATA_COIN_KEY
#define REQUEST_DATA_COIN_KEY "coin"
#endif

#ifndef REQUEST_DATA_DIAMOND_KEY
#define REQUEST_DATA_DIAMOND_KEY "diamond"
#endif

#ifndef REQUEST_DATA_POINT_KEY
#define REQUEST_DATA_POINT_KEY "point"
#endif

#ifndef REQUEST_DATA_CAPACITY_KEY
#define REQUEST_DATA_CAPACITY_KEY "capacity"
#endif

#ifndef AUTHENTICATE_CALLBACK_NAME
#define AUTHENTICATE_CALLBACK_NAME "authenticate"
#endif

#ifndef CREATE_ROOM_CALLBACK_NAME
#define CREATE_ROOM_CALLBACK_NAME "createRoom"
#endif

#ifndef JOIN_ROOM_CALLBACK_NAME
#define JOIN_ROOM_CALLBACK_NAME "joinRoom"
#endif

#ifndef LEAVE_ROOM_CALLBACK_NAME
#define LEAVE_ROOM_CALLBACK_NAME "leaveRoom"
#endif

#ifndef GET_ROOM_CALLBACK_NAME
#define GET_ROOM_CALLBACK_NAME "getRoom"
#endif

#ifndef GET_LIST_ROOM_CALLBACK_NAME
#define GET_LIST_ROOM_CALLBACK_NAME "getListRoom"
#endif

#ifndef GET_USER_CALLBACK_NAME
#define GET_USER_CALLBACK_NAME "getUser"
#endif

#ifndef UPDATE_POINT_CALLBACK_NAME
#define UPDATE_POINT_CALLBACK_NAME "updatePoint"
#endif

#ifndef GET_LIST_USER_CALLBACK_NAME
#define GET_LIST_USER_CALLBACK_NAME "getListUser"
#endif

#ifndef GET_LEADER_BOARD_CALLBACK_NAME
#define GET_LEADER_BOARD_CALLBACK_NAME "getLeaderBoard"
#endif

#ifndef NOTIFY_IN_ROOM_CALLBACK_NAME
#define NOTIFY_IN_ROOM_CALLBACK_NAME "notifyInRoom"
#endif

#ifndef NOTIFY_USER_LIST_CALLBACK_NAME
#define NOTIFY_USER_LIST_CALLBACK_NAME "notifyListUser"
#endif

#ifndef NOTIFY_MESSAGE_CALLBACK_NAME
#define NOTIFY_MESSAGE_CALLBACK_NAME "onNotifyMessage"
#endif

namespace AppRealKit {
    namespace Realtime {

        /**
         * APP type data
         */
        struct kitCode {

            enum ActionType {
                AUTHENTICATE,
                CREATE_ROOM,
                JOIN_ROOM,
                LEAVE_ROOM,
                GET_ROOM,
                GET_LIST_ROOM_OF_USER,
                GET_USER,
                UPDATE_POINT,
                GET_LIST_USER,
                GET_LEADER_BOARD,
                NOTIFY_IN_ROOM,
                NOTIFY_USER_LIST
            };

            enum ErrorType {
                SUCCESS,
                FAILURED,
                WRONG_PARAM
            };
        };
    }
}

#endif	/* CONSTANT_H */

