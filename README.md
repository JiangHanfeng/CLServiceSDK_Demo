## 导入相关文件

#### 卡盟相关

	* CLSdk.framework
	* CLSdk.bundle
	* CLDeviceService.framework
	* CLDeviceService.bundle

#### 森瑞设备SDK

* SRIDCardReader.framework
* libReliableBurstData_arm64.a

#### 卡尔设备SDK

* KaerIDCardItem.framework

#### HT设备SDK

* libHTCardReader.a

#### 腾讯人脸识别

* faceLiveReflect.framework
* NextCV.framework
* rapidnet_ios.framework
* WBCloudReflectionFaceVerify.framework
* YTCommon.framework
* YTIllumination.framework
* YTPoseDetector.framework
* YTTrackProWB.framework
* detector_wb.bundle
* PEDat_wb.bundle
* ufa_wb.bundle
* WBCloudReflectionFaceVerify.bundle

#### 支付宝SDK（接入方自行导入）

***



## 添加隐私权限列表

Info.plist中添加

* Privacy - Bluetooth Always Usage Description
* Privacy - Bluetooth Peripheral Usage Description
* Privacy - Camera Usage Description
* Privacy - Photo Library Usage Description
* Privacy - Photo Library Additions Usage Description
* Privacy - Location When In Use Usage Description

***



## 允许HTTP协议

Info.plist中添加

```objective-c
App Transport Security Settings
```

并设置App Transport Security Settings的值为YES

***



## 设置后台运行模式

Xcode选中项目，选择Signing&Capabilities ，点击+Capabilities，选择Background Modes，勾选

```
Uses Bluetooth LE accessories
```

和

```
Acts as a Bluetooth LE accessory
```

***



## 添加依赖

#### 在Build Phases-Link Binary With Libraries中添加以下依赖的系统库：

+ libc++.tbd

+ libz.tbd

+ libicucore.tbd

+ UIKit.framework

+ AVFoundation.framework

+ MobileCoreServices.framework

+ CoreVideo.framework

+ Accelerate.framework

+ Security.framework

+ SystemConfiguration.framework

+ CoreMedia.framework

+ AudioToolbox.framework

+ CoreTelephony.framework

+ ImageIO.framework

+ WebKit.framework

+ AdSupport.framework

+ CoreLocation.framework

+ MessageUI.framework

+ CoreBluetooth.framework

  ***

#### 在Build Settings-Linking-Other Linker flags中添加"-Objc"

***



## 代码调用

#### 注册卡盟SDK

```objective-c
[CLService resgisterWithAppId:@"your appId" appKey:@"your appKey" appScheme:@"your appScheme which will be used to call AlipaySDK"];
```

##### 参数说明

* appScheme即接入支付宝SDK时在所设置的URL Schemes（Xcode-Info-URL Types）,详情见支付宝开放平台-App支付-快速接入-客户端 iOS 集成流程



#### 调起卡盟SDK

```objective-c
[CLService startWithUserId:@"your userId" userPhone:@"your phone number"];
```

##### 参数说明

* userId为接入方后台系统为每个用户分配的userId
* userPhone为该用户绑定的手机号码，如17099999999



#### 处理支付回调

```objective-c
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    if ([url.host isEqualToString:@"safepay"]) {
        // 支付跳转支付宝钱包进行支付，处理支付结果
        [[AlipaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(NSDictionary *resultDic) {
						/*
             * 接入方自己的处理
             */
            
          	// 将resultDic透传给卡盟SDK
            [CLService processAlipayResult:resultDic];
        }];
    }
    return YES;
}
```

##### 调用说明

* 在AppDelegate.m中的

  ```objective-c
  - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
  ```

  方法中处理支付宝回调时，将resultDic透传给CLService