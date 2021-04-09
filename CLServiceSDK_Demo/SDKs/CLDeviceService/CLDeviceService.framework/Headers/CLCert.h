//
//  CLCert.h
//  CLSDK_Demo
//
//  Created by Borya on 2020/3/26.
//  Copyright © 2020 Yuantel. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLCert : NSObject

@property (nonatomic, strong) NSString * type; // 1.大陆居民身份证 2.港澳台居住证 3.外国人永久居留身份证
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * number;
@property (nonatomic, strong) NSString * address;
@property (nonatomic, strong) NSString * period;
@property (nonatomic, strong) NSData * profileImageData;

@end

NS_ASSUME_NONNULL_END
