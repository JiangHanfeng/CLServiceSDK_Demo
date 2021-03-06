//
//  CLReaderNavigationController.h
//  CLDeviceService
//
//  Created by Spike on 2020/5/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLReaderNavigationController : UINavigationController

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController navigationBarBackgroundColor:(UIColor *)navigationBarBackgroundColor;

@end

NS_ASSUME_NONNULL_END
