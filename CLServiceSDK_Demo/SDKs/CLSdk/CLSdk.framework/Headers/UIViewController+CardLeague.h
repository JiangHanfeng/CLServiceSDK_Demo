//
//  UIViewController+CardLeague.h
//  CardLeagueSDK
//
//  Created by Borya on 2020/3/23.
//  Copyright © 2020 Yuantel. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (CardLeague)

- (void)cl_alert:(NSString *)title message:(NSString *)message;
- (void)cl_indicatorStartAnimating:(NSString * __nullable)text;
- (void)cl_indicatorStopAnimating;

- (void)cl_showHint:(NSString *)hint;
- (void)execute:(dispatch_block_t)block after:(double)seconds;
+ (UIViewController *)cl_current;

@end

NS_ASSUME_NONNULL_END
