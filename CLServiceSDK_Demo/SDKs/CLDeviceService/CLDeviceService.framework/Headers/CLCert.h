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

@property (nonatomic, strong) NSString * type;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * number;
@property (nonatomic, strong) NSString * address;
@property (nonatomic, strong) NSString * period;
@property (nonatomic, strong) NSData * profileImageData;

@end

NS_ASSUME_NONNULL_END
