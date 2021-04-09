//
//  KaerAdapter.h
//卡尔身份证阅读器——IOS sdk
//version：1.45.31
//更新内容：1.45.1 蓝牙搜索回调两次的bug、kt8003支持港澳台居住证
//        1.45.2 读kt8000设备支持港澳台居住证和外国人永居证
//        1.45.3 增加可传入主备解码服务器地址的读身份证接口，主解码服务器解码失败自动切换到备用解码服务器
//        1.45.4 上一版本的主从接口取消，换成传入服务器列表，遇到服务器状态异常的情况则根据传入的服务器列表依次解码。（除服务器状态异常，其他错误状态不会根据服务器列表依次解码）
//        1.45.5 修改sdk 断开蓝牙立即搜索连接有可能崩溃的问题
//        1.45.6  1.45版本的蓝牙搜索列表有缓存，搜索返回之前的所有设备列表，此版本修复问题
//        1.45.7  外国人永居证增加版本号字段
//        1.45.8  整理外国人永居证国籍/地区代号和国籍文字的显示
//        1.45.9  接口调用日志打印
//        1.45.10 旧读身份证接口阻塞失效、第二次读不出来问题修改
//        1.45.11 新接口禁用重读接口，防止卡在读证页面
//        1.45.12 第6~30序号之间的流程，增加蓝牙端接收超时的检测，防止读证中途拿掉身份证，阻塞15秒
//        1.45.13 民族毛难改为毛南
//        1.45.14 获取DN码
//        1.45.15 getCardSN 有可能crash
//        1.45.16 更改默认解码地址。SDK内部增加设备名称、设备软件版本、设备mac地址上报平台。增加读卡结果上报平台
//        1.45.17 增加msgo需求，平台加密机制
//        1.45.18 增加WoXingXiao平台加密机制
//        1.45.19 msgo 一体本地加固
//        1.45.20 解决网络差的环境下服务器登录返回慢导致读卡异常问题
//        1.45.21 解决iOS13.1.3及以后版本出现的写卡兼容问题
//        1.45.22 增加zjyd 防篡改机制
//        1.45.23 增加JD防篡改流程--卡尔通用的防篡改
//        1.45.24 优化wxx msgo 防篡改，去掉send result ； 需要服务同步升级
//        1.45.25 移动写卡D1开头的加密数据写失败的修复
//        1.45.26 修复旧流程读证接口，兼容；
//        1.45.27 一体本地加固接口，内部去掉账号限制
//        1.45.28 增加KT8016设备支持
//        1.45.29 优化内部重读机制，提高读证成功率;
//        1.45.30 防篡改接口再单独实现一个，不区分一体或分体设备
//        1.45.31 msgo防篡改：配合解码服务优化一体设备前后端因极少数证件存在乱码问题导致加密串不一致; 联调卡读短信中心号码问题修复

#import <Foundation/Foundation.h>
#import "KEreader_global.h"
#import "IDCardItem.h"
#import "WaitTimer.h"
#import <CoreBluetooth/CoreBluetooth.h>

#import "KEDelegateProtocol.h"




@interface KaerAdapter : NSObject

@property(weak,nonatomic)id<KaerAdapterDelegate> KEDelegate;

@property(weak,nonatomic)id<OnDataReceivedListener> keDatacallback;//KT8016回调相关数据

@property(strong,nonatomic) IDCardItem *result_idcarditem;

//初始化方法，入参是实现委托的OC对象
+ (instancetype)getInstance:(id)targetDelegateCls ;


///开始搜索蓝牙，如果不调用ble_stopSearch会一直搜索，调用连接蓝牙接口会停止
-(void)ble_startSearch;

///停止蓝牙搜索
-(void)ble_stopSearch;

///扫描周围蓝牙阅读器,定时停止搜索。这个接口是老版本的阻塞接口，建议使用新的接口ble_startSearch ，通过-(void)KE_DiscoverBlePeripheral:(BleDevice*)bledevice;返回发现的设备
-(NSMutableArray*)ScanDeviceList:(float)scanTime;//scanTime扫描等待时间，秒

///连接蓝牙
-(BOOL)connectBt:(NSString*)UUID; //uuid 要连接的设备uuid

///蓝牙断开
-(BOOL)disconnectBt;


#pragma mark -集成连接服务器、读身份证、相片解码的接口,可读分体和一体身份证阅读器

/**
 读身份证接口，此接口兼容设备KT8000 新/旧协议，KT8003协议。
 入参 ：  KEReadcertParm对象的初始化请参考 <KaerIDCardItem/IDCardItem.h> 的KEReadcertParms
 */
-(IDCardItem*)readCertwithParm:(KEReadcertParms*)parm;



/**
 新兼容读身份证接口，此接口兼容设备KT8000 新/旧协议，KT8003协议。
 入参 ：  1、protocolType 一体身份证阅读器的协议类型(此参数与分体阅读器读身份证无关)，
            传值0 默认协议
            传值1 联通集团kt8000一体读身份证协议;
        2、serverUrl 分体身份证阅读器的身份证文本信息解码地址(此参数与一体身份证阅读器读身份证无关)
            如果传nil，则默认使用kaer的云身份证解码服务器
        3、wltServerUrl 身份证照片信息解码服务器
            如果传值nil，则默认使用kaer的云相片解码服务器
        
 note:调用此接口会自动连接身份证解码服务器和相片解码服务器，不需要像以前的版本做连接服务器、断开服务器连接的操作。
 二次开发时的读身份证步骤：
        a. 调用ScanDeviceList方法获取蓝牙列表
        b. 调用connectBt 方法连接到蓝牙设备
        c. 调用此方法读身份证，返回身份证信息，返回IDCardItem 对象的picImgData属性是解码后的照片数据，能直接在UIImageView中显示
        d. 调用disconnectBt方法断开蓝牙连接
 */
-(IDCardItem*)readCert:(int)protocolType
                   url:(NSString*)serverUrl
             wltImgUrl:(NSString*)wltServerUrl;

#pragma mark KT8000一体设备 -加固专用
-(IDCardItem*)readCert_msgo_KT8000:(NSString*)serverUrl
                         wltImgUrl:(NSString*)wltServerUrl USER:(NSString *)user PWD:(NSString*)password;

/**
 2020年04月10日新增加的加固防篡改接口
 需要对接防篡改时调用此接口，适用分体、一体设备
 入参：1、serverUrl 加固服务的身份证文本信息解码地址
      2、wltServerUrl 加固服务的身份证相片解码地址（可传nil）
      3、user 加固服务的登录用户名 例如：demo
      4、password 加固服务的登录密码明文（内部加密） 例如：demo
 备注：以前对接加固防篡改时分体设备用updateAccount加readCert，一体设备用readCert_msgo_KT8000；现在为简便统一用这个
 */
-(IDCardItem*)readCertWithSignature:(NSString*)serverUrl wltImgUrl:(NSString *)wltServerUrl USER:(NSString *)user PWD:(NSString*)password;

#pragma mark 新增 - 有需要更改SDK内置账号的用户，调用此接口
-(void)updateAccount:(NSString *)user PWD:(NSString *)password;

#pragma mark -重庆联通防篡改读卡接口

/**
 重庆联通防篡改读身份证接口

 @param param json字符串，内容如下
 {
 "appId":"random",//本地读卡的appid
 "baseUrl":"http://x.x.x.x:xx",//获取secretKey的服务器地址，示例IP，请替换成正式的服务器地址
 "restPath":"/clourReadCard/appId" //获取seceretKey的api路径
 }
 @param serverUrl 身份证解码url
 @param wltServerUrl 相片解码url
 @return 身份证信息
 */
-(IDCardItem*)cloudReadCert:(NSString*)param
                        url:(NSString*)serverUrl
                  wltImgUrl:(NSString*)wltServerUrl;


#pragma mark -Tools

///获取蓝牙状态
-(int)getBleState;

///蓝牙连接状态查询,返回值:YES 已连接  NO 未连接
-(BOOL)connectStatus;

///蓝牙连接状态查询，返回: 0已断开  1连接中 2已连接 3断开中
-(int)connectStatusBT;

///分体专用-服务器连接状态查询，返回值yes  已连接   no 未连接
-(BOOL)connectStatusSSL;

///当前连接的设备蓝牙名
-(NSString*)connectedBLEName;

///当前连接设备是否是分体设备  返回yes 是分体设备  返回no  一体设备
-(BOOL)connectedIsNetworkType;

#pragma mark 新增8016设备读证
//KT8016读取二代证信息,返回身份证文本信息，返回IDCardItem 对象的picImgData属性是解码后的照片数据，能直接在UIImageView中显示
-(IDCardItem*)readCertWithoutSearch;

#pragma mark -移动sim卡开卡接口
/**
 * <p>
 * 该函数用于读取卡片空卡序列号，该函数支持本标准发布前和发布后的所有现场写卡系统空卡。
 * 因此CRM客户端可通过调用GetCardSN判断是否为本标准发布后生产的空卡
 *
 * @param CardSN
 *           空卡序列号，如卡片符合中国移动《SIM卡远程写卡业务规范》v1.0.0版本，则长度为16位，
 *           如卡片符合中国移动《现场写卡技术规范》，则长度为20位</i>
 * @return <li>0－>Success；非0状态码－>Fail
 */
-(int)GetCardSN:(char[]) CardSN;


/**
 * <b><i>public static  int GetCardICCID(char[] iccid);</i></b>
 * <p>
 * 该函数用于读卡片ICCID
 *
 * @param iccid
 *           读取到的卡信息，iccid号
 * @return <li>0－>Success；非0状态码－>Fail
 */
-(int)GetCardICCID:(char[]) iccid;


/**
 * <b><i>public static   int GetCardInfo(char[] CardInfo);</i></b>
 * <p>
 * 该函数用于读取卡片信息，卡片信息包含卡片ICCID、卡片空卡序列号
 *
 * @param CardInfo
 *           读取到的卡信息，包括空卡序列号+iccid号
 * @return <li>0－>Success；非0状态码－>Fail
 */
-(int)GetCardInfo:(char[]) CardInfo;


/**
 * <b><i>public static   int WriteCard(char[] IssueData, char[] Result);</i></b>
 * <p>
 * 该函数用于实时写卡数据写入。函数返回值为0时表示统一写卡组件向卡片发送写卡数据成功并得到卡片响应。
 * 写卡是否成功须根据Result判断.
 *
 * @param IssueData
 *           写卡数据
 * @param Result
 *           CRM向现场写卡系统回传写卡结果时须传带MAC值的完整结果
 * @return <li>0－>Success；非0状态码－>Fail
 */
-(int)WriteCard:(NSString*)IssueData ResultData:(char[])Result;

/**
 * <b><i>public static   int GetOPSErrorMsg(int ErrorCode, char[] ErrorMsg);</i></b>
 * <p>
 * 该函数用于获取错误信息，统一写卡组件将返回最近一次函数调用的错误信息
 *
 * @param ErrorCode
 *           该参数为统一写卡组件最近一次接口调用的错误代码，如最近一次执行成功则该参数返回0
 * @param ErrorMsg
 *           CRM向现场写卡系统回传写卡结果时须传带MAC值的完整结果
 * @return <li>0－>Success；非0状态码－>Fail
 */
-(int)GetOPSErrorMsg:(int) ErrorCode ErrorMessage:(char[])ErrorMsg;


#pragma mark -联通sim卡开卡接口

/**
 *readICCID   读iccid
 *返回值keys:
 *     errCode: NSString 0 成功 其他失败
 *     ICCIDData:NSData iccid数据
 **/
-(NSDictionary *) readICCID;
/**
 *readIMSI   读imsi
 *入参:Byte   0x02 读2G卡   0x03 读3G卡
 *返回值keys:
 *     errCode: NSString 0成功 其他失败
 *     isBlank: NSNumber 0 成卡  1 白卡
 *     IMSI2G:  NSData  2GIMSI  成卡时有此值
 *     IMSI3G:  NSData  3GIMSI  成卡时有此值
 **/
-(NSDictionary*)readIMSI:(Byte)simType;
/**
 *writeIMSI andIMSI2  写imsi
 *入参: IMSI2G(必填) 写IMSI2G  、 IMSI3G(选填) 写IMSI3G ，填nil则只写IMSI2G
 *返回值 int: 0 成功  1失败
 *
 **/
-(int)writeIMSI:(NSString*)IMSI2G andIMSI2:(NSString*)IMSI3G;

/**
 *writeSMSC withNumberIndex  写短信中心号
 *入参: PhoneNumber 短信中心号  、 NumberIndex 短信中心号索引
 *返回值 int: 0成功  1失败
 *
 **/
-(int)writeSMSC:(NSString *)PhoneNumber withNumberIndex:(Byte)NumberIndex;

/**
 *读短信中心
 */
-(NSString*)readSMCC;


#pragma mark -其他定制接口

/**
 发送指令关闭蓝牙
 
 @return 设备响应结果
 */
-(NSData*)command_BLE_turnoff;

/**
 发送指令设备进入休眠
 
 @return 设备响应结果
 */
-(NSData*)command_SleepMode;


/**
 获取设备版本号
 */
-(NSString *)getDeviceVersion;

/**
 卡片上电
 
 @return 0 函数执行成功 ， 非0 函数执行失败
 */
-(int)cardPowerOn;


-(int)cardPowerOn_ATR:(NSData **) ATRData;//东信

/**
 卡片下电
 
 @return 0 函数执行成功 ， 非0 函数执行失败
 */
-(int)cardPowerOff;



/**
 发送APDU指令
 
 @param sendData 要发送的指令
 @param resultData 接收到的指令
 @return 0 函数执行成功 ， 非0 函数执行失败
 */
-(int)sendApduCommand:(NSData*)sendData out:(NSData**)resultData;



/**
 一体身份证阅读器专用-获取SAMID
 
 @return samid结果
 */
-(NSData *)getSAMNo;


/**
 读身份证后获取S1(摘要)
 
 @return S1(摘要)结果
 */
-(NSData*)getS1;

/**
 读身份证后获取H1
 */
-(NSData*)getH1;

/**
 读身份证后获取C1
 note:获取C1之前必须先获取S1，调用顺序 getS1->getH1->getC1
 */
-(NSData*)getC1;



+(NSString*)getSDKVersion;


-(NSString*)getDNCode;


-(NSDictionary *)getDevSerial;
-(NSDictionary *)getSM_EncodeData;
-(int)updateSMKey:(NSData *)keys;


#pragma mark -以下接口是兼容旧版本(低于v1.32)保留的旧sdk接口。新读卡接口已更改，第一次对接或要兼容联通KT8000身份证阅读器协议的读卡请忽略以下接口

///连接服务器   返回值0 成功，其他失败    2020-03-10 旧接口不建议使用
-(int)connectServer:(NSString*)siteUrl withUser:(NSString *)uname andPwd:(NSString*)upwd;

///读身份证  2020-03-10 旧接口不建议使用
-(IDCardItem*)readCert;


///分体专用-断开服务器  2020-03-10 旧接口不建议使用
-(BOOL)disconnectSSL;



/**
 *  获取最后一次读卡数据的照片的wlt解码后数据
 *
 *  @return 返回类型NSDictionary<br>
 *  keys:<br>
 *  errCode 0为解码成功 -1解码失败<br>
 *  errDesc 在解码失败时有效，失败错误信息描述<br>
 *  DecPicData NSData型，解码成功时该key有效,解码后的相片信息
 *  2020-03-10 旧接口不建议使用
 */
-(NSDictionary*)GetDecodedPicData;

/**
 *  获取最后一次读卡数据的照片的wlt解码后数据 ,可传入服务器地址
 *
 *  @param ServUrl 自建的可用相片解码服务器外网地址
 *
 *  @return 返回类型NSDictionary<br>
 *  keys:<br>
 *  errCode 0为解码成功 -1解码失败<br>
 *  errDesc 在解码失败时有效，失败错误信息描述<br>
 *  DecPicData NSData型，解码成功时该key有效,解码后的相片信息
 *  2020-03-10 旧接口不建议使用
 */
-(NSDictionary*)getDecodedPicDataOnServerUrl:(NSString*)ServUrl;


/**
 * 获取读取结果的文字描述
 */
-(NSString *)gerResultDesc:(int)resultCode;

-(void)setCatch_serv:(NSString *)catch_srv;
-(void)setFinger_resp:(int)idata;
-(void)doRingDidi:(int)icount;
-(NSString*)getfangyiflag;
/**
 * 主动获取设备里离线存储的温度数据
 */
-(void*)getDevTemperatures;
#pragma mark -只调用一次，接口内部完成连接蓝牙、服务器，读身份证，解照片，断开蓝牙服务器操作，返回身份证结果
/**
 *测试接口作废
 * 浙江移动测试接口。只调用一次，接口内部完成连接蓝牙、连接服务器、读身份证、解照片、断开蓝牙、断开服务器操作，返回身份证结果
 */
-(IDCardItem*)readCertIntegrationInterface:(int) protype
                               BLEIdentify:(NSString*) bleuuid
                              IDCardServer:(NSString*) idcardserveraddr
                              PicImgServer:(NSString*) picimgdecodeserver;


@end
