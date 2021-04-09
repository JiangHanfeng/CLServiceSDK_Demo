//
//  IDCardItem.h
//  SharedTypeIDCardReader
//
//  Created by kaer on 15-10-15.
//  Copyright (c) 2015年 xc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDCardItem : NSObject

@property int resultCode;
@property (nonatomic,retain) NSString *resultErrDesc;

@property int cardType;//0国内居民身份证  1外国人永久居留身份证 2港澳台
@property (nonatomic,retain) NSString *cardTypeStr;//I 外国人永居证   J港澳台居住证
@property (nonatomic,retain) NSString *partyName;//姓名，如果证件是外国人永久居留身份证，此字段是中文姓名
@property (nonatomic,retain) NSString *englishName;//外国人永久居留身份证英文姓名字段
@property (nonatomic,retain) NSString *sexCode;//性别代号
@property (nonatomic,retain) NSString *gender;//性别
@property (nonatomic,retain) NSString *nation;//民族，外国人永久居留身份证的国籍或所在地区代码字段
@property (nonatomic,retain) NSString *nationCode;//民族代码、或外国人居留身份证的国际所在地区代码

@property (nonatomic,retain) NSString *bornDay;//出生日期
@property (nonatomic,retain) NSString *certAddress;//家庭住址，外国人永居证此字段无效
@property (nonatomic ,retain) NSString *certNumber;//证件号码 身份证18位，外国人永居证 15位
@property (nonatomic,retain) NSString *certOrg;//签发机关

@property (nonatomic,retain) NSString *effDate;//证件签发日期
@property (nonatomic,retain) NSString *expDate;//证件终止日期

@property (nonatomic,retain) NSData *picImgData;//身份证照片-解密后，可直接显示
@property (nonatomic,retain) NSData *fingerInfoData;//指纹数据

@property (nonatomic,retain) NSData * encodePicData;//身份证照片-解密前的1024字节
@property (nonatomic,retain) NSData * encodeIDInfo;//身份证文本-解密前的256字节

@property (nonatomic,retain) NSString *respUUID;//河南中移在线
@property (nonatomic,retain) NSString *dn;//河南中移在线
@property (nonatomic,retain) NSString *timeTag;//河南中移在线
@property (nonatomic,retain) NSString *nfcSignature;//河南中移在线

@property (nonatomic,retain) NSString *foreignerCardVersion;//外国人永居证的证件版本

@property (nonatomic,retain) NSString *passNumber;//港澳台通行证号码
@property (nonatomic,retain) NSString *numberOfIssues;//港澳台签发次数

@property (nonatomic,retain) NSString *appId;//重庆防篡改传入的appId
@property (nonatomic,retain) NSString *localSignVal;//重庆防篡改的本地签名结果
@property (nonatomic,retain) NSString * timestamp;//(码上购) 沃行销安全加固
@property (nonatomic,retain) NSString * procId;//(码上购) 沃行销安全加固
@property (nonatomic,retain) NSString * contentSign;//(码上购) 沃行销安全加固
@property (nonatomic,retain) NSString * photoSign;//(码上购) 沃行销安全加固
@property (nonatomic,retain) NSString * contentSignFields;//沃行销安全加固
@property (nonatomic,retain) NSString * photoSignFields;//沃行销安全加固

@property (nonatomic,retain) NSString * collectKey;//20191120-浙移防篡改
@property (nonatomic,retain) NSString * factory_id;//浙移防篡改
@property (nonatomic,retain) NSString * deviceId;//浙移防篡改
@property (nonatomic,retain) NSString * Device_vid;//浙移防篡改
@property (nonatomic,retain) NSString * Device_pid;//浙移防篡改
@property (nonatomic,retain) NSString * Device_status;//浙移防篡改

@property (nonatomic,retain) NSString * readUUID;//通用、读证流水号
@property (nonatomic,retain) NSString * picImgBase64data;//新的防篡改流程里，取服务端返回的身份证头像数据转base64后的字符串，避免客户端base64转码出现不一致


-(IDCardItem*)initIDCardItem:(NSData*)picInfoData;
-(void)setErrDesc:(int)errCode;


-(NSString*)toString;

@end

@interface BleDevice : NSObject

@property (nonatomic,retain) NSString *BleIdentify;
@property (nonatomic,retain) NSString *BleName;

@end

@interface KEReadcertParms :NSObject

///读kt8000 设备的协议类型 0使用卡尔协议   1使用联通一体规范的读卡协议
@property int kt8000Protocol;

///主身份证解码服务器地址
@property (nonatomic,retain) NSArray<NSString *> *certServers;

///主相片解码服务器地址
@property (nonatomic,retain) NSArray<NSString *> *imgServers;



/**
 * 读身份证初始化参数
 * 入参： kt8000protocol   kt8000阅读器的协议类型
                            传值0 默认协议
                            传值1 联通集团kt8000一体读身份证协议;
        CertService  kt8003阅读器的身份证解码服务器ip地址列表，sdk遇到服务器错误的状态会遍历服务器地址解码，直到解码成功
        majorImgService  相片解码服务器ip地址列表，sdk遇到服务器错误的状态会遍历服务器地址解码，直到解码成功
 */
-(instancetype)initParms:(int)kt8000protocol
              CertServer:(NSArray<NSString*>*)CertService
               ImgServer:(NSArray<NSString*>*)ImgService;


@end


