//
//  PrefixHeader.pch
//  Hand16
//
//  Created by Hand-hitech-mac on 2018/3/26.
//  Copyright © 2018年 Hand-Hitech. All rights reserved.
//

#ifndef PrefixHeader_pch
#define PrefixHeader_pch

//#ifdef __OBJC__
#include "NSDate+Extension.h"
#import "NSString+category.h"
#import "NSString+Extension.h"
#import "NSString+URL.h"
#import "PPNetworkHelper.h"
#import "Masonry.h"
//#import <SDAutoLayout.h>
#import "MJExtension.h"
#import "MBProgressHUD+MJ.h"
#import "BTDataCenter.h"
#import "HDBaseViewController.h"
#import "HDBaseTableViewCell.h"
//#import <ReactiveCocoa/ReactiveCocoa.h>
#import "ReactiveCocoa.h"
#import "DKHttpServiceManager.h"
#import "DKCommand.h"
#import "DKExtension.h"
#import "HandBaseBtn.h"
#import <ChuckTableView/ChuckTableView.h>
#import "HDConst.h"
//#import <SVProgressHUD.h>
//#import <MBProgressHUD+DK/DKProgressHUD.h>
//#endif

//测试和正式环境切换开关
//#define DEBUG 1

//#define kCusotmerDeBang 1 //德邦客户

#define BLE_SEARCH_DUPLICATE 1 //蓝牙是否重复搜索

#define CALIBRATION_WEIGHT_COMBINED 1 //标定重量三合一

//app用户角色:1,安装工，2,算法工(appid:com.handhitech.channel16)，3,客户
//#define kAppUserRoleInstall 1 //1,角色:安装工  2,appid:com.handhitech.channel16Install 3,app名称:汉德装车
//#define kAppUserRoleCaculate 2 //2,角色:算法工  2,appid:com.handhitech.channel16 3,app名称:16通道
//#define kAppUserRoleDriver 3 //3,角色:客户  2,appid:com.handhitech.channel16Driver 3,app名称:16通道
//#define kAppUserRoleMatlab 4 //4,角色:matlab算法版 2,appid:com.handhitech.matlab+日期+客户拼音+车牌号码 3,app名称:日期+客户拼音+车牌号码
//#define kAppUserRoleProduction 4 //4,角色:生产测试 2,appid:com.handhitech.produdction 3,app名称:汉德生产测试,算法随kAppUserRoleMatlab的算法动态变化
//测试URL
//#ifdef DEBUG
//
//#define kBaseUrl @"http://39.108.114.33:8088"
//#define kBaseUrl @"http://119.23.230.76:8088"
//#define kBaseUrl @"http://192.168.10.165:8088"
#define kBaseUrl @"http://api.truckloading.cn"
//
//#else

//#define kBaseUrl @"http://api.truckloading.cn"

//#endif

#define HDAPI(url) [NSString stringWithFormat:@"%@/api/%@",kBaseUrl,url]
#define DKToken DKGetUserDefault(@"token")

//系统版本
//检查<a class="keylink" href="http://www.2cto.com/os/" target="_blank">系统</a>版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
#define IS_IOS_11_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.0)? (YES):(NO))

#define APP_DISPLAY_NAME ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"])

//屏幕宽度
#define ScreenHeight  [[UIScreen mainScreen] bounds].size.height
#define ScreenWidth   [[UIScreen mainScreen] bounds].size.width
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define kMainFont [UIFont systemFontOfSize:isPad?22:15]

/// RGB颜色(16进制)
#define COLOR_HEX(rgbValue, a) \
[UIColor colorWithRed:((CGFloat)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
green:((CGFloat)((rgbValue & 0xFF00) >> 8)) / 255.0 \
blue:((CGFloat)(rgbValue & 0xFF)) / 255.0 alpha:(a)]

#define ColorFromHex(rgbValue) COLOR_HEX(rgbValue, 1.0)
#define kNavBarColor [UIColor colorWithRed:34/255.0 green:85/255.0 blue:161/255.0 alpha:1.0]
#define kMainColor [UIColor colorWithRed:49/255.0 green:144/255.0 blue:213/255.0 alpha:1.0]
#define kWordNoramlColor [UIColor colorWithRed:100/255.0 green:100/255.0 blue:100/255.0 alpha:1.0]
#define kPageBgColor [UIColor colorWithRed:225/255.0 green:225/255.0 blue:225/255.0 alpha:1.0]

//代码执行时间
#define TICK   NSDate *startTime = [NSDate date]
#define TOCK   NSLog(@"Time: %f", -[startTime timeIntervalSinceNow])

//tableviewcell默认间距
#define TABLEVIEW_CELL_AUTO_MARGIN(tableview) \
if ([[UIDevice currentDevice].systemVersion doubleValue] >= 9.0) \
{\
    if (@available(iOS 9.0, *)) {\
        tableview.cellLayoutMarginsFollowReadableWidth = NO;\
    } \
}

/*** UserDefaults ***/
#define HDUserDefaultSet(key,value)\
[[NSUserDefaults standardUserDefaults] setObject:(value) forKey:(key)];\
[[NSUserDefaults standardUserDefaults] synchronize];

#define HDUserDefaultGet(key) [[NSUserDefaults standardUserDefaults] objectForKey:(key)]

/*** Notification ***/
//创建通知
#define HDNotificationAdd(selectorName,key) [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(selectorName) name:key object:nil];
//发送通知
#define HDNotificationSend(key,obj,user) [[NSNotificationCenter defaultCenter] postNotificationName:(key) object:(obj) userInfo:(user)];
//移除通知
#define HDNotificationRemove(key) [[NSNotificationCenter defaultCenter]removeObserver:self name:key object:nil];

/*** 蓝牙 ***/
#define kBleDisconnectAlert \
if (!currentPort) {\
[MBProgressHUD showError:@"蓝牙未连接" toView:self.view];\
return;\
}


/*** 失败提示框 ***/
#define kAlertError(error)\
[MBProgressHUD showError:(error) toView:[UIApplication sharedApplication].keyWindow.rootViewController.view];\
NSLog(@"%@",error);

/*** 成功提示框 ***/
#define kAlertSuccess(success)\
[MBProgressHUD showSuccess:(success) toView:[UIApplication sharedApplication].keyWindow.rootViewController.view];\
NSLog(@"%@",success);

/*** 显示加载提示框 ***/
#define kAlertLoaing(loaingText,isDimBack) [MBProgressHUD showMessage:loaingText dimBack:isDimBack];\


/*** 隐藏提示框 ***/
#define kAlertHide \
[MBProgressHUD hideHUD];


//懒加载
/** 默认初始化方式 */
#define kLazyLoadDefInit(class,model,_model)\
- (class *)model{\
if (!_model) {\
    _model = [[class alloc] init];\
}\
return _model;\
}

#define kLazyLoadPriInit(class,model,_model,method)\
- (class *)model{\
if (!_model) {\
_model = [class method];\
}\
return _model;\
}



//判断字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
//判断数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//判断字典是否为空
#define kDictionaryIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)


#endif /* PrefixHeader_pch */
