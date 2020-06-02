//
//  CLCentralManager.h
//  CLSDK_Demo
//
//  Created by Borya on 2020/3/26.
//  Copyright © 2020 Yuantel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    CLCentralManagerStatePoweredOff = 0,
    CLCentralManagerStateDisconnect,
    CLCentralManagerStateConnecting,
    CLCentralManagerStateConnected,
} CLCentralManagerState;

typedef void(^PeripheralsUpdatedBlock)(NSArray *, NSArray *);
typedef void(^CompletionBlock)(void);

static NSNotificationName const CLCentralManagerConnectFailedNotiName = @"CLCentralManagerConnectFailedNotiName";
static NSNotificationName const CLCentralManagerStateUpdatedNotiName = @"CLCentralManagerStateUpdatedNotiName";
static NSNotificationName const CLCentralManagerPeripheralUpdatedNotiName = @"CLCentralManagerPeripheralUpdatedNotiName";
static NSNotificationName const CLCentralManagerReadCertNotiName = @"CLCentralManagerReadCertNotiName";
static NSNotificationName const CLCentralManagerReadIccidNotiName = @"CLCentralManagerReadIccidNotiName";
static NSNotificationName const CLCentralManagerReadSmspNotiName = @"CLCentralManagerReadSmspNotiName";
static NSNotificationName const CLCentralManagerReadImsiNotiName = @"CLCentralManagerReadImsiNotiName";
static NSNotificationName const CLCentralManagerWriteImsiAndSmspNotiName = @"CLCentralManagerWriteImsiAndSmspNotiName";


@interface CLCentralManager : NSObject

+ (CLCentralManager *)shared;

@property (nonatomic, assign, readonly) CLCentralManagerState state;
@property (nonatomic, strong, readonly, nullable) CBPeripheral * connectedPeripheral;
@property (nonatomic, strong, readonly) NSArray<CBPeripheral *> * discoveredPeripherals;
@property (nonatomic, strong, readonly) NSArray<NSDictionary *> * cachedPeripherals;

- (void)setUp;

- (void)startScan;
- (void)stopScan;

- (void)connect:(CBPeripheral *)peripheral;
- (void)disconnect;
- (void)readCert;
- (void)readIccid;
- (void)readSmsp;
- (void)readImsi;
- (BOOL)writeImsi:(NSString *)imsi smsp:(NSString *)smsp;

@end

NS_ASSUME_NONNULL_END
