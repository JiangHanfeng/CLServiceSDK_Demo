//
//  KeSmAlgorithm.h
//  KeSmAlgorithm
//
//  Created by mac on 2019/3/11.
//  Copyright © 2019 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KeSmAlgorithm : NSObject

-(void) sm3calc:(unsigned char *) message Len:(int)iLen Out:(unsigned char *) outData;

-(void) sm4_encode:(unsigned char *)input Size:(int)ilen Count:(int)icount Key:(unsigned char *) key Out:(unsigned char *) output;

-(void) sm4_decode:(unsigned char *)input Size:(int)ilen Key:(unsigned char *)key Out:(unsigned char *) output;

@end
