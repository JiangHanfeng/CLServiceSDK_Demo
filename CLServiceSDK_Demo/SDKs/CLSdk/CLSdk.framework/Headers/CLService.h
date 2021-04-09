//
//  CLService.h
//  CardLeagueSDK
//
//  Created by Borya on 2020/3/24.
//  Copyright © 2020 Yuantel. All rights reserved.
//  Version 2020061800 0.8.5

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLService : NSObject

+ (NSString *)buildVersion;

//+ (NSString *)testToken;

+ (void)setDebugMode:(BOOL)isDebug;

+ (void)resgisterWithAppId:(NSString *)appId
                    appKey:(NSString *)appKey
                 appScheme:(NSString *)appScheme;

+ (void)startWithUserId:(NSString *)userId userPhone:(NSString *)userPhone;

//+ (void)startWithUserId:(NSString *)userId
//             userPhone:(NSString *)userPhone
//         deviceDelegate:(id<CLDeviceDelegate>)deviceDelegate;

+ (void)processAlipayResult:(NSDictionary *)result;

//+ (void)testUserId:(NSString *)userId phoneNumber:(NSString *)phoneNumber webUrl:(NSString *)webUrl;

@end

NS_ASSUME_NONNULL_END
