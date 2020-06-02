//
//  HTIDCardDefine.h
//  SRIDCardDemo
//
//  Created by 叶威 on 17/5/20.
//  Copyright © 2017年 Syt. All rights reserved.
//

#import <Foundation/Foundation.h>

#define UserDefaultsGET(key) [[NSUserDefaults standardUserDefaults] objectForKey:key] // 取
#define UserDefaultsSET(object,key) [[NSUserDefaults standardUserDefaults] setObject:object forKey:key]  // 写
#define UserDefaultsSynchronize [[NSUserDefaults standardUserDefaults] synchronize] // 存
#define UserDefaultsRemove(key) [[NSUserDefaults standardUserDefaults] removeObjectForKey:key]  // 删

#define WeakSelf __weak typeof(self) weakSelf = self;

//协议定义

static const Byte ERR_OK = 0x00;
static const Byte ERR_TIMEOUT = 0x01;
static const Byte ERR_CHECK = 0x02;
static const Byte ERR_DATALOST = 0x03;
static const Byte ERR_CARDLOST = 0x04;

static const Byte CARD_IC = 0x00;
static const Byte CARD_ID = 0x05;
static const Byte CARD_TYPEA = 0x01;
static const Byte CARD_TYPEB = 0x02;

static const int READER_CONNECTION_LOST = 10000008;     //读卡器连接丢失，用于中途读卡器断开（蓝牙、OTG断开都适用）
static const int CARD_SELECT_FAILD = 10000010;          //选卡失败，可能的情况是没卡或放置不正确
//和服务端解码相关的错误码
#define ERR_OK 0                    //执行成功
#define ERR_Card -1                 //不是白卡或空卡
#define ERR_TIMEOUT -3              //解码（网络）超时
#define ERR_DATA -4                 //数据错误（选卡成功后的数据协议错误）
#define ERR_UNKNOWN -5              //未知错误（初始状态）
#define ERR_PORT -6                 //端口错误（如串口、蓝牙、USB等等物理链路的失败），使用应用层已有定义！
#define ERR_PARAM -7                //入参错误
#define ERR_SOCKET -8               //SOCKET错误
#define ERR_CARDLOST -9             //选卡失败，包括TransmitAPDU中的失败，使用应用层已有定义！
#define ERR_READERLOST -10          //读卡器连接失败，使用应用层已有定义！
#define ERR_SYSTEM -11              //系统返回错误
#define ERR_NETWORK -12             //未连接网络，使用应用层已有定义！

static const int OPS_OK = 0;                    //执行成功
static const int OPS_ConnectReaderFaild = -1;   //读卡器连接失败
static const int OPS_CardSelectFaild = -2;      //SIM卡插入不正确
static const int OPS_DataTransmitError = -3;    //指令数据错误
static const int OPS_NotBlankCard = -4;         //SIM卡不是空卡
static const int OPS_NOMacFound = -5;           //没有Mac数据
static const int OPS_MacDisplayTextError = -6;  //未知错误

@interface HTIDCardInfo : NSObject

@property (nonatomic,copy) NSString* name; // 姓名
@property (nonatomic,copy) NSString* sex;  //性别
@property (nonatomic,copy) NSString* ethnicity;	//民族
@property (nonatomic,copy) NSString* birth;  //生日：格式xxxx年xx月xx日
@property (nonatomic,copy) NSString* cardNo; //身份证号码
@property (nonatomic,copy) NSString* authority;	//发证机关
@property (nonatomic,copy) NSString* address; //地址
@property (nonatomic,copy) NSString* period;		//有效期
@property (nonatomic,copy) NSString* periodbegin; //有效期开始日期
@property (nonatomic,copy) NSString* periodend;  //有效期结束日期
@property (nonatomic,copy) NSString* reserved; // 保留
@property (nonatomic,strong) NSMutableData *imgData;  //身份证相片
@property (nonatomic,copy) NSString* dn; //身份证DN
@property (nonatomic,copy) NSString* certtype; //证件类型"I"是外国人，"J"是港澳台
//港澳台
@property (nonatomic,copy) NSString* passportNo; //通行证号码
@property (nonatomic,copy) NSString* checkTimes;  //签发次数
//外国人
@property (nonatomic,copy) NSString* enname; //英文姓名
@property (nonatomic,copy) NSString* DeptCode; //受理机关编码
@property (nonatomic,copy) NSString* location; //原籍地区编码
@property (nonatomic,copy) NSString* certversion; //证件版本号


// 暂时未用到的字段
//@property (nonatomic,copy) NSString* uuid;  //中移在线uuid
//@property (nonatomic,copy) NSString* timeTag; //中移在线
//@property (nonatomic,copy) NSString* nfcsignature; //中移在线
//@property (nonatomic,copy) NSString* photoWLT;  //WLT照片
//
//@property (nonatomic,strong)  NSMutableData *arrdata; // 照片流

//@property (nonatomic,strong)  NSMutableData *arrTwoIdPhotoJpeg; // jpeg照片流
//@property (nonatomic) int unTwoIdPhotoJpegLength; //数据长度


-(NSString *)getEthnicityNameByCode:(NSInteger)code;

@end

typedef void (^IDCardReadCallBack)(HTIDCardInfo *cardInfo,NSError *error);


/// 设备信息
@interface ReaderDeviceInfo : NSObject

@property (nonatomic,copy) NSString* module;  //型号
@property (nonatomic,copy) NSString* version;  //固件版本
@property (nonatomic) NSInteger battaryper;  //电量百分比
@property (nonatomic,copy) NSString* number;  //固件序列号


@end

typedef void (^NoDataCallBack)(void);
typedef void (^DataCallBack)(NSData *recieveData);
typedef void (^DeviceListCallBack)(NSArray *deviceList);
typedef void (^BoolCallBack)(BOOL isFinish);
typedef void (^IDCardInfoCallBack)(HTIDCardInfo* cardInfo,int reCode);
typedef void (^DeviceInfoCallBack)(ReaderDeviceInfo* readerInfo);
typedef void (^StringCallBack)(NSString* string);
typedef void (^BLEReCodeCallBack)(int reCode);
typedef void (^StringAndRecodeCallBack)(NSString* string,int reCode);


