//
//  东莞农商定制sdk v1.40.1
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>


/**
 *  委托
 */
@protocol BR_Callback<NSObject>

/**
 *  蓝牙状态回调
 *
 *  @param isconnected 断开false 连接 true
 */

-(void)BR_connectResult:(BOOL)isconnected;

@end


@interface KaerBleTool : NSObject

@property (nonatomic, strong) id <BR_Callback> delegate;
/**
 *  初始化
 *
 *  @param scanDeviceList 初始化列表
 *  @param scanTime       初始化界面
 *
 *  @return bletool
 */
-(id)init:(id)mySelf;

/**
 *  连接指定蓝牙
 *
 *  @param  特征
 *  @param  中心角色
 *
 *  @return 连接与否状态
 */
-(BOOL)connectBt:(CBPeripheral *)Peripheral usingCBManager:(CBCentralManager *) cManeger;

/**
 *  获取连接状态
 *
 *  @return 连接成功与否
 */
-(BOOL)isConnect;

/**
 *  断开连接
 *
 *  @return 断开成功与否
 */
-(BOOL)disconnectBt;

/**
 *  读取身份证信息
 *
 *  @return 身份证信息
 */
-(NSDictionary*)readCert;

@end
