//
//  CustomIDCardManager.h
//  SRIDCardDemo
//
//  Created by 叶威 on 17/5/20.
//  Copyright © 2017年 Syt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HTIDCardDefine.h"

typedef void(^BeConnectBlock)(BOOL isReady);

@interface CustomIDCardManager : NSObject

@property(nonatomic,copy)BeConnectBlock beConnectBlock;
/**单例实例化接口*/
+(instancetype)sharedInstance;

/**获取设备列表*/
-(void)getDeviceList:(DeviceListCallBack)callBack;

/**连接读取数据读卡器*/
-(BOOL)startConnectIDCardWithSelectDevice:(id)selectDeive;

/// 选卡
-(NSData *)selectCard:(Byte)cardType;

/// 发送APDUTRANS数据
-(void)sendAPDUTRANSDataByLength:(Byte)length data:(Byte [])inputData ouputLength:(int *)outputLength ouputData:(Byte [])ouputDdata;

///获取IDBuddle数据
-(void)getIDBuddleWithOutLength:(int *)outputLength outData:(Byte [])ouputDdata;

-(NSData *)getSimPower;

/// 断开连接
-(void)disConnect;

/// 关闭设备
-(BOOL)shutdownDevice;

/// 获得设备信息
-(NSData *)getDeviceInfo;
- (void)rescanAndConnect:(NSInteger)time;

@property( nonatomic,assign) BOOL isCtimeout;
@property(nonatomic,copy) BLEReCodeCallBack bLEReCodeCallBack;

@end
