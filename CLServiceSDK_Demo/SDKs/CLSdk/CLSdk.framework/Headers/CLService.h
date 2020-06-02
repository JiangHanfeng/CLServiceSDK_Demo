//
//  CLService.h
//  CardLeagueSDK
//
//  Created by Borya on 2020/3/24.
//  Copyright © 2020 Yuantel. All rights reserved.
//  Version 0.8.0

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLService : NSObject

+ (void)setDebugMode:(BOOL)isDebug;

+ (void)resgisterWithAppId:(NSString *)appId
                    appKey:(NSString *)appKey
                 appScheme:(NSString *)appScheme;

+ (void)startWithUserId:(NSString *)userId userPhone:(NSString *)userPhone;

//+ (void)startWithUserId:(NSString *)userId
//             userPhone:(NSString *)userPhone
//         deviceDelegate:(id<CLDeviceDelegate>)deviceDelegate;

+ (void)processAlipayResult:(NSDictionary *)result;

@end

NS_ASSUME_NONNULL_END
