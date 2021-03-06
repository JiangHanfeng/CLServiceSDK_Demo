//
//  KEInterface.h
//  KaerIDCardItem
//
//  Created by apple on 17/2/17.
//  Copyright © 2017年 kaer. All rights reserved.
//

#ifndef KEDelegateProtocol_h
#define KEDelegateProtocol_h

@protocol KaerAdapterDelegate <NSObject>

///蓝牙连接状态代理，yes 蓝牙连接成功  no 蓝牙连接失败
-(void)BR_ConnectResult:(BOOL)isconnected;


///分体专用-共享服务器连接状态，yes 服务器连接成功  no 服务器连接失败
-(void)SSL_ConnectResult:(BOOL)isconnected;


///读身份证进度
-(void)KE_ProgressUpdate:(float)progress;

-(void)KE_ReadcertResult:(IDCardItem*)resultItem;

-(void)KE_DiscoverBlePeripheral:(BleDevice*)bledevice;

@end


@protocol OnDataReceivedListener <NSObject>
//收到卡号数据回调
-(void)onCardReceived:(Byte *)data;
//收到体温数据上报
-(void)onTempReceived:(Byte *)data;
//收到二维码数据上报
-(void)onQRCodeReceived:(Byte *)data;
//收到离线温度和二维码数据
-(void)onTempAndQRCodeReceived:(Byte *)data;

@end

#endif /* KEInterface_h */
