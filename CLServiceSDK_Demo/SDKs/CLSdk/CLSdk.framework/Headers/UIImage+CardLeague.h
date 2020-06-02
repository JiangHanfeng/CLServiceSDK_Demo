//
//  UIImage+CardLeague.h
//  CardLeagueSDK
//
//  Created by Borya on 2020/3/19.
//  Copyright © 2020 Yuantel. All rights reserved.
//
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (CardLeague)

+ (UIImage *)cl_imageWithColor:(UIColor *)color size:(CGSize)size;

+ (UIImage *)cl_imageNamed:(NSString *)imageName;

- (UIImage *)cl_resizeTo720p;

@end

NS_ASSUME_NONNULL_END
