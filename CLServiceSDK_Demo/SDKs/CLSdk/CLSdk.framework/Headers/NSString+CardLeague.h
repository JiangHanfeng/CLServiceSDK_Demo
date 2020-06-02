//
//  NSString+CardLeague.h
//  CardLeagueSDK
//
//  Created by Borya on 2020/3/19.
//  Copyright © 2020 Yuantel. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (CardLeague)

+ (NSString *)cl_stringFromTimeInterval:(NSTimeInterval)timeInterval dateFormat:(NSString *)dateFormat;

- (NSString *)cl_yyyyMMddHHmm;

+ (NSString *)cl_documentPath;

+ (NSString *)cl_tmpPath;

+ (NSString *)cl_tokenWithUserId:(NSString *)userId
                         tmsi:(NSString *)tmsi
                    timestamp:(NSTimeInterval)timestamp
                        appId:(NSString *)appId
                       appKey:(NSString *)appKey;
+ (NSString *)cl_boryaAuthWithUserId:(NSString *)userId md5String:(NSString *)md5String;

- (NSString *)cl_md5;

@end

NS_ASSUME_NONNULL_END
