//
//  OCViewController.m
//  CLServiceSDK_Demo
//
//  Created by Borya on 2020/6/2.
//  Copyright © 2020 Spike. All rights reserved.
//

#import "OCViewController.h"
#import <CLSdk/CLService.h>

@interface OCViewController ()

@end

@implementation OCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)registSDK {
    // 这个appScheme为集成支付宝SDK时在URL-Types设置的URL Schemes，如果填写的不一致，将导致支付完成后无法返回接入方的app
    [CLService resgisterWithAppId:@"your app id"
                           appKey:@"your app key"
                        appScheme:@"your appScheme"];
}

- (void)callSDK {
    // userId 接入方平台的用户id
    // userPhone 接入方平台的用户手机号
    [CLService startWithUserId:@"your user id"
                     userPhone:@"your user phone number"];
}

@end
