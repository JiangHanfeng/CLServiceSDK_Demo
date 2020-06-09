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

#import "YTAES.h"
#import "YTCrypt.h"
#import "YTKey.h"
#import "yt_crypt.h"

FOUNDATION_EXPORT double YTCryptVersionNumber;
FOUNDATION_EXPORT const unsigned char YTCryptVersionString[];

