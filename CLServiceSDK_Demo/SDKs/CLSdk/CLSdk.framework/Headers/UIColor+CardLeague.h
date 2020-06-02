//
//  UIColor+CardLeague.h
//  CardLeagueSDK
//
//  Created by Borya on 2020/3/19.
//  Copyright © 2020 Yuantel. All rights reserved.
//
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (CardLeague)

+ (UIColor *)cl_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

- (NSString *)cl_hexString;

+ (UIColor *)cl_ytColor;

@end

NS_ASSUME_NONNULL_END
