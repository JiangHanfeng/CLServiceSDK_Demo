//
//  YTCrypt.h
//  YTCrypt
//
//  Created by Chauncy on 7/28/16.
//  Copyright © 2016 Chauncy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YTCrypt : NSObject

/**
 * 获取秘钥
 * @param timestamp 秒为单位
 */
+ (NSData *)privateKeyWithTmsi:(NSString *)tmsi
                     timestamp:(NSTimeInterval)timestamp;

+ (NSData *)privateKeyWithTmsi:(NSString *)tmsi
                        appKey:(NSString *)appKey
                     timestamp:(NSTimeInterval)timestamp;

/**
 * 加密
 */
+ (NSString *)encryptStringWithSourceString:(NSString *)src
                                        key:(NSData *)key;

/**
 * 解密
 */
//+ (NSString *)decryptStringWithSourceString:(NSString *)src
//                                        key:(NSData *)key;

/**
 * MD5加密
 */
+ (NSString *)md5:(NSString *)src;

/**
 * 对MD5再加密
 */
+ (NSString *)encryptMD5String:(NSString *)md5String;

/**
 * 对字符串签名
 */
+(NSString *)signWithString:(NSString *)src;

/**
 * 对字典签名
 */
+ (NSString *)signWithDictionary:(NSDictionary *)dic;

/**
 * 将明文参数加密
 */
+ (NSDictionary *)encryptDictionary:(NSDictionary *)dic;

@end
