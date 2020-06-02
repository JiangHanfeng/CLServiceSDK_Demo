//
//  HTCardReader.h
//  HTCardReader
//
//  Created by Wind on 2017/12/4.
//  Copyright © 2017年 Hetian. All rights reserved.
//
//  阅读器接口库

//Version:1.1.4
//更新内容：1.1.0 增加了港澳台和外国人证件解析
//        1.1.1 统一显示返回错误码
//        1.1.2 增加通过uuid连接蓝牙
//        1.1.3 增加是否建立通道完成状态isReadConnect 添加搜索蓝牙时间
//        1.1.4 增加获得SMSC信息

#import <Foundation/Foundation.h>
#import "HTIDCardDefine.h"
typedef void(^StartReadCardBlock)(BOOL isReady);
@class HTIDCardInfo;
@class ReaderDeviceInfo;

@interface HTCardReaderManager : NSObject

/**
 # 是否建立通道完成
 0:不未完成
 1:完成
 */
@property(nonatomic ,assign)BOOL isReadConnect;

/**
 # 判断蓝牙电量
 0:低于10%
 1:正常电量
 */
@property(nonatomic,copy)StartReadCardBlock startReadCardBlock;
/**
 # 蓝牙连接状态
 0:蓝牙连接失败
 1:蓝牙连接成功
 */
@property(nonatomic,copy)BLEReCodeCallBack bLEReCodeCallBack;
/**单例接口*/
+(instancetype)sharedInstance;

#pragma mark -- 蓝牙设备相关

/**
 # 取设备列表
 - Parameter callBack: 返回设备列表 CBPeripheral 列表
 */

-(void)getDeviceList:(DeviceListCallBack)callBack;
/**
 # 重新取设备列表
 - Parameter callBack: 返回设备列表 CBPeripheral 列表
 */
-(void)htrescanAndConnect:(NSInteger)time;

/**
 # 连接设备
 - Parameter peripheral: 蓝牙设备CBPeripheral引用，在 getDeviceList 接口中可以拿到设备
 0:读卡器交互中或读卡器连接错误
 1:读卡器正常连接
 */
-(BOOL)connectDevice:(id)peripheral;

-(BOOL)connectDeviceWithUUID:(NSString *)peripheralUUID;

/**
 # 断开当前设备连接
 */
-(void)disConnectDevice;

/**
 # 设置设备状态变化回调，通常使用该回调来刷新列表的设备状态
 */
-(void)setDeviceStateChangeCallBack:(NoDataCallBack)callBack;

/**
 # 设置是否自动连接最近一次连接的设备，默认为YES
 */
-(void)autoConnectLastDevice:(BOOL)autoConnect;

#pragma mark -- 读卡器相关

/**
 # 设置服务器的地址和端口号，该接口请在初始化的时候调用
 - Parameter host: 服务器地址
 - Parameter port: 端口号
 */
-(void)setServerAddress:(NSString *)host port:(NSInteger)port;

/**
 # 选卡
 */
-(void)selectIDCard:(Byte)cardType finishCallBack:(DataCallBack)finishCallBack;

/**
 # 读取身份证信息
 */
-(void)readIDCardInfo:(IDCardInfoCallBack)finishCallBack;

/**
 # 获取ICCID
 */
-(void)readICCID:(StringCallBack)finishCallBack;

/**
 # 判断空卡
  0:空卡
 -1:非空卡
 */
-(int)isBlankCard;

/**
 # 读取imsi
 */
-(void)readIMSI:(StringCallBack)finishCallBack;

/**
 # 判断白卡
  0:白卡
 -1:成卡
 */
-(int)isWhiteCard;

/**
 # 写imsi
 */
-(void)writeIMSI:(NSString *)strIMSI And:(BoolCallBack)finishCallBack;
/**
 # 写短消息中心
 */
-(void)writeSMSC:(NSString *)strSmsc And:(BoolCallBack)finishCallBack;

/**
 # 写卡
 */
- (int)writeSimCard:(NSString *)imsi withSmsc:(NSString *)smscNo;

/**
 # 传输apdu数据
 - Parameter apdu: 要传输的Data
 */
-(void)apduTransmit:(NSData *)apdu finishCallBack:(DataCallBack)finishCallBack;

- (NSData *)apduTransmit:(NSData *)apdu;
/**
 # 获得Sim信息
 */
-(void)getSimPower:(StringCallBack)finishCallBack;


/**
 # 获得SMSC信息
 */
-(void)readSMSC:(StringCallBack)finishCallBack;

/**
 # 关机
 */
-(void)shutdownReader:(BoolCallBack)finishCallBack;

/**
 # 获得读卡器设备信息
 */
-(void)getReaderInfo:(DeviceInfoCallBack)finishCallBack;

//// OPS ////
-(void)OPSGetCardSN:(StringCallBack)finishCallBack;
-(void)OPSReadICCID:(StringCallBack)finishCallBack;
-(void)OPSWriteDataWithStrIssueData:(NSString *)strIssueData finishCallBack:(StringAndRecodeCallBack)finishCallBack;


@end
