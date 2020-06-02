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
    
    [CLService resgisterWithAppId:@"sdkdaqin" appKey:@"123456" appScheme:@"CLServiceSDK_demo"];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [CLService startWithUserId:@"JU200526175310251758" userPhone:@"18848371206"];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
