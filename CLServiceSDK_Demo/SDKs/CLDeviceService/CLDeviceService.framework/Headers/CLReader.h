//
//  CLReader.h
//  CLSDK_Demo
//
//  Created by Borya on 2020/3/26.
//  Copyright © 2020 Yuantel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "CLCert.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^CLReaderListUpadtedBlock)(NSArray<CBPeripheral *> *, NSArray<CBPeripheral *> *);
typedef void(^CLReaderCompletionBlock)(void);
typedef void(^CLReadCertSuccessBlock)(CLCert *);
typedef void(^CLReadCardSuccessBlock)(NSString *);
typedef void(^CLReaderFailureBlock)(NSError *);
typedef void(^CLWriteCardCompletionBlock)(NSError * __nullable);
    
typedef enum {
    CLReaderConnectionStateDisconnect = 0,
    CLReaderConnectionStateConnecting,
    CLReaderConnectionStateConnected,
} CLReaderConnectionState;

@interface CLReader : NSObject

@property (nonatomic, assign, readonly) BOOL powerOn;
@property (nonatomic, assign, readonly) CLReaderConnectionState connectionState;
@property (nonatomic, strong, readonly) NSArray<CBPeripheral *> * pairedReaders;
@property (nonatomic, strong, readonly) NSArray<CBPeripheral *> * unpairReaders;
@property (nonatomic, strong, readonly, nullable) CBPeripheral * connectedPeripheral;
@property (nonatomic, assign) NSUInteger scanTimeoutInterval;
@property (nonatomic, assign) NSUInteger connectTimeoutInterval;
//@property (nonatomic, assign) NSUInteger readTimeoutInterval;

@property (nonatomic, strong) CLReaderCompletionBlock stateChanged;

+ (void)setUp;

- (void)scan:(CLReaderListUpadtedBlock)readerListUpadted
  completion:(CLReaderCompletionBlock)completion;
- (void)stopScan;
- (void)connect:(CBPeripheral *)peripheral
        success:(CLReaderCompletionBlock)success
        failure:(CLReaderFailureBlock)failure;
- (void)disconnect;

- (void)readCertSuccess:(CLReadCertSuccessBlock)success
                failure:(CLReaderFailureBlock)failure;

- (void)readIccidSuccess:(CLReadCardSuccessBlock)success
                 failure:(CLReaderFailureBlock)failure;
- (void)readSmspSuccess:(CLReadCardSuccessBlock)success
                failure:(CLReaderFailureBlock)failure;
- (void)readImsiSuccess:(CLReadCardSuccessBlock)success
                failure:(CLReaderFailureBlock)failure;
- (void)writeImsi:(NSString *)imsi
             smsp:(NSString *)smsp
       completion:(CLWriteCardCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
