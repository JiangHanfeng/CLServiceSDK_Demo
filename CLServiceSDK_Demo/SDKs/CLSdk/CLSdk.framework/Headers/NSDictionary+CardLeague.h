//
//  NSDictionary+CardLeague.h
//  CardLeagueSDK
//
//  Created by Borya on 2020/3/27.
//  Copyright © 2020 Yuantel. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (CardLeague)

- (NSString *)cl_sign;
- (NSDictionary *)cl_encrypt;

@end

NS_ASSUME_NONNULL_END
