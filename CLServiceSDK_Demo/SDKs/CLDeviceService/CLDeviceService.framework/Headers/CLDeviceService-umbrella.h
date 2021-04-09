#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "CLCentralManager.h"
#import "CLCert.h"
#import "CLReader.h"
#import "CLReaderManagerController.h"
#import "CLReaderNavigationController.h"
#import "CustomIDCardManager.h"
#import "HTCardReaderManager.h"
#import "HTIDCardDefine.h"
#import "HTidCardDriver.h"
#import "IDCardItem.h"
#import "KaerAdapter.h"
#import "KaerBleTool.h"
#import "KaerIDCardItem.h"
#import "KEDelegateProtocol.h"
#import "KEreader_global.h"
#import "KeSmAlgorithm.h"
#import "WaitTimer.h"
#import "KESRWebSocket.h"
#import "btreader.h"
#import "BTReaderDriver.h"
#import "DataPackage.h"
#import "HexUtil.h"
#import "SRByteUtil.h"
#import "SRIDCardReader.h"
#import "srSm4.h"

FOUNDATION_EXPORT double CLDeviceServiceVersionNumber;
FOUNDATION_EXPORT const unsigned char CLDeviceServiceVersionString[];

